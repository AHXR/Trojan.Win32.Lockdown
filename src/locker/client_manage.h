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
extern HANDLE						h_client;
extern DWORD						dw_client;
extern bool							b_new_message;
extern char *						c_message;
extern bool							b_ready_to_send;
extern char *						s_server_host;
extern SOCKET						ConnectSocket;

extern bool							isClientReady();
DWORD WINAPI						t_clientServer(LPVOID lpParameter);

#define	SEND_NEW_MESSAGE(MSG)		{ b_new_message = true; c_message = MSG; }
#define START_CLIENT_THREAD()		{ h_client = CreateThread(0, 0, t_clientServer, 0, 0, &dw_client); }
#define SET_HOST_ADDRESS(AHOST)		{ s_server_host = AHOST; }