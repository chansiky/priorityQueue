#pragma once
#include <utility> //used for "pair" template
#include <iostream> //remove when it is complete


//chunkList should store elements in chunks of sorted arrays.
//
//because the arrays should be presorted, ideally the algorithm "inserts" the newest element into the chunklist.
//
//"enqueing" an item into the list: you will look through each "chunk" head, checking the head number of each array, and then searching within that list for a more accurate number in the sequence.
//because of the way arrays work, the 

//dequeing take item with lowest priority, the head item in the list.
//

template<typename _T>
class pQueueChunkList
{
public:
	static const int LIST_LENGTH = 32; //static since these values must exist outside of the class instance;
	static const int DIVISOR = 2; //DIVISOR is how large a list will get before being split into smaller lists; 
	static const int LENGTH_DIV = LIST_LENGTH / DIVISOR; //2 = 1/2; 3 = 1/3; 4 = 1/4;

	struct chunk {
	public:
		std::pair<int, _T> arrKV[LIST_LENGTH];
		chunk* prev = NULL;
		chunk* next = NULL;////now we have to backtrack and add a next pointer to everything.
		int count = 0;
	};
	struct chunkNull : chunk {


	};
	pQueueChunkList();
	~pQueueChunkList();
	void enqueue(int priority, _T val);
	_T dequeue();
	_T dequeue(int &priority);
	_T peek();
	int size();
	//include a sizeof command that checks the bytes used/memory used/// crucial for this step for you to learn how memory works.
	//redistributes _TPairs into DIVISOR/LIST_LENGTH long chunks;
	void redistribute();
private:
	chunk* head;
	chunk* tail;
	bool isChunkFull(chunk* a);
	chunk* splitChunk(chunk* a, int priority); //should return the tail chunk
	////Subroutines:
	//subroutine for special case: head element
	void enqueueFirst(int priority, _T val);
	//sub for finding which chunk holds the value;
	chunk* findChunk(int priority);
	//sub for finding the index within the chunk where the object should go.  the index is the arr[index] as in count starts from 0;
	int indexInChunk(int priority, chunk* chunkA);
	void insert_TPair(std::pair<int,_T> _TPair, chunk* a);
	void removeFirstIndex(chunk* a);
};

#include "pQueueChunkList.cpp"