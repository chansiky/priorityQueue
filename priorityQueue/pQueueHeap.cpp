#include "pQueueHeap.h"

//incomplete and buggy, something isn't working right where either the number is not bulbbling up or isn't trickling down properly.

template <typename _T>
pQueueHeap<_T>::pQueueHeap()
{
	count = 0;
	head = NULL;
//	*last = NULL;
}

template <typename _T>
pQueueHeap<_T>::~pQueueHeap()
{
	delete head;
}

template <typename _T>
int pQueueHeap<_T>::size()
{
	return count;
}

template <typename _T>
_T pQueueHeap<_T>::peek() {
	if (count > 0) {
		return head->arrKV[0].first;
	}
	else {
		return NULL;
	}
}

template <typename _T>
void pQueueHeap<_T>::enqueue(std::pair<int, _T> kvPair)
{
	if (isEmpty()) {
		enqueueFirst(kvPair);
	}
	else {
		heapInsert(kvPair);
	}
}

template <typename _T>
bool pQueueHeap<_T>::isEmpty() 
{
	if (head == NULL) {
		return true;
	}
	else return false;
}

template <typename _T>
void pQueueHeap<_T>::enqueueFirst(std::pair<int, _T> kvPair) {
	arrChunk* newChunk = new arrChunk;
	newChunk->next = NULL;
	head = newChunk;
	head->arrKV[0] = kvPair;
	count = 1;
}

template <typename _T>
void pQueueHeap<_T>::heapInsert(std::pair<int, _T> kvPair){
		//findcorrectChunk;
		//insertIntoLastValue;
	arrChunk* temp = getChunk(count);
	//insert kvPair into the correct location
	temp->arrKV[count % ARR_LENGTH] = kvPair;
	count++; //increment count because a value has been added.

	//swap kvPair until it has bubbled up properly
	bubbleUpRec(count-1);
}

//note: index (s:0)
template <typename _T> 
typename pQueueHeap<_T>::arrChunk* pQueueHeap<_T>::getChunk(int index){
	int j = index+1;
	arrChunk* temp = head;
	//Reduce j until it is less than ARR_LENGTH meanwhile traversing through chunks to get to the last chunk
	while (j > ARR_LENGTH) {
		j -= ARR_LENGTH;
		if (temp->next != NULL) {
			temp = temp->next;
		}
		else
		{
			arrChunk* newChunk = new arrChunk;
			newChunk->next = NULL;
			temp->next = newChunk;
			temp = temp->next;
			break;
		}
	}
	return temp;
}

template <typename _T>
void pQueueHeap<_T>::bubbleUpRec(int index) {
	//if arrIndex A is at the top of the heap, exit the recursive function
	if (index <= 0) {
		return;
	}
	//else find the parent.  if the parent is smaller, then bubble up.
	else{
		int indexParent = getParentIndex(index);
		arrChunk* chunkParent = getChunk(indexParent);
		arrChunk* chunkA = getChunk(index);

		int indInChkP = indexParent % ARR_LENGTH;
		int indInChkA = index % ARR_LENGTH;

		if (chunkA->arrKV[index % ARR_LENGTH].first < chunkParent->arrKV[indexParent % ARR_LENGTH].first) {
			swap(chunkA->arrKV[index % ARR_LENGTH],chunkParent->arrKV[indexParent % ARR_LENGTH]);
			bubbleUpRec(indexParent);
		}
		return;
	}
}

//doublechecked,  this is correct
template <typename _T>
int pQueueHeap<_T>::getParentIndex(int index) {
	if (index == 0) {
		return 0;
	}
	else {
		int a = (((index + 1) - ((index + 1) % 2)) / 2) - 1;
//		std::cout << index << " : " << a << std::endl;// i think this is getting me the wrong value;
		return a;
	}
}

template <typename _T>
_T pQueueHeap<_T>::dequeue(){
	//remove first element, 
	_T a = head->arrKV[0].second;
	//get last element:
	arrChunk* tail = getChunk(count - 1); // get the last chunk on the list, theoretically
	swap(head->arrKV[0], tail->arrKV[(count - 1) % ARR_LENGTH]);//swap the last element with the first element;
	//for good measure: set the value to NULL;
	tail->arrKV[(count - 1) % ARR_LENGTH].first = NULL;
	if (tail->arrKV[0].first == NULL) {
		delete tail;
	}	
	count--;
	heapifyRec(0);

	return a;
}

template <typename _T>
_T pQueueHeap<_T>::dequeue(int &priority) {
	//remove first element, 
	if (count <= 0) {
		return NULL;
	}

	priority = head->arrKV[0].first;
	_T a = head->arrKV[0].second;
	//get last element:
	arrChunk* tail = getChunk(count - 1); // get the last chunk on the list, theoretically
	swap(head->arrKV[0], tail->arrKV[(count - 1) % ARR_LENGTH]);//swap the last element with the first element;
	//delete the last element (or rather just set it's value to NULL;
	
	
	//tail->arrKV[(count - 1) % ARR_LENGTH].first = NULL;
	if ((count-1) % ARR_LENGTH == 0) {
		delete tail;
	}
	count--;

	heapifyRec(0); //starting from index 0 the heap will now "trickle down"
	return a;
}

template <typename _T>
void pQueueHeap<_T>::heapifyRec(int index) {
	//childA is the index of the index's child (counting from 0);
	int childA = ((index + 1) * 2) - 1;
	if ((childA) > count) {
		return;//if a > count then 'a' has no children so the recursion stops here.
	}
	else {
		int childB = childA + 1;//double checked the math, it is correct for index s:0;
		//std::cout << index << " - " << childA << ":" << childB << std::endl;
		//check if index is greater than either children.		
		arrChunk* chunkP = getChunk(index);
		arrChunk* chunkA = getChunk(childA);
		arrChunk* chunkB = getChunk(childB);

		int prP = chunkP->arrKV[index % ARR_LENGTH].first;
		int prA = chunkA->arrKV[childA % ARR_LENGTH].first;
		int prB = chunkB->arrKV[childB % ARR_LENGTH].first;
		if (prP >= prA ||// if the priority of the parent is greater than either children...
			prP >= prB) {

			int indLesser = lesserIndex(childA, childB);
			swap(chunkP->arrKV[index % ARR_LENGTH], getChunk(indLesser)->arrKV[indLesser % ARR_LENGTH]);
			heapifyRec(indLesser);
		}
	}
}


template <typename _T>
int pQueueHeap<_T>::lesserIndex(int indA, int indB) {
	arrChunk* chunkA = getChunk(indA);
	arrChunk* chunkB = getChunk(indB);

	if (chunkA->arrKV[indA % ARR_LENGTH].first < chunkB->arrKV[indB % ARR_LENGTH].first){
		return indA;
	}
	else {
		return indB;
	}
}

