#include "linkedlist.h"
#include <conio.h>

uint8_t is_empty(struct node** HEAD);
void divide(struct node** HEAD, struct node** HEAD1, struct node** HEAD2, int val);
void print_both(struct node** HEAD1, struct node** HEAD2);

int main()
{
	struct node* HEAD = NULL;
	struct node* HEAD1 = NULL;
	struct node* HEAD2 = NULL;
	uint8_t switcher;
	int value;
	while (1)
	{
		printf("What do you want to do?\n");
		printf("Add to start of the list - 1\n");
		printf("Set divider value - 2\n");
		printf("Print divided lists - 3\n");
		printf("Print original list - 4\n");
		printf("Exit program - 0\n");

		scanf_s("%" SCNu8, &switcher);

		switch (switcher)
		{
		case 0:
			exit(0);
			break;
		case 1:
			printf("Enter a value to add to start of the list:\n");
			scanf_s("%d", &value);
			add_to_list(&HEAD, value, 0);
			break;
		case 2:
			printf("Enter divider value:\n");
			scanf_s("%d", &value);
			if(is_empty(&HEAD))
				printf("Linked list is empty!\n");
			else
				divide(&HEAD, &HEAD1, &HEAD2, value);
			break;
		case 3:
			printf("Printing both lists...\n");
			print_both(&HEAD1, &HEAD2);
			break;
		case 4:
			printf("Printing original list..\n");
			print_list(&HEAD);
			break;
		}
	}

	_getch();
	return 0;
}

uint8_t is_empty(struct node** HEAD) {
	if (*HEAD == NULL)
		return 1;
	else
		return 0;
}

void divide(struct node** HEAD, struct node** HEAD1, struct node** HEAD2, int val)
{
	struct node* ptr = *HEAD;

	if (ptr == NULL) 
	{
		printf("-- Stack is empty! Nothing to divide!\n");
		return;
	}
	while (ptr != NULL) {
		struct node* ptr1 = (struct node*) malloc(sizeof(struct node));
		ptr1->val = ptr->val;
		if (ptr->val > val) {
			
			ptr1->next = *HEAD1;
			*HEAD1 = ptr1;
		}
		else
		{
			ptr1->next = *HEAD2;
			*HEAD2 = ptr1;
		}

		ptr = ptr->next;
	}
}

void print_both(struct node** HEAD1, struct node** HEAD2)
{
	struct node* head1 = *HEAD1;
	struct node* head2 = *HEAD2;
	
		if (head1 == NULL) {
			printf("-- Stack 1 is empty!\n");
		} 
		else
		{
			while (head1 != NULL) {
				printf("[%d] -->", head1->val);
				head1 = head1->next;
			}
			printf("NULL\n");
		}

		if (head2 == NULL) {
			printf("-- Stack 2 is empty!\n");
		}
		else
		{
			while (head2 != NULL) {
				printf("[%d] -->", head2->val);
				head2 = head2->next;
			}
			printf("NULL\n");
		}
}