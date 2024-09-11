
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

struct student{

	int id;
	char name[50];
	int age;
	float gpa;

}data;

struct node {

    struct student data;
	struct node *next;

};

struct node *head = NULL;  // Initialize a global "head" pointer.

void CreateLinkedList (int id, const char *name, int age, float gpa){  //Function to create a linked list in the memory to hold all data of students.

	struct node *current = NULL;   // Initialize a current pointer to loop in the linked list.

	struct node *link = (struct node*) malloc(sizeof(struct node)); //locate an area in the memory with the size of struct node and set link pointer to it.

	assert (link != NULL); // Check memory allocation process is successful.


	// Save the data given from the user in this node.
	link->data.id = id;
	strcpy(link->data.name , name);
	link->data.age = age;
	link->data.gpa = gpa;

	link->next = NULL;  // Set the pointer value of next node to NULL.


	// Set the head pointer to the first node.
	/* A process only made at the beginning of linked list formation*/
	if(head == NULL){
		head = link;
		return;
	}

    //If more than one node exists in the linked list
	current = head;  // Set the current pointer to the head node to loop on all nodes in the linked list.

	while(current->next != NULL){    //Loop till the last node in the linked list.
		current = current->next;
	}

	// Locate the new node at the end of the linked list.
	current->next = link;
}

void AddStudent (const struct student *const ptr){ // Function to Add new student's info in the linked list.


	struct node *current = NULL;  // Initialize a current pointer to loop in the linked list.

	current = head;  // Set the current pointer to the head node.

	while(current != NULL){ // Loop on all nodes in the linked list.

		// Check the student does not already exist in the linked list.
		if(current->data.id == ptr->id){   // If the ID given from the user matches the ID in this node print a message indicates student already exists.
			printf("\n---------------------------\nStudent already exists.\n");
			fflush(stdout);
			return;
		}
		else{
			// IF the ID does not match, shift the current pointer to the next node to continue checking.
			current = current->next;
		}

	// If ID does not match with any ID within the linked list, exit the while loop.
	}

    // Create a new node in the linked list with the data received from the user.
	CreateLinkedList(ptr->id, ptr->name, ptr->age, ptr->gpa);
}

void DisplayStudents(void){  //Function to display student's data stored in all nodes in the linked list.

	 struct node *current = NULL; // Initialize a current pointer to loop in the linked list.


	if(head == NULL){   // If no linked list exists
		// Print a message to indicate no student's data saved.
		printf("\n---------------------------\nNo student are present.\n");
		fflush(stdout);
		return; //Return to main.
	}

	// IF linked list is found in memory
	current = head;  // Set the current pointer to the head node.

	while (current != NULL){   //Loop on all the nodes in the linked list.

		// Print all data existing in this node.
		printf("\n---------------------------\n\nID\t%d\nName:\t%s\nAge:\t%d\nGPA:\t%f\n", current->data.id , current->data.name, current->data.age, current->data.gpa);


		current = current->next;  // Shift the current pointer to the next node.
	}
}

void SearchStudentByID(int id){  // Function to search for a student's data in the linked list by their ID.

  struct node *current = NULL;  // Initialize a current pointer to loop in the linked list.

  current = head;             // Set the current pointer to the head node.

  while(current != NULL){  //Loop on all the nodes in the linked list.

	  if(current->data.id == id)    {// If the ID in this node the same as the ID received from the user

		  //Print all the data stored in this node.
		  printf("\n---------------------------\nID\t%d\nName:\t%s\nAge:\t%d\nGPA:\t%f\n", current->data.id , current->data.name, current->data.age, current->data.gpa);
		  fflush(stdout);
		  return;
	  }

	  else{ // If this node's ID does not match the ID given from user
		  current = current->next; // Shift the current pointer to the next node.
	  }

  } // Exit the while loop.

  // Print a message to indicate student of given ID does not exist in the linked list.
  printf("Student not found.");
}


