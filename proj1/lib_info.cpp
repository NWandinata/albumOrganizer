/*Makenzie Johnson and Nicholas Wandinata*/
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
