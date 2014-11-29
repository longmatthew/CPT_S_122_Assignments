#include "FileHeader.h"

int main(){

	StackNode *pStack = NULL;
	char infixsym = '\0', infixinput = '\0';

	printf("Welcome to the infix to postfix program\n");
	printf("This program will convert an infix equation to its postfix equivalent\n");
	system("pause");
	system("cls");
	printf("Please enter in the infix expression you wish to convert:\n");

	while ((infixinput = getchar()) != '\n'){
		printf("%c", pStack->data);
		if (isalnum(infixinput)){
			printf("%c", infixinput);
		}
		else{
			if (infixinput == '('){
				push(pStack, '(');
			}
			else{
				if (infixinput == ')'){
					while (infixsym = pop(pStack) != '('){
						printf("%c", infixsym);
					}
				}
				else{
					while (priority(infixinput) <= 4 && (pStack != NULL)){
						infixsym = pop(pStack);
						printf("%c", infixsym);
					}
					push(pStack, infixinput);
				}
			}
		}
	}
	while (pStack != NULL){
		infixsym = pop(pStack);
		printf("%c", infixsym);
	}
	return 0;
}