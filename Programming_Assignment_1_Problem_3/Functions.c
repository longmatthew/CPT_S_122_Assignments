#include "FileHeader.h" // Inclusion of Header.
#include "TestHeader.h" // Inclusion of Test Header.

// Menu Option function that will ask for user input based on options available.
int menuOption(){
	// Initialization of variables.
	int option = 0;
	Boolean badEntry = TRUE;

	// Welcome the user to the program and explain the fundamentals behind it.
	printf("Welcome to the Caesar Shift Cipher Program!\n");
	printf("A Caesar Shift program is able to encrypt and decrypt phrases or sentences\n");
	printf("and will shift according to the key that you enter\n\n");
	
	// Here is the display of the menu options that will allow the user to navigate through the program.
	printf("Please make a selection from the following options below:\n");
	printf("To encrypt a phrase or sentence press #1 on your keyboard\n");
	printf("To decrypt a phrase or sentence press #2 on your keyboard\n");
	printf("To exit the program press 3 on your keyboard\n");
	scanf("%d", &option);

	// This check determines if the user entered any value over or under 1 through 3.
	if (option < 1 || option > 3){
		do{
			// Let the user know they have entered an incorrect value. Display the menu options again in case they are confused as to
			// why this check appeared.
			printf("\nENTRY IS NOT VALID - Please select from the following menu options: \n");
			printf("To encrypt a phrase or sentence press #1 on your keyboard\n");
			printf("To decrypt a phrase or sentence press #2 on your keyboard\n");
			printf("To exit the program press 3 on your keyboard\n");
			scanf("%d", &option);

			// If the option selected is 1 through 3 then the program continues as it normally would have.
			// Otherwise, the program calls the check again in the do-while function.
			if (option == 1 || option == 2 || option == 3){
				badEntry = FALSE;
			}
			else{
				badEntry = TRUE;
			}
		} while (badEntry == TRUE); // End of do-while function.
	}

	return option; // Returns the option selected by the user.
}

// Encryption function that will shift the user's input based on the shift key.
char *encryption(char str[], int key){
	// Initialization of variables.
	int length = 0, i = 0;
	char *encrypt; // Place holder to display the string after encryption.

	length = strlen(str); // Calculate the string length to be used in for loop to store string information.

	// Collect the necessary memory to fill the encryption data.
	encrypt = (char *)malloc(sizeof(char) *length);

	// Check to see if memory was indeed allocated for the variable.
	if (encrypt == NULL){
		printf("ERROR IN MEMORY ALLOCATION - memory was not able to be allocated for this variable.");
	}

	// If the value of the key entered is above 0 then a shift up (from A <- Z) is implemented.
	if (key > 0){
		for (i = 0; i < length; i++){ // Iterate the length of the string.
			if (isalpha(str[i])){ // The encryption will only be performed on alphabetical characters only.
				encrypt[i] = (toupper(str[i]) - 'A' + key) % 26 + 'A'; /* The encryption changes the user input to all upper case letters
																		  then subtracts it from the value of the capital letter A with
																		  the addition of the key enetered. This calculation is then based
																		  on the modulo of the number of alphabetic characters to remain
																		  within the alphabet. The addition of the last A is to calculate
																		  the final position of the shift.*/
			}
			else{
				encrypt[i] = str[i]; // If the string entered encounters a special or numeric character it simply places
									 // in the same position of the holder.
			}
		}
		encrypt[i] = '\0'; // This is, as mentioned before, a null terminator that will deallocate the rest of the initialized array size.
	}

	// This if statement is to shift down the alphabet (from A-> Z).
	else if (key < 0){
		for (i = 0; i < length; i++){ // Iterate the length of the string.
			if (isalpha(str[i])){
				encrypt[i] = (toupper(str[i]) - 'Z' + key) % 26 + 'Z'; /* Again, the encryption changes the users input to all upper case letters
																		  subtracts it from the letter Z with the addition of the key modulo 26 then
																		  added to Z again to place the final position.*/
			}
			else{
				encrypt[i] = str[i]; // If the string entered encounters a special or numeric character it simply places
									 // in the same position of the holder.
			}
		}
		encrypt[i] = '\0'; // Again, same as before to eliminate unecessary string lengths.
	}

	return encrypt; // Return of data type.
}

// Decryption function that will shift the user's input based on the shift key.
// Many of the same checks and manipulations are used from the Encryption function.
char *decryption(char str[], int key){
	// Initialization of variables.
	int length = 0, i = 0;
	char *decrypt; // Place holder to display the string after encryption.

	length = strlen(str); // Calculate the string length to be used in for loop to store string information.
	
	// Collect the necessary data for the decryption variable.
	decrypt = (char *)malloc(sizeof(char) *length);

	// If the memory was not able to be allocated then the program will crash. This error message will let the 
	// user know what happened.
	if (decrypt == NULL){
		printf("ERROR IN MEMORY ALLOCATION - memory was not able to be allocated for this variable.");
	}

	// Same manipulation as before. Except for the decryption portion.
	if (key > 0){
		for (i = 0; i < length; i++){
			if (isalpha(str[i])){
				decrypt[i] = (toupper(str[i]) + 'Z' - 26 - key) % 26 + 'A' + 1; /* The decryption is calculated from the user input passed in all upper case letters
																			   then is subtracted from the value of A with the addition of all leters in the alphabet
																			   with the addition of the key enetered modulo number of letters in the alphabet plus
																			   the letter A. It will parse through the alphabet based on the key enetered and direction
																			   since it is a decryption the algorithm is a bit more complicated.*/
			}
			else{
				decrypt[i] = str[i]; // If the string entered encounters a special or numeric character it simply places
									 // in the same position of the holder.
			}
		}
		decrypt[i] = '\0'; // Ditto.
	}

	// Same decryption but the arithmetic operation is altered since the key is assumed less than 0.
	else if (key < 0){
		for (i = 0; i < length; i++){
			if (isalpha(str[i])){
				decrypt[i] = (toupper(str[i]) + 'Z' - 26 - key) % 26 + 'A' + 1;
			}
			else{
				decrypt[i] = str[i];
			}
		}
		decrypt[i] = '\0'; // Ditto.
	}

	return decrypt; // Return of the data type.
}
