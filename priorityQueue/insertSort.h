#pragma once
#include <vector>
#include "swap.h"

template <typename ElumType>
class insertSort
{
public:
	insertSort();
	~insertSort();
};

////sort through insertion,  basically, look at prev number.  if the number is greater, move down.  
template<typename ElumType>
void insertionSort(std::vector<ElumType> &vT);

template<typename _A, typename _B>
void insertionSort(std::vector<std::pair<_A, _B>> &vT);

template<typename ElumType>
void swap(ElumType &_a, ElumType &_b);

#include "insertSort.cpp"