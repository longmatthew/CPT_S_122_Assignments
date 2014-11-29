#ifndef FILE_HEADER // File Header 'lock'.
#define FILE_HEADER

// inclusion of preprocessor directives.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Creation of Queue Node for the storage of data nodes.
typedef struct queueNode
{
	int customerNumber;
	int serviceTime;
	int totalTime;
	struct queueNode *pNext;
}QueueNode;

// Creation of Que with two nodes that point to both the header
// and tail of the Que.
typedef struct queue
{
	QueueNode *pHead;
	QueueNode *pTail;
}Queue;

// Function prototypes initialized here.
// Healper function makeNode for memory allocation.
QueueNode *makeNode(int cust_num, int serv_time, int total_time);
// Enqueue function to add nodes to a Que.
void Enqueue(Queue *pLane, int cust_num, int serv_time, int total_time);
// Printing the contents of the Que.
void printQue(Queue pLane);
// Deallocate and remove nodes from the Que.
int deQueue(Queue *pLane);

#endif // End of 'Lock'.