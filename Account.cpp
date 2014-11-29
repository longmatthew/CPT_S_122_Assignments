#include "Account.h" // Inclusion of header.

// Print menu function that will be caled in Main until the user exits.
void printMenu()
{
	cout << "Please enter one of the selections below:" << endl;
	cout << "1. Create a new account" << endl;
	cout << "2. Make a deposit to an existing account" << endl;
	cout << "3. Make a withdraw from an existing account" << endl;
	cout << "4. Delete an account" << endl;
	cout << "5. Modify an existing account" << endl;
	cout << "6. Display the current account" << endl;
	cout << "7. Exit the program" << endl;
}

// Default Constructor for class Account
Account::Account()
{
	// Initialize private members to given values.
	account_balance = 0.0;
	account_number = 0;
	customer_name = '\0';
	date_opened = '\0';
}

// Initialized Constructor for class Account.
Account::Account(double init_balance, int init_account, string init_name, string open_date)
{
	// Check if initial balance that is passed to the constructor is above zero.
	if (init_balance < 0)
	{
		account_balance = 0; // set account to zero
		// Display appropriate error message.
		cout << "The initial balance cannot be less than zero.\n Balance has been initalized to zero instead" << endl;
	}
	// Should the balance be above zero.
	else{
		account_balance = init_balance;
	}

	// Assign values to constructors private members.
	account_number = init_account;
	customer_name = init_name;
	date_opened = open_date;
}

// Copy Constructor - Not used for this program.
Account::Account(Account &copy)
{
	// Not used as we do not need to copy the objects contents to another object.
}

// Destructor - Not used for this program.
Account::~Account()
{
	// Not used as we are not using dynamic memory allocation.
}

// Setters - set Account Balance.
void Account::setBalance(double bal)
{
	account_balance = bal;
}

// Set Account Number.
void Account::setAccountNum(int acc_num)
{
	account_number = acc_num;
}

// Set Customer Name.
void Account::setName(string name)
{
	customer_name = name;
}

// Set Date Account was Opened.
void Account::setDateOpened(string opened)
{
	date_opened = opened;
}

// Getters - get Account Balance from private member.
double Account::getBalance() const
{
	return account_balance;
}

// Get Account Number from private member.
int Account::getAccountNum() const
{
	return account_number;
}

// Get Customer Name from private member.
string Account::getName() const
{
	return customer_name;
}

// Get Date the Account was Opened from private member.
string Account::getDateOpened() const
{
	return date_opened;
}

// Member function to create a new account.
void Account::create_account()
{
	// Initialize place holder variables.
	double init_balance = 0.0;
	int init_account = 0;
	string name, date;

	// Ask the user a set of questions to enter data. Account Number, Customer Name, 
	// Date Account was Opened, and Initial Account Balance.
	cout << "Please enter the new account number for this customer:" << endl;
	cin >> init_account;
	cout << "Please enter the name of the customer:" << endl;
	cin.ignore();
	getline(cin, name);
	cout << "Please enter the date the account is opened:" << endl;
	getline(cin, date);
	cout << "Please enter the customer's initial deposit:" << endl;
	cin >> init_balance;

	// Assign private members the data that was enetered. Setters could have been
	// used here but it seems redundant.
	customer_name = name;
	account_number = init_account;
	account_balance = init_balance;
	date_opened = date;
}

// Member function to deposit money into the customer's account.
void Account::deposit()
{
	// Initialize variables.
	double deposit_amount = 0.0;

	// Ask user for deposit amount.
	cout << "Please enter the amount you would like to deposit:" << endl;
	cin >> deposit_amount;

	// Error check to determine if the deposit amount was less than zero.
	if (deposit_amount < 0)
	{
		cout << "Please enter the correct deposit amount" << endl; // The appropriate message will be displayed.
	}
	else
	{
		account_balance += deposit_amount; // Add deposit amount to the overall account balance.
	}
}

// Mmeber function to withdraw money from the customer's account.
void Account::withdraw()
{
	// Initialize variables.
	double withdraw_amount = 0.0;
	double balance = getBalance();// Get the current balance without accessing private members.

	// Ask user for the withdraw amount they would like to take out of their account balance.
	cout << "Please enter the amount you would like to withdraw:" << endl;
	cin >> withdraw_amount;

	// Error check to determine if the asking withdraw amount is positive.
	if (withdraw_amount < 0)
	{
		cout << "Withdraw amount must be greater than zero:" << endl; // Display the appropriate message.
	}
	else 
	{
		// Second error check to determine if the amount being withdrawn goes over the amount held within the customers account.
		balance -= withdraw_amount; // Place holder to perform operation on.
		if (balance < 0)
		{
			cout << "Unable to withdraw from Account " << account_number << " balance is less than zero after withdraw." << endl; // Display the appropriate message.
		}
		else
		{
			// Should all checks pass, complete the withdraw.
			account_balance -= withdraw_amount;
		}
	}
}

// Member function to delete account.
void Account::delete_account()
{
	// Set all values to their initial constructor.
	// I could not come up with a better way to implement this delete function
	// as we are not using dynamic memory.
	account_balance = 0.0;
	account_number = 0;
	customer_name = '\0';
	date_opened = '\0';
}

// Member function to modify certain elements within the class Account.
void Account::modify_account()
{
	// Initialize variables.
	int selection = 0, init_account = 0;;
	bool entry = false;
	double init_balance = 0.0;
	string name, date;

	// Created a do-while loop because the user could eneter the wrong selection at this screen.
	do
	{
		// Menu options to determine which data member the user would like to modify.
		cout << "Please select what you would like to modify:" << endl;
		cout << "1. Account Number" << endl;
		cout << "2. Customer Name" << endl;
		cout << "3. Date Account was Opened" << endl;
		cout << "4. Initial Deposit" << endl;
		cin >> selection;

		// Error check to determine if the user selected the correct option.
		if (selection > 4 || selection < 1)
		{
			cout << "Please selection a valid option" << endl;
			system("pause");
			system("cls");
		}
		else
		{
			entry = true; // Should the selection be true, the loop will exit.
		}
	} while (entry == false); // End of do-while loop.

	// Switch-case statement, similar to what is offered in creating a new account.
	switch (selection)
	{
	case 1:
	{
		// Ask user for new account number.
		cout << "Please enter the new account number for this customer:" << endl;
		cin >> init_account;
		cout << "Account Number has changed" << endl;
		account_number = init_account;
		break;
	}
	case 2:
	{
		// Ask user for new customer name.
		cout << "Please enter the name of the customer:" << endl;
		cin.ignore();
		getline(cin, name);
		cout << "Customer Name has changed" << endl;
		customer_name = name;
		break;
	}
	case 3:
	{
		// Ask user for the new account opened date.
		cout << "Please enter the date the account is opened:" << endl;
		cin.ignore();
		getline(cin, date);
		cout << "Account Open Date has changed" << endl;
		date_opened = date;
		break;
	}
	case 4:
	{ 
		// Ask user for the new initial deposit.
		cout << "Please enter the customer's initial deposit:" << endl;
		cin >> init_balance;
		cout << "Account Balance has changed" << endl;
		account_balance = init_balance;
		break;
	}
	// Default response if any other option was selected by error.
	default:
	{
		cout << "ERROR ENTRY -- invalid entry accepted" << endl;
		system("cls");
		break;
	}
	}
}