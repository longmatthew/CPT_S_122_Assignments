#include "FileHeader.h" // Inclusion of Header.
#include "TestHeader.h" // Inclusion of Test Header.

// Function to determine if the string passed in is a palindrome.
Boolean isPalindrome(char str[], int length){
	// Initialization of variables. Assuming that the string entered is a Palindrome.
	Boolean status = TRUE;

	// Through the steps of recursion, if the length of the string that is returned is less than or equal to zero
	// then the string has to be a palindrome as the other checks in this function will determine if it is not.
	if (length <= 0){
		return status;
	}

	// This step of the recursion checks to see if the first element in the string and the last element are equal.
	// If they are equal the function call will increment the starting location and decrease the string length.
	// The check will recursively call the function as long as the begin and end elements are equal.
	if (str[0] == str[length]){
		isPalindrome(str + 1, length - 1);
	}
	else{
		// If the first and last element to be checked is not equal to each other, then the function will return false. 
		return status = FALSE;
	}

	return status; // return of status regardless of actions performed.
}