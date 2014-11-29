#include "Simpletron.h" // Inclusion of header.

// A function to display a welcome message to the user and 
// to explain the prupose of the program.
void printMessage()
{
	cout << "*** Welcome to Simpletron! ***" << endl;
	cout << "*** You will need to enter the name of the file    ***" << endl;
	cout << "*** that you would like to read instructions from. ***" << endl;
	cout << "*** These instructions will be completed using the ***" << endl;
	cout << "*** Simpletron Simulation Program. ***" << endl << endl;
	system("pause");
	system("cls");
}

// Constructor function, intialize variables 
Simpletron::Simpletron()
{
	// We are using an integer array and not a pointer to 
	// an integer array we do not make use of allocating 
	// a new integer array.
	for (int i = 0; i < SIZE; i++)
	{
		memory[i] = 0;
	}

	// All other variables are initialized to zero.
	accumulator = 0;
	instructionCounter = 0;
	operationCode = 0;
	operand = 0;
	instructionRegister = 0;
}

// Destructor function.
Simpletron::~Simpletron()
{
	// Nothing to delete, not working with dynamic memory.
}

// Copy Constructor function.
Simpletron::Simpletron(const Simpletron& copy)
{
	// initialize variables for index copy.
	int i = 0;
	
	// Copy evey memory location from one memory array into
	// another at the same location.
	for (i = 0; i <= SIZE; i++)
	{
		memory[i] = copy.memory[i];
	}

	// Copy all other registers.
	accumulator = copy.accumulator;
	instructionCounter = copy.instructionCounter;
	operationCode = copy.operationCode;
	operand = copy.operand;
	instructionRegister = copy.instructionRegister;
}

// Setting memory locations. Again we are not using pointer arrays
// so we cannot make use of the new int[] array assignment.
void Simpletron::setMemory(int newMemory[])
{
	int i = 0;

	for (i = 0; i <= SIZE; i++)
	{
		memory[i] = newMemory[i];
	}
}

// Set accumulator register.
void Simpletron::setAccum(int newAccum)
{
	accumulator = newAccum;
}

// Set counter register.
void Simpletron::setCounter(int newCounter)
{
	instructionCounter = newCounter;
}

// Set operation code.
void Simpletron::setOpCode(int newOpCode)
{
	operationCode = newOpCode;
}

// Set operand.
void Simpletron::setOperand(int newOperand)
{
	operand = newOperand;
}

// Set instruction register.
void Simpletron::setInstReg(int newInstReg)
{
	instructionRegister = newInstReg;
}

// Get memory location.
int Simpletron::getMemory() const
{
	// Instead of returning the entire array, we only return the 
	// instruction held within the memory location.
	return memory[instructionCounter];
}

// Get accumulator register.
int Simpletron::getAccum() const
{
	return accumulator;
}

// Get counter register.
int Simpletron::getCounter() const
{
	return instructionCounter;
}

// Get operation code.
int Simpletron::getOpCode() const
{
	return operationCode;
}

// Get operand.
int Simpletron::getOperand() const
{
	return operand;
}

// Get instruction register.
int Simpletron::getInstReg() const
{
	return instructionRegister;
}

// Load memory function to take file command instructions and 
// place them into Simpletrons memory locations.
void Simpletron::loadMemory()
{
	// Initializtion of variables including file 
	// processing variables.
	ifstream infile;
	string file;
	int index = 0;

	// Ask user for filename to ready instructions from.
	cout << "Please enter the filename for SML instructions (i.e. filename.txt): ";
	cin >> file;

	infile.open(file.c_str(), std::ios::in); // Open the file and set all appropriate flags.

	// We will check if the user has given us a valid file name.
	// if the file name is invalid we ask the user again until an appropriate
	// filename is given.
	if (infile.good())
	{
		// If the file is valid we will read the contents until the end of the file into memory.
		while (!infile.eof())
		{
			infile >> memory[index++];
		}
	}
	// Should the filename not be valid.
	else
	{
		do
		{
			// Indicate to the user that the file name entered was not valid.
			cout << "Please enter a valid filename" << endl;
			system("pause");
			system("cls");

			// Ask for the filename again.
			cout << "Please enter the filename for SML instructions (i.e. filename.txt): ";
			cin >> file;

			infile.open(file.c_str(), std::ios::in); // Open file set all flags.
		} while (!infile.good());
		
		// Since the file is good at this point, we read the file instructions into memory.
		if (infile.good())
		{
			while (!infile.eof())
			{
				infile >> memory[index++];
			}
		}
	}

	system("pause");
	system("cls");
	infile.close(); // Close the infile.
}

