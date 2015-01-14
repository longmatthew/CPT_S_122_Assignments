#include "File_Header.h" // Inclusion of header file.

// Makenode helper function to allocate dynamic memory for use in the Enqueue function call.
QueueNode *makeNode(int cust_num, int serv_time, int total_time)
{
	// Initialization of variables.
	QueueNode *pMem = NULL;

	pMem = (QueueNode *)malloc(sizeof(QueueNode)); // create the QueueNode which is creating space in memory.

	// Should the memory allocation be successful we will assign data given from
	// main into this node.
	if (pMem != NULL){
		// Assigning data from main to node.
		pMem->customerNumber = cust_num;
		pMem->serviceTime = serv_time;
		pMem->totalTime = total_time;
		pMem->pNext = NULL; // Node will point to NULL unless new node is aquired.
	}
	else{
		// Display to user if memory was not able to be allocated that something went wrong.
		printf("MEMORY ALLOCATION ERROR -- unable to allocate enough memory space.\n");
	}

	return pMem; // return the Node.
}

// Function to place node in a Que or grocery lane in this case.
void Enqueue(Queue *pLane, int cust_num, int serv_time, int total_time){
	
	// Initialization of variables.
	QueueNode *pMem = NULL;

	pMem = makeNode(cust_num, serv_time, total_time); // using the makeNode function call we allocate memory for this node.

	// Should memory be allocated we will create checks to place the node in the
	// appropriate location.
	if (pMem != NULL)
	{
		// Should the list be empty we will place the node in the Head and Tail
		// which will both be in the same position (the Head).
		if ((pLane->pHead) == NULL){
			pLane->pHead = pMem;
			pLane->pTail = pMem;
		}
		else{
			// Should the Que not be empty, we will place the new node at the tail
			// section of the que and assign the tail to the new node. FIFO
			pLane->pTail->pNext = pMem;
			pLane->pTail = pMem;
		}
	}
}

// The print function, this will allow us to print the list every 10 mins.
void printQue(Queue pLane){

	// Initialize variables. May not be needed in this case but better to be safe.
	QueueNode *pCur = NULL;

	pCur = pLane.pHead; // Assign the Pointer Node to the head of the Que.

	// While the head is not empty, display important information from node then assign
	// head node to head nodes next node.
	while (pCur != NULL)
	{
		printf("Customer Number %d, Service Time %d minutes, Total Time in lane %d minutes\n", pCur->customerNumber, pCur->serviceTime, pCur->totalTime); //  Display.
		pCur = pCur->pNext; // Assign head node to head's next node.
	}
}

// The deallocation of memory from the Que and the subsuqent loss of a customer from a lane.
int deQueue(Queue *pLane){

	// Initialization of variables.
	QueueNode *pTemp = NULL;
	int dataHold = 0; // variable to hold customer number that was released.

	// We are assuming the lane or Que is not empty.
	// This assumption is solely based on the programmer's intuition.
	if (pLane != NULL){

		// Using the temp pointer, place the que head in the temp pointer
		// assign the Que head to Que head's next node. Place the customer
		// number to be returned in the data holder.
		pTemp = pLane->pHead;
		pLane->pHead = pLane->pHead->pNext;
		dataHold = pTemp->customerNumber;

		// Should the head of the Que be in the same position as the tail
		// we should assign the tail to null so that no Que position pointer
		// still points to data that has been deallocated.
		if ((pTemp) == (pLane->pTail)){
			(pLane->pTail) = NULL;
		}

		free(pTemp); // Free the head node which is FIFO.
	}

	return dataHold; // return data holder which holds the contents of customer #.
}
