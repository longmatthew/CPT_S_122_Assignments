#ifndef SUBSTITUTION_HEADER // Header 'Lock'.
#define SUBSTITUTION_HEADER

#include "Cipher.h" // Inclusion of Cipher header for inheritance.

// Inclusion of preprocessor directives.
#include <stdlib.h>
#include <time.h>
#include <iomanip>

// Inclusion of standard library keywords.
using std::rand;

// Substitution Class collection, inheritance from Cipher Class.
class Substitution : public Cipher
{
	public:
		Substitution(); // Constructor
		~Substitution(); // Destructor.
		Substitution(Substitution &copy); // Copy Constructor.

		virtual void encryption(); // Encryption inherited from base class.
		virtual void decryption(); // Decryption inherited from base class.
		
		// Setters.
		void setEncoded(string newEncoded);
		void setCount(int newCount[]);

		// Getters.
		string getEncoded() const;
		int *getCount();

	private:
		// Private data members.
		string encodMessage;
		int count[25];
};

#endif // End of lock.
