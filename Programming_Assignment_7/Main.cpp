// Inclusion of header files
#include "Cipher.h"
#include "Caesar.h"
#include "Substitution.h"

// Main driver of program
int main()
{
	// Initialization of variables.
	int selection = 0;
	bool success = false, exitsuccess = false;

	// We use polymorphism to essentially 'hide' the objects from the user and to make when class
	// the basis for all other classes.
	Cipher *myCCipher = new Caesar; // Using polymorphism from Base Class: Cipher to inherit new Class Caesar Shift.
	Cipher *mySCipher = new Substitution; // Using polymorphism from Base Class: Cipher to inherit new Class substitution Cipher.
	
	// Introduce user, print general use of the program.
	printIntro(); 

	// do-while loop to be executed until user wants to exit program
	do
	{
		printSelection(); // Display selection menu for option to drive the programs essential functions.
		cout << endl << "? ";
		cin >> selection;

		// Error checking if selection was out of range.
		if (selection < 1 || selection > 5)
		{
			do
			{
				cout << "Please enter the correct selection for this program" << endl;
				system("pause");
				system("cls");
				printSelection();
				cin >> selection;

				if (selection > 0 && selection < 7)
				{
					success = true;
				}
			} while (success == false);
		}

		// case statement for selection options.
		switch (selection)
		{
			// To encrypt using a Caesar Shift program.
			case 1:
			{
				system("cls");
				myCCipher->encryption(); // Encryption function call.
				system("pause");
				system("cls");
				break;
			}
			// To decrypt the Caesar Shift program.
			case 2:
			{
				// Error checking to determine if a 'message' was even entered.
				if (myCCipher->getMessage()[0] == '\0')
				{
					system("cls");
					cout << "No encrypted message was entered, cannot perform decryption" << endl;
					system("pause");
					system("cls");
				}
				else
				{
					system("cls");
					myCCipher->decryption(); // Function call for decryption.
					system("pause");
					system("cls");
				}
				break;
			}
			// To encrypt using a substitution cipher.
			case 3:
			{
				system("cls");
				mySCipher->encryption(); // Encryption function call.
				system("pause");
				system("cls");
				break;
			}
			// Decryption of Substitution Cipher using frequency analysis.
			case 4:
			{
				// Again, error checking to determine if the Cipher already has a message to decrypt.
				if (mySCipher->getMessage()[0] == '\0')
				{
					system("cls");
					cout << "No encrypted message was entered, cannot perform decryption" << endl;
					system("pause");
					system("cls");
				}
				else
				{
					system("cls");
					mySCipher->decryption(); // Decryption function call.
					system("pause");
					system("cls");
				}
				break;
			}
			// Case to exit the program.
			case 5:
			{
				system("cls");
				cout << "Thank you for using this program!" << endl;
				exitsuccess = true; // exit success to be assigned true since we want to exit.
				exit(0); // exit program.
				break;
			}
			// Default case if any special character was able to make it past our initial checking.
			default:
			{
				// Display fatal error message, exit program.
				cout << "FATAL ERROR HAS OCCURRED -- A fatal error has occurred during the selection process" << endl;
				cout << "This program will now exit" << endl;
				system("pause");
				exit(1);
				break;
			}
		}
	} while (exitsuccess == false); // End of do-while to exit program.

	// Delete the instants of these objects.
	delete myCCipher;
	delete mySCipher;

	return 0;
}