void UpdateByID (int id){  // Function to update the data of a student exists in the linked list.


	struct node *current = NULL;  // Initialize a current pointer to loop in the linked list.

	 current = head;    // Set the current pointer to the head node.


	 while(current != NULL){ //Loop on all the nodes in the linked list.

		 if(current->data.id == id){ // If the ID in this node the same as the ID received from the user

			 printf("Enter New info (ID, Name, Age, GPA) :\n");  //Take the new info from the user to be update the data in this node
			 fflush(stdout);
			 scanf("%d%s%d%f", &data.id, &data.name, &data.age, &data.gpa);

			 //Start replacing the old data with the new ones taken from the user.
			 current->data.id = data.id;
			 strcpy(current->data.name , data.name);
			 current->data.age = data.age;
			 current->data.gpa = data.gpa;

			 // Print a message to indicate successful update
			 printf("\n---------------------------\nInformation successfully updated.\n---------------------------\n");
			 fflush(stdout);
			 return;
		 }

		 // If this is not the node that contains the student with the user's given ID
		 current = current->next;  // Shift the current pointer to the next node.

	 }  // Exit the while loop.

	 // Print a message to indicate no student found if the ID does not match with any ID in the Linked list.
	 printf("Student not found.");


}

float CalculateAVGgpa (void){  //Function to Calculate the average of GPAs stored in the linked list.

	struct node *current = NULL;         //Initialize a pointer to loop in the linked list.

	float sum = 0, counter=0, avg = 0;

	if (head == NULL){   //If no linked list exist, print average GPA of 0.0

		printf("Average GPA: ");
		fflush(stdout);
		return 0.0;
	}

    //If there's a linked list stored in the memory

	current = head;    //Set the current pointer to the head node.

	while(current != NULL){    // Loop on all the nodes in the linked list.

		sum += current->data.gpa;  //Increment the sum variable with the value of the GPA stored in ach node.

		counter++;      // Increment the counter by 1 each loop to get the number of nodes in the entire linked list.

		current = current->next;   // Shift the current pointer to the next node.
	}

	avg = sum/counter;

	return avg;  //Return the calculated average to the main.
}

void SearchHighestGPA (void){     //Function to search for the student of the highest GPA in the linked list.

	struct node *current = NULL; //Initialize a pointer to loop in the linked list.

	float max_gpa = 0;         //Initialize a variable to hold the maximum GPA found.

	struct node* highest_student = NULL;  //Initialize a pointer to hold the address of the node of highest GPA.


	if (head == NULL){  //If no linked list exists print a message to indicate no data is stored.

		printf("\n---------------------------\nNo student information available\n---------------------------\n");
		return;
	}


	if(head->next == NULL){   //If the linked list contains only one node.

		// Print the Info of this student.
		printf("\n---------------------------\nStudent of highest GPA is:\n\nID\t%d\nName:\t%s\nAge:\t%d\nGPA:\t%f\n\n---------------------------\n", head->data.id, head->data.name, head->data.age, head->data.gpa);
		return;
	}

     //If several nodes exist

     current = head;   //Set current pointer on the head node.

     max_gpa = current->data.gpa;    //Assume this node has the maximum GPA.

     highest_student = current;    //set the highest_student pointer to this node.

     current = current->next;    //shift the current pointer to the next node.


	while(current != NULL){  //Loop on all the nodes in the linked list.

		if(current->data.gpa > max_gpa){  //Compare the GPA in this node ith the assumed maximum GPA.

			//If this GPA is greater than the assumed maximum GPA
			max_gpa = current->data.gpa;    // Save this GPA as the maximum GPA.

			highest_student = current;    // Set the highest_student pointer to this node.

			current = current->next;    // Shift the current pointer to the next node to continue comparing.

		}

		else{
			//If the GPA in this node is smaller than the assumed maximum GPA
			current = current->next;  // Shift the current pointer to the next node to continue comparing.
		}

	} //Exit the while loop.

	// Print the data of the student exists in the node of the highest_student pointer.
	printf("\n---------------------------\nStudent of highest GPA is:\nID\t%d\nName:\t%s\nAge:\t%d\nGPA:\t%f\n---------------------------\n", highest_student->data.id, highest_student->data.name, highest_student->data.age, highest_student->data.gpa);
	fflush(stdout);


}

