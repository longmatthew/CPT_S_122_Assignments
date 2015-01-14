#ifndef SIMPLE_TRON // Header 'Lock'
#define SIMPLE_TRON

// Inclusion of preprocessor directives.
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>

// Inclusion of standard system operators.
using std::cin;
using std::cout;
using std::endl;
using std::showpos;
using std::noshowpos;
using std::setfill;
using std::internal;
using std::setw;
using std::string;
using std::ifstream;
using std::ios;

/* This define packet is to eliminate the need to define every
   instruction found within the file commands which will essentially
   come from the compiler. */

#define SIZE 1000
#define READ 10
#define WRITE 11
#define LOAD 20
#define STORE 21
#define ADD 30
#define SUBTRACT 31
#define DIVIDE 32
#define MULTIPLY 33
#define MODULUS 34
#define EXPONENT 35
#define BRANCH 40
#define BRANCHNEG 41
#define BRANCHZERO 42
#define HALT 43

// Function definition to print a welcome message to the end user.
void printMessage(); 

// Simpletron Class Definition, includes main driver of program.
class Simpletron
{
	// Public class definition available to all users.
	public:
		Simpletron(); // Constructor.
		~Simpletron(); // Destructor.
		Simpletron(const Simpletron& copy); // Copy Constructor.

		// Setters - Mutators.
		void setMemory(int newMemory[]);
		void setAccum(int newAccum);
		void setCounter(int newCounter);
		void setOpCode(int newOpCode);
		void setOperand(int newOperand);
		void setInstReg(int newInstReg);

		// Getters - Accessors.
		int getMemory() const;
		int getAccum() const;
		int getCounter() const;
		int getOpCode() const;
		int getOperand() const;
		int getInstReg() const;

		void loadMemory(); // Will load instructions from the file directly into memory.
		void displayMemory(); // Display or dump of memory command operations, directly.
		void execute(); // Main driver of program, handles all memory computations and operations directly from the
						// file command.

	// Private data members, only those that have access to this class will be able to implement these members.
	private:
		int memory[SIZE], accumulator, 
			instructionCounter, operationCode, 
			operand, instructionRegister;
};

#endif  // End of header 'lock'.
