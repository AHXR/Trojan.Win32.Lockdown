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
#include <vector>
#include "zombie.h"

using namespace std;

int i_zombie_idx = 0;

struct ZOMBIE_DATA {
	int ZOMBIE_ID;
	int ZOMBIE_LIST_ID;
	std::string ZOMBIE_ADDRESS;
	std::string ZOMBIE_MESSAGE;
};
vector< ZOMBIE_DATA > v_zombies;

int addZombie(string zombAddress, string zombieMessage) {

	ZOMBIE_DATA zomb;
	zomb.ZOMBIE_ID = i_zombie_idx;
	zomb.ZOMBIE_ADDRESS = zombAddress;
	zomb.ZOMBIE_MESSAGE = zombieMessage;

	v_zombies.push_back(zomb);
	i_zombie_idx++;
	return zomb.ZOMBIE_ID;
}

void setZombieListID(int zombieID, int idx) {
	for (auto & zomb : v_zombies)
		if (zomb.ZOMBIE_ID == zombieID)
			zomb.ZOMBIE_LIST_ID = idx;
}

int getZombieCount() {
	return v_zombies.size();
}

string getZombieAddress(int zombieID) {
	for (auto & zomb : v_zombies)
		if (zomb.ZOMBIE_ID == zombieID)
			return zomb.ZOMBIE_ADDRESS;
	return NULL;
}

string getZombieMessage(int zombieID) {
	for (auto & zomb : v_zombies) 
		if (zomb.ZOMBIE_ID == zombieID)
			return zomb.ZOMBIE_MESSAGE;
	return NULL;
}

int getZombieIDFromAddress(string zombAddress) {
	for (auto & zomb : v_zombies) {
		if (zomb.ZOMBIE_ADDRESS == zombAddress)
			return zomb.ZOMBIE_ID;
	}
	return -1;
}

int getZombieIDFromMessage(string zombMessage) {
	for (auto & zomb : v_zombies) {
		if (zomb.ZOMBIE_MESSAGE == zombMessage)
			return zomb.ZOMBIE_ID;
	}
	return -1;
}

int getZombieIDFromIDX(int idx) {
	for (auto & zomb : v_zombies) {
		if (zomb.ZOMBIE_LIST_ID == idx)
			return zomb.ZOMBIE_ID;
	}
	return -1;
}

void deleteZombie(int zombieID) {
	for (size_t i = 0; i < v_zombies.size(); i++)
		if (v_zombies[i].ZOMBIE_ID = zombieID)
			v_zombies.erase(v_zombies.begin() + i);
}