#ifndef PROG2_HEADER // Header Security 'Lock'.
#define PROG2_HEADER

// Preprocessor Directives.
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define SIZE 31	// Used to determine the Maximum size of the string entered.

// Enumeration for Boolean data type.
typedef enum boolean{
	FALSE, TRUE
}Boolean;

// Function initialization. Will determine if string passed in is a palindrome.
Boolean isPalindrome(char str[], int length);

#endif // End of 'Lock'.