// The execute is the main driver of the program. It will execute the commands stored in memory
// and make the appropriate operations based on those commands.
void Simpletron::execute()
{
	// Initialize a temorary hold variable for user input.
	int hold = 0;

	// The do-while loop will continue until HALT or a fatal error has occurred.
	do
	{
		// The main driver of this program will be in the assignment 
		// of operations to the register.
		instructionRegister = memory[instructionCounter]; // Store the memory location to the instruction register.
		operationCode = instructionRegister / 100; // Gather the operation code from that instrcution register.
		operand = instructionRegister % 100; // Gather the number that will be used for use in operations.

		system("cls");
		displayMemory(); // Display the memory to the user.

		// Switch-case statement from operation code.
		switch (operationCode)
		{
			// READ 10
			case READ:
			{
				// Display type of command ask user for the operation
				// to compute.
				cout << endl << "COMMAND READ" << endl;
				cin >> hold;
				memory[operand] = hold; // Place the temp vvariable into the memory location.
				instructionCounter++; // Increment counter to next command in memory.
				system("pause");
				break;
			}
			// WRITE 11
			case WRITE:
			{
				// Display type of command and what is held within the memory location.
				cout << endl << "COMMAND WRITE" << endl;
				cout << showpos << memory[operand] << endl;
				instructionCounter++; // Increment counter to next command in memory.
				system("pause");
				break;
			}
			// LOAD 20
			case LOAD:
			{
				// Load the memory location into our accumulator register.
				cout << endl << "COMMAND LOAD" << endl;
				accumulator = memory[operand];
				instructionCounter++; // Increment counter to next command in memory.
				system("pause");
				break;
			}
			// STORE 21
			case STORE:
			{
				// take the accumulator register and store the contents into the current memory location.
				cout << endl << "COMMAND STORE" << endl;
				memory[operand] = accumulator;
				instructionCounter++; // Increment counter to next command in memory.
				system("pause");
				break;
			}
			// ADD 30
			case ADD:
			{
				// Take the number stored within the memory location and perform the add 
				// operation to the accumulator.
				cout << endl << "COMMAND ADD" << endl;
				accumulator += memory[operand];
				instructionCounter++; // Increment counter to next command in memory.
				system("pause");
				break;
			}
			// SUBTRACT 31
			case SUBTRACT:
			{
				// Take the number stored within the memory location and perform the subtract 
				// operation to the accumulator.
				cout << endl << "COMMAND SUBTRACT" << endl;
				accumulator -= memory[operand];
				instructionCounter++; // Increment counter to next command in memory.
				system("pause");
				break;
			}
			// DIVIDE 32
			case DIVIDE:
			{
				// Take the accumulator and divide it by the memory location. Should the memory location
				// be zero, an error message is displayed instead of performing the operation.
				cout << endl << "COMMAND DIVIDE" << endl;
				if (memory[operand] == 0)
				{
					cout << "Memory location is trying to divide by zero!!!" << endl;
				}
				else
				{
					accumulator /= memory[operand];
				}
				instructionCounter++; // Increment counter to next command in memory.
				system("pause");
				break;
			}
			// MULTIPLY 33
			case MULTIPLY:
			{
				// Take the memory location and multiply and store the results in the accumulator.
				cout << endl << "COMMAND MULTIPLY" << endl;
				accumulator *= memory[operand];
				instructionCounter++; // Increment counter to next command in memory.
				system("pause");
				break;
			}
			// MODULUS 34
			case MODULUS:
			{
				// Take the accumulator and perform the modulus operation with the memory location.
				cout << endl << "COMMAND MODULUS" << endl;
				accumulator %= memory[operand];
				instructionCounter++; // Increment counter to next command in memory.
				system("pause");
				break;
			}
			// EXPONENT 35
			case EXPONENT:
			{
				// Perform the exponent operation with the memory location and the accumulator.
				cout << endl << "COMMAND EXPONENT" << endl;
				hold = (int)pow(accumulator, memory[operand]); // Need to cast the results to integer format.
				accumulator = hold; // Assign temp to accumulator.
				instructionCounter++; // Increment counter to next command in memory.
				system("pause");
				break;
			}
			// BRANCH 40
			case BRANCH:
			{
				// Branch the operation to the appropriate memory location by using the operand
				// and assigning it to the counter register.
				cout << endl << "COMMAND BRANCH" << endl;
				instructionCounter = operand;
				instructionCounter++; // Increment counter to next command in memory.
				break;
			}
			// BRANCHNEG 41
			case BRANCHNEG:
			{
				// Branch operation if accumulator is less than zero.
				cout << endl << "COMMAND BRANCHNEG" << endl;
				if (accumulator < 0)
				{
					instructionCounter = operand; // Assign counter with operand.
				}
				else
				{
					instructionCounter++; // Increment counter to next command in memory.
				}
				break;
			}
			// BRANCHZERO 42
			case BRANCHZERO:
			{
				// Branch operation if the accumulator is equal to zero.
				cout << endl << "COMMAND BRANCHZERO" << endl;
				if (accumulator == 0)
				{
					instructionCounter = operand; // Assign counter with operand.
				}
				else
				{
					instructionCounter++; // Increment counter to next command in memory.
				}
				break;
			}
			// HALT 43
			case HALT:
			{
				// Should the instruction encounter the halt command the program will stop.
				// and subsuqently exit.
				cout << endl << "COMMAND HALT" << endl;
				system("pause");
				exit(0);
				break;
			}
			// Should the program encounter a command that has not been defined then an error will be thrown.
			// and the program will exit.
			default:
			{
				cout << "FATAL ERROR HAS OCCURRED -- SIMPLETRON OPERATION NOT VALID FOR SYSTEM" << endl;
				exit(1);
				break;
			}
		}
	}while (operationCode != HALT); // End of do-while function.
}

