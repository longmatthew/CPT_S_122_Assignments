#ifndef ACCOUNT_FILE // Inclusion of header 'lock'
#define ACCOUNT_FILE

// Inclusion of preprocessor directives.
#include <iostream>
#include <iomanip>
#include <string>

// Collection of library object calls.
using std::cin;
using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;
using std::string;

void printMenu(); // Menu print as is not part of Account class.

// Define the Account class that will handle Bank Accounts in Main.
class Account
{
	// Public portion of class.
	public:
		Account(); // Default Constructor.
		Account(double init_balance, int init_account, string init_name, string open_date); // Initialized Constructor.
		Account(Account &copy); // Copy Constructor.
		~Account(); // Destructor.

		// Setters - Mutators.
		void setBalance(double bal);
		void setAccountNum(int acc_num);
		void setName(string name);
		void setDateOpened(string opened);

		// Getters - Accessors.
		double getBalance() const;
		int getAccountNum() const;
		string getName() const;
		string getDateOpened() const;

		// Function definitions.
		void create_account();
		void deposit();
		void withdraw();
		void delete_account();
		void modify_account();

	// Private portion of class
	private:
		// Primary account information that will be held.
		double account_balance; 
		int account_number;
		string customer_name, date_opened;
};

#endif // End of header 'lock'.
