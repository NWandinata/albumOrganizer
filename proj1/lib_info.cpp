/*Makenzie Johnson and Nicholas Wandinata*/
<<<<<<< HEAD
=======
#include <iostream>
#include <fstream>
#include <strings>
>>>>>>> 817c6c0eca4390342540d23cacb4fcd2e9d658a6
#include "lib_info.h"

using namespace std;

int main(int argc, char **argv) {
	string musicInfo;

	ifstream file;
	file.open(argv[1]);
	while(!file.eof()) {
		getline(file, musicInfo);
	}

	file.close();
	return 0;
}
