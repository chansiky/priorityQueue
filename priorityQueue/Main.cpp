#pragma once;
#include <random>
#include <iostream>
#include <vector>
#include "randNumListGen.h"
#include "pQueueChunkList.h"
#include "Utilities.h"
#include <utility>
#include "insertSort.h"
#include "pQueueHeap.h"

////TODO:
//redistribute()  --- redistributes all items in the list so that every chunk is x number of items long.

//sizeof(); ---- sizeof to check how much memory is being used

template <typename _T>
void dequeueList(_T &list);
void main() {
	int size = 200;

	std::vector<int> vInt = randomizedList(size, 1, 200); //create a random vector of integers
	std::vector<std::string> vStr =	getVStrFromFile("EnglishWords.dat",size); //read "size" number of elements from the file;
	std::vector < std::pair<int,std::string>> vPair = convertTwoVectorsToVectorOfPairs(vInt, vStr);//combine the integers and names into a pair

	printVector(vInt);
	printVector(vStr);
	pauseConsole();
	printVectorOfPairs(vPair);

	pQueueHeap < std::string> heapList;

	//pQueueChunkList<std::string> chunkList;
	/*
	std::vector<std::pair<int, std::string>>::iterator vPairIt;
	for (vPairIt = vPair.begin(); vPairIt != vPair.end(); vPairIt++) {
		chunkList.enqueue((*vPairIt).first, (*vPairIt).second);
	}

	int priority = 0;
	for (int i = 0; i < 30; i++){
		std::cout << chunkList.dequeue(priority) << " ";
		std::cout << priority << std::endl;
	}

	std::cout << "size of queue is:" << chunkList.size() << std::endl;

	chunkList.nullPtrCheckCode();

	std::cout << " kjhgkjhg " << std::endl;

	dequeueChunkList(chunkList);

*/

	std::vector<std::pair<int, std::string>>::iterator vPairIt;
	for (vPairIt = vPair.begin(); vPairIt != vPair.end(); vPairIt++) {
		heapList.enqueue((*vPairIt));
	}

	for (int i = 0; i < 30; i++) {
		int priority = 0;
		std::cout << heapList.dequeue(priority) << " : ";
		std::cout << priority << std::endl;
	}

	dequeueList(heapList);
	pauseConsole();
}


template <typename _T>
void dequeueList(_T &list) {
	int a = -1;
	while (true) {

		std::cout << "Press any key to dequeue, or 0 to exit" << std::endl;
		a = std::cin.get();
		if (a == 0) {
			break;
		}

		
		else {
			int priority = 0;
			if (!list.isEmpty()) {
				std::cout << list.dequeue(priority) << " : ";
				std::cout << priority << std::endl;

				std::cout << "size of queue is:" << list.size() << std::endl;
			}
			else {

				std::cout << "queue is empty" << std::endl;
			}


		}
	}
}