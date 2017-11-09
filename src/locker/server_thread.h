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
#define SERVER_ERROR_0						"SOCKET FAILED"
#define SERVER_ERROR_1						"FAILED TO START SERVER"
#define SERVER_ERROR_2						"Server still not accepting(?)"

#define DEFAULT_BUFLEN						512
#define DEFAULT_PORT						"27016"

extern HANDLE								t_handle;
extern DWORD								d_thread_id;
extern DWORD WINAPI							calculateHandleData(LPVOID lpParameter);

#define START_SERVER_THREAD()				{t_handle = CreateThread(0, 0, calculateHandleData, 0, 0, &d_thread_id);}

