#include "FileHeader.h" //Inclusion of Header

int main(){

	// Initialization of variables including the two stacks.
	StackNodechar *pStack = NULL; // These two stacks could be implemented under one node
	StackNodeint *iStack = NULL;  // however they will be handling two seperate types of data.
	char infixsym = '\0', infixinput = '\0', infixarr[MAX];
	int i = 0, j = 0, op1 = 0, op2 = 0, postHold = 0, result = 0, digithold = 0;;

	// Welcome the user to the program.
	// Explain the details of this program and its use to convert an infix expression to a prefix.
	// then evaluate the postfix expression.
	printf("Welcome to the infix to postfix program\n");
	printf("This program will convert an infix equation to its postfix equivalent\n");
	system("pause");
	system("cls");

		printf("Please enter in the infix expression you wish to convert or type 'exit' to exit the program:\n");

		/*The next few processes could have been completed within their own functions.
		With that being said I did not place them in their own functions so that the computations
		could be evident within main and would not fall victim to a pass by value or reference
		computation error.*/

		// The main collection of user input to take an infix expression and then convert it.
		while ((infixinput = getchar()) != '\n'){
			// If the user had entered a digit at somepoint in the string, it will be collected first.
			if (isalnum(infixinput)){
				// Collect into character array.
				infixarr[i] = infixinput;
				i++;
			}
			else{
				// The will evaluate any number given in a parenthesis
				// and the expressions included within it.
				if (infixinput == '('){
					// Push the character to the stack to be popped off later.
					pushchar(&pStack, '(');
				}
				else{
					// Should the end of the parenthesis' occur then the contents of the expression inside
					// will be popped in the order if was found.
					if (infixinput == ')'){
						// This is where the pop occurs until the first parenthesis' is reached.
						while ((infixsym = popchar(&pStack)) != '('){
							// Collect the expression.
							infixarr[i] = infixsym;
							i++;
						}
					}
					else{
						// Should the other checks not occur the priority of the operators will take effect.
						// The operators come in order and will be evaluated against the top of the stack.
						while ((priority(infixinput) <= priority(top(pStack))) && (pStack != NULL)){
							// Pop the operator into a collector which will then be placed in the character array.
							infixsym = popchar(&pStack);
							infixarr[i] = infixsym;
							i++;
						}
						// Should that check not be sufficent, then the rest of the symbols equivalent or not
						// will be placed in the stack.
						pushchar((&pStack), infixinput);
					}
				}
			}
		}

		// This will pop the stack so that no symbol will be kept in the stack.
		while (pStack != NULL){
			// Pop the operator into a collector.
			infixsym = popchar(&pStack);
			infixarr[i] = infixsym;
			i++;
		}

		// Setting the last iterative operation to the null character eliminates the need to have additional
		// data if it is unused.
		infixarr[i] = '\0';
	
		// Display the postfix equation to the user.
		printf("The postfix expression is: %s\n", infixarr);

		// The process below will compute or evalute the postfix expression
		// The process starts if the infix character array is not the null terminator.
		while (infixarr[j] != '\0'){
			// While the array is iterated, a check will be made if the character is a digit.
			if (isdigit(infixarr[j])){
				// if the character is a digit, the charatcer will be converted to its digit form.
				digithold = infixarr[j] - '0';
				// The digit will then be pushed onto the integer stack.
				pushint(&iStack, digithold);
			}
			else{
				// should the computation not be a digit but instead an operator then this check will be performed.
				if (isOperator(infixarr[j]) == TRUE){
					op2 = popint(&iStack); // Pop the first digit in the stack which is actually the second operand.
					op1 = popint(&iStack); // Pop the next operand to be computed.
					postHold = Operations(infixarr[j], op1, op2); // perform the operation listed in the character array and then place the results in a place holder.
					pushint(&iStack, postHold); // push the resulting place holder into the stack to be popped later.
				}
			}
			j++; // increase the iterator.
		}

		result = popint(&iStack); // should the array reach the null terminator - pop the results of the stack.
		printf("\nThe postfix value is: %d\n", result); // display results to the user.

	return 0;
}