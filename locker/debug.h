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
#pragma once
#include <string>

#define DUMMY_FILE "C:\\Users\\-\\Documents\\Visual Studio 2015\\Projects\\AHXR ScreenLock\\Debug\\Dummy.exe"
#define DUMMY_STUDIO_THIS_EXE "C:\\Users\\-\\Documents\\Visual Studio 2015\\Projects\\AHXR ScreenLock\\Debug\\AHXRLocker.exe" 
#define DUMMY_EXE "C:\\Users\\-\\Documents\\Visual Studio 2015\\Projects\\AHXR ScreenLock\\calc.exe"
#define DUMMY_PASSWORD "hi"
#define DUMMY_MESSAGE "Locked out :)"

extern void packLocker(std::string fileName, std::string password, std::string message);
extern void attachExecutable(std::string packedFile, std::string exePath);