#include "FileHeader.h" // Inclusion of header.
#include "TestHeader.h" // Inclusion of the Test Header.

int main(){
	// Initialization of elements.
	int numberElements = 0, order = 0, i = 0, j = 0, cont = 0;
	char entry[MAX][SIZE]; // 2-D array for the number of elements and their corresponding size.
	char *pEntry[MAX];

	// This section calls the two test functions that essentially drive the program.
	// This will test how the information is sorted.
	testSortAscend(); // Test of the Ascended order.
	testSortDescend(); // Test of the Descended order.


	// Welcome the end user to the program. 
	// Then ask the user for how many elements they would like to enter.
	printf("Welcome to the sort string function\n");
	printf("Please enter the number of strings that you would like to enter:\n");
	scanf("%d", &numberElements);

	// Error Handling: If the number of elements the user wants to enter is above the Max of 10
	// Then an error message is generated and closes the program.
	if (numberElements >= MAX){
		printf("\nCan only enter 10 elements into list.The program will close now\n");
		exit(0);
	}

	// Ask the user for the elements they wish to enter. 
	// If the elements entered go over the alloted Size of 30 then the program will crash.
	printf("\nPlease enter the strings you wish to enter followed by the enter key:\n");
	for (i = 0; i < numberElements; i++){
		scanf("%s", entry[i]);
		pEntry[i] = entry[i];
	}

	// Ask the user if they would like to sort the elemnets they entered in either acending or descending order.
	printf("\nWould you like to sort your order in ascending or descending order?\n");
	printf("1.ascending order\n");
	printf("2.descending order\n");
	scanf("%d", &order);

	// Error Handling: If the user places a character that is not 1 or 2 for sort indication
	// Then this error message occurs and asks again for the proper input.
	if (order < 1 || order > 2){
		do{
			printf("Please chose either the number 1 for ascending order or 2 for descending order:\n");
			scanf("%d", &order);
			if (order == 1 || order == 2){
				cont = TRUE;
			}
			else
				cont = FALSE;
		} while (cont == FALSE);
	}

	// Display the order of the elements before the sorting action occurs.
	printf("\nThe order before the sort:\n");
	for (j = 0; j < i; j++){
		printf("%s\n", pEntry[j]);
	}

	// If the users wanted the acending order of elements a check is located here.
	if (order == 1){
		// Function call to sort elements in ascending order.
		sortAscend(pEntry, numberElements);
		// Print the elements after the sort occurs.
		printf("\nThe order after the sort:\n");
		for (j = 0; j < i; j++){
			printf("%s\n", pEntry[j]);
		}
	}
	// If the user wanted the descending order of elements a check is located here.
	else if (order == 2) {
		// Function call to sort elements in descending order.
		sortDescend(pEntry, numberElements);
		// Print the elements after the sort occurs.
		printf("\nThe order after the sort:\n");
		for (j = 0; j < i; j++){
			printf("%s\n", pEntry[j]);
		}
	}

	return 0;
}