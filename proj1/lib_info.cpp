/*Makenzie Johnson and Nicholas Wandinata*/
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char **argv) {
	ifstream file;
	file.open(argv[1]);

	file.close();
	return 0;
}
