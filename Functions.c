#include "FileHeader.h"

int priority(char infixchar){

	switch (infixchar){
	case ('(') : {
					return 0;
					break;
	}
	case ('+') : {
	case ('-') : {
					return 1;
					break;
	}
	}
	case ('*') : {
	case ('/') : {
	case ('%') : {
					return 2;
					break;
	}
	}
	}
	default:{
				return 3;
				break;
	}
	}
}

StackNode *makeNode(char newData){

	StackNode *pMem = NULL;

	pMem = (StackNode *)malloc(sizeof(StackNode));

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

void push(StackNode *Stack, char infixcahr){

	StackNode *pTemp = NULL, *pNew = NULL;

	pTemp = Stack;
	pNew = makeNode(infixcahr);

	pNew->pNext = pTemp;
	pTemp = pNew;

}

char pop(StackNode *Stack){

	StackNode *pTemp = NULL;
	char postHold = '\0';

	pTemp = Stack;
	postHold = pTemp->data;
	pTemp = pTemp->pNext;

	free(pTemp);

	return postHold;
}

char top(StackNode *Stack){

	char topHold;

	topHold = Stack->data;
	
	return topHold;
}