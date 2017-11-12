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
#include							"lockdown.h"
#include							"ownership.h"
#include							"locker.h"
#include							"pack.h"
#include							"resource.h"
#include							<fstream>
#include							<Windows.h>

using namespace						std;

void lockdownFile(string fileName) {
	if (!isFileLocked(fileName)) {

		ifstream
			f_old;
		ofstream
			f_new;
		string
			s_new_name = fileName + SHUTDOWN_EXT;

		f_old.open(fileName, ios::binary);
		f_new.open(s_new_name, ios::binary);

		f_new << f_old.rdbuf();

		f_old.close();
		f_new.close();

		TakeOwnership(const_cast< char * >(fileName.c_str()));
		remove(fileName.c_str());

		/*
			// Old building lockdown method.
			string
				s_args = string( "AHXRBuilder.exe " ) + "\"" + fileName + "\" \"hi\" " + "\"SHUTDOWN PROTECTION\"" + " \"" + s_new_name + "\"";

			puts(const_cast<char *>(s_args.c_str()));
			STARTUPINFO p_start = {
				sizeof(p_start)
			};
			PROCESS_INFORMATION p_info;

			if (!CreateProcess(NULL, const_cast<char *>(s_args.c_str()), NULL, NULL, TRUE, 0, NULL, NULL, &p_start, &p_info))
				exit(0);

			WaitForSingleObject(p_info.hProcess, INFINITE);
			CloseHandle(p_info.hProcess);
			CloseHandle(p_info.hThread);
		*/

		HRSRC hRes = FindResource(NULL, MAKEINTRESOURCE(IDR_BINARY2), RT_RCDATA);
		unsigned int i_resource = ::SizeofResource(NULL, hRes);
		LPVOID lpRes = LoadResource(NULL, hRes);
		void * pResourceLock = LockResource(lpRes);

		TCHAR tmpPath[MAX_PATH];
		GetTempPath(MAX_PATH, tmpPath);

		std::string s_extract;
		s_extract = tmpPath;
		s_extract += "shutdown17.tmp";

		std::fstream f;

		f.open(s_extract, std::ios::out | std::ios::binary);
		f.write((char*)pResourceLock, i_resource);
		f.close();

		setLockerFileName(s_extract);

		buildNewLocker(fileName);
		packLocker(fileName, SHUTDOWN_PW, SHUTDOWN_MSG);
		attachExecutable(fileName, s_new_name);

		TakeOwnership(const_cast< char * >(s_new_name.c_str()));
		remove(s_new_name.c_str()); // Remove old .exe file.
		remove(s_extract.c_str()); // Remove .tmp
	}
}

bool isFileLocked(string fileName) {
	fstream
		f_exe;
	streamoff
		is_length;
	int
		i_length;
	f_exe.open(fileName, ios::in | ios::binary);

	// Fetching the length of the .exe file.
	f_exe.seekg(0, std::ios::end);
	is_length = f_exe.tellg();
	f_exe.close();

	i_length = static_cast<int>(is_length);

	// Reading the file and converting it to a standard string.
	char * c_search = new char[i_length];
	f_exe.read(c_search, i_length);
	std::string s_search(c_search, i_length);

	// Closing it. No longer needed.
	f_exe.close();

	size_t t_dashes = s_search.find("----");
	if (t_dashes != string::npos)
		return true;
	else
		return false;
}