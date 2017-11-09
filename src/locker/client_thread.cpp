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
#define							WIN32_LEAN_AND_MEAN

#include						<windows.h>
#include						<winsock2.h>
#include						<ws2tcpip.h>
#include						<stdlib.h>
#include						<stdio.h>
#include						<string>
#include						<iostream>

#include						"read_settings.h"
#include						"client_thread.h"
#include						"on_command.h"
#include						"client_manage.h"

#pragma comment					(lib, "Ws2_32.lib")
#pragma comment					(lib, "Mswsock.lib")
#pragma comment					(lib, "AdvApi32.lib")

std::string						MBFromW(LPCWSTR pwsz, UINT cp);

DWORD WINAPI t_clientServer(LPVOID lpParameter) {
	WSADATA wsaData;
	
	struct addrinfo *result = NULL,
		*ptr = NULL,
		hints;
	int iResult;
	int recvbuflen = DEFAULT_CLIENT_BUFLEN;

	// Initialize Winsock
	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0) {
		printf("WSAStartup failed with error: %d\n", iResult);
		return 1;
	}

	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;

	// Resolve the server address and port
	iResult = getaddrinfo(s_server_host, DEFAULT_CLIENT_PORT, &hints, &result);
	if (iResult != 0) {
		printf("getaddrinfo failed with error: %d\n", iResult);
		WSACleanup();
		return 1;
	}

	// Attempt to connect to an address until one succeeds
	for (ptr = result; ptr != NULL; ptr = ptr->ai_next) {

		// Create a SOCKET for connecting to server
		ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype,
			ptr->ai_protocol);
		if (ConnectSocket == INVALID_SOCKET) {
			printf("socket failed with error: %ld\n", WSAGetLastError());
			WSACleanup();
			return 1;
		}

		// Connect to server.
		iResult = connect(ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
		if (iResult == SOCKET_ERROR) {
			closesocket(ConnectSocket);
			ConnectSocket = INVALID_SOCKET;
			continue;
		}
		break;
	}

	freeaddrinfo(result);

	if (ConnectSocket == INVALID_SOCKET) {
		printf("Unable to connect to server! %ld\n\n", WSAGetLastError());
		WSACleanup();
		return 1;
	}

	b_ready_to_send = true;

	std::string
		s_data,
		os_name
	;

	// Getting the computer name.
	TCHAR t_computer_name[MAX_COMPUTERNAME_LENGTH + 1];
	DWORD d_size = sizeof(t_computer_name) / sizeof(t_computer_name[0]);
	GetComputerName(t_computer_name, &d_size);

	// Getting the OS
	OSVERSIONINFO os_vi;
	os_vi.dwOSVersionInfoSize = sizeof(os_vi);
	if (GetVersionEx(&os_vi) == 0)
		os_name = "Unknown";

	switch (os_vi.dwPlatformId) {
		case VER_PLATFORM_WIN32s: {
			os_name = "Windows 3.x";
			break;
		}
		case VER_PLATFORM_WIN32_WINDOWS: {
			os_name = os_vi.dwMinorVersion == 0 ? "Windows 95" : "Windows 98";
			break;
		}
		case VER_PLATFORM_WIN32_NT: {
			os_name = "Windows NT";
			break;
		}
	}

	if (os_vi.dwMajorVersion == 10 && os_vi.dwMinorVersion == 0)
		os_name = "Windows 10";
	else if (os_vi.dwMajorVersion == 6 && os_vi.dwMinorVersion == 3)
		os_name = "Windows 8.1";
	else if (os_vi.dwMajorVersion == 6 && os_vi.dwMinorVersion == 2)
		os_name = "Windows 8";
	else if (os_vi.dwMajorVersion == 6 && os_vi.dwMinorVersion == 1)
		os_name = "Windows 7";
	else if (os_vi.dwMajorVersion == 6 && os_vi.dwMinorVersion == 0)
		os_name = "Windows Vista";

	s_data += MBFromW(t_computer_name, 1) + " (" + os_name + ") - " + s_message;
	puts((char*)s_data.c_str());

	// Setting the message up for queue.
	SEND_NEW_MESSAGE((char*)s_data.c_str());

	while (1) {
		if (b_new_message) {
			iResult = send(ConnectSocket, c_message, strlen(c_message), 0);

			if (iResult == SOCKET_ERROR) {
				printf("send failed with error: %d\n", WSAGetLastError());
				closesocket(ConnectSocket);
				WSACleanup();
				return 1;
			}
			b_new_message = false;
		}
	}
	return 0;
}

// https://stackoverflow.com/a/5513888
std::string MBFromW(LPCWSTR pwsz, UINT cp) {
	int cch = WideCharToMultiByte(cp, 0, pwsz, -1, 0, 0, NULL, NULL);

	char* psz = new char[cch];

	WideCharToMultiByte(cp, 0, pwsz, -1, psz, cch, NULL, NULL);

	std::string st(psz);
	delete[] psz;

	return st;
}