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
#define							_WINSOCK_DEPRECATED_NO_WARNINGS

#include						<Windows.h>
#include						<iostream>
#include						<string>
#include						<stdlib.h>
#include						<winsock2.h>
#include						<ws2tcpip.h>
#include						<stdio.h>
#include						"client_thread.h"
#include						"server_thread.h"
#include						"server_manage.h"
#include						"on_command.h"

#pragma comment					(lib, "Ws2_32.lib")
#pragma comment					(lib, "Mswsock.lib")
#pragma comment					(lib, "AdvApi32.lib")

HANDLE							t_handle;
DWORD							d_thread_id;
DWORD WINAPI					calculateHandleData(LPVOID lpParameter);

DWORD WINAPI t_serverProcess(LPVOID lpParameter) {
	WSADATA wsaData;
	int iResult;

	SOCKET ListenSocket = INVALID_SOCKET;
	SOCKET ClientSocket = INVALID_SOCKET;

	struct addrinfo *result = NULL;
	struct addrinfo hints;

	char recvbuf[DEFAULT_BUFLEN];
	int recvbuflen = DEFAULT_BUFLEN;

	// Initialize Winsock
	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0) {
		printf("WSAStartup failed with error: %d\n", iResult);
		return 1;
	}

	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	hints.ai_flags = AI_PASSIVE;

	// Resolve the server address and port
	iResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);
	if (iResult != 0) {
		printf("getaddrinfo failed with error: %d\n", iResult);
		WSACleanup();
		return 1;
	}

	// Create a SOCKET for connecting to server
	ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
	if (ListenSocket == INVALID_SOCKET) {
		printf("socket failed with error: %ld\n", WSAGetLastError());
		freeaddrinfo(result);
		WSACleanup();
		return 1;
	}

	// Setup the TCP listening socket
	iResult = bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen);
	if (iResult == SOCKET_ERROR) {
		printf("bind failed with error: %d\n", WSAGetLastError());
		freeaddrinfo(result);
		closesocket(ListenSocket);
		WSACleanup();
		return 1;
	}

	freeaddrinfo(result);

	iResult = listen(ListenSocket, SOMAXCONN);
	if (iResult == SOCKET_ERROR) {
		printf("listen failed with error: %d\n", WSAGetLastError());
		closesocket(ListenSocket);
		WSACleanup();
		return 1;
	}

	b_accepting = true;

	struct sockaddr ip_address;
	socklen_t ip_len = sizeof(ip_address);

	// Accept a client socket
	ClientSocket = accept(ListenSocket, &ip_address, &ip_len);
	if (ClientSocket == INVALID_SOCKET) {
		printf("accept failed with error: %d\n", WSAGetLastError());
		closesocket(ListenSocket);
		WSACleanup();
		return 1;
	}

	// No longer need server socket
	closesocket(ListenSocket);

	struct sockaddr_in * s_in = (struct sockaddr_in *) & ip_address;

	while (1) {
		iResult = recv(ClientSocket, recvbuf, recvbuflen, 0);
		if (iResult > 0) {

			if (iResult < DEFAULT_BUFLEN - 1)
				recvbuf[iResult] = '\0';

			std::cout << recvbuf << std::endl;
			void(*callback)(char *);
			callback = &onClientSendCommand;
			callback(recvbuf);
		}
		else {
			/*
				If the client closed their program and/or the connection is reset,
				we're going to reset the server as well. Recv will automatically
				shut itself down and mess up everything once the connection is reset.
			*/
			printf("recv failed with error: %d\n", WSAGetLastError());
			closesocket(ListenSocket);
			WSACleanup();
			stopServer();
			startServer();
			break;
		}
		Sleep(1000);
	}

	return 0;
}