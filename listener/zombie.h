//=======================================================
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
#include <string>

extern int addZombie(std::string zombAddress, std::string zombieMessage);
extern int getZombieCount();
extern std::string getZombieAddress(int zombieID);
extern std::string getZombieMessage(int zombieID);
extern void setZombieListID(int zombieID, int idx);
extern int getZombieIDFromAddress(std::string zombAddress);
extern void deleteZombie(int zombieID);
extern int getZombieIDFromMessage(std::string zombMessage);
extern int getZombieIDFromIDX(int idx);