#include "Cipher.h" // Inclusion of header file.

// Print introduction for user.
void printIntro()
{
	cout << "Welcome to the Cipher Program!" << endl;
	cout << "This program will encrypt messages entered by the user" << endl;
	cout << "as well as decrypt messages. " << endl << endl;
	cout << "There are various ways in which this program will allow the user to encrypt the" << endl;
	cout << "messages (Caesar Cipher, Substitution Cipher). Also there are ways in which the" << endl;
	cout << "program will break these ciphers (Key Breaking, Frequency Analysis)." << endl;
	system("pause");
	system("cls");
}

// Print selection options, error checking and selection processing completed in Main program.
void printSelection()
{
	cout << "Please enter a selection below: " << endl;
	cout << "1. To encrypt a message using a Caesar Cipher" << endl;
	cout << "2. To decrypt a message from a Caesar Cipher" << endl;
	cout << "3. To encrypt a message using a Substitution Cipher" << endl;
	cout << "4. To decrypt a Substitution Cipher using Frequency Analysis" << endl;
	cout << "5. To exit the program" << endl;
}

// Constructor for Cipher Class.
Cipher::Cipher()
{
	message = '\0';
}

// Destructor for Cipher Class.
Cipher::~Cipher()
{
	// Not dynamically allocating memory.
}

// Copy constructor for Cipher Class.
Cipher::Cipher(Cipher &copy)
{
	message = copy.message;
}

// Assignment operator overloading.
Cipher &Cipher::operator= (Cipher &copy)
{
	this->message = copy.message;
	return (*this);
}

// Gather information from user, collect data from a file.
void Cipher::getMessagefromfile()
{
	// Initialize file variables.
	ifstream infile;
	string filename;

	// Ask user for file name.
	cout << "Please enter the name of the file that you wish to encrypt: " << endl;
	cout << "? ";
	cin >> filename;

	infile.open(filename.c_str(), std::ios::in); // Open file.

	// Error checking to determine if file name was valid and the file was able to be opened
	// and is ready for use.
	if (infile.good())
	{
		while (!infile.eof())
		{
			infile >> message; // Place contents into message data member.
		}
		system("cls");
	}
	else
	{
		// Error checking process, ask for filename again if previous file name was not valid.
		do
		{
			cout << "Please enter a valid filename to continue: " << endl;
			cout << "? ";
			cin >> filename;

			infile.open(filename.c_str(), std::ios::in); //  Open file again.
		} while (!infile.good());

		// Place contents in data member.
		if (infile.good())
		{
			while (!infile.eof())
			{
				infile >> message;
			}
			system("cls");
		}
	}

	infile.close(); // CLose file.
}

// Ask user for message, gather information from the terminal.
void Cipher::getMessagefromusr()
{
	// Initialize variables.
	string usrMessage;

	// Ask user for message.
	cout << "Please enter the message you would like to encrypt: " << endl;
	cout << "? ";
	cin.ignore();
	getline(cin, usrMessage); // Gather entire string data from terminal without ommiting breaks.

	setMessage(usrMessage); // Set newMessage.
}

// Setters and Getters.

// Set message.
void Cipher::setMessage(string newMessage)
{
	message = newMessage;
}

// Get message.
string Cipher::getMessage() const
{
	return message;
}
