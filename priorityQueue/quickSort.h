#pragma once
#include <vector>
#include <random>
#include <time.h>
#include "swap.h"
#include <queue>


///quickSort Wrapper
template<typename _T>
void quickSort(std::vector<_T> &v_T);

///quickSort Algorithm
template<typename _T>
void quickSortFull(std::vector<_T> &vT,typename std::vector<_T>::iterator indL,typename std::vector<_T>::iterator indR);


///quickSort partitioning
template<typename _T>
int partition(std::vector<_T> &vT,typename std::vector<_T>::iterator l, typename std::vector<_T>::iterator r);

///selects a random pivot
int selectPivot(int L, int R);

///selects the median of three pivot
template<typename _T>
int selectPivot(std::vector<_T> &vT,typename std::vector<_T>::iterator l,typename std::vector<_T>::iterator r);

///subroutine for selecting pivot: check for finding out if a pivot is the lesser of the two;
template<typename _T>
bool checkIfMid(_T L, _T M, _T R);

#include "quickSort.cpp"