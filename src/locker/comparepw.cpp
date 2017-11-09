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
#include					"comparepw.h"
#include					"sha256.h"
#include					"read_settings.h"
#include					"handle_thread.h"
#include					"client_manage.h"
#include					<msclr\marshal_cppstd.h>

using namespace				msclr::interop;

void comparePasswords(System::String ^ passwordInput) {
	std::string
		s_input
	;

	s_input = marshal_as< std::string >(passwordInput);
	s_input = sha256(s_input);

	if (s_input.compare(s_password) == 0) {
		b_password_res = true;

		if (b_exe_attach)
			remove(ATTACH_FILE_C); // Remove the attachment file before closing. No footsteps.

		closesocket(ConnectSocket);
		WSACleanup();

		exit(1);
	}
}
