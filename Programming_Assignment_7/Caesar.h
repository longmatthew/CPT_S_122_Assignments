#ifndef CAESAR_HEADER // Inclusion of Header 'Lock'
#define CAESAR_HEADER

#include "Cipher.h" // inclusion of Cipher header.

// Caesar Shift Class inherting from Cipher Base Class.
class Caesar : public Cipher
{
	public:
		Caesar(); //  Constructor
		~Caesar(); // Destructor
		Caesar(Caesar &copy); // Copy Constructor.

		virtual void encryption(); // Encryption inherited from base class.
		virtual void decryption(); // Decryption inherited from base class.

		// Support functions to gather information from user.
		void askKey();
		void breakKey();
		void breakForce();

		// Getters.
		int getKey() const;
		string getEncodedmessage() const;
		string getDecodedmessage() const;

		// Setters.
		void setKey(int newKey);
		void setEncodedmessage(string newEncodedmessage);
		void setDecodedmessage(string newDecodedmessage);

	private:
		// private data members.
		int key;
		string encodedMessage;
		string decodedMessage;
};

#endif // End of 'Lock'
