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
#include							<Windows.h>

extern void							minimizeAllWindows();
extern void							restoreWindows();
extern HWND							h_window_process;

#define MINIMIZE_ALL_WINDOWS()		{h_window_process = FindWindow(L"Shell_TrayWnd", NULL); SendMessage(h_window_process, WM_COMMAND, 419, 0); }
#define RESTORE_WINDOWS()			{SendMessage(h_window_process, WM_COMMAND, 416, 0);}