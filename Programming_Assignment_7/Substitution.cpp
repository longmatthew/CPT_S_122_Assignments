#include "Substitution.h" // Inclusion of header.

// Constructor for Substitution Class.
Substitution::Substitution()
{
	encodMessage = '\0';

	//set the count array to default at zero which will allocate memory for this array.
	for (int i = 0; i < 26; i++)
	{
		count[i] = 0;
	}
}

// Destructor for Substitution Class.
Substitution::~Substitution()
{
	// Nothing to deallocate, not using dynamic memory.
}

// Copy constructor for Sub Class.
Substitution::Substitution(Substitution &copy)
{
	encodMessage = copy.encodMessage;

	// We want to copy each memory location (int) from the copy array.
	for (int i = 0; i < 26; i++)
	{
		count[i] = copy.count[i];
	}
}

// Encryption algorithm for Substitution array.
void Substitution::encryption()
{
	// Initialize variables, open outfile to put encryption.
	int rand_key = 0, strlength = 0;
	ofstream outfile("substitution_output.txt", std::ios::out);

	srand((unsigned int)time(NULL)); // Used to initialize time to NULL for random number generation.

	rand_key = rand() % 26 + 1; // randomly generate a number between 1 and 26.

	getMessagefromusr(); // Using inheritance we gather a message from the user using the terminal input stream.

	// Since the for loops in C++ cannot parse through a string without the use of unsigned int types
	// this step is to ensure we are able to use an int.
	strlength = message.length();
	encodMessage.resize(strlength); // We want to allocate enough space in our encoded message, so we can place
									// encoded characters there.

	// For loop to encrypt a message using a substitution cipher.
	for (int i = 0; i <= strlength; i++)
	{
		// If the letter is alphanumeric, we want to encode, otherwise just store.
		if (isalpha(message[i]))
		{
			// Base algorithm, it is similar to the Caesar shift algorithm.
			encodMessage[i] = (toupper(message[i]) - 'A' + rand_key) % 26 + 'A';
		}
		else
		{
			// Store character symbol.
			encodMessage[i] = message[i];
		}
	}

	// Let the user know if the encryption was successful.
	cout << "Encryption Successful" << endl;

	outfile.close();
}

// Decryption Algorithm, using frequency analysis.
void Substitution::decryption()
{
	// Initialization of strlength storage variable.
	int strlength = 0;
	
	strlength = encodMessage.length(); // Store encoded message length.

	// Clear the contents of count, re-initialize count to zero in all points of the array.
	// this will allow the user to use the decrypt option multiple times.
	for (int i = 0; i < 26; i++)
	{
		count[i] = 0;
	}

	// Store the encoded message letter occurrances in a int count array that correspondes
	// to how often the letter occurs in the encoded message.
	for (int i = 0; i <= strlength; i++)
	{
		// Again, we check if the encoded message position is at a letter.
		if (isalpha(encodMessage[i]))
		{
			count[encodMessage[i] - 'A']++; // Letter count.
		}
	}
	
	// Display the encoded message and then show the frequency analysis.
	cout << "The Encoded Message is: " << encodMessage << endl;
	cout << "The Frequency Analysis is: " << endl;

	// Display frequency of letters to the user so that they may make educated guesses
	// based on the occurrance of these letters.
	for (int i = 0; i < 26; i++)      
	{
		cout << "  " << char(i + 'A') << " occurs "
			<< std::setw(5) << count[i] << " times" << endl;
	}

	/*I did not include an algorithm to display the 'Best guess' at determining the original message
	since the interpretation of the anaylsis is best left to the user as no one message could be similar in nature
	depending upon the random shift included in the encoded message.*/
}

// Setters and Getters

// Set the encoded message.
void Substitution::setEncoded(string newEncoded)
{
	encodMessage = newEncoded;
}

// Set the count.
void Substitution::setCount(int newCount[])
{
	for (int i = 0; i < 26; i++)
	{
		count[i] = newCount[i];
	}
}

// Get the encoded message.
string Substitution::getEncoded() const
{
	return encodMessage;
}

// Get the count.
int *Substitution::getCount()
{
	return count;
}
