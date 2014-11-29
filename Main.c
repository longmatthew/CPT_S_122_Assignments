#include "File_Header.h" // Inclusion of File Header

int main(){

	// Initialization of variables
	Queue Express_Queue = { NULL, NULL };
	Queue Normal_Queue = { NULL, NULL };
	int sim_length = 0, count_cust = 0, exp_service = 0, norm_service = 0,
		express_time = 0, normal_time = 0, deexpress_hold = 0, 
		denormal_hold = 0, express_count = 0, normal_count = 0, i = 0;
	
	// Introduce the user to the program and detail a short description 
	// of what this program will try to accomplish.
	printf("Welcome to the Grocery Store Simulation\n");
	printf("\nThis program is intended to simulate the experience\n");
	printf("of being at a grocery store. Customers will be randomly selected\n");
	printf("and placed in express and normal checkout lanes. This simulation\n");
	printf("will run for as long as you would like.\n");
	// Pause to allow user to read the information.
	system("pause");
	system("cls"); // Clear screen

	// Ask the user how long they would like to run the simulation. The iterator will be stored.
	printf("Please enter how long you would like this simulation to run (in minutes):\n");
	scanf("%d", &sim_length);
	system("cls"); // Clear screen.

	/* We intend to iterate through this process until it is complete.
	 We will place a customer in a Que or Grocery Lane, display a message as to
	 what lane the customer was placed in. Then iterate through a few more steps
	 until their service time has been completed.*/

	for (i = 0; i < sim_length; i++){

		count_cust += 1; // assign customers a number 1 through 24

		if (count_cust == 25){ // When the 25th customer appears the count will be reset for
			count_cust = 0;    // those customers.
		}

		exp_service = (rand() % 5) + 1;		// This is essentially how the lanes will be give a que time and then subsuquentily dequed
		norm_service = (rand() % 5) + 3;	// The service time is given a random number 1 - 5 for express lanes and 3 - 8 for normal lanes.

		// to print the Que of each lane we will need to wait until 10mins. has passed.
		// Once 10 mins has passed we will print out the que for each lane.
		if (i >= 1){
			if ((i % 10) == 0){
				printf("\nThe Express Lane currently has:\n");
				printQue(Express_Queue); // Printing of Express Lane
				printf("\n");
				printf("\nThe Normal Lane currently has:\n");
				printQue(Normal_Queue); // Printing of Normal Lane.
				printf("\n");
			}
		}
		
		express_time += exp_service; // We would also like a collection of the total time of service of each customer in the lane.
									 // This assign essentially performs that operation.

		// I place an identifier string literal to show the user which process has placed a customer in a lane.
		printf("The Process:\n");
		// Display the customer information to the user to verify simulation results.
		printf("Customer %d has been placed into the Express Lane with Service Time %d at Time %d\n", count_cust, exp_service, i);
		// Push he information we have just gathered from this iteration to the Que of the Express Lane.
		Enqueue(&Express_Queue, count_cust, exp_service, express_time);
		
		normal_time += norm_service; // Again, push a total collective time to be placed within the Que.
		printf("The Process:\n"); // Identifier.
		printf("Customer %d has been placed into a Normal Lane with Service Time %d at Time %d\n", count_cust, norm_service, i); // Display iterative process of the information collected.
		Enqueue(&Normal_Queue, count_cust, norm_service, normal_time); // Push the infromation from the Normal Lane to the Normal Lane Que.
		
		express_count++; // Iterative step to check the service time in each Lane.
		normal_count++;  // This is required for the comparison to release a customer from a lane.

		// The check will be in place to not only check if the customer can be released if their service time has been completed 
		// but will also check if their is a customer in the lane at the time of release. 
		if ((Express_Queue.pHead != NULL) && (Express_Queue.pHead->serviceTime == express_count)){
			express_count = 0;	// reset the express count so that it will process and release the next customer once the service time has been reached.
			deexpress_hold = deQueue(&Express_Queue); // return which customer was released from the lane from the deQue function.
			printf("\nCustomer %d has finished their service in the Express Lane\n\n", deexpress_hold); // Display which customer was released.
		}

		// Again, same check - this might be more useful if the random number generation where synced to only one lane.
		if ((Normal_Queue.pHead != NULL) && (Normal_Queue.pHead->serviceTime == normal_count)){
			normal_count = 0; // reset the express count so that it will process and release the next customer once the service time has been reached.
			denormal_hold = deQueue(&Normal_Queue); // Gather customer information from time of release.
			printf("\nCustomer %d has finished their service in the Normal Lane\n\n", denormal_hold); // Display Customer that has finished thier service.
		}
	}

	// For the end of the simulation I wanted to pause so that the user can look
	// over the available information that was given in this run.
	system("pause");
	printf("\nThe simulation has ended\n"); // Display identifier that that sim has ended.
	return 0;
}