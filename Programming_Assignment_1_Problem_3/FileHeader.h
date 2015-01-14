#ifndef HEADER_H // Define Header 'Lock'.
#define HEADER_H

// Include Preprocessor Directives.
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

#define SIZE 1000 // Define maximum string size that can be entered in this program.

// Define boolean enumeration data type that will be useful in checking the programing.
typedef enum boolean{
	FALSE, TRUE
}Boolean;

// Define prototype functions here to be used to drive the program.
int menuOption();
char *encryption(char str[], int key);
char *decryption(char str[], int key);

#endif // End of 'Lock'.
