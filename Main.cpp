#include "Account.h" // Inclusion of Header File.

// Where main BankAccount function will be completed.
int main()
{
	// Initialization of variables.
	Account BankAccount; // Creation of BankAccount object.
	int selection = 0;
	bool entry = false, exit_prog = false;

	// Welcome the user to the program and let them know what we
	// would like to accomplish when executing.
	cout << "Welcome to the Bank Program!" << endl;
	cout << "\nThis program will allow the user to create,\nmodify, and delete bank accounts" << endl;
	system("pause");
	system("cls");

	// Creation of do-while loop to step through options the user will need to complete.
	do
	{
		// Second do-while loop for error checking in the selection enetered.
		do
		{
			printMenu(); // Function call to print Menu.
			cin >> selection;

			// Error checking process to determine if the right selection was enetered.
			if (selection > 7 || selection < 1)
			{
				cout << "Please selection a valid option" << endl; // Display the appropriate error message.
				system("pause");
				system("cls");
			}
			else
			{
				entry = true; // Should the entry be valid, the loop should end.
			}
		} while (entry == false); // End of first do-while loop.

		// Switch-case statement that drives the program based on the selection enetered.
		switch (selection)
		{
		// Create account function call.
		case 1:
		{
			cout << "---------- Create Account ----------" << endl;
			BankAccount.create_account(); // Object calls the create account function.
			cout << "Account number: " << BankAccount.getAccountNum() << " was created" << endl; // Display account number on what was created.
			system("pause");
			system("cls");
			break;
		}
		// Deposit function call.
		case 2:
		{
			cout << "---------- Deposit ----------" << endl;
			BankAccount.deposit(); // Object calls the deposit function.
			cout << "Current account balance is: " << fixed << setprecision(2) << BankAccount.getBalance() << " for account number " << BankAccount.getAccountNum() << endl; // Display the account balance.
			system("pause");
			system("cls");
			break;
		}
		// Withdraw function call.
		case 3:
		{
			cout << "---------- Withdraw ----------" << endl;
			BankAccount.withdraw(); // Object calls the withdraw function.
			cout << "Current account balance is: " << fixed << setprecision(2) << BankAccount.getBalance() << " for account number " << BankAccount.getAccountNum() << endl; // Display the account balance.
			system("pause");
			system("cls");
			break;
		}
		// Delete function call.
		case 4:
		{
			cout << "---------- Account Deleted ----------" << endl;
			BankAccount.delete_account(); // Object calls the delete account function.
			cout << "Account was deleted" << endl; // Display message that account was deleted.
			system("pause");
			system("cls");
			break;
		}
		// Function call to modify the contents of the class.
		case 5:
		{
			cout << "---------- Modify Account ----------" << endl;
			BankAccount.modify_account(); // Object calls to modify contents of Account
			system("pause");
			system("cls");
			break;
		}
		// Print class Account details.
		case 6:
		{
			// The object will display the contents of the private members.
			cout << "---------- Account Information ----------" << endl;
			cout << "Bank Account Number: " << BankAccount.getAccountNum() << endl;
			cout << "Customer Name: " << BankAccount.getName() << endl;
			cout << "Date Opened: " << BankAccount.getDateOpened() << endl;
			cout << "Account Balance: " << fixed << setprecision(2) << BankAccount.getBalance() << endl;
			system("pause");
			system("cls");
			break;
		}
		// Exit the program.
		case 7:
		{
			// Display message for exiting program.
			cout << "Thank you for using this program!" << endl;
			exit_prog = true;
			exit(0);
			break;
		}
		// Should the selection happen to enter something other than what was given by the previous cases
		// The default will display.
		default:
		{
			cout << "ERROR INVLAID ENTRY -- entry was of invlaid data type." << endl;
			system("cls");
			break;
		}
		}
	} while (exit_prog == false); // End of second do-while loop.

	return 0;
}