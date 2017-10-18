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
#include "debug.h"
#include "sha256.h"
#include "readSettings.h"

#include <string>
#include <fstream>

void packLocker(std::string fileName, std::string password, std::string message) {
	std::ifstream
		f_old;
	std::ofstream
		f_new;

	remove(DUMMY_FILE);

	f_old.open(DUMMY_STUDIO_THIS_EXE, std::ios::binary);
	f_new.open(DUMMY_FILE, std::ios::binary);

	f_new << f_old.rdbuf();

	f_old.close();
	f_new.close();

	std::fstream
		f_file;

	f_file.open(DUMMY_FILE, std::fstream::app);

	f_file << SEARCH_OPENER << sha256(password) << SEARCH_CLOSER;
	f_file << SEARCH_OPENER << message << SEARCH_CLOSER;

	f_file.close();
}
