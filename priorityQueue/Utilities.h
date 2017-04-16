#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

////a file to help test bugs
////in this case to help generate a sorted vector of pairs

template <typename _T>
void printVector(std::vector<_T> v_T);

std::vector<std::string> getVStrFromFile(std::string filename, int vLength);

void pauseConsole();

template <typename _A, typename _B>
std::vector<std::pair <_A, _B>> convertTwoVectorsToVectorOfPairs(std::vector<_A> v_A, std::vector<_B> v_B);

template <typename _A, typename _B>
void printVectorOfPairs(std::vector<std::pair<_A, _B>>);

#include "Utilities.cpp"
