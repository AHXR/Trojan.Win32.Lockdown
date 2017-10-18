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
#include "handleThread.h"
#include "windows.h"
#include <tlhelp32.h>
#include <string>

#define TASK_MANAGER_KILL
#define FORCE_WINDOW

#define SCREEN_LOCK_FRM L"frmScreenLock"
#ifdef TASK_MANAGER_KILL
	#define SCREEN_LOCK_TSKMGR L"taskmgr.exe"
#endif

using namespace System;
using namespace System::Threading;
using namespace System::Diagnostics;
using namespace System::ComponentModel;

bool b_password_res;
HANDLE t_handle;
DWORD d_thread_id;

DWORD WINAPI calculateHandleData(LPVOID lpParameter);

#ifdef TASK_MANAGER_KILL
	DWORD FindProcessId(const std::wstring& processName);
#endif

void startHandleThreading() {
	
	t_handle = CreateThread(0, 0, calculateHandleData, 0, 0, &d_thread_id);
}

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
		}
	}
	return 0;
}

#ifdef TASK_MANAGER_KILL
	/*
		Taken from - https://stackoverflow.com/a/13716992
	*/
	DWORD FindProcessId(const std::wstring& processName)
	{
		PROCESSENTRY32 processInfo;
		processInfo.dwSize = sizeof(processInfo);

		HANDLE processesSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
		if (processesSnapshot == INVALID_HANDLE_VALUE)
			return 0;

		Process32First(processesSnapshot, &processInfo);
		if (!processName.compare(processInfo.szExeFile))
		{
			CloseHandle(processesSnapshot);
			return processInfo.th32ProcessID;
		}

		while (Process32Next(processesSnapshot, &processInfo))
		{
			if (!processName.compare(processInfo.szExeFile))
			{
				CloseHandle(processesSnapshot);
				return processInfo.th32ProcessID;
			}
		}

		CloseHandle(processesSnapshot);
		return 0;
	}
#endif