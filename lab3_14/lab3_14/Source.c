#include <stdio.h> // библиотека для ввода и вывода
#include <stdlib.h> // для работы с динамической памятью и вызова функции system

/*
 * функция для сортировки матрицы по сумме каждой строки
 */
void* sortMatrix(int** matrix, int ROWS, int COLUMNS, int* vectorSum);

/*
 * функция по подсчету суммы определенной строки матрицы
 */
int* calculateSumElementsVector(int **matrix, int CURRENT, int COLUMNS);

int main()
{
	int m; // количество строк
	int n; // количество столбцов

	printf("Enter the number of rows and columns of the matrix:\n");

	/*
	 * считываем число m и n с клавиатуры(количество строк и столбцов)
	 */
	scanf_s("%d", &m);
	scanf_s("%d", &n);
	printf("\n");

	/*
	 * создаем матрицу при помощи двумерного
	 * массива с выделением динамической памяти
	 */
	int** matrix = (int**)malloc(m * sizeof(int*));
	for (int i = 0; i < m; i++) {
		matrix[i] = (int*)malloc(n * sizeof(int));
	}

	printf("Enter the matrix elements:\n");

	/*
	 * заполняем нашу матрицу элементами
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
	 * выделяем память под одномерный массив сумм
	 * элементов каждой строки матрицы
	 */
	int* vectorSum = (int*)malloc(m * sizeof(int));

	/*
	 * добавляем в наш массив vectorSum сумму
	 * элементов каждой строки матрицы
	 */
	for (int i = 0; i < m; i++)
	{
		/*
		 * передаем в качестве второго аргумента
		 * фукнции calculateSumElementsVector
		 * текущее значение i, чтобы функция знала
		 * элементы какой строки надо суммировать
		 */
		vectorSum[i] = calculateSumElementsVector(matrix, i, n);
	}

	printf("Entered matrix with the sum of the elements of each row:\n");
	printf("--------------------------------------------------------\n");
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			/*
			 * для нормального вывода матрицы
			 * на экране добавим в конец строки \t,
			 * чтобы использовать табуляцию (пробел
			 * между каждым элементом)
			 */
			printf("%d\t", matrix[i][j]);
		}
		
		/*
		 * для удобства выводим на экран
		 * также сумму каждой строки
		 */
		printf("|\t%d\n", vectorSum[i]);
	}
	printf("\n\n");
	
	/*
	 * сортируем матрицу по суммам строк
	 */
	sortMatrix(matrix,m, n, vectorSum);

	/*
	 * выводим на экран полученную отсортированную матрицу
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

	/*
	 * освобождаем явным образом динимически выделенную
	 * память под матрицу и под сумму элементов каждой
	 * строки, так в дальнейшем она нам уже больше
	 * не понадобится, и делаем это при помощи функции free
	 */
	free(vectorSum);

	/*
	 * так как массив matrix является двумерным
	 * в отличии от vectorSum, то нужно не забыть
	 * также высвободить память под столбцы матрицы
	 */
	for (int i = 0; i < m; i++)
	{
		free(matrix[i]);
	}
	free(matrix);
	
	system("pause");
	return 0;
}

/*
 * функция для сортировки матрицы по сумме каждой строки
 */ 
void* sortMatrix(int** matrix, const int ROWS, const int COLUMNS, int* vectorSum)
{
	/*
	 * используем метод Пузырька для сортировки
	 */
	for (int i = 0; i < ROWS - 1; i++)
	{
		for (int j = 0; j < ROWS - i - 1; j++)
		{
			/*
			 * если сумма текущей строки больше
			 * суммы следующей, то...
			 */
			if (vectorSum[j] > vectorSum[j + 1])
			{
				/*
				 * ...меняем их местами
				 */
				const int temp1 = vectorSum[j];
				vectorSum[j] = vectorSum[j + 1];
				vectorSum[j + 1] = temp1;

				/*
				 * а затем также меняем и строки самой матрицы
				 */

				/*
				 * чтобы можно было поменять строки местами
				 * не по одному элементу ещё одним вложенным
				 * циклом, объявим temp как указатель
				 * (присваивая тем самым адрес на все
				 * элементы указанной строки матрицы)
				 */
				const int *temp2 = matrix[j];
				matrix[j] = matrix[j + 1];
				matrix[j + 1] = temp2;
			}
		}
	}
}

/*
 * функция по подсчету суммы определенной строки матрицы
 */
int* calculateSumElementsVector(int** matrix, const int CURRENT, const int COLUMNS)
{
	/*
	 * обязательно надо проинициализировать
	 * переменную sum как 0, так как мы
	 * прибавляем к ней другие значения,
	 * а не перезаписываем
	 */
	int sum = 0;

	for (int i = 0; i < COLUMNS; i++)
	{
		/*
		 * прибавляем к нашей сумме каждый
		 * элемент указанной строки матрицы
		 */
		sum += matrix[CURRENT][i];
	}
	/*
	 * чтобы записывать результат подсчитанной
	 * суммы строки в элемент массива vectorSum,
	 * используем оператор return
	 */
	return sum;
}