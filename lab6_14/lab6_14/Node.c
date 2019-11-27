#include <stdlib.h>
#include <stdio.h>        
#include <stdbool.h>
#include <math.h> 
#include "Node.h"

/*
 * глобальна€ константна€ переменна€, котора€ будет
 * задействована также и в исходном файле Lab6.c
 */
const int LENGTH_OF_VALUE = 11;

void printList(tNode* head)
{
	tNode* current = head;
	
	int num = 1;
	while (current->next != NULL)
	{
		printf("%d. ", num);
		for (int i = 0; i < LENGTH_OF_VALUE; i++)
		{
			printf("%hhi", current->value[i]);
		}
		printf("\n");

		current = current->next;
		num++;
	}
}

void constructNode(tNode* head)
{
	tNode* current = head;

	current->next = NULL;
}

void push(tNode* head, const char* VALUE)
{
	tNode* current = head;

	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = (tNode*)malloc(sizeof(tNode));

	for (int i = 0; i < LENGTH_OF_VALUE; i++)
	{
		current->value[i] = VALUE[i];
	}

	current->next->next = NULL;
}

void removeWrongValues(tNode** head)
{
	tNode* current = (*head);

	bool flag1 = false;
	for (int i = 0; i < LENGTH_OF_VALUE; i++)
	{
		if (current->value[i] == WRONG_FIGURE)
		{
			flag1 = true;
			break;
		}
	}

	while (current->next != NULL)
	{
		bool flag2 = true;
		for (int i = 0; i < LENGTH_OF_VALUE; i++)
		{
			if (current->next->value[i] == WRONG_FIGURE)
			{
				current->next = current->next->next;
				flag2 = false;
				break;
			}
		}
		if (flag2)
		{
			current = current->next;
		}
	}
	if (flag1)
	{
		pop(head);
	}
}

int pop(tNode** head) {
	tNode* nextNode;
	if (*head == NULL) {
		printf("Error! You cannot remove an empty component.\n\n");
		return 1;
	}
	nextNode = (*head)->next;
	free(*head);
	*head = nextNode;

	return 0;
}

char* generateValue()
{
	char* value = (char*)malloc(LENGTH_OF_VALUE * sizeof(char));

	int random = rand() % 9000 + 1000;
	char* chRandom1 = toArray(random);
	for (int j = 0; j < 4; j++)
	{
		value[j] = chRandom1[j];
	}

	random = rand() % 9000 + 1000;
	chRandom1 = toArray(random);
	for (int j = 4; j < 8; j++)
	{
		value[j] = chRandom1[j - 4];
	}

	random = rand() % 900 + 100;
	char* chRandom2 = toArray(random);
	for (int j = 8; j < LENGTH_OF_VALUE; j++)
	{
		value[j] = chRandom2[j - 8];
	}

	return value;
}

char* toArray(int value)
{
	int n = (int)log10(value) + 1;
	char* numberArray = (char*)malloc(n * sizeof(char));
	for (int i = n - 1; i >= 0; i--, value /= 10)
	{
		numberArray[i] = value % 10;
	}
	return numberArray;
}