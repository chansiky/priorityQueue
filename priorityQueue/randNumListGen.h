#pragma once
#include <iostream>
#include <random>
#include <time.h>
#include <vector>
#include <fstream>

class randNumListGen
{
public:
	randNumListGen();
	~randNumListGen();
	std::vector<int> getNumList();
private:
	std::vector<int> vInt;

};

std::vector<int> randomizedList(int numValues, int low, int high);

template <typename _t>
void writeVectToFile(std::vector<_t> vInt, std::string filename);

#include "randNumListGen.cpp"