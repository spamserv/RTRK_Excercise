#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>

#ifndef SCNu8
#define SCNu8 "hhu"
#endif

struct node {
	int val;
	struct node* next;
	struct node* prev;
};

void push(struct node** HEAD, struct node** REAR,int val);
void display(struct node** HEAD, struct node** REAR);
void print_nth(struct node**, int val);

int main()
{
	struct node* HEAD = NULL;
	struct node* REAR = NULL;
	int value;
	uint8_t switcher;

	while (1)
	{
		printf("What do you want to do?\n");
		printf("Add element to doubly linked list - 1\n");
		printf("Print elements - 2\n");
		printf("Print every n-th character - 3\n");
		printf("Exit program - 0\n");

		scanf_s("%" SCNu8, &switcher);

		switch (switcher)
		{
		case 0:
			exit(0);
			break;
		case 1:
			printf("Enter a value to add doubly linked list:\n");
			scanf_s("%d", &value);
			push(&HEAD, &REAR,value);
			break;
		case 2:
			printf("Printing list:\n");
			display(&HEAD, &REAR);
			break;
		case 3:
			printf("Select value to iterate through doubly linked round buffer:\n");
			scanf_s("%d", &value);
			print_nth(&HEAD, value);
			break;
		case 4:
			printf("Printing list in a reverse way..\n");
			display(&HEAD, 1);
		}
	}
	_getch();
	return 0;
}


void push(struct node** HEAD, struct node** REAR, int val)
{
	struct node* ptr = (struct node*) malloc(sizeof(struct node));
	struct node* head = *HEAD;
	struct node* rear = *REAR;
	ptr->val = val;

	if (*REAR == NULL)
	{
		ptr->next = ptr;
		ptr->prev = ptr;
		*HEAD = *REAR = ptr;
	}
	else
	{
		ptr->next = rear;
		ptr->prev = head;
		rear->prev = ptr;
		head->next = ptr;
		*HEAD = ptr;
	}
}


void display(struct node** HEAD,struct node** REAR)
{
	int counter = 0;
	struct node* ptr = *HEAD;
	struct node* rear = *REAR;
	if (ptr == NULL)
	{
		printf("List is empty!\n");
		return;
	}

	while (ptr != ptr->prev)
	{
		printf("| Value: %d\t Current: %p\t Next: %p\t Previous: %p|\n", ptr->val,ptr,ptr->next,ptr->prev);
		ptr = ptr->next;
	}
	printf("Finished printing the list.\n");
	printf("----------------------------\n");
	return;
}

void print_nth(struct node** HEAD, int val)
{
	struct node* ptr = *HEAD;
	
	bool is_left = false;
	if (ptr == NULL) 
	{
		printf("Doubly linked round buffer is empty!");
		return;
	}
	while (ptr != ptr->next) {
		for (int i = 0; i < val; i++)
		{
			if (is_left)
				ptr = ptr->prev;
			else
				ptr = ptr->next;
		}

		ptr->next->prev = ptr->prev;
		ptr->prev->next = ptr->next;
		is_left = !is_left;
		printf("%d. value -[%d], REMOVED\n", val, ptr->val);
		
	}
}
