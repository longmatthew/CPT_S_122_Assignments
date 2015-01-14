#include "FileHeader.h" // Inclusion of Header File.

// Priority function indicates the priority of the operator in the char Stack.
// The priority is for the sole purpose of determining when to pop the stack.
int priority(char infixchar){

	// Switch statement is used to characterize the infix operator.
	switch (infixchar){
		// A ( has the lowest value thus when encountering the right parenthesis'
		// it will indicate that all the contents within will be popped.
	case ('(') : {
					return 0;
					break;
	}
		// Addition and subtraction take the next precedence.
	case ('+') : {
	case ('-') : {
					return 1;
					break;
	}
	}
		// Lastly- Multiplication, Division, and Modulous take the higher precedence.
	case ('*') : {
	case ('/') : {
	case ('%') : {
					return 2;
					break;
	}
	}
	}
		//The default expression will be the highest precedence as the lowest ones have been accounted for.
	default:{
				return 3;
				break;
	}
	}
}

// Boolean call function that determines if the character is indeed an operator.
Boolean isOperator(char op){

	// Should the character in question be an operator the statement will return true.
	if (op == '*' || op == '+' || op == '-' || op == '/' || op == '%'){
		return TRUE;
	}
	else{
		// Anything other than an operator will return false.
		return FALSE;
	}
}

// The Operations function computes the postfix operation from the integer call stack.
int Operations(char oper, int op1, int op2){

	// Using a switch statement to determine what operation to performed based on the operator used.
	switch (oper){
	case('+') : {
		return op1 + op2; // add the two integers.
		break;
	}
	case('-') : {
		return op1 - op2; // subtract the two integers.
		break;
	}
	case('*') : {
		return op1 * op2; // multiply the two integers.
		break;
	}
	case('/') : {
		return (op1 / op2); // divide the two integers.
		break;
	}
	case('%') : {
		return (op1 % op2); // mod the two integers
		break;
	}
	default:
		return 0; // should no operations be present the default will return 0 to indicate something went wrong.
		break;
	}
}

// A helper funtion to create the data necessary for the character stack call.
StackNodechar *makeNodechar(char newData){

	// Initialize variables - creating a node.
	StackNodechar *pMem = NULL;

	pMem = (StackNodechar *)malloc(sizeof(StackNodechar)); // Allocating space for the new node within the stack.

	// Should the new node not be equal to null - meaning memory was allocated
	// then the data should be passed in.
	if (pMem != NULL)
	{
		pMem->data = newData; // assign data from main to the new node.
		pMem->pNext = NULL; // assign the next placement of the node to null to essentially add more data later.
	}
	else{
		// Although this step is not necessary, I will display a message to the user in case new memory was
		// unable to be allocated properly.
		printf("UNABLE TO ALLOCATE MEMORY -- Program was unable to allocate enough memory\n");
	}

	return pMem; // return the new node in the stack.
}

// This make node statement is for the integer stack.
// It will essentially use the same types of checks as the char makeNode function.
StackNodeint *makeNodeint(int newData){

	StackNodeint *pMem = NULL;

	pMem = (StackNodeint *)malloc(sizeof(StackNodeint));

	if (pMem != NULL)
	{
		pMem->data = newData;
		pMem->pNext = NULL;
	}
	else{
		printf("UNABLE TO ALLOCATE MEMORY -- Program was unable to allocate enough memory\n");
	}

	return pMem;
}

// Push of the char node onto the Stack.
void pushchar(StackNodechar **pStack, char infixchar){

	StackNodechar *pNew = NULL; // an area to create a node to be assigned to the stack.

	pNew = makeNodechar(infixchar); // using our helper function we allocate memory for the new node.

	// We have already performed a check in the helper function to determine if memory was allocated.
	// This check is used is assigned the node to the head.
	if (pNew != NULL)
	{
		pNew->pNext = *pStack; // assign new nodes next to the top of the Stack.
		*pStack = pNew; // The head of the stack now becomes the new node.
	}
}

// Push of the integer node onto the Stack.
// Again this is the exact same as the character push onto the character Stack.
void pushint(StackNodeint **pStack, int infixint){

	StackNodeint *pNew = NULL;

	pNew = makeNodeint(infixint);

	if (pNew != NULL)
	{
		pNew->pNext = *pStack;
		*pStack = pNew;
	}
}

// The charcter pop will essentially remove the first character on the 
// character Stack.
char popchar(StackNodechar **pStack){

	StackNodechar *pTemp = NULL; // A temporary pointer function to be used as a place to store 
								 // the header of the Stack.
	char postHold = '\0'; // we would like to return the data that will be deleted.

	// Should the Stack not be empty we would like ot perform the pop.
	if (*pStack != NULL)
	{
		pTemp = *pStack;// Place the head of the stack in the temporary pointer.
		*pStack = pTemp->pNext; // Point the head of the stack to the next node.
		postHold = pTemp->data; // Place the head of the Stack's data in the postfix holder.

		free(pTemp); // free the memory located at the head of the Stack.
	}

	return postHold; // Return the place holder of the head Stack's data.
}

// Again the exact same style and purpose as the character Pop Stack except we are dealing
// with integers this time instead of characters.
int popint(StackNodeint **pStack){

	StackNodeint *pTemp = NULL;
	int postHold = 0;

	if (*pStack != NULL)
	{
		pTemp = *pStack;
		postHold = pTemp->data;
		*pStack = pTemp->pNext;

		free(pTemp);
	}

	return postHold;
}

// The top function call returns the character data listed in the character stack
// that will be used in the priority computation.
char top(StackNodechar *pStack){

	char topHold = '\0'; // create a place holder for the top data.

	// Assuming the stack is not empty.
	if (pStack != NULL){
		topHold = pStack->data; // place the top data within the place holder to be returned.
	}
	
	return topHold; // return of the placeholder data.
}
