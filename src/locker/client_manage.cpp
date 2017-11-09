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
#include						<Windows.h>
#include						"client_manage.h"

HANDLE							h_client;
DWORD							dw_client;
bool							b_new_message = false;
char *							c_message;
bool							b_ready_to_send;
char *							s_server_host;
SOCKET							ConnectSocket = INVALID_SOCKET;

bool isClientReady() {
	return b_ready_to_send;
}