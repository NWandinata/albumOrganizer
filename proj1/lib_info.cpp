/*Makenzie Johnson and Nicholas Wandinata*/
#include <iostream>
#include <fstream>
#include <strings>
#include "lib_info.h"

using namespace std;

int main(int argc, char **argv) {
	ifstream file;
	file.open(argv[1]);

	file.close();
	return 0;
}
