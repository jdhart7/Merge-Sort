/* Merge sort algorithm for algorithms. recursively cuts the array into parts, orders them, then puts them back together. 
John DeHart
September 2, 2019
*/

#ifndef __MERGE_SORT
#define __MERGE_SORT
#endif



int merge (int arr[], int low, int mid, int length) {		//this function is for sorting and merging sections of the array
	int *temp = new int[length - low + 1];		//temporary array for putting parts into 
	int i = low, j = mid + 1, k = 0;	//low keeps track of the where the "first element is in the new array, mid does pretty much the same thing
	
	while (i <= mid && j <= length) {
		if (arr[i] <= arr[j]) {
			temp[k++] = arr[i++];		//if the numbers are switched, put one in the temp array
		}
		else
			temp[k++] = arr[j++];		//else, put the already sorted number in the array
	}
	
	while (i <= mid) {
		temp[k++] = arr[i++];			//putting the left-hand part of the array in the temp array
	}
	
	while(j <= length) {
		temp[k++] = arr[j++];			//putting the right-hand part in the temp array
	}
	
	for (k = 0, i = low; i <= length; ++i, ++k) {		//copies the merged temporary array into the original array
		arr[i] = temp[k];
	}
	
	delete []temp;			//deletes the temp array to save memory
	
}





int mergeSort (int arr[], int low, int length) {		//this function cuts the array into pieces for the next function
	
	int mid, i = 0;
	if (low < length) {			//while the first number is less than the larges number
		mid = (low + length) / 2;		//find the midpoint by taking the average of the max and min
		mergeSort (arr, low, mid);	  	//recursively find the middle of the array until the array has been broken into small enough parts
		mergeSort (arr, mid + 1, length);	//do the same thing with the second half of the array
		merge (arr, low, mid, length);		//merge the parts of the array in the above
	}

}

