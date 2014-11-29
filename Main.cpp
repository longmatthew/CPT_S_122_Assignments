#include "Simpletron.h" // Inclusion of header.

// Main function, will cycle through
int main()
{
	Simpletron myComputer; // Creation of Simpletron Computer Object.

	printMessage(); // Print introduction message.
	myComputer.loadMemory(); // Load memory from file.
	myComputer.execute(); // Execute file commands found within myComputer memory.
	return 0;
}