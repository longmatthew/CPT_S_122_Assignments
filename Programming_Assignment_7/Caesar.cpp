#include "Caesar.h" // Inclusion of Header.

// Constructor for Caesar Class.
Caesar::Caesar()
{
	key = 0;
	encodedMessage = '\0';
	decodedMessage = '\0';
}

// Destructor for Caesar Class.
Caesar::~Caesar()
{
	// Nothing to deallocate as we are not using dynamic memory.
}

// Copy constructor for Caesar Class.
Caesar::Caesar(Caesar &copy)
{
	key = copy.key;
	encodedMessage = copy.encodedMessage;
}

// Encryption algorithm for Caesar Class.
void Caesar::encryption()
{
	// Initialization of variables.
	int selection = 0, strlength = 0;
	bool success = false;
	ofstream outfile("caesar_output.txt", std::ios::out); // Set outfile to specified name.

	// Ask user to indicate which encryption method they wish to use.
	cout << "Please enter the selection you wish to use to encrypt a message: " << endl;
	cout << "1. Encrypt message from a file" << endl;
	cout << "2. Encrypt message entered into terminal" << endl;
	cout << endl << "? ";
	cin >> selection;

	// Error checking to determine if the selection was out of scope.
	if (selection < 1 || selection > 2)
	{
		// Gather the selection again since it was out of scope.
		do
		{
			cout << "Please enter the correct selection" << endl;
			system("pause");
			system("cls");

			cout << "Please enter the selection you wish to use to encrypt a message: " << endl;
			cout << "1. Encrypt message from a file" << endl;
			cout << "2. Encrypt message entered into terminal" << endl;
			cout << endl << "? ";
			cin >> selection;

			if (selection == 1 || selection == 2)
			{
				success = true;
			}
		} while (success == false);

		// Case Statement for selection process.
		switch (selection)
		{
			// Gather message from file to be encoded.
			case 1:
			{
				system("cls");
				getMessagefromfile(); // Function call to gather message from a file.
				askKey();
				break;
			}
			// Gather message from terminal (user entry).
			case 2:
			{
				system("cls");
				getMessagefromusr(); // Function call to gather message from user.
				askKey();
				break;
			}
			// Incase a character was able to be entered past our initial error checking, this message will display.
			default:
			{
				cout << "FATAL ERROR HAS OCCURRED -- In trying to allocate the encryption message this system has suffered a fatal error" << endl;
				break;
			}
		}
	}
	else
	{
		// This will gather the information from the user in the same manner as in the previous portion of
		// the if statement.
		switch (selection)
		{
			case 1:
			{
				system("cls");
				getMessagefromfile();
				askKey();
				break;
			}
			case 2:
			{
				system("cls");
				getMessagefromusr();
				askKey();
				break;
			}
			default:
			{
				cout << "FATAL ERROR HAS OCCURRED -- In trying to allocate the encryption message this system has suffered a fatal error" << endl;
				break;
			}
		}
	}

	// This is method of storage is used to subvert having to use unisgned int types
	strlength = message.length();
	encodedMessage.resize(strlength); // Create enough space in the encoded message to match the message entered in.

	// Encryption algorithm for Caesar Shift.
	for (int i = 0; i <= strlength; i++)
	{
		// If the message letter is alphanumeric we will perform the shift.
		if (isalpha(message[i]))
		{
			// Perform the encryption by wrapping around the alphabet to find the correct position when 
			// the shift occurs.
			encodedMessage[i] = (toupper(message[i]) - 'A' + key) % 26 + 'A';
		}
		else
		{
			// Store all other character symbols.
			encodedMessage[i] = message[i];
		}
	}

	// Place the results in the outfile, let the user know the encryption process worked.
	outfile << encodedMessage << endl;
	cout << endl << "Encryption Successful" << endl;

	outfile.close();
}

