#include "pQueueChunkList.h"

template<typename _T>
pQueueChunkList<_T>::pQueueChunkList() {
	head = NULL;
	tail = NULL;
}


//untested code below:
template<typename _T>
pQueueChunkList<_T>::~pQueueChunkList() {
	chunk* a = tail;
	chunk* b = NULL;

	while (a != NULL) {
		b = a->prev;
		delete a;
		a = b;
	}
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
	while (priority <= min && temp->prev != NULL) {
		//there used to be a huge sorting bug because the two lines below were switched.  always think about the order of operations.
		temp = temp->prev;
		min = temp->arrKV[0].first;
	}
	return temp;
}


//inserts an item into the array.
template <typename _T>
void pQueueChunkList<_T>::insert_TPair(std::pair<int, _T> _TPair, typename pQueueChunkList<_T>::chunk* a) {
	//find the index of the array in the chunk to place the value into
	int priority = _TPair.first;
	int index = indexInChunk(priority, a);
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


template<typename _T>
int pQueueChunkList<_T>::indexInChunk(int priority,typename pQueueChunkList<_T>::chunk* chunkA) {
	int i = (chunkA->count - 1);//count -1 because count is the number, the size of elements starting from 1.
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

	//rewire... if a == tail(if the chunk we are splitting is the last chunk) then only rewire a->next; else rewire a->next and a->next->prev;
	chunk* newChunk = new chunk;
		newChunk->prev = a;
		newChunk->next = a->next;

	if (tail == a) {
		tail = newChunk;
		a->next = newChunk;
	}
	else {
		a->next->prev = newChunk;
		a->next = newChunk;
	}
	int j = 0; // j exists to account for integer division rounding error; the value of j starts from 1; if correct integer division takes place j = LENGTH_DIV;

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
bool pQueueChunkList<_T>::isFilled() {
	if (head != NULL) {
		return true;
	}
	else {
		return false;
	}
}

template <typename _T>
_T pQueueChunkList<_T>::dequeue(int &priority) {
	if (head != NULL) {
		priority = head->arrKV[0].first;
		_T _Tval = head->arrKV[0].second;
		removeFirstIndex();
		return _Tval;
	}
	else {
		std::cout << "list is empty" << std::endl;
		return NULL;
	}
}

template <typename _T>
_T pQueueChunkList<_T>::dequeue() {
	if (head != NULL) {
		_T temp = head->arrKV[0].second;
		removeFirstIndex();
		return temp;
	}
	else {
		std::cout << "list is empty" << std::endl;
		return NULL;
	}
}
template <typename _T>
void pQueueChunkList<_T>::removeFirstIndex() {
	//if the size of the head chunk is 1 then delete the chunk and make "head" point to the next chunk in the list.
	if ((head->count - 1) <= 0) {
		chunk *a;
		a = head;

		//if this is the last chunk in the list, as in head->next == null, then make head and tail both equal to NULL
		if (head->next == NULL) {
			head = NULL;
			tail = NULL;

			delete a;
		}
		else {
			head = head->next;
			head->prev = NULL;
			delete a;
		}
		return;
	}
	else {
		for (int i = 0; i < head->count; i++) {
			head->arrKV[i] = head->arrKV[i + 1];
		}
	}
	--(head->count);
	return;
}

//problem solved:  issue was that the pointer was not pointing to a NULL address.  this was not because the NULL check wasn't working, rather, the pointers were not pointing to NULL because the rewiring process during split chunk was not written properly.  Essentially, the NULL check should work.  I just happened to think that error in reading an address in memory meant the same thing ax  0x00000...
template<typename _T>
int pQueueChunkList<_T>::size() {
	int size = 0;
	chunk *a = tail;
	while (a != NULL) {
		size += a->count;
		a = a->prev;
		if (a == NULL) break;
	}
	return size;
}

template<typename _T>
bool pQueueChunkList<_T>::nullChunkCheck(chunk *aChunk) {

	if (aChunk != NULL) {
		std::cout << "the size of this chunk is : " << aChunk->count << std::endl;
		return true;
	}
	else if (aChunk ==NULL)
	{
		std::cout << "chunk is null" << std::endl;
		return false;
	}
	return false;
}

template<typename _T>
typename pQueueChunkList<_T>::chunk* pQueueChunkList<_T>::getHead() {
	return head;
}

template<typename _T>
typename pQueueChunkList<_T>::chunk*  pQueueChunkList<_T>::getTail() {
	return tail;
}

template<typename _T>
void pQueueChunkList<_T>::nullPtrCheckCode() {
	nullChunkCheck(head);
	chunk *a;

	a = head->prev;
	nullChunkCheck(a);
	nullChunkCheck(tail);
}