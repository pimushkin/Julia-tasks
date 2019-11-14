#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*
 * функция по замене символов строки с нижнего регистра на верхний
 */
void* changeToUppercase(char* string, int* counterSentences);

int main()
{
	/*
	 * открытаем два текстовых файла(первый на чтение, а второй на запись)
	 */
	FILE* in, * out;
	in = fopen("input.txt", "r");
	out = fopen("output.txt", "w");

	/*
	 * переменная для хранения считанной строки
	 * из файла input.txt при помощи функции fgets
	 */
	char string[10000];
	/*
	 * счетчик количества строк, записанных в файл output.txt
	 */
	int counterSentences = 0;

	while (counterSentences != 5)
	{
		/*
		 * считываем строку из файла input.txt
		 */
		fgets(string, sizeof string, in);
		/*
		 * меняем в ней малые буквы на большие
		 */
		changeToUppercase(string, &counterSentences);
		/*
		 * записываем новую строку в файл output.txt
		 */
		fprintf(out, "%s", string);
		/*
		 * проверяем, что не достигли конца файла input.txt,
		 * и если достигли, то перестаем работать с файлами
		 */
		if (feof(in))
		{
			break;
		}
	}

	/*
	 * закрываем оба файла
	 */
	fclose(in);
	fclose(out);

	return 0;
}

void* changeToUppercase(char* string, int* counterSentences)
/*
 * так как уже существующая функция toupper не может
 * работать с украинским алфавитом, то придется это
 * делать вручную
 */
{
	char* uppercase = "АБВГҐДЕЄЖЗИІЇЙКЛМНОПРСТУФХЦЧШЩЬЮЯ";
	char* lowercase = "абвгґдеєжзиіїйклмнопрстуфхцчшщьюя";
	/*
	 * замену букв осуществляем посимвольно
	 */
	for (char* symbol = string; *symbol != '\0'; symbol++)
	{
		/*
		 * записываем указатель на текущую букву из алфавита малых букв
		 *
		 * если буква не из украинского алфавита или уже является
		 * большой и украинской, то записываем NULL(пустоту)
		 */
		char* pointer = strchr(lowercase, *symbol);
		/*
		 * проверяем, что указатель получилось записать (то есть символ
		 * является буквой из украинского алфавита)
		 */
		if (pointer != NULL)
			/*
			 * меняем указатель на букву из алфавита малых букв на указатель из больших
			 */
			*symbol = uppercase[pointer - lowercase];
		else // если символ не из украниского алфавита
			/*
			 * используем существующую функцию toupper по замене
			 * малой буквы на большую букву
			 */
			*symbol = toupper(*symbol);
		/*
		 * проверяем, что достигли конца предложения(точки с последующим
		 * пробелом, табуляции или символом новой строки)
		 */
		if ((*symbol == '.' && *(symbol + 1) == ' ') || *symbol == '\t' || *symbol == '\n')
		{
			(*counterSentences)++;
		}

		/*
		 * если считали уже 5 предложений
		 */
		if (*counterSentences == 5)
		{
			/*
			 * ставим на место следующего символа(в конец предложения) символ
			 * конца строки, чтобы не записывать в файл оставшуюся часть
			 * не фармитированной строки
			 */
			*(symbol + 1) = '\0';
			break;
		}
	}
}