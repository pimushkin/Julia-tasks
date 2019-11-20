#include <stdlib.h>
#include <stdio.h>         
#include <time.h>  
#include "Node.h"

/*
 * глобальна€ константна€ переменна€, котора€ будет
 * задействована также и в исходном файле Node.c
 */
const int WRONG_FIGURE = 3;

int main()
{
	srand((unsigned int)time(NULL));
	
	tNode* head = NULL;
	head = (tNode*)malloc(sizeof(tNode));
	constructNode(head);

	char* tempValue = (char*)malloc(LENGTH_OF_VALUE * sizeof(char));
	for (int i = 0; i < 50; i++)
	{
		tempValue = generateValue();
		push(head, tempValue);
	}

	printf("Linked list:\n");
	printf("------------\n");
	printList(head);
	printf("\n\n");

	removeWrongValues(&head);

	printf("New linked list:\n");
	printf("----------------\n");
	printList(head);
	printf("\n");

	system("pause");

	return 0;
}