// Display function to indicate where the process is currently.
void Simpletron::displayMemory()
{
	// Initialization of index variables.
	int index = 0;

	cout << setfill('0') << internal; // Used to place a zero where the width has been set.

	// Display routine, accumulators and instrcution registers 
	// will display if positive or negative.
	cout << "REGISTERS" << endl;
	cout << "accumulator:\t\t\t" << showpos << setw(5) << accumulator << endl;
	cout << "instructionCounter:\t\t" << noshowpos << setw(5) << instructionCounter << endl;
	cout << "instructionRegister:\t\t" << showpos << setw(5) << instructionRegister << endl;
	cout << "operationCode:\t\t\t" << noshowpos << setw(5) << operationCode << endl;
	cout << "operand:\t\t\t" << setw(5) << operand << endl << endl;
	
	// To show file commands held within memory.
	cout << "FILE COMMANDS:" << endl;

	while (memory[index] != 0)
	{
		cout << memory[index] << " ";
		index++;
	}

	cout << endl << endl;

	// Display column headers for memory locations.
	cout << "MEMORY:" << endl;
	cout << setfill(' ') << setw(2) << ' '; // Set space between each header.

	// Column headers
	for (index = 0; index <= 9; index++)
	{
		cout << ' ' << setw(5) << index;
	}

	cout << endl;

	// Display the memory contents at each location. The memory location when run will only display to 999 locations,
	// so 0 to 999 will be 1000 locations.
	for (index = 0; index < SIZE; index += 10)
	{
		cout << noshowpos << setfill(' ') << setw(2) << index; // Column numbers.
		cout << setfill('0') << showpos; // show whether positive or negative.

		// Memory location display
		for (int j = 0; j <= 9; j++)
		{
			cout << ' ' << setw(5) << memory[index + j];
		}
		cout << endl;
	}
}
