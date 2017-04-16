#include "insertSort.h"

template<typename _A>
void insertionSort(std::vector<_A> &vT){
	for (std::vector<_A>::iterator itOne = std::next(vT.begin()); itOne != vT.end(); itOne++) {
		std::vector<_A>::reverse_iterator ritOne(itOne + 1);
		std::vector<_A>::reverse_iterator ritOth(ritOne + 1);
		while ((*ritOne < *ritOth) && (ritOth != vT.rend())) {
			swap(*ritOne, *ritOth);
			ritOne = ritOth;
			++ritOth;
			if (ritOth == vT.rend()) {
				break;
			}
		}
	}
};

template<typename _A, typename _B>
void insertionSort(std::vector<std::pair<_A,_B>> &vT) {
	for (std::vector<std::pair<_A, _B>>::iterator itOne = std::next(vT.begin()); itOne != vT.end(); itOne++) {
		std::vector<std::pair<_A, _B>>::reverse_iterator ritOne(itOne + 1);
		std::vector<std::pair<_A, _B>>::reverse_iterator ritOth(ritOne + 1);
		while ((*ritOne < *ritOth) && (ritOth != vT.rend())) {
			swap(*ritOne, *ritOth);
			ritOne = ritOth;
			++ritOth;
			if (ritOth == vT.rend()) {
				break;
			}
		}
	}
};
