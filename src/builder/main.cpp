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
#include				<msclr\marshal_cppstd.h>
#include				<iostream>

using namespace			msclr::interop;
using namespace			System;
using namespace			System::Windows::Forms;

std::string				s_attached_p;
bool					b_tracking_toggle;

#include				"build.h"
#include				"locker.h"
#include				"pack.h"
#include				"frmMain.h"
#include				"settings.h"

//#define DEBUG_MODE
#define ARG_FILE_NAME	0
#define ARG_PASSWORD	1
#define ARG_MESSAGE		2
#define ARG_EXE			3
#define ARG_ADDRESS		4

[STAThread]
void main(array<String^>^ args) {
#ifdef DEBUG_MODE
	packLocker("AXHRLocker.exe", "hi", "basic message.");
#endif
	setLockerFileName(LOCKER_FILE_PATH);

	if (args->Length >= 3)
		createClientLocker(args[ARG_FILE_NAME], args[ARG_PASSWORD], args[ARG_MESSAGE], args[ARG_EXE], args[ARG_ADDRESS]);

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	AHXRScreenLock::frmMain frm;
	Application::Run(%frm);
}