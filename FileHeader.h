#ifndef HEADER	// Header Security 'Lock'.
#define HEADER

// Preprocessor directives.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 11	// Maximum number of elements alloted for this program.
#define SIZE 31 // Maximum size of the entries. Cannot exceede this amount .

// Enumerated data type for error checking.
typedef enum boolean{
	FALSE, TRUE
}Boolean;

// Function initialization for sorting character pointer arrays.
void sortAscend(char *list[], int number);
void sortDescend(char *list[], int number);

#endif // End of Security 'Lock'.