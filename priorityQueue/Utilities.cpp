#include "Utilities.h"
#include <utility>

template <typename _T>
void printVector(std::vector<_T> v_T)
{
	for (std::vector<_T>::iterator it = v_T.begin(); it != v_T.end(); it++) {
		std::cout << *it << std::endl;
	}
}

std::vector<std::string> getVStrFromFile(std::string filename, int vLength) {

	std::ifstream fs;
	fs.open(filename);
	std::string str;
	std::vector<std::string> vStr;

	for (int i = 0; i < vLength; i++) {
		std::getline(fs, str);
		vStr.push_back(str);
	}
	return vStr;
}

void pauseConsole() {
	std::cin.get();
	std::cin.clear();
}

template <typename _A, typename _B>
void formPairs(_A a, _B b){
	
}


template <typename _A, typename _B>
std::vector<std::pair <_A,_B>> convertTwoVectorsToVectorOfPairs(std::vector<_A> v_A, std::vector<_B> v_B) {
	int maxSize;
	std::vector<std::pair<_A, _B>> v_Pair;
	if (v_A.size() > v_B.size()) {
		maxSize = v_A.size();
	}
	else maxSize = v_B.size();
	for (int i = 0; i < maxSize; i++) {
		std::pair<_A, _B> A_B(v_A.at(i), v_B.at(i));
		v_Pair.push_back(A_B);
	}
	return v_Pair;
}


template <typename _A, typename _B>
void printVectorOfPairs(std::vector<std::pair<_A, _B>> vPair) {
	for (std::vector<std::pair<_A, _B>>::iterator it = vPair.begin(); it != vPair.end(); it++) {
		std::cout << (*it).first <<  " : " << (*it).second << std::endl;
	}
}