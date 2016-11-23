#include <stdio.h>
#define MAXSIZE 5

struct stack
{
	char stk[MAXSIZE];
	int top;
};
typedef struct stack STACK;
STACK s;

void push();
int  pop();
void display();
void check_parenthesis();

void main()
{
	int choice;
	int option = 1;
	s.top = -1;

	printf("STACK OPERATION\n");
	while (1)
	{

		printf("push - 1\n");
		printf("pop - 2\n");
		printf("display - 3\n");
		printf("check - 4\n");
		printf("exit - 0\n");


		printf("Enter your choice\n");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1:
			push();
			break;
		case 2:
			pop();
			break;
		case 3:
			display();
			break;
		case 4:
			check_parenthesis();
			break;
		case 0:
			exit(0);
			break;
		default:
			break;
		}
		fflush(stdin);
	}
}

void push()
{
	char num;
	if (s.top == (MAXSIZE - 1))
	{
		printf("Stack is full!\n");
		return;
	}
	else
	{
		printf("Enter the element:\n");
		scanf_s(" %c", &num);
		s.top = s.top + 1;
		s.stk[s.top] = num;
	}
	return;
}

int pop()
{
	int num;
	if (s.top == -1)
	{
		printf("Stack is empty!\n");
		return (s.top);
	}
	else
	{
		num = s.stk[s.top];
		printf("Poped element is = %dn", s.stk[s.top]);
		s.top = s.top - 1;
	}
	return(num);
}

void display()
{
	if (s.top == -1)
	{
		printf("Stack is empty!\n");
		return;
	}
	else
	{
		printf("\n Current stack \n");
		for (int i = s.top; i >= 0; i--)
		{
			printf("%c\n", s.stk[i]);
		}
	}
	printf("\n");
}

void check_parenthesis()
{
	if (s.top == -1)
	{
		printf("Stack is empty!\n");
		return;
	}

	int arr[MAXSIZE];
	memset(arr, -1, sizeof arr);
	printf("%d", arr[0]);
	int counter = 0;
	int j = 0;

	for (int i = s.top; i >= 0; i--)
	{
		if (s.stk[i] == '(') {
			counter++;
			arr[j] = i;
			j++;
			continue;
		}
		
		if (s.stk[i] == ')') {
			counter--;
			if (j > 0) {
				printf("Index of closed brackets (%d, %d)\n", arr[j - 1], i);
				j--;
			}
		}
	}

	if (counter == 0)
		printf("There are equal amount of left ( and right ) parenthesis! \n");
	else
		printf("The number of left and right parenthesis is not the same! \n");
}