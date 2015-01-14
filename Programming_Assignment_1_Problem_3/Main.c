#include "FileHeader.h" // Inclusion of Header.
#include "TestHeader.h" // Inclusion of Test Header.

int main(){
	// Initialization of variables.
	int menuSelect = 0, key = 0, i = 0;
	char stringHold[SIZE], charHold = '\0', *endHold = '\0';
	Boolean noEntry = FALSE;

	// Inclusion of Test functions here. The output will be placed in seperate folders and will not confuse
	// or prevent the user from completing the program.
	testEncryption();
	testDecryption();

	// Function call to menu select. The program entry and title are found in this call - which was too large and cubersome to fit into the main program.
	// The function itself returns a value that is implimented in a case statement further in main.
	menuSelect = menuOption();

	// Use of a case statement for the menu options was the best option when handling user input.
	switch (menuSelect){

	// First case statement is to call the encrytion function - to encrypt a phrase or sentence.
	case 1:{

		// Ask the user for a phrase or sentence that will be encrypted.
		printf("\nPlease enter the word or phrase you would like to encrypt:\n");

		fflush(stdin); /* This library function call was needed as the library function call of
						  scanf asks the user for an input and then places a new line terminator \n.
						  That new line terminator would skip the while statement to get the phrase or sentence 
						  from the user, ultimitely breaking the program. A 'flush' is performed on the input 
						  buffer to eliminate this error.
					   */
		// Grab the input from the user and place in the place holder string to be manipulated.
		while ((charHold = getchar()) != '\n'){
			stringHold[i++] = charHold;
		}
		// The use of putting a NULL terminator at the last increment is to eliminate the use of the maximum space size which will cause
		// an error when using and displaying the string.
		stringHold[i] = '\0';

		// Ask the user for the key that will be used to shift input left or right.
		printf("\nPlease select the shift key that will shift your encryption:\n");
		scanf("%d", &key);

		// This check in main is to establish that a numerical value needs to be entered in order to compute the shift.
		if (key == 0){
			do{
				printf("Please enter a key in which to encrypt your phrase:\n");
				scanf("%d", &key);
				
				// If the entry is still NULL or zero, then the do-while statement will continue 
				// to execute until a value has been placed.
				if (key == 0){
					noEntry = TRUE;
				}
				else
					noEntry = FALSE;
			} while (noEntry == TRUE); // end of do-while function.
		}

		// Function call to encrypt the user's input and shift according to the key entered.
		// Used a place holder so that I could also test the same function later.
		endHold = encryption(stringHold, key);
		printf("%s", endHold);
		break;
	}

	// The second case statement is to call the decryption function - to decrypt a phrase or sentence.
	// Much of this statement is a reiteration of the first case statement as the checks are identical.
	case 2:{

		// Ask user for input phrase_sentence.
		printf("\nPlease enter the word or phrase you would like to decrypt:\n");

		fflush(stdin); // Again, the same reason as stated in case statement 1 - used to eliminate
					   // the error of scanf returning a '\n' character that will terminate the getchar statement.

		// Grab the input from the user and place in the place holder string to be manipulated.
		while ((charHold = getchar()) != '\n'){
			stringHold[i++] = charHold;
		}
		stringHold[i] = '\0';

		// Ask the user for decryption key.
		printf("\nPlease select the shift key that will shift your decryption:\n");
		scanf("%d", &key);

		// Same check as before in the first case statement. Will ask user for key input if no input is placed.
		if (key == 0){
			do{
				printf("Please enter a key in which to encrypt your phrase:\n");
				scanf("%d", &key);

				if (key == 0){
					noEntry = TRUE;
				}
				else
					noEntry = FALSE;
			} while (noEntry == TRUE);
		}

		// Function call to decrypt user's input and shift according to the key enetered.
		// 
		endHold = decryption(stringHold, key);
		printf("The Decrypted sentence is: %s\n", endHold);
		break;
	}

	// The last case statement will exit the program if the user no longer wishes to continue.
	case 3:{
		printf("\nThank you for using this program\n");
		exit(0);
		break;
	}

	// The default statement is used in case the program encounters undefined behavior and will exit.
	default:{
		// The difference between this statement and the third case statement is that the third case statement 
		// is selected by the user input whereas this default statement is selected by undefined behavior.
		printf("Something went terribly wrong here!");
		exit(0);
		break;
	}
	}

	return 0; // End of Main.
}
