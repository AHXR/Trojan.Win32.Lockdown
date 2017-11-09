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
#include						 <string>
#include						<iostream>

#include						"on_command.h"

using namespace std;

void onClientSendCommand(char * commandName) {
	string
		s_command,
		s_parameters
		;
	s_command = commandName;

	size_t t_command = s_command.find(" ");

	if (t_command != string::npos) {
		s_command = s_command.substr(0, t_command);
		s_parameters = s_command.substr(t_command, s_command.length());
	}

	cout << "CMD: " << s_command << "\r\nPARAMS: " << s_parameters << endl;

	if (!s_command.compare(UNLOCK_COMMAND))
		exit(0);
}