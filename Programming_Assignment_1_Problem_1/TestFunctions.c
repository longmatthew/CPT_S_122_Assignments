#include "TestHeader.h" // Inclusion of Test Header

// Function to test the sort ascending function.
void testSortAscend(void){
	// Initialize variables and create file.
	FILE *outfile;
	char *testEntry[] = { "Matt", "Jack", "Amy", "Becca" }; // Array that will be tested to see if the function sorted in ascending order.
	int testElements = 0, i = 0;

	outfile = fopen("TestData_PA1_1_Ascend", "w"); // Create outfile to write to to display results of sort without
												   // disrupting the users flow through the program.

	// Error checking to see if there was memory and a command to create an outfile for this test.
	if (outfile == NULL)
	{
		printf("ERROR FOUND - Could not open outfile\n");
		exit(0);
	}

	testElements = 4; // Hard coded the number of elements for testing purposes.
	sortAscend(testEntry, testElements); // Call of the sort in ascended order function to test the variables initialized in this test function.

	// Display the sorted order and output the format in ascended order.
	fprintf(outfile, "Sort Ascended\n"); 
	for (i = 0; i < testElements; i++){
		fprintf(outfile, "%s\n", testEntry[i]);
	}

	// This part essentially tests to see whether the information was sorted correctly. I chose names but other information could be substituted.
	// If the information is in the correct locations then the test will display that it has passed.
	if (testEntry[0] == "Amy" && testEntry[1] == "Becca" && testEntry[2] == "Jack" && testEntry[3] == "Matt"){
		fprintf(outfile, "Test Passed");
	}
	else{
	// Should the test fail, this sentence will be displayed.
		fprintf(outfile, "Test Failed");
	}

	fclose(outfile); // Close the output file so that no more information from the input buffer stream can be placed.
}

// Function to test the sort Descending function. This test will have some of the same elements and procedures in order
// to carry out the functionality of the test.
void testSortDescend(void){
	// Initialize variables and create file.
	FILE *outfile;
	char *testEntry[] = { "Matt", "Jack", "Amy", "Becca" }; // Array that will be tested to see if the function sorted in ascending order.															
	int testElements = 0, i = 0;							 

	outfile = fopen("TestData_PA1_1_Descend", "w"); // Create outfile to write to to display results of sort without
												    // disrupting the users flow through the program.

	// Error checking to see if there was memory and a command to create an outfile for this test.
	if (outfile == NULL)
	{
		printf("ERROR FOUND - Could not open outfile\n");
		exit(0);
	}

	testElements = 4; // Hard coded the number of elements for testing purposes.
	sortDescend(testEntry, testElements); // Call of the sort in descended order function to test the variables initialized in this test function.

	// Display the output of the sorted order and let the user know that it was in descended order.
	fprintf(outfile, "Sort Descended\n");
	for (i = 0; i < testElements; i++){
		fprintf(outfile, "%s\n", testEntry[i]);
	}

	// The test is reversed, so the strings have been placed in reverse order from the sorted ascend function.
	if (testEntry[0] == "Matt" && testEntry[1] == "Jack" && testEntry[2] == "Becca" && testEntry[3] == "Amy"){
		fprintf(outfile, "Test Passed");
	}
	else{
		fprintf(outfile, "Test Failed");
	}

	fclose(outfile); // Close the output file as noted in the ascended order test.
}
