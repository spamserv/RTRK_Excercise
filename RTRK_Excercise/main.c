#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "linkedlist.h"


int main()
{
	struct node* HEAD = NULL;
	uint8_t switcher;
	int value;
	while (1)
	{
		printf("What do you want to do?\n");
		printf("Add to start of the list - 1\n");
		printf("Add to end of the list - 2\n");
		printf("Remove from list - 3\n");
		printf("Search in list - 4\n");
		printf("Reverse list - 5\n");
		printf("Print list - 6\n");
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
			printf("Enter a value to add to end of the list:\n");
			scanf_s("%d", &value);
			add_to_list(&HEAD, value, 1);
			break;
		case 3:
			printf("Enter a value to remove from the list:\n");
			scanf_s("%d", &value);
			remove_from_list(&HEAD, value);
			break;
		case 4:
			printf("Enter a value to check if it exists:\n");
			scanf_s("%d", &value);
			printf("Value %s", (search_in_list(&HEAD, value) != NULL) ? "exists!\n" : "does not exist!\n");
			break;
		case 5:
			reverse_list(&HEAD);
			printf("List has been reversed.\n");
			break;
		case 6:
			printf("Printing the list...\n");
			print_list(&HEAD);
			break;
		default:
			break;
		}
	}
	return 0;
}


