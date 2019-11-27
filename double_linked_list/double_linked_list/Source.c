#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include "DblLinkedList.h"

int main()
{
	tNode* head;
	head = (tNode*)malloc(sizeof(tNode));
	createList(head);
	
	int numOfAnimals;
	char kindOfAnimals[20];
	float weight;
	int age;

	while(1)
	{
		printf("Choose an option:\n");
		printf("-----------------\n");
		printf("1) Push new animal(s);\n");
		printf("2) Pop animal;\n");
		printf("3) Delete all animals with an odd sequence number;\n");
		printf("0) Exit.\n\n");
		const int option = _getch();
		switch (option)
		{
		case '1':
			printf("Enter the number of animals: ");
			scanf("%d", &numOfAnimals);
			printf("Enter the kind, weight and age of animal(s):\n");
			for (int i = 0; i < numOfAnimals; i++)
			{
				scanf("%s %f %d", kindOfAnimals, &weight, &age);
				push(head, kindOfAnimals, weight, age);
			}
			printf("\n");
			printList(head);
			break;
		case '2':
			pop(&head);
			printList(head);
			break;
		case '3':
			deleteAllOddNodes(&head);
			printList(head);
			break;
		case '0':
			system("pause");
			return 0;
		default:
			printf(ANSI_COLOR_RED "Wrong option!\n" ANSI_COLOR_RESET);
			
		}
		printf("\n");
	}
}