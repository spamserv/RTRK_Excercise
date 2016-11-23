#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef SCNu8
#define SCNu8 "hhu"
#endif

struct node {
	int val;
	struct node* next;
	struct node* prev;
};

void push(struct node** HEAD, int val);
void reverse_list(struct node** HEAD);
void display(struct node** HEAD, uint8_t val);
void print_desired(struct node** HEAD);

int main()
{
	struct node* HEAD = NULL;
	struct node* TAIL = NULL;
	int value;
	uint8_t switcher;

	while (1)
	{
		printf("What do you want to do?\n");
		printf("Add element to doubly linked list - 1\n");
		printf("Print elements - 2\n");
		printf("Print in desired way ( n/2, (n/2)+1, (n/2)-1, (n/2)+2, ... - 3\n");
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
			push(&HEAD, value);
			break;
		case 2:
			printf("Printing list:\n");
			display(&HEAD,0);
			break;	
		case 3:
			printf("Printing list...\n");
			print_desired(&HEAD);
			break;
		case 4:
			printf("Printing list in a reverse way..\n");
			display(&HEAD,1);
		}
	}
	_getch();
	return 0;
}


void push(struct node** HEAD, int val)
{
	struct node* ptr = (struct node*) malloc(sizeof(struct node));
	ptr->val = val;

	if (NULL == *HEAD) 
	{
		ptr->next = *HEAD;
		ptr->prev = NULL;
		*HEAD = ptr;
		return;
	}

	ptr->next = *HEAD;
	ptr->prev = NULL;
	*HEAD = ptr;
	ptr->next->prev = ptr;
}


void display(struct node** HEAD, uint8_t val)
{
	int counter = 0;
	struct node* ptr = *HEAD;
	if (ptr == NULL)
	{
		printf("List is empty!\n");
		return;
	}

	if (val == 0) 
	{
		while (ptr != NULL)
		{
			printf("| Value: %d |\n", ptr->val);
			ptr = ptr->next;
		}
		printf("Finished printing the list.\n");
		printf("----------------------------\n");
		return;
	}

	if (val == 1) {
		while (ptr->next != NULL) 
		{
			ptr = ptr->next;
		}
		while (ptr != NULL)
		{
			printf("| Value: %d |\n", ptr->val);
			ptr = ptr->prev;
		}
		printf("Finished printing the list REVERSED.\n");
		printf("----------------------------\n");
	}
}

void print_desired(struct node** HEAD)
{
	struct node* ptr = *HEAD;
	int number_of_elements = 1;
	int pivot = 1;
	bool is_left = false;
	while (ptr->next != NULL) 
	{
		number_of_elements++;
		ptr = ptr->next;
	}

	while (ptr != NULL && pivot <= (number_of_elements / 2))
	{
		ptr = ptr->prev;
		pivot++;
	}
	for (int i = 0; i < number_of_elements; i++)
	{
		for (int j = 0; j < i; j++) {
			if (is_left)
			{
				ptr = ptr->prev;
			}
			else
			{
				ptr = ptr->next;
			}
		}
		is_left = !is_left;
		printf("Value: [%d]\n", ptr->val);
		
	}
}
