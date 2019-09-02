/* This program creates an array filled with randomly generated numbers, then sorts them using the merge sort algorithm. The algorithm basically divides the array
into smaller arrays that are easier to sort, then puts them back together (hence the term "divide and conquer"). The array is stored in a header file to make it
modular in case I need it to sort anything else in the future. 
-John DeHart
9/2/2019
Algorithms */

#include <iostream>
#include <time.h>
#include "mergeSort.h"	   //includes the merge sort algorithm from header file

using namespace std;

int main() {
	
	srand (time(NULL));		//gets "random" number from the system's time
	
	int arr[14], temp = 0, i = 0, length = 14;	//array for sorting, a temp value for the random number genorator, i for counting, length of array
	
	for (i = 0; i <= 14; i++) {
		temp = rand() % 100;	  //for loop takes a random number from the system, takes the remainder of that number
		arr[i] = temp;			//then fills the array with these numbers.
	}
	
	for (i = 0; i <=14; i++) {
		cout << arr[i];			//This prints the array so the user can see it before it's sorted.
		if (i <= 13) {	
			cout << ", ";		//prints a comma for all numbers except the last
		}
	}

	mergeSort (arr, 0, length);	  	  //calling the merge sort algorithm from the header file
	
	cout << "\n\n" << "sorted array: " << endl;
	
	for (i = 0; i <= 14; i++) {
		cout << arr[i];
		if (i <= 13) {			//prints the array again, now that it's sorted.
			cout << ", ";
		}
	}
	
	return 0;
	
}

