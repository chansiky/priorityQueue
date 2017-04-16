#include "quickSort.h"

////quicksort Algorithm
//wrapper for the Quicksort Recursive Function
template<typename _T>
void quickSort(std::vector<_T> &v_T) {
	quickSortFull(v_T, v_T.begin(), v_T.end() - 1);
}

template<typename _T>
void quickSortFull(std::vector<_T> &vT, typename std::vector<_T>::iterator indL, typename std::vector<_T>::iterator indR) {
	int part; //location of partition from vT.begin()
	//1) if the size of the vector < 1, (too short to be sorted), function ends.
	if (vT.size() < 1) {
		return;
	}
	//2)else partition the list
	else { 
		coutQSBounds(vT, indL, indR);////debug checkpoint code
		part = partition(vT, indL, indR);
	}
	std::vector<_T>::iterator p = (vT.begin() + part); //convert integer location of partition to a vector iterator

	//3) recursion calling quickSort on each side of the partition
	if (p >= vT.begin()+1) {
		if (indL < p - 1) {
			std::cout << "p-1" <<std::endl;////debug checkpoint code
			coutQSBounds(vT, indL, p - 1);////debug checkpoint code
			quickSortFull(vT, indL, p - 1);
		}
	}

	if (p < vT.end()-1) {
		if (p + 1 < indR) {
			std::cout << "p+1" <<std::endl;////debug checkpoint code
			coutQSBounds(vT, p + 1, indR);////debug checkpoint code
			quickSortFull(vT, p + 1, indR);
		}
	}
}


////debug checkpoint code
template<typename _T>
void coutQSBounds(std::vector<_T> &vT, typename std::vector<_T>::iterator indL, typename std::vector<_T>::iterator indR) {
	std::cout << "QS: " << std::distance(vT.begin(), indL) << " - " << std::distance(vT.begin(), indR) << std::endl;
	for (std::vector<_T>::iterator it = indL; it < indR; it++) {
		std::cout << *it << ",";
	}
	std::cout << *indR << std::endl;
}


//Divides the list into values less than and values greater than a "pivot" value
template<typename _T>
int partition(std::vector<_T> &vT,typename std::vector<_T>::iterator l,typename std::vector<_T>::iterator r) {
	
	std::vector<_T>::iterator i(l);
	std::vector<_T>::iterator j(r);
	int pivLoc = selectPivot(vT,l,r);

	_T pivot = vT[pivLoc]; 
	std::vector<_T>::iterator p(vT.begin() + pivLoc);
	std::cout << "pivot: " << pivLoc << "=" << pivot << std::endl;////debug checkpoint code

	swap(*p, *l);	//swap the pivot to the front of the list

	while (i <= j) {
		//increment i until it finds a value greater than the pivot
		//decrement j uniil it finds a value less than the pivot
		//swap the two values, this puts the values less than the pivot on the left and those greater on the right.
		//the loop stops once i or j moves past the other.
		while (*i <= pivot && i != vT.end()-1 && i <=j ) { 
			std::cout << "i++: " << std::distance(vT.begin(), i) << std::endl;////debug checkpoint code
			i++;
		}
		while (*j >= pivot && j != vT.begin() && i <=j ) { 
			std::cout << "j--: " << std::distance(vT.begin(), j) << std::endl;////debug checkpoint code
			j--;
		}
		if (i < j) {
			std::cout << "swapping " << std::distance(vT.begin(), i) << ":" << *i << " - " << std::distance(vT.begin(), j) << ":" << *j << std::endl;
			swap(*i, *j);
		}
	}

	//swaps the pivot back to correct position between partitioned elements, returns the index location of the pivot, otherwise returns 0
	if (i >= vT.begin()+1) {
		swap(*(i - 1), *l);
		return std::distance(vT.begin(), i - 1);
	}
	else {
		return 0;
	}

}

////selects the median value from the the list's leftmost, rightmost, and middle elements
template<typename _T>
int selectPivot(std::vector<_T> &vT,typename std::vector<_T>::iterator l,typename std::vector<_T>::iterator r) {
	_T L = *l;
	_T R = *r;
	int lDist = std::distance(vT.begin(), l);
	int rDist = std::distance(vT.begin(), r);
	int mDist = ((rDist - lDist) / 2) + lDist;
	_T M = vT[mDist];

	if (checkIfMid(L, M, R) ){
		return mDist;
	}
	if (checkIfMid(M, L, R)) {
		return lDist;
	}
	if (checkIfMid(L, R, M)) {
		return rDist;
	}
	else return 0;
}

////subroutine for select Pivot: returns true if 'M' is the median value
template<typename _T>
bool checkIfMid(_T L, _T M, _T R) {
	if (L < M && M < R) {
		return true;
	}
	else if (R < M && M < L) {
		return true;
	}
	else if (R == M || M == L) {
		return true;
	}
	return false;
}