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
#include "pack.h"
#include "sha256.h"
#include <string>
#include <fstream>
#include <vector>

using namespace std;

void packLocker(string fileName, string password, string message) {
	fstream
		f_file;

	f_file.open(fileName, fstream::app);

	f_file << "----";
	f_file << "{" << sha256(password) << "}";
	f_file << "{" << message << "}";
	f_file << "{" << "0" << "}";

	f_file.close();
}

void packLocker(string fileName, string password, string message, string address) {
	fstream
		f_file;

	f_file.open(fileName, fstream::app);

	f_file << "----";
	f_file << "{" << sha256(password) << "}";
	f_file << "{" << message << "}";
	f_file << "{" << address << "}";

	f_file.close();
}

void attachExecutable(string packedFile, string exePath) {
	fstream
		f_exe;
	fstream
		f_write;

	// Opening the attached exe and the packed locker file.
	f_exe.open( exePath, fstream::in | fstream::binary );
	f_write.open( packedFile, fstream::app | fstream::binary);

	// Creating brackets and writing the exe into the packed file.
	f_write << "{";
	f_write << f_exe.rdbuf();
	f_write << "}";

	f_exe.close();
	f_write.close();
}