/*
 * mergeSort.cpp
 *
 *  Created on: 2017年3月22日
 *      Author: ipr
 */

// Simple merge sort as review
// Output: int as access order

// TODO in-place merge

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;


#define BUFF_SIZE  80


void printArray(const int *a, int len)
{
	cout <<"[";
	for(int i = 0; i < len; i++){
		cout <<a[i];
		if(i == len-1){
			cout <<"]" <<endl;
		}
		else{
			cout <<", ";
		}
	}
}


void sortSub(int *a, int lenA, int *b, int lenB)
{
	int *buff = new int[lenA+lenB];
	int i = 0, j = 0, k = 0;

	while(i < lenA && j < lenB){
		if(a[i] <= b[j]){
			buff[k++] = a[i++];
		}
		else{
			buff[k++] = b[j++];
		}
	}

	// Handle rest of a/b, case A and B won't happen at the same time
	while(i < lenA){ // case A: b's elements used up, part of a still undone
		buff[k++] = a[i++];
	}
	while(j < lenB){ // case B: a's elements used up, part of b still undone
		buff[k++] = b[j++];
	}

	i = 0;
	while(i < k){
		a[i] = buff[i];
		++i;
	}

	delete [] buff; // Not in-place
}


void mergeSort(int *array, int len)
{
	if(len == 1 || len == 0){
		return; // Sorting over
	}
	else{
		// Sort
		int lenA = (len+1) / 2;
		int lenB = len - lenA;// Maybe 0. lenA >= lenB
		int *a = array;
		int *b = &array[lenA];// lenA == 1 && lenB == 0 exception will not occurs.

		// Split
		mergeSort(a, lenA);// First half of array
		mergeSort(b, lenB);

		// Sort and merge whole array
		sortSub(a, lenA, b, lenB);
	}
}

int main()
{
	int buff[BUFF_SIZE];
	int idx = 0;

	cout <<"Simple merge sort:\n"
			<<"\tEnter number split by <enter> or <space>\n"
			<<"\tPress <Ctrl+D> to finish" <<endl;
	int data;
	while(cin >>data && idx < BUFF_SIZE){
		buff[idx++] = data;

	}

	cout <<"input count: " <<idx <<endl;
	cout <<"Input array: ";
	printArray(buff, idx);

	mergeSort(buff, idx);

	cout <<"Output array: ";
	printArray(buff, idx);

//	delete [] buff;
	return 0;
}


