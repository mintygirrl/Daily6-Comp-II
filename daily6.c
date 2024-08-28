#include <stdio.h>
#include <stdlib.h>

/**********************************************************************
Program: Daily 6
Author: Fallon Weiss
Date: 2/5/24
Time spent: A Day and a Half.
Purpose: The purpose of this program is to used a link list and reverse it
while passing to that function a pointer to the head of Node.
***********************************************************************/

typedef struct node Node;
struct node
{
	int data;
	Node* next;
};


//declare your function here.
Node* reverse_list(Node* head);

int main(int argc, char* argv[])
{
	Node* head = NULL;
	int i;
	Node* temp;

	//set up a test list with values 9->8->7->...->0
	for (i = 0; i < 10; i++)
	{
		temp = (Node*)malloc(sizeof(Node));
		if (temp == NULL)
		{
			printf("out of memory?\n");
			exit(1);
		}
		temp->data = i;
		temp->next = head;
		head = temp;
	}

	//call your function to reverse the list (should work for any list given the head node pointer).
    head = reverse_list(head);

	//print the reversed list.
	temp = head;
	while (temp != NULL)
	{
		printf("%d\n", temp->data);
		temp = temp->next;
	}
	return 0;
}

//Define your function here

Node* reverse_list(Node* head)
{
    Node* next = head->next;
	Node* prev = NULL;
	
	while(next != NULL)
	{
		next = head->next;
		head->next = prev;
		prev = head;
		head = next;
	}

	return prev;
}