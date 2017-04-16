#pragma once;
#include <random>;
#include <iostream>;
#include <vector>;
#include "randNumListGen.h";
#include "pQueueChunkList.h";
#include "Utilities.h";
#include "quickSort.h";
#include <utility>
#include "insertSort.h";

////TODO:
//redistribute
//size();
//isEmpty();
//sizeof();



void main() {
	int size = 200;

	std::vector<int> vInt = randomizedList(size, 1, 200); //create a random vector of integers
	std::vector<std::string> vStr =	getVStrFromFile("EnglishWords.dat",size); //read "size" number of elements from the file;
	std::vector < std::pair<int,std::string>> vPair = convertTwoVectorsToVectorOfPairs(vInt, vStr);//combine the integers and names into a pair

	insertionSort(vPair); //sort the values in the pairs

	pQueueChunkList<std::string> chunkList;
	
	std::string abc = "abc";
	chunkList.enqueue(200, abc);
	chunkList.enqueue(20, abc);
	chunkList.enqueue(40, std::string("joker"));
	chunkList.enqueue(263, abc);
	chunkList.enqueue(33, abc);
	chunkList.enqueue(16, std::string("joker"));
	chunkList.enqueue(773, abc);
	chunkList.enqueue(234, abc);
	chunkList.enqueue(142, std::string("joker"));
	chunkList.enqueue(33, abc);
	chunkList.enqueue(98, abc);
	chunkList.enqueue(45, std::string("joker"));
	chunkList.enqueue(3, abc);
	chunkList.enqueue(277, abc);
	chunkList.enqueue(430, std::string("joker"));
	chunkList.enqueue(8, abc);
	chunkList.enqueue(74, abc);
	chunkList.enqueue(37, std::string("joker"));
	chunkList.enqueue(200, abc);
	chunkList.enqueue(20, abc);
	chunkList.enqueue(40, std::string("joker"));
	chunkList.enqueue(263, abc);
	chunkList.enqueue(33, abc);
	chunkList.enqueue(16, std::string("joker"));
	chunkList.enqueue(773, abc);
	chunkList.enqueue(234, abc);
	chunkList.enqueue(142, std::string("joker"));
	chunkList.enqueue(33, abc);
	chunkList.enqueue(98, abc);
	chunkList.enqueue(45, std::string("joker"));
	chunkList.enqueue(3, abc);
	chunkList.enqueue(277, abc);
	chunkList.enqueue(430, std::string("joker"));
	chunkList.enqueue(8, abc);
	chunkList.enqueue(74, abc);
	chunkList.enqueue(37, std::string("joker"));
	chunkList.enqueue(200, abc);
	chunkList.enqueue(20, abc);
	chunkList.enqueue(40, std::string("joker"));
	chunkList.enqueue(263, abc);
	chunkList.enqueue(33, abc);
	chunkList.enqueue(16, std::string("joker"));
	chunkList.enqueue(773, abc);
	chunkList.enqueue(234, abc);
	chunkList.enqueue(142, std::string("joker"));
	chunkList.enqueue(33, abc);
	chunkList.enqueue(98, abc);
	chunkList.enqueue(45, std::string("joker"));
	chunkList.enqueue(3, abc);
	chunkList.enqueue(277, abc);
	chunkList.enqueue(430, std::string("joker"));
	chunkList.enqueue(8, abc);
	chunkList.enqueue(74, abc);
	chunkList.enqueue(37, std::string("joker"));
	chunkList.enqueue(200, abc);
	chunkList.enqueue(20, abc);
	chunkList.enqueue(40, std::string("joker"));
	chunkList.enqueue(263, abc);
	chunkList.enqueue(33, abc);
	chunkList.enqueue(16, std::string("joker"));
	chunkList.enqueue(773, abc);
	chunkList.enqueue(234, abc);
	chunkList.enqueue(142, std::string("joker"));
	chunkList.enqueue(33, abc);
	chunkList.enqueue(98, abc);
	chunkList.enqueue(45, std::string("joker"));
	chunkList.enqueue(3, abc);
	chunkList.enqueue(277, abc);
	chunkList.enqueue(430, std::string("joker"));
	chunkList.enqueue(8, abc);
	chunkList.enqueue(74, abc);
	chunkList.enqueue(37, std::string("joker"));
	chunkList.enqueue(200, abc);
	chunkList.enqueue(20, abc);
	chunkList.enqueue(40, std::string("joker"));
	chunkList.enqueue(263, abc);
	chunkList.enqueue(33, abc);
	chunkList.enqueue(16, std::string("joker"));
	chunkList.enqueue(773, abc);
	chunkList.enqueue(234, abc);
	chunkList.enqueue(142, std::string("joker"));
	chunkList.enqueue(33, abc);
	chunkList.enqueue(98, abc);
	chunkList.enqueue(45, std::string("joker"));
	chunkList.enqueue(3, abc);
	chunkList.enqueue(277, abc);
	chunkList.enqueue(430, std::string("joker"));
	chunkList.enqueue(8, abc);
	chunkList.enqueue(74, abc);
	chunkList.enqueue(37, std::string("joker"));
	chunkList.enqueue(200, abc);
	chunkList.enqueue(20, abc);
	chunkList.enqueue(40, std::string("joker"));
	chunkList.enqueue(263, abc);
	chunkList.enqueue(33, abc);
	chunkList.enqueue(16, std::string("joker"));
	chunkList.enqueue(773, abc);
	chunkList.enqueue(234, abc);
	chunkList.enqueue(142, std::string("joker"));
	chunkList.enqueue(33, abc);
	chunkList.enqueue(98, abc);
	chunkList.enqueue(45, std::string("joker"));
	chunkList.enqueue(3, abc);
	chunkList.enqueue(277, abc);
	chunkList.enqueue(430, std::string("joker"));
	chunkList.enqueue(8, abc);
	chunkList.enqueue(74, abc);
	chunkList.enqueue(37, std::string("joker"));

	int priority = 0;
	for (int i = 0; i < 30; i++){
		std::cout << chunkList.dequeue(priority);
		std::cout << priority << std::endl;
	}

	std::cout << "size of queue is:" << chunkList.size() << std::endl;

	std::cout << "   kjhgkjhg   " << std::endl;



	printVector(vInt);
	printVector(vStr);
	pauseConsole();
	printVectorOfPairs(vPair);
	pauseConsole();
}