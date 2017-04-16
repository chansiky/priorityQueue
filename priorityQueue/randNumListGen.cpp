#include "randNumListGen.h"

randNumListGen::randNumListGen()
{
}

randNumListGen::~randNumListGen()
{
}

std::vector<int> randNumListGen::getNumList() {
	return vInt;
}

std::vector<int> randomizedList(int numValues, int low, int high) {
	srand(time(NULL));
	std::vector<int> vInt;
	int x;
	for (int i = 0; i < numValues; i++) {
		x = rand() % high + low;
		vInt.push_back(x);
	}
	std::cout << numValues << " of random numbers generated." << std::endl;
	return vInt;
}

template <typename _t>
void writeVectToFile(std::vector<_t> vInt, std::string filename) {
	std::ofstream numFile;
	numFile.open(filename);
	for (std::vector<_t>::iterator vIt = vInt.begin(); vIt != vInt.end(); vIt++) {
		numFile << *vIt << "\n";
	}
	numFile.close();
}