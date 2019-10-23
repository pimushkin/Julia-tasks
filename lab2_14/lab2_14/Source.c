#include <stdio.h> // ���������� ��� ����� � ������
#include <stdlib.h> // ��� ������ � ������������ ������� � ������ ������� system

/*
 * ������� ��� ���������� �������
 */
void* sortMatrix(int** Matrix, int ROWS, int COLUMNS);

/*
 * ������� ��� ������� ������ �������� � �������
 */
void* addElement(int** Matrix, int ROWS, int *COLUMNS, int NEW_ELEMENT);

/*
 * ������� ��� �������� ����� ��������� �� ��������� �������
 */
int* countDiagonalSum(int** Matrix, int ROWS, int COLUMNS);

int main()
{
	int m; // ���������� �����
	int n; // ���������� ��������
	
	printf("Enter the number of rows and columns of the matrix:\n");
	
	/*
	 * ��������� ����� m � n � ����������(���������� ����� � ��������)
	 */
	scanf_s("%d", &m);
	scanf_s("%d", &n);
	printf("\n");

	/*
	 * ������� ����������� ������� ��� ������
	 * ���������� ������� � ���������� ������������ ������
	 */
	int** Matrix = malloc(sizeof(int) * m);
	for (int i = 0; i < m; i++) {
		Matrix[i] = malloc(sizeof(int) * (n + 1));
	}
	
	printf("Enter the matrix elements:\n");

	/*
	 * ��������� ���� ������� ����������
	 */
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf_s("%d", &Matrix[i][j]);
		}
	}
	printf("\n\n");

	/*
	 * ���������� ������ ���������� ��� ����� ����������� �������
	 */
	sortMatrix(Matrix, m, n);
	
	printf("Sorted matrix:\n");
	printf("--------------\n");

	/*
	 * ������� �� ����� ���������� ��������������� �������
	 */
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d\t", Matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");

	/*
	 * ������ �������� � ���������� �������� �
	 * ��������� ����� ������� � ������ ������ �������
	 */

	int newElement; // ����� ������� �������, ������� ��������� � ������ ������
	printf("Enter the item you want to add to each row of the matrix.:\n");
	scanf_s("%d", &newElement);
	printf("\n\n");

	/*
	 * �������� ������� addElement �� ���������� ������ �������� � �������
	 */
	addElement(Matrix, m, &n, newElement);
	
	printf("New matrix:\n");
	printf("-----------\n");
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d\t", Matrix[i][j]); // ������� �������� ���������� ����� �������
		}
		printf("\n");
	}
	printf("\n\n");

	/*
	 * ������������ ����� ��������� �� ���������
	 * �������, � ���� ��� �� ����������, �� � sum
	 * ���������� �������(�������� NULL)
	 */
	const int* sum = countDiagonalSum(Matrix, m, n);

	/*
	 * ���� ����� ���� ����������, ��
	 * ������� �� ����� ���������� �����
	 */
	if (sum != NULL)
	{
		printf("Diagonal sum of elements = %d.", sum);
		printf("\n\n");
	}

	system("pause");
	return 0;
}

/*
 * ���������� ������� ������� ��������(������� ����������,
 * ����� �� ����������� ��� ������� ��� ������ ������)
 */
void* sortMatrix(int** Matrix, const int ROWS, const int COLUMNS)
{
	for (int k = 0; k < ROWS; k++)
	{
		/*
		 * ��� ��� ��� ����� ������������� ������ ������ ���������� ����
		 * �� �����, �� ���������� ��������� ������ �������� ���������
		 */

		/*
		 * �������� �������, ����� �� ����� �� ������� ������� �� ����� ����������
		 */
		for (int i = 0; i < COLUMNS - 1; i++)
		{
			for (int j = 0; j < COLUMNS - i - 1; j++)
			{
				/*
				 * ���� ������� ������� ������ ������� ������
				 * ����������, �� ������ �� �������
				 */
				if (Matrix[k][j] > Matrix[k][j + 1])
				{
					const int temp = Matrix[k][j];
					Matrix[k][j] = Matrix[k][j + 1];
					Matrix[k][j + 1] = temp;
				}
			}
		}
	}
}

/*
 * ������� �� ���������� ������ ���������� � ������ ������ �������
 */
void* addElement(int** Matrix, const int ROWS, int *COLUMNS, const int NEW_ELEMENT)
{
	for (int i = 0; i < ROWS; i++)
	{
		Matrix[i][*COLUMNS] = NEW_ELEMENT;
	}

	/*
	 * ����������� ���������� �������� � ������� �� �������
	 */
	*COLUMNS = *COLUMNS + 1;

	/*
	 * ����� ���������� ������ �������� � ����� ������ ������
	 * �������, �� ��������� ���� ������� �� �����
	 */
	sortMatrix(Matrix, ROWS, *COLUMNS);
}

/*
 * ������� ��� �������� ����� ��������� �� ��������� �������(���� ��� ������������)
 */
int* countDiagonalSum(int** Matrix, const int ROWS, const int COLUMNS)
{
	/*
	 * ���������, ����� ���������� �����
	 * � �������� ���� ���������� (�� ����
	 * ������� ���� ����������)
	 */
	if (ROWS == COLUMNS)
	{
		int sum = 0;
		int i = 0;
		int j = 0;
		for (; i < ROWS; i++, j++)
		{
			sum += Matrix[i][j];
		}

		/*
		 * �������� return ��������� ���������� ������� �
		 * ���������� ���������� ���������� �������,
		 * ������� return NULL ���� ����� ��������� 
		 * ��������� if �� ���������
		 */
		return sum;
	}

	/*
	 * ���� � ��� �� ���������� �������, ��
	 * ������� ���������� NULL(�� ���� �������)
	 */
	return NULL;
}