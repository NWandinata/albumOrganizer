/*Makenzie Johnson and Nicholas Wandinata*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>
#include "lib_info.h"
// If compilation error, try including iterator

using namespace std;

int main(int argc, char **argv) {
	string musicInfo;
	// map<string, Artist> map; - This may or may not be necessary
	Artist entryAr;
	Album entryAl;
	Song entryS;

	ifstream file;
	file.open(argv[1]);
	while(!file.eof()) {
		getline(file, musicInfo);
		replace(musicInfo.begin(), musicInfo.end(), '_', ' ');
		// Insert into struct here using sstream

	}

	for(map<string,Artist>::iterator it= artists.begin(); it != artists.end(); ++it) {
   		cout << it->first << ": " << it->second.nsongs << ", ";
   		printTime(it->second.time);
	}

	file.close();
	return 0;
}
