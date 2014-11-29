#include "FileHeader.h" // Inclusion of Header.
#include "TestHeader.h" // Inclusion of Test Header.

int main(){

	// Initialize variables.
	char charHold = '\0';
	char str[SIZE];
	int i = 0, end = 0;
	Boolean noEntry = FALSE;

	testPalindrome(); // The test function call. Will place the output indicators to an output file that will not interrupt the users
					  // flow through the program in main.

	// Welcome the user to the program an explain the dynamics of what it will do and the meaning behind a palindrome.
	printf("Welcome to the Palindrome Program\n");
	printf("This program will determine if the string you \nwill enter momentarily is a palindrome\n");
	printf("A palindrome is a sequence of characters that \ncan be read the same way in either direction\n");
	printf("\nPlease enter the string you would like to use to \ndetermine if it is a palindrome: ");

	// Using a while statement as it is a good way in this situation to ask for user input.
	// The string holder will be condensed into a format that we will use to recursively check if it is a palindrome.
	while ((charHold = getchar()) != '\n'){
		if (!isspace(charHold) && !ispunct(charHold)){ // This will remove punctuation and whitespace in the sentence to not have an error occur later when computing a palindrome of the statement.
			str[i++] = tolower(charHold); // Places the sentence into
		}
	}

	// Since the string that will now hold the entry has a defined size, if the next element is not the null termintor then the string will return all elements.
	// A null terminator is placed in the next element to avoid this error.
	str[i] = '\0';

	// This check is to determine if the user entered in anything at all. Although the user input will not end until something has been entered.
	// A check is still needed for entries less than or equal to one.
	if (strlen(str) <= 1){
		do
		{
			i = 0;
			printf("\nPlease enter a string that you would like to determine if it is a palindrome:\n");
			while ((charHold = getchar()) != '\n'){
				if (!isspace(charHold) && !ispunct(charHold)){
					str[i++] = tolower(charHold);
				}
			}
			str[i] = '\0';

			// This section will check to see if the same mistake or error was made when the user was inputting information in again.\
			// The if statement will return false for no or single entries.
			if (strlen(str) <= 1){
				noEntry = FALSE;
			}
			else{
				noEntry = TRUE;
			}
		} while (noEntry == FALSE); // The Do-While function will continue as long as the Boolean entry returns false.
	}

	// Calculate the length of the string itself to be used in the recursive function call
	end = strlen(str) - 1;

	// While calling the function, this if statement also performs a check to determine if the result
	// that is returned from the function is true or false.
	if (isPalindrome(str, end)){
		printf("\n%s is a palindrome\n", str);
	}
	else{
		printf("\n%s is not a palindrome\n", str);
	}

	return 0;
}