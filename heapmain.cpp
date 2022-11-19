#include "minheap.hpp"
//#include "heap.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){

	//int* heap = (int*)malloc(sizeof(int));
	int lastIndex = -1;
	int value, rootValue;
	int nums;
	int choice;
	cout << "How many numbers: ";
	cin >> nums;
	int* arr = (int*)malloc(sizeof(int)* nums);
	int* heap = (int*)malloc(sizeof(int)* nums);
	srand(time(nullptr));
	for(int i = 0; i < nums; i++){
		heap[i] = rand()%101;
		lastIndex++;
		//cout << endl;
	}
	for(int i = 0; i < nums; i++){
		cout << heap[i] << " " ;
	}
	cout << endl;
	heapify(heap, nums);
	cout <<endl;
	do{
		cout << "1. Insert new value\n";
		cout << "2. Remove root\n";
		cout << "0. Quit\n";
		cin >> choice;
		
		for(int i = 0; i <= lastIndex; i++){
			cout << heap[i] << " ";
		}
		cout<< endl;
		
		if(choice == 1){
			cout << "Enter a value to insert: ";
			cin >> value;
			insertHeap(heap, value, lastIndex);
		}
		if(choice == 2){
			rootValue = deleteHeap(heap, lastIndex);
			cout << "Processed " << rootValue << endl;
		}
		for(int i = 0; i <= lastIndex; i++){
			cout << heap[i] << " ";
		}
		cout<< endl;
	}while(choice != 0);
	
	return 0;
}