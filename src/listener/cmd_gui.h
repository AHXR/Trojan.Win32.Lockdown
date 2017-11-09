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
extern void					showCommandGUI();
extern DWORD WINAPI			t_showCommandGUI(LPVOID lpParameter);
extern void					closeCommandGUI(System::Windows::Forms::Control ^ frmref);
extern std::string			convertCommand(System::String ^ str);

extern bool					b_unlock_dialog;
extern int					i_zombie_update;
extern int					i_selected_idx;
extern HANDLE				h_command;
extern DWORD				dw_command;

#define SHOWCMDGUI()		{h_command = CreateThread(0, 0, t_showCommandGUI, 0, 0, &dw_command);}