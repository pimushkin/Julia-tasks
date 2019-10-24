#include <stdio.h> // ���������� ��� ����� � ������
#include <stdlib.h> // ��� ������ � ������������ ������� � ������ ������� system

/*
 * ������� ��� ���������� ������� �� ����� ������ ������
 */
void* sortMatrix(int** matrix, int ROWS, int COLUMNS, int* vectorSum);

/*
 * ������� �� �������� ����� ������������ ������ �������
 */
int* calculateSumElementsVector(int **matrix, int CURRENT, int COLUMNS);

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
	 * ������� ������� ��� ������ ����������
	 * ������� � ���������� ������������ ������
	 */
	int** matrix = malloc(sizeof(int) * m);
	for (int i = 0; i < m; i++) {
		matrix[i] = malloc(sizeof(int) * n);
	}

	printf("Enter the matrix elements:\n");

	/*
	 * ��������� ���� ������� ����������
	 */
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf_s("%d", &matrix[i][j]);
		}
	}
	printf("\n\n");

	/*
	 * �������� ������ �� ���������� ������ ����
	 * ��������� ������ ������ �������
	 */
	int* vectorSum = malloc(sizeof(int) * m);

	/*
	 * ��������� � ��� ������ vectorSum �����
	 * ��������� ������ ������ �������
	 */
	for (int i = 0; i < m; i++)
	{
		vectorSum[i] = calculateSumElementsVector(matrix, i, n);
	}

	printf("Entered matrix with the sum of the elements of each row:\n");
	printf("--------------------------------------------------------\n");
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d\t", matrix[i][j]);
		}
		
		/*
		 * ��� �������� ������� �� �����
		 * ����� ����� ������ ������
		 */
		printf("|\t%d\n", vectorSum[i]);
	}
	printf("\n\n");
	
	/*
	 * ��������� ������� �� ������ �����
	 */
	sortMatrix(matrix,m, n, vectorSum);

	/*
	 * ������� �� ����� ���������� ��������������� �������
	 */
	printf("New sorted matrix:\n");
	printf("------------------\n");
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d\t", matrix[i][j]);
		}
		printf("|\t%d\n", vectorSum[i]); 
	}
	printf("\n");

	system("pause");
	return 0;
}

/*
 * ������� ��� ���������� ������� �� ����� ������ ������
 */ 
void* sortMatrix(int** matrix, const int ROWS, const int COLUMNS, int* vectorSum)
{
	/*
	 * ���������� ����� �������� ��� ����������
	 */
	for (int i = 0; i < ROWS - 1; i++)
	{
		for (int j = 0; j < ROWS - i - 1; j++)
		{
			/*
			 * ���� ����� ������� ������ ������
			 * ����� ���������, ��...
			 */
			if (vectorSum[j] > vectorSum[j + 1])
			{
				/*
				 * ...������ �� �������
				 */
				const int temp1 = vectorSum[j];
				vectorSum[j] = vectorSum[j + 1];
				vectorSum[j + 1] = temp1;

				/*
				 * � ����� ����� ������ � ������ ����� �������
				 */
				for (int k = 0; k < COLUMNS; k++)
				{
					const int temp2 = matrix[j][k];
					matrix[j][k] = matrix[j + 1][k];
					matrix[j + 1][k] = temp2;
				}
			}
		}
	}
}

/*
 * ������� �� �������� ����� ������������ ������ �������
 */
int* calculateSumElementsVector(int** matrix, const int CURRENT, const int COLUMNS)
{
	int sum = 0;
	for (int i = 0; i < COLUMNS; i++)
	{
		/*
		 * ���������� � ����� ����� ������
		 * ������� ��������� ������ �������
		 */
		sum += matrix[CURRENT][i];
	}
	return sum;
}