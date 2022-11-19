#ifndef MINHEAP_HPP
#define MINHEAP_HPP

#include <iostream>
#include <cstdlib> //malloc/realloc
#include <ctime>
using namespace std;



void insertHeap( int*& heap, int key, int& lastIndex ){
	//assume that array is not large enough to insert new value
	lastIndex++;
	heap = (int*)realloc(heap, sizeof(int) * (lastIndex + 1));
	heap[lastIndex] = key;
	//heapify(heap, lastIndex);
	
	//Now we reheap
	int cIndex = lastIndex; // current index a.k.a. where we are.
	int pIndex; // parent Index
	
	
	/*while(cIndex != 0){
		pIndex = (cIndex - 1) / 2;
		if (heap[cIndex] < heap[pIndex]){
			int tmp = heap[cIndex];
			heap[cIndex] = heap[pIndex];
			heap[pIndex] = tmp;
			pIndex = cIndex; //Update to what was the parent
		}else{
			break;
		}
	}*/
	int size = lastIndex + 1;
	for(int i = 0; i < size; i++){
		int cIndex = size - 1;
		while(cIndex != 0){
			pIndex = (cIndex - 1) / 2;
			
			if (heap[cIndex] < heap[pIndex]){
				int tmp = heap[cIndex];
				heap[cIndex] = heap[pIndex];
				heap[pIndex] = tmp;
				pIndex = cIndex; //Update to what was the parent
			}
			cIndex--;
		}
	}
	for(int i = 0; i <= lastIndex; i++){
		cout << heap[i] << " " ;
	}
	cout<< endl;
}

int deleteHeap(int *& heap, int& lastIndex ){
	if (lastIndex == -1){
		cout << "The heap is empty\n";
		return -1;
	}
	
	int rootValue = heap[0];
	heap [0] = heap[lastIndex];
	if(lastIndex == 0){
		lastIndex--;
		return rootValue;
	}//realloc with size 0 bytes. 
	
	heap = (int*)realloc(heap, sizeof(int) * lastIndex);
	lastIndex--;
	
	int cIndex = 0;
	int smallChild, lChild, rChild;
	
	
	do{
		smallChild = -1;
		lChild = 2*cIndex + 1;
		rChild = 2*cIndex + 2;
		//See if children exist.
		if(lChild <= lastIndex){
			
			if(rChild <= lastIndex){
				if(heap[lChild] < heap[rChild]){
					smallChild = lChild;
				}else{
					smallChild = rChild;
				}
			}else{
				smallChild = lChild;
			}
		
			if(heap[cIndex] < heap[smallChild]){
				int tmp = heap[cIndex];
				heap[cIndex] = heap[smallChild];
				heap[smallChild] = tmp;
				cIndex=smallChild;
			}else{
				break;
			}
		}//if(lChild <= lastIndex){
		/*else{//leaf
			break;
		}*/
	}while(smallChild < lastIndex);
	int size = lastIndex;
	int pIndex;
	for(int i = 0; i < size; i++){
		int cIndex = size - 1;
		while(cIndex != 0){
			pIndex = (cIndex - 1) / 2;
			
			if (heap[cIndex] < heap[pIndex]){
				int tmp = heap[cIndex];
				heap[cIndex] = heap[pIndex];
				heap[pIndex] = tmp;
				pIndex = cIndex; //Update to what was the parent
			}
			cIndex--;
		}
	}
	return rootValue;
}
void heapify(int*& heap, int& size){
	/*for(int i = 0; i < size; i++){
		cout << heap[i] << " " ;
	}*/
	int pIndex;
	int lastIndex = -1;
	int cIndex = size - 1;
	/*for(int i = 0; i <= lastIndex; i++){
		cout << heap[i] << " " ;
	}*/
	for(int i = 0; i < size; i++){
		int cIndex = size - 1;
		while(cIndex != 0){
			pIndex = (cIndex - 1) / 2;
			
			if (heap[cIndex] < heap[pIndex]){
				int tmp = heap[cIndex];
				heap[cIndex] = heap[pIndex];
				heap[pIndex] = tmp;
				pIndex = cIndex; //Update to what was the parent
			}
			cIndex--;
		}
	}
	/*
	int cIndex = 0;
	int smallChild, lChild, rChild;
	
	
	do{
		smallChild = -1;
		lChild = 2*cIndex + 1;
		rChild = 2*cIndex + 2;
		//See if children exist.
		if(lChild <= size){
			
			if(rChild <= size){
				if(heap[lChild] < heap[rChild]){
					smallChild = lChild;
				}else{
					smallChild = rChild;
				}
			}else{
				smallChild = lChild;
			}
		
			if(heap[cIndex] < heap[smallChild]){
				int tmp = heap[cIndex];
				heap[cIndex] = heap[smallChild];
				heap[smallChild] = tmp;
				cIndex=smallChild;
			}else{
				break;
			}
		}//if(lChild <= lastIndex){
		else{//leaf
			break;
		}
	}while(smallChild <= size);*/
	for(int i = 0; i < size; i++){
		cout << heap[i] << " " ;
	}
	return;
}


#endif