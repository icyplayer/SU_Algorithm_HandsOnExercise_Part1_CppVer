/*
 * mergeSort.cpp
 *
 *  Created on: 2017年3月22日
 *      Author: ipr
 */
// Simple merge sort as review
// Output: int as access order
// Limitation: 17:30
// TODO in-place merge

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

void printArray(const int *a, int len)
{
	cout <<"[" <<endl;
	for(int i = 0; i < len; i++){
		cout <<a[i] <<", ";
	}
	cout <<"]" <<endl;
}


// lenA, lenB >= 1(this limitation maybe needless FIXME), lenA >= lenB
void sortSub(int *a, int lenA, int *b, int lenB)
{
	int *buff = new int[lenA+lenB];
	int i = 0, j = 0, k = 0;

	while(i < lenB){
		if(a[i] <= b[i]){
			buff[k++] = a[i]; // First place a
			buff[k++] = b[i];
		}
		else{ // b > a
			buff[k++] = b[i]; // First place b
			buff[k++] = a[i];
		}
		++i;
	}

	// Now i == lenB
	while(i < lenA){
		buff[k++] = a[i++];
	}

	j = 0;
	while(j < k){
		a[j] = buff[j];
		++j;
	}
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
		// Sub-array sorted after two call of mergeSub

		// Merge and sort whole array
		sortSub(a, lenA, b, lenB);
	}
}

#define BUFF_SIZE  80
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