void DeleteStudent (int id){
	struct node *current = NULL;      //Initialize a pointer to loop in the linked list.

	struct node *delete_node = NULL; //Initialize a pointer to free when the node to be deleted is reached.

	struct node *prev = NULL;      //Initialize another pointer to loop in the linked list.

	prev = head; //Set the prev pointer on the head node.

	if(head == NULL){   //No linked list exists.
		printf("\n---------------------------\nNo Information available.\n---------------------------\n");
		fflush(stdout);
		return;
	}

	if(head->data.id == id){  //If student's Id is found in the head node

		delete_node = prev;  // set the delete_node pointer on this node.

		head = head->next;  //shift the head pointer to the next node.

		free(delete_node); //Delete this node from the linked list.

		printf("\n\nStudent is deleted.\n---------------------------\n");  //print a message to indicate the deleting process.
		fflush(stdout);
		return;  //leave this function and return to main.
	}

	//If this ID does not exit in the head node, shift the ointer to the next node.
	prev = head;
	current = prev->next; //set the current pointer the node after this node.

    while(current != NULL){                //Loop until the end of the linked list.

    	if(current->data.id == id){       //If student's Id is found in this node

    		delete_node = current;       //set the delete_node pointer on this node.

    		prev->next = current->next; //set the next of the prev node to the next of the current node.

    		free(delete_node);         //Delete this node from the linked list.

    		printf("\n\nStudent is deleted.\n---------------------------\n");  //print a message to indicate the deleting process.
    		fflush(stdout);
    		return;   //leave this function and return to main.
    	}

    	//If Id is not found in this node
    	prev = prev->next;         //shift the prev pointer to the next node.

    	current = current->next;  //shift the current pointer to the after next node.

    } //Exit while loop.

    //If ID is not found within the entire linked list

	printf("\n---------------------------\nStudent not found.\n---------------------------\n"); //Print a message that student is not found within the saved data.
	fflush(stdout);

}




int main(void) {
	int exit = 0; //initiallize a variable to terminate the program.


	while (exit != 1){ // A condition for the program to loop.

	int choice;


	//Take the user's choice
    printf("\n---------------------------\n1\tAdd new student\n2\tDisplay info\n3\tSearch student\n4\tUpdate student\n5\tCalculate average GPA\n6\tDisplay highest GPA\n7\tDelete Student\n0\tExit program\n");
    fflush(stdout);
    printf("---------------------------\nChoose an option: ");
    fflush(stdout);
    scanf("%d",&choice);

    	switch(choice){

    	case 0: exit = 1; //Exit program
    	      break;

    	case 1:
    		printf("\n---------------------------\nEnter student info:\nID ,Name ,Age, GPA:\n");
    		fflush(stdout);
    		scanf("%d%s%d%f", &data.id, &data.name, &data.age, &data.gpa);

    		//send data of student to AddStudent function to be added to the linked list.
    		AddStudent(&data);
    	      break;

    	case 2:  DisplayStudents(); //display all info of student saved in the linked list
    	      break;

    	case 3:
    		printf("\n---------------------------\nEnter ID:"); //Take ID of student from user to search for in the linked list.
    		fflush(stdout);
    		int id_to_search;
    		scanf("%d",&id_to_search);
    		SearchStudentByID(id_to_search); //send the ID to the function SearchStudentByID to search in the linked list.
    	      break;

    	case 4:
    	    printf("\n---------------------------\nEnter ID of student:"); //Take ID of student from the user to access the student info
    	    fflush(stdout);
    	    int id_to_check;
    	    scanf("%d", &id_to_check);

    	    UpdateByID(id_to_check); //send the ID to the function UpdateByID to access the node of the student to update their info

    	       break;

    	case 5:
                 //Function to calculate the sum of all student's GPA saved in the linked list and print out the average.
    		     printf("\n---------------------------\nStudent's average GPA: %f\n",CalculateAVGgpa());
	             fflush(stdout);
	             break;


    	case 6:
    		    //Function to search for the student of the highest GPA in the linked list and print out their info.
    		    SearchHighestGPA();
    	        break;

    	case 7:
    		    //Take the ID of the student to be delete from the user.
    		    printf("\n---------------------------\nEnter ID of student to be deleted: ");
    		    fflush(stdout);
    		    int id_to_delete;
    		    scanf("%d",&id_to_delete);

    		    DeleteStudent(id_to_delete); //send the ID from the user to the function DeleteStudent to delete their node from the linked list.
    		    break;


    	}

	}

	return 0;
}
