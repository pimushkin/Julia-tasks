#pragma once
/*
 * объявление пользовательского типа (с наименованием
 * через typedef), являющийся глобальным (2-ой пункт лабы)
 */
typedef struct Node
{
	struct Node* next;
	char value[11];
} tNode; // tNode - новое имя пользовательского типа(то есть структры Node)

/*
 * объявление константных переменных, являющихся глобальными (2-ой пункт лабы)
 *
 * использование extern позволяет объявить переменную, не определяя ее,
 * он сообщает, что переменная находится где-то в другом месте
 *
 * внутри заголовочного файла нельзя определять переменные
 */
extern const int LENGTH_OF_VALUE, WRONG_FIGURE;

void printList(tNode* head);
void constructNode(tNode* head);
void push(tNode* head, const char* VALUE);
void removeWrongValues(tNode** head);
int pop(tNode** head);
char* generateValue();
char* toArray(int value);