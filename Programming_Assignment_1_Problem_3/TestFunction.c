#include "TestHeader.h" // Inclusion of Test Header.

// Function to test encryption algorithm.
void testEncryption(void){
	// Initialization of variables.
	FILE *outfile;
	char testStr[] = { "TESTA" }, *pHolder = { '\0' }, *nHolder = { '\0' };
	char strHold[] = "VGUVC"; // For first Hold
	char strNold[] = "RCQRY"; // For second Hold
	int positiveKey = 0, negativeKey = 0;

	outfile = fopen("Test_File_PA1_encryption", "w"); // Create an output file that will display the results of the test.
													  // this prevents interruption from the user while they complete the main program.

	// If the output file was not able to be created - this error message will be displayed to the user.
	if (outfile == NULL){
		printf("ERROR OUTPUT - the output file was not able to be created\n");
	}

	// Hard code of the key used in the encryption process.
	// This is for testing purposes to show the encryption algorithm can handle the key.
	positiveKey = 2;
	negativeKey = -2;

	// Call and assign results from the encryption algorithm to the char pointers to be checked in the test.
	pHolder = encryption(testStr, positiveKey);
	nHolder = encryption(testStr, negativeKey);

	// The check is performed here to determine if the place holder matches the literal string.
	// This check could have been done in a for-loop but I decided to do one large if statement as I did not want to print
	// to the output 5 times.
	if ((pHolder[0] == strHold[0]) && (pHolder[1] == strHold[1]) && (pHolder[2] == strHold[2]) && (pHolder[3] == strHold[3]) && (pHolder[4] == strHold[4])){
		fprintf(outfile, "The Encrytped Phrase: %s\nEncryption passed the positive key.\n", pHolder);
	}
	else {
		// Should the encryption not equal the place holder then this else statement is executed.
		fprintf(outfile, "Encryption did not pass the positive key correctly.\n");
	}

	// Again, the place holder string should equal the literal string and will pass the sentence to the output file that
	// the string ecryption was completed sucessfully.
	if ((nHolder[0] == strNold[0]) && (nHolder[1] == strNold[1]) && (nHolder[2] == strNold[2]) && (nHolder[3] == strNold[3]) && (nHolder[4] == strNold[4])){
		fprintf(outfile, "The Encrytped Phrase: %s\nEncryption passed the negative key.\n", nHolder);
	}
	else{
		// If the strings do not match then this sentence will be pushed to the output.
		fprintf(outfile, "Encryption did not pass the negative key correctly.\n");
	}

	fclose(outfile); // Close the outfile.
}

// This function will test the Decryption algorithm. It is set the exact same way as the encryption algorithm so commenting will be limited.
void testDecryption(void){
	// Initialization of variables.
	FILE *outfile;
	char testStr[] = { "TESTA" }, *pHolder = '\0', *nHolder = '\0';
	char strHold[] = "QBPQX";
	char strNold[] = "UFTUB";
	int positiveKey = 0, negativeKey = 0;

	outfile = fopen("Test_File_PA1_decryption", "w"); // Creating the output file were the results of this test will be placed.

	// Should the output file not be created this message will be displayed.
	if (outfile == NULL){
		printf("ERROR OUTPUT - the output file was not able to be created\n");
	}

	// Hardcoding the key for testing purposes.
	positiveKey = 2;
	negativeKey = -2;

	// Call and assign the decrytpion function to the place holder strings.
	pHolder = decryption(testStr, positiveKey);
	nHolder = decryption(testStr, negativeKey);

	// If all string characters match the decryption literal string then the function has successfully been performed.
	if ((pHolder[0] == strHold[0]) && (pHolder[1] == strHold[1]) && (pHolder[2] == strHold[2]) && (pHolder[3] == strHold[3]) && (pHolder[4] == strHold[4])){
		fprintf(outfile, "The Decrytped Phrase: %s\nDecryption passed the positive key.\n", pHolder);
	}
	else {
		// Otherwise this statement will be passed to the output file.
		fprintf(outfile, "Decryption did not pass the positive key correctly.\n");
	}

	// Again, the exact same as before where the string place holders should match the string lieteral.
	if ((nHolder[0] == strNold[0]) && (nHolder[1] == strNold[1]) && (nHolder[2] == strNold[2]) && (nHolder[3] == strNold[3]) && (nHolder[4] == strNold[4])){
		fprintf(outfile, "The Decrytped Phrase: %s\nDecryption passed the negative key.\n", nHolder);
	}
	else{
		// If not, this message will be displayed.
		fprintf(outfile, "Decryption did not pass the negative key correctly.\n");
	}

	fclose(outfile); // Close the outfile.
}
