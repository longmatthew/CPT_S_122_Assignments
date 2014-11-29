#ifndef FILE_HEADER
#define FILE_HEADER

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 30

typedef struct stacknode
{
	char data;
	struct stacknode *pNext;
}StackNode;

int priority(char infixchar);
StackNode *makeNode(char newData);
void push(StackNode *Stack, char infixcahr);
char pop(StackNode *Stack);
char top(StackNode *Stack);

#endif