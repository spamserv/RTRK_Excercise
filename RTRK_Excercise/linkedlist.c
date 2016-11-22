#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#ifndef SCNu8
#define SCNu8 "hhu"
#endif

struct node {
	int val;
	struct node *next;
};

struct node* initialize_list(struct node **HEAD, int val)
{
	struct node *head = *HEAD;
	struct node *ptr = (struct node*) malloc(sizeof(struct node));
	ptr->val = val;
	if (NULL == head)
	{
		ptr->next = head;
		head = ptr;
	}

	return ptr;
}

struct node* add_to_list(struct node **HEAD, int val, uint8_t add_to_end)
{
	struct node *ptr = (struct node*) malloc(sizeof(struct node));

	if (NULL == *HEAD) {
		ptr->val = val;
		ptr->next = *HEAD;
		*HEAD = ptr;
		return ptr;
	}

	if (!add_to_end)
	{
		ptr->val = val;
		ptr->next = *HEAD;
		*HEAD = ptr;
	}
	else
	{
		struct node *temp = *HEAD;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}

		ptr->val = val;
		ptr->next = temp->next;
		temp->next = ptr;
	}

	return ptr;
}

void remove_from_list(struct node **HEAD, int val)
{
	struct node *prev = (struct node*) malloc(sizeof(struct node));
	struct node *ptr = *HEAD;

	if (ptr != NULL && ptr->val == val) {
		*HEAD = ptr->next;
		return;
	}

	while (ptr != NULL && ptr->val != val)
	{
		prev = ptr;
		ptr = ptr->next;
	}

	if (ptr == NULL) {
		printf("[%d] is not in the list\n", val);
		return;
	}

	prev->next = ptr->next;
	free(ptr);
	printf("Value [%d] is removed.\n", val);
}

struct node* search_in_list(struct node **HEAD, int val)
{
	struct node *ptr = *HEAD;

	while (ptr != NULL)
	{
		if (ptr->val == val) {
			return ptr;
		}

		ptr = ptr->next;
	}

	if (ptr == NULL) {
		return NULL;
	}

	return NULL;
}

void print_list(struct node **HEAD)
{
	int counter = 0;
	struct node *ptr = *HEAD;
	if (ptr == NULL)
	{
		printf("List is empty!\n");
		return;
	}
	while (ptr != NULL)
	{
		printf("| Value: %d |\n", ptr->val);
		ptr = ptr->next;
	}
	printf("Finished printing the list.\n");
	printf("----------------------------\n");
}

void reverse_list(struct node **HEAD)
{
	struct node *ptr = *HEAD;
	struct node *new_head = NULL;
	struct node *temp = (struct node*) malloc(sizeof(struct node));
	while (ptr != NULL)
	{
		temp = ptr->next;
		ptr->next = new_head;
		new_head = ptr;
		ptr = temp;
	}

	*HEAD = new_head;
}