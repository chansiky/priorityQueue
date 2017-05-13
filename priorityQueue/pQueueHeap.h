#pragma once
#include <utility>
#include "swap.h"

template <typename _T> 
class pQueueHeap
{
public:
	pQueueHeap();
	~pQueueHeap();

	static const int ARR_LENGTH = 16;

	struct arrChunk {		
		std::pair<int,_T> arrKV[ARR_LENGTH]; //key-value array;
		arrChunk* next;
	};
	void enqueue(std::pair<int, _T> kvPair);
	_T dequeue();
	_T dequeue(int &priority); //overloading with an integer "priority" so we can send back the information.
	_T peek();                      
	int size();
	bool isEmpty();
private:
	int count; //size is the number of elements in the list (counting from 1);	
	arrChunk* head; //head is the first chunk of Array containing pairs of priority and values
	//functions to support public functions;
	void enqueueFirst(std::pair<int, _T> kvPair);
	void heapInsert(std::pair<int, _T> kvPair);
	arrChunk* getChunk(int index);//getChunk will return the chunk where the index(s:0) is.
	void bubbleUpRec(int index);
	int getParentIndex(int index);
	void heapifyRec(int index);
	int lesserIndex(int intA, int intB);
};


#include "pQueueHeap.cpp"