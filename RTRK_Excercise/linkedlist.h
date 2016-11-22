#pragma once
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

struct node* initialize_list(struct node **HEAD, int val);
struct node* add_to_list(struct node **HEAD, int val, uint8_t add_to_end);
void remove_from_list(struct node **HEAD, int val);
struct node* search_in_list(struct node **HEAD, int val);
void reverse_list(struct node **HEAD);
void print_list(struct node **HEAD);