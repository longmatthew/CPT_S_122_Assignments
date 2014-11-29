#ifndef CIPHER_HEADER // Inclusion of header 'lock'
#define CIPHER_HEADER

// Inclusion of preprocessor directives.
#include <iostream>
#include <fstream>
#include <string>

// Standard library inclusions.
using std::ifstream;
using std::ofstream;
using std::ios;
using std::getline;
using std::cin;
using std::cout;
using std::endl;
using std::string;

// Non-primary functions to print text for user.
void printIntro();
void printSelection();

// Cipher Base Class - Will be abstract class for all other classes.
class Cipher
{
	public:
		Cipher(); // Constructor.
		~Cipher(); // Destrcutor.
		Cipher(Cipher &copy); // Copy Constrcutor.

		Cipher &operator= (Cipher &copy); // Assignment operator overloading.

		// Getters.
		void getMessagefromfile();
		void getMessagefromusr();

		// Setters.
		string getMessage() const;
		void setMessage(string newMessage);

		// Pure virtual functions, making this class an abstract class.
		// From this all other classes that inherit from this class will need
		// to have the functions defined.
		virtual void encryption() = 0;
		virtual void decryption() = 0;
	protected:
		// Protected data member, can be accessed by derived classes.
		string message;
};

#endif