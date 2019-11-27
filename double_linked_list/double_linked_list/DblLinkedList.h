#pragma once
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_RESET "\x1b[0m"
typedef struct node
{
	struct node* prev;
	struct node* next;
	char kindOfAnimal[20];
	double weight;
	int age;
} tNode;

void createList(tNode* head);
void printList(tNode* head);
void push(tNode* head, const char KIND_OF_ANIMAL[], const double WEIGHT, const int AGE);
void pop(tNode** head);
void deleteAllOddNodes(tNode** head);