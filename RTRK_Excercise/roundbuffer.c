#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <conio.h>

#ifndef SCNu8
#define SCNu8 "hhu"
#endif

struct node {
	int val;
	struct node *next;
};

void push(struct node** HEAD, struct node** REAR, int val);
void print_buffer(struct node** HEAD, struct node** REAR);

int main() {
	struct node* HEAD = NULL;
	struct node* REAR = NULL;
	int n;
	while (1) {
		printf("Add to buffer: \t");
		scanf_s("%d", &n);
		push(&HEAD, &REAR, n);
		print_buffer(&HEAD, &REAR);
	}
	_getch();
	return 0;
}


void push(struct node** HEAD, struct node** REAR, int val) {
	struct node* ptr = (struct node*) malloc(sizeof(struct node));
	struct node* head = *HEAD;
	struct node* rear = *REAR;
	ptr->val = val;

	if (*REAR == NULL)
	{
		ptr->next = ptr;
		*HEAD = *REAR = ptr;
	}
	else
	{
		rear->next = ptr;
		ptr->next = head;
		*HEAD = ptr;
	}

}

void print_buffer(struct node** HEAD, struct node** REAR)
{
	struct node* head = *HEAD;
	struct node* rear = *REAR;
	int i = 0;

	if (*HEAD == NULL)
	{
		printf("Round buffer is empty!\n");
		return;
	}

	while (head != rear) {
		printf("ROUND BUFFER: position [%d], address [%p], points to [%p]\n", ++i, head, head->next);
		head = head->next;
	}
	printf("ROUND BUFFER: position [%d], address [%p], points to [%p]\n", ++i, head, head->next);
}