#include "FileHeader.h" // Inclusion of header
#include "TestHeader.h" // Test Header.

// Sort the items in ascending order.
void sortAscend(char *list[], int number){
	// Initialization of variables used in the sort algorithm.
	int i = 0, j = 0;
	char *pTmp;

	// Pass through the elements one at a time to compare them
	// The second for loop will evaluate each individual element with the outer loop.
	for (i = 0; i < number; i++){
		for (j = 0; j < number - (i + 1); j++){
			if (strcmp(list[j], list[j + 1]) > 0){ // Compare the strings located in these two locations, ascending returns a 1.
				// Perform the swap by comparing the first element to the
				// next element in the array if the next element is greater
				// on the comparisson the swap is performed.
				pTmp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = pTmp;
			}
		}
	}
}

// Sort the items in descending order
void sortDescend(char *list[], int number){
	// Initialization of variables used in the sort algorithm
	int i = 0, j = 0;
	char *pTmp;

	// Pass through the elements one at a time to compare them
	// The second for loop will evaluate each individual element with the outer loop
	for (i = 0; i < number; i++){
		for (j = 0; j < number - 1; j++){
			if (strcmp(list[j + 1], list[j]) > 0){ // Compare the strings located in these two locations, ascending returns a 1. 
												   // This time the position of the elements has changed to reverse the order.
				// Perform the swap by comparing the first element to the
				// next element in the array if the next element is greater
				// on the comparisson the swap is performed.
				pTmp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = pTmp;
			}
		}
	}
}