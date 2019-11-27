#define _CRT_SECURE_NO_WARNINGS
#include "DblLinkedList.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void createList(tNode* head)
{
	tNode* current = head;
	/*
	 * так как список двусвязный, а не односвязный, то присваиваем
	 * пустоту указателю не только на следующий узел, но и на предыдущий
	 */
	current->next = current->prev = NULL;
}

void printList(tNode* head)
{
	tNode* current = head;
	if (current->next == NULL)
	{
		printf(ANSI_COLOR_YELLOW "The list of animals is empty.\n" ANSI_COLOR_RESET);
	}
	
	int num = 1;
	while (current->next != NULL)
	{
		printf("%d. ", num);
		printf("%s %f %d", current->kindOfAnimal, current->weight, current->age);
		printf("\n");

		current = current->next;
		num++;
	}
}

void push(tNode* head, const char KIND_OF_ANIMAL[], const double WEIGHT, const int AGE)
{
	tNode* current = head;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = (tNode*)malloc(sizeof(tNode));
	strcpy(current->kindOfAnimal, KIND_OF_ANIMAL);
	current->weight = WEIGHT;
	current->age = AGE;
	current->next->next = NULL;
	/*
	 * каждый следующий узел должен иметь указатель на предыдущий
	 */
	current->next->prev = current;
}

void pop(tNode** head)
{
	/*
	 * после создания первого пустого узла списка при помощи функции createList
	 * указатель на следующий узел равен NULL, таким образом можно определить,
	 * что в первый узел ещё ничего не добавлено
	 */
	if ((*head)->next == NULL) {
		printf(ANSI_COLOR_RED "Error!\n" ANSI_COLOR_RESET);
		return;
	}
	
	tNode* nextNode = (*head)->next;
	nextNode->prev = NULL;
	free(*head);
	*head = nextNode;
}

void deleteAllOddNodes(tNode** head)
{
	if ((*head)->next == NULL) {
		printf(ANSI_COLOR_RED "Error!\n" ANSI_COLOR_RESET);
		return;
	}
	
	/*
	 * Удаляем все нечетные узлы списка по следующему принципу:
	 * 1. записываем указатель на первый нечетный элемент
	 * 2. у следующего узла указатель на предыдущий узел(next->prev)меняем на указатель на предыдущий
	 * узел текущего(prev), а у прыдыдущего узла указатель на следующий узел(prev->next) меняем
	 * на указатель на следующий узел текущего(next)
	 * 3. сохраняем у текущего узла указатель на следующий узел во временный узел(temp), а затем
	 * очищаем текущий узел и присваиваем ему следующий узел при помощи временного узла
	 * 4. делаем переход к следующему узлу
	 */
	tNode* newHead = (*head)->next;
	while((*head)->next != NULL)
	{
		/*
		 * прежде, чем изменять указатель у следующего или препыдущего
		 * узла, проверяем, что они не пустые
		 */
		if ((*head)->next != NULL)
		{
			(*head)->next->prev = (*head)->prev;
		}
		if ((*head)->prev != NULL)
		{
			(*head)->prev->next = (*head)->next;
		}
		tNode* temp = (*head)->next;
		free(*head);
		*head = temp;
		/*
		 * после присвоения текущему узлу следующего, нужно ещё раз проверить,
		 * что следующий узел не пустой
		 */
		if ((*head)->next != NULL)
		{
			*head = (*head)->next;
		}
	}
	/*
	 * после удаления всех нечетных узлов указатель на текущий узел будет указывать
	 * на последний узел, поэтому нужно его вернуть в начало
	 */
	if (newHead != NULL)
	{
		*head = newHead;
	}
}