// Decryption of Caesar Shift.
void Caesar::decryption()
{
	// Initialization of variables.
	int selection = 0;
	bool success = false;

	// Ask the user for the preferred decryption method.
	cout << "Please select the decryption method preferred:" << endl;
	cout << "1. Decrypt using a key stored from encryption" << endl;
	cout << "2. Decrypt by 'guessing' at the key stored from encryption" << endl;
	cout << endl << "? ";
	cin >> selection;

	// Error checking to determine if selection was out of scope.
	if (selection < 1 || selection > 2)
	{
		do
		{
			cout << "Please enter the correct selection to decrypt a message" << endl;
			cout << "? ";
			cin >> selection;

			if (selection > 0 && selection < 3)
			{
				success = true;
			}
		} while (success == false);
	}

	// Case statement to determine the method the user would like to use
	// to decrypt the encrypted message.
	switch (selection)
	{
		// Decrypt using the key originally entered by the user.
		case 1:
		{
			system("cls");
			breakKey();
			break;
		}
		// Decrypt by using a guessing method, will ask the user for the key for the correct
		// decryption method.
		case 2:
		{
			system("cls");
			breakForce();
			break;
		}
		// Default message incase our previous error checking allowed an invalid character symbol to be enetered.
		default:
		{
			cout << "FATAL ERROR HAS OCCURRED -- In trying to decrypt the message this system has suffered a fatal error" << endl;
			break;
		}
	}
}

// Function to ask the user for a key to shift a message.
void Caesar::askKey()
{
	// Initialize variables.
	int keyHold = 0;
	bool success = false;

	// Ask user for the key to encrypt messages.
	cout << endl << "Please enter key to use in the text encryption (from 1 - 26): " << endl;
	cout << "? ";
	cin >> keyHold;

	// Error check to determine if key went out of scope.
	if (keyHold < 1 || keyHold > 25)
	{
		do
		{
			cout << "Please enter a valid key identifier from 1 to 26: " << endl;
			cout << "? ";
			cin >> keyHold;

			if (keyHold > 0 && keyHold < 27)
			{
				success = true;
			}
		} while (success == false);
	}

	key = keyHold; // Place the key holder in the key data member.
}

// To allow the user to decrypt using the key already stored in the data member Caesar class.
void Caesar::breakKey()
{
	// Initialize variables.
	int strlength = 0;

	// Again, to avoid using the unsigned int data types.
	strlength = encodedMessage.length();
	decodedMessage.resize(strlength);

	// Decryption Alogrithm.
	for (int i = 0; i <= strlength; i++)
	{
		// Again, if encoded message is a letter in the alphabet, we will perform the decryption.
		if (isalpha(encodedMessage[i]))
		{
			decodedMessage[i] = 'A' + (((encodedMessage[i] - 'A') + key) % 26);
		}
		else
		{
			// All other character symbols are stored.
			decodedMessage[i] = encodedMessage[i];
		}
	}
	// Display decoded message to user - which should be the exact same as the message entered in.
	cout << "Decrypted Message: " << decodedMessage << endl;
}

// To allow the user to try and decrypt the encryption by 'guessing' at the key.
void Caesar::breakForce()
{

	int strlength = 0, keyHold = 0;

	strlength = encodedMessage.length();
	decodedMessage.resize(strlength);

	// Do-while loop to continue to ask the user for a key until the encryption is 'broken'.
	do
	{
		system("cls");
		cout << "Please enter the key you wish to use to decrypt the message: " << endl;
		cout << "? ";
		cin >> keyHold;

		// Similar decryption alogrithm.
		for (int i = 0; i <= strlength; i++)
		{
			if (isalpha(encodedMessage[i]))
			{
				decodedMessage[i] = 'A' + (((encodedMessage[i] - 'A') + keyHold) % 26);
			}
			else
			{
				decodedMessage[i] = encodedMessage[i];
			}
		}
		// Display decrypted message.
		cout << decodedMessage << endl;

		// If the key has not been found, display message.
		if (keyHold != key)
		{
			cout << endl << "Decryption Unsuccessful, try using a different key" << endl;
		}
		system("pause");
	} while (keyHold != key); // End of do-while loop.

	// Display what key was successful in 'breaking' the encryption.
	cout << endl << "Decryption Successful with key: " << keyHold << endl;
}

// Setters and Getters.

// Get key member.
int Caesar::getKey() const
{
	return key;
}

// Get encoded message.
string Caesar::getEncodedmessage() const
{
	return encodedMessage;
}

// Get decoded message.
string Caesar::getDecodedmessage() const
{
	return decodedMessage;
}

// Set key member.
void Caesar::setKey(int newKey)
{
	key = newKey;
}

// Set encoded message.
void Caesar::setEncodedmessage(string newEncodedmessage)
{
	encodedMessage = newEncodedmessage;
}

// Set decoded message.
void Caesar::setDecodedmessage(string newDecodedmessage)
{
	decodedMessage = newDecodedmessage;
}
