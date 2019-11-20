#pragma once
/*
 * ���������� ����������������� ���� (� �������������
 * ����� typedef), ���������� ���������� (2-�� ����� ����)
 */
typedef struct Node
{
	struct Node* next;
	char value[11];
} tNode; // tNode - ����� ��� ����������������� ����(�� ���� �������� Node)

/*
 * ���������� ����������� ����������, ���������� ����������� (2-�� ����� ����)
 *
 * ������������� extern ��������� �������� ����������, �� ��������� ��,
 * �� ��������, ��� ���������� ��������� ���-�� � ������ �����
 *
 * ������ ������������� ����� ������ ���������� ����������
 */
extern const int LENGTH_OF_VALUE, WRONG_FIGURE;

void printList(tNode* head);
void constructNode(tNode* head);
void push(tNode* head, const char* VALUE);
void removeWrongValues(tNode** head);
int pop(tNode** head);
char* generateValue();
char* toArray(int value);