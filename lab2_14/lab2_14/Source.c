#include <stdio.h> // библиотека для ввода и вывода
#include <stdlib.h> // для работы с динамической памятью и вызова функции system

/*
 * фукнция для сортировки матрицы
 */
void* sortMatrix(int** Matrix, int ROWS, int COLUMNS);

/*
 * функция для вставки нового элемента в матрицу
 */
void* addElement(int** Matrix, int ROWS, int *COLUMNS, int NEW_ELEMENT);

/*
 * функция для подсчёта суммы элементов по диагонали матрицы
 */
int* countDiagonalSum(int** Matrix, int ROWS, int COLUMNS);

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
	 * создаем изначальную матрицу при помощи
	 * двумерного массива с выделением динамической памяти
	 */
	int** Matrix = malloc(sizeof(int) * m);
	for (int i = 0; i < m; i++) {
		Matrix[i] = malloc(sizeof(int) * (n + 1));
	}
	
	printf("Enter the matrix elements:\n");

	/*
	 * заполняем нашу матрицу элементами
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
	 * производим первую сортировку для нашей изначальной матрицы
	 */
	sortMatrix(Matrix, m, n);
	
	printf("Sorted matrix:\n");
	printf("--------------\n");

	/*
	 * выводим на экран полученную отсортированную матрицу
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
	 * теперь работаем с полученной матрицей и
	 * добавляем новый элемент в каждую строку матрицы
	 */

	int newElement; // новый элемент матрицы, который добавляем в каждую строку
	printf("Enter the item you want to add to each row of the matrix.:\n");
	scanf_s("%d", &newElement);
	printf("\n\n");

	/*
	 * вызываем функцию addElement по добавлению нового элемента в матрицу
	 */
	addElement(Matrix, m, &n, newElement);
	
	printf("New matrix:\n");
	printf("-----------\n");
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d\t", Matrix[i][j]); // выводим элементы полученной новой матрицы
		}
		printf("\n");
	}
	printf("\n\n");

	/*
	 * подсчитываем сумму элементов по диагонали
	 * матрицы, и если она не квадратная, то в sum
	 * передается пустота(значение NULL)
	 */
	const int* sum = countDiagonalSum(Matrix, m, n);

	/*
	 * если сумма была подсчитана, то
	 * выводим на экран полученную сумму
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
 * сортировка матрицы методом Пузырька(немного измененным,
 * чтобы не сортировать всю матрицу как единую строку)
 */
void* sortMatrix(int** Matrix, const int ROWS, const int COLUMNS)
{
	for (int k = 0; k < ROWS; k++)
	{
		/*
		 * так как нам нужно отсортировать каждую строку независимо друг
		 * от друга, то количество вложенных циклов придется увеличить
		 */

		/*
		 * вычитаем единицу, чтобы не выйти за пределы массива во время сортировки
		 */
		for (int i = 0; i < COLUMNS - 1; i++)
		{
			for (int j = 0; j < COLUMNS - i - 1; j++)
			{
				/*
				 * если текущий элемент строки матрицы больше
				 * следующего, то меняем их местами
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
 * функция по добавлению нового элеменента в каждую строку матрицы
 */
void* addElement(int** Matrix, const int ROWS, int *COLUMNS, const int NEW_ELEMENT)
{
	for (int i = 0; i < ROWS; i++)
	{
		Matrix[i][*COLUMNS] = NEW_ELEMENT;
	}

	/*
	 * увеличиваем количество столбцов в матрице на единицу
	 */
	*COLUMNS = *COLUMNS + 1;

	/*
	 * после добавления нового элемента в конец каждой строки
	 * матрицы, мы сортируем нашу матрицу по новой
	 */
	sortMatrix(Matrix, ROWS, *COLUMNS);
}

/*
 * функция для подсчёта суммы элементов по диагонали матрицы(если она квадратичная)
 */
int* countDiagonalSum(int** Matrix, const int ROWS, const int COLUMNS)
{
	/*
	 * проверяем, чтобы количество строк
	 * и столбцов было одинаковое (то есть
	 * матрица была квадратная)
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
		 * оператор return завершает выполнение функции и
		 * возвращает управление вызывающей функции,
		 * поэтому return NULL ниже после условного 
		 * оператора if не сработает
		 */
		return sum;
	}

	/*
	 * если у нас не квадратная матрица, то
	 * функция возвращает NULL(то есть пустоту)
	 */
	return NULL;
}