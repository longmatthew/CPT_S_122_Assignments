#include "TestHeader.h"

/* This function will test a few place holder statements to see if they are a palindrome.
 the algorithm to make the senetences without punctuation has been placed in main and 
 will not be tested. The reason is to only test the algorithm to see if it will return a plaindrome
 in the simplest case.*/
void testPalindrome(void){
	// Initialization of variables.
	FILE *outfile;
	char test_isPal[] = { "madamimadam" }; // This sentence is a palindrome.
	char test_notPal[] = { "sentence place holder" }; // This sentence is not a palindrome.
	int num_isPal = 0, num_notPal = 0;
	Boolean check_isPal = FALSE, check_notPal = FALSE;

	// Create an output file that will not interrupt the user in main as they continue with the program.
	// This output file will show the test results of the functions called later.
	outfile = fopen("Test_File_PA1_2", "w");

	// Check to see if the output file was able to be created in the environment it was created in.
	if (outfile == NULL){
		printf("ERROR OUTPUT - The output file was not able to be opened!\n");
	}

	// Variables used to calculate the string length of each test string.
	// These values will be passed to the function for use in the recursion aspect.
	num_isPal = strlen(test_isPal) - 1;
	num_notPal = strlen(test_notPal) - 1;

	// Boolean variable place holders that will help in the testing process.
	check_isPal = isPalindrome(test_isPal, num_isPal);
	check_notPal = isPalindrome(test_notPal, num_notPal);

	/* The test here is check the pace holders to determine if the function did return
	 the correct results. The first if statement determines if the sentence that is a 
	 palindrome that was passed to the function isPalindrome is indeed a palindrome.
	 This should return the TRUE if statement.

	 The second if statement determines if the second test sentence that was passed to the function
	 isPalindrome is not a palindrome. This should return FALSE and should execute the beginning part
	 of the second if statement.
	 */

	// First if statment.
	if (check_isPal == TRUE){
		fprintf(outfile, "%s is a palindrome.\n", test_isPal);
	}
	else{
		fprintf(outfile, "Test Case 1 has failed.\n");
	}

	// second if statement.
	if (check_notPal == FALSE){
		fprintf(outfile, "%s is NOT a palindrome.\n", test_notPal);
	}
	else{
		fprintf(outfile, "Test Case 2 has failed.\n");
	}

	fclose(outfile); // Close of output file.
}
