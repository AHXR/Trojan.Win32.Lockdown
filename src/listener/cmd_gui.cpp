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
#include				<Windows.h>
#include				<msclr\marshal_cppstd.h>

HANDLE					h_command;
DWORD					dw_command;

#include				"cmd_unlock.h"
#include				"cmd_gui.h"
#include				"zombie.h"
#include				"frmCommand.h"

bool					b_unlock_dialog;
int						i_zombie_update;
int						i_selected_idx;

std::string convertCommand(System::String ^ str) {
	return msclr::interop::marshal_as< std::string >(str) + " ";
}

DWORD WINAPI t_showCommandGUI(LPVOID lpParameter) {
	b_unlock_dialog = true;
	AHXRListener::frmCommand frm;
	System::Windows::Forms::Application::Run(%frm);
	return 0;
}

void closeCommandGUI( System::Windows::Forms::Control ^ frmref ) {
	b_unlock_dialog = false;
	frmref->Hide();
	CloseHandle(h_command);
}