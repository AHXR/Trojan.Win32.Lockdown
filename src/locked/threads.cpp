#include									"threads.h"
#include									"frmMain.h"

HANDLE										h_frm_thread;
HANDLE										h_frm_top_thread;
DWORD										dw_frm_top_thread;
DWORD										dw_frm_thread;
DWORD WINAPI								t_showLockdownForm(LPVOID lpParameter);
DWORD WINAPI								t_alwaysOnTop(LPVOID lpParameter);
DWORD										FindProcessId(const std::wstring& processName);
bool										b_scan_status;

using namespace								System;
using namespace								System::Windows::Forms;

DWORD WINAPI t_showLockdownForm(LPVOID lpParameter) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	AHXRShutdownLocked::frmMain frm;
	Application::Run(%frm);
	return 0;
}

DWORD WINAPI t_alwaysOnTop(LPVOID lpParameter) {
	bool b_found = false;
	HWND h_lockdown;
	while (1) {
		if (!b_found) {
			h_lockdown = FindWindow(NULL, WINDOW_NAME);
			if (h_lockdown != NULL)
				b_found = true;
		}
		else {
			SetWindowPos(h_lockdown, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);

			// FORCE the window to be in front at all times
			SetActiveWindow(h_lockdown);
			SetFocus(h_lockdown);
			SetCapture(h_lockdown);
			SetForegroundWindow(h_lockdown);
			EnableWindow(h_lockdown, true);

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

DWORD FindProcessId(const std::wstring & processName) {
	PROCESSENTRY32 processInfo;
	processInfo.dwSize = sizeof(processInfo);

	HANDLE processesSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
	if (processesSnapshot == INVALID_HANDLE_VALUE)
		return 0;

	Process32First(processesSnapshot, &processInfo);
	if (!processName.compare(processInfo.szExeFile)) {
		CloseHandle(processesSnapshot);
		return processInfo.th32ProcessID;
	}

	while (Process32Next(processesSnapshot, &processInfo)) {
		if (!processName.compare(processInfo.szExeFile)) {
			CloseHandle(processesSnapshot);
			return processInfo.th32ProcessID;
		}
	}

	CloseHandle(processesSnapshot);
	return 0;
}