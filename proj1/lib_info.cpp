/*Makenzie Johnson and Nicholas Wandinata*/
#include <iostream>
#include <fstream>
#include <strings>
#include "lib_info.h"

using namespace std;

int main(int argc, char **argv) {
	string musicInfo;

	ifstream file;
	file.open(argv[1]);
	while(!file.eof()) {
		getline(file, musicInfo);
		replace(musicInfo.begin(), musicInfo.end(), '_', ' ');
	}

	file.close();
	return 0;
}
