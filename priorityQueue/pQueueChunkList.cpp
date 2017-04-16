#include "pQueueChunkList.h"

template<typename _T>
pQueueChunkList<_T>::pQueueChunkList() {
	head = NULL;
	tail = NULL;
}
template<typename _T>
pQueueChunkList<_T>::~pQueueChunkList() {
	//todo:
	//delete every chunk that exists in the memory
}
template<typename _T>
void pQueueChunkList<_T>::enqueue(int priority, _T val) {
	if (head == NULL) {//if there are no items in the list
		enqueueFirst(priority, val);//enqueues the head element in the list
	}
	else { //add item to the list
		chunk* chunkA;
		chunkA = findChunk(priority); //find chunk with the current priority
		if (isChunkFull(chunkA)) { //if the chunk is full, 
			chunkA = splitChunk(chunkA, priority); //split the chunk
		}
		//add item to the list
		std::pair<int, _T> stdPair(priority, val);
		insert_TPair(stdPair, chunkA);
		//if this compiles successfully, move this bit of code into the insertType(),,, also change enqueueFirst to reflect this change.
		std::cout << "enqueue success" << priority << std::endl;
	}
	////set the head and tail chunk to the item.
	//if chunklist is full, divide the list into two
	////
}

template<typename _T>
void pQueueChunkList<_T>::enqueueFirst(int priority, _T val) {
	chunk *temp = new chunk;
	std::pair<int, _T> pairA = std::make_pair(priority, val);
	temp->arrKV[0] = pairA;
	++(temp->count);
	temp->prev = NULL;
	temp->next = NULL;
	head = temp;
	tail = temp; 
}
//whew!! returning a sub-struct in a templated class!!!!!  why is typename required again?
template<typename _T>
typename pQueueChunkList<_T>::chunk* pQueueChunkList<_T>::findChunk(int priority) {
	int min;
	min = tail->arrKV[0].first;
	chunk* temp = tail;
	while (min >= priority && temp->prev != NULL) {
		min = temp->arrKV[0].first;
		temp = temp->prev;
	}
	return temp;
}

template<typename _T>
int pQueueChunkList<_T>::indexInChunk(int priority,typename pQueueChunkList<_T>::chunk* chunkA) {
	int i = (chunkA->count - 1);
	while (priority < ((chunkA->arrKV[i]).first) && i >= 0) {
		--i;
	}
	i++; // at the end of the while loop, i is pointing at the index previous to the position it should take.  therefore, we want the index to increment so that it refers to the position that the next _T will go into.
	return i;
	////unfinished, garbage
	/*
	for loop version
	for (int i = (chunkA->count -1); i >= 0; i--) {
	if (chunkA[i].head < priority) {
	}
	}
	*/

	/*
	//////std::array version below//////
	int i = chunkA->count;
	std::array<std::pair<int, _T>::iterator arrIt = chunkA->arrKV[(chunkA->count -1)];
	while (*arrIt.first >= priority && arrIt != chunkA->arrKV.begin()) {
		--arrIt;
		--i;
	}
	*/
}
 
//inserts an item into the array.
template <typename _T>
void pQueueChunkList<_T>::insert_TPair(std::pair<int, _T> _TPair, typename pQueueChunkList<_T>::chunk* a) {
	//find the index of the array in the chunk to place the value into
	int priority = _TPair.first;
	int index = indexInChunk(priority, a);// is the bug from this returning the wrong index or
	//the code in this function going down not far enough?

	// shift down all elements of the array from the index down

	int i = (a->count - 1);
	while (i >= index) {
		a->arrKV[i + 1] = a->arrKV[i];
		--i;
		////why does i turn into -1?
	}

	i++;
	a->arrKV[i] = _TPair;
	++(a->count);
	return;
}

template <typename _T>
bool pQueueChunkList<_T>::isChunkFull(chunk* a) {
	if (a->count >= LIST_LENGTH) {
		return true;
	}
	else return false;
}

template <typename _T>
typename pQueueChunkList<_T>::chunk* pQueueChunkList<_T>::splitChunk(chunk* a, int priority) {
	int index = indexInChunk(priority, a);
	//copy LIST_LENGTH/2 to LIST_LENGTH to a new chunk(chunk2)
		//update chunk 2 count
		//connect chunk2 to chunk1 
	//update chunk 1
		//delete LIST_LENGTH/2 to LIST_LENGTH
		//update chunk 1 count
		//chunk1.prev should be correct;  double check if chunklist connects forwards or backwards
	//connect chunk3(outside) to chunk 2;
	chunk* newChunk = new chunk;
	if (tail == a) {
		tail = newChunk;
	}
	int j = 0; // j exists to account for integer division rounding error; the value of j starts from 1; if correct integer division takes place j = LENGTH_DIV;

	newChunk->next = a->next;
	newChunk->prev = a;
	a->next = newChunk;
////

	for (int i = (LIST_LENGTH-1); i > (LENGTH_DIV-1); i--) {
		newChunk->arrKV[i - LENGTH_DIV] = a->arrKV[i];
		j++;
	}
	newChunk->count = j;
	a->count = LIST_LENGTH - j;

	////to decide which chunk is returned based on the priority;
	if (index <= (LIST_LENGTH-j)-1) { //LIST_LENGTH - j == total length(starting from 1)-number of elements that were removed
		//-1 and <= were used for readability.  So both sides of the operators count  starting from 0;
		return a;
	}
	else
	{
		return newChunk;
	}
}


template <typename _T>
_T pQueueChunkList<_T>::peek() {
	if (head != NULL) {
		return head->arrKV[0].second;
	}
	else {
		std::cout << "list is empty" << std::endl;
		return NULL;
	}
}

template <typename _T>
_T pQueueChunkList<_T>::dequeue(int &priority) {
	if (head != NULL) {
		priority = head->arrKV[0].first;
		_T _Tval = head->arrKV[0].second;
		removeFirstIndex(head);
		return _Tval;
	}
	else {
		std::cout << "list is empty" << std::endl;

	}
}

template <typename _T>
_T pQueueChunkList<_T>::dequeue() {
	if (head != NULL) {
		_T temp = head->arrKV[0].second;
		removeFirstIndex(head);
		return temp;
	}
	else {
		std::cout << "list is empty" << std::endl;
		return NULL;
	}
}



template <typename _T>
void pQueueChunkList<_T>::removeFirstIndex(chunk* a) {
	if ((a->count - 1) <= 0) {
		head = a->next;
		delete a;
	}
	else {
		for (int i = 0; i < a->count; i++) {
			a->arrKV[i] = a->arrKV[i + 1];
		}
	}
	--(a->count);
	return;
}

template<typename _T>
int pQueueChunkList<_T>::size() {
	int size = 0;
	chunk *a = tail;
	while (a) { // this if condition is causing problems.  basically the chunk of head->prev does not equal null.  ?? why not?  //null values not working in 
		size += a->count;
		a = a->prev;
		if (a == NULL) break;
	}
	return size;
}


