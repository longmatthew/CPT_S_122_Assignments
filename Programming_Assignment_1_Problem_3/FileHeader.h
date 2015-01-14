#ifndef FILE_HEADER // Creation of the File Header 'Lock'.
#define FILE_HEADER

// Inclusion of preprocessor directives.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 30 // define the character array size using this definition.

// Creation of a boolean (0 or 1) operator.
typedef enum boolean
{
	FALSE, TRUE
}Boolean;

// This is the character Stack used in converting infix to postfix.
typedef struct stacknodechar
{
	char data;
	struct stacknodechar *pNext;
}StackNodechar;

// This is the integer Stack used in processing the postfix evaluation.
typedef struct stacknodeint
{
	int data;
	struct stacknodeint *pNext;
}StackNodeint;

// Function Prototype calls are indicated here. The explanation of each function
// will be listed in the functions file.
int priority(char infixchar);
Boolean isOperator(char op);
int Operations(char oper, int op1, int op2);
StackNodechar *makeNode(char newData);
StackNodeint *makeNodeint(int newData);
void pushchar(StackNodechar **pStack, char infixchar);
void pushint(StackNodeint **pStack, int infixint);
char popchar(StackNodechar **pStack);
int popint(StackNodeint **pStack);
char top(StackNodechar *pStack);

#endif // End of 'Lock'.
