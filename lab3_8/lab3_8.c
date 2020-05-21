#define _CRT_SECURE_NO_WARNINGS
#include <malloc.h>
#include <stdio.h>
#include <direct.h>
#include <locale.h>
#include <stdlib.h>
int main() {
	setlocale(LC_ALL, "");
	printf("Программа начала работу\n");
#pragma region Declaring vars
	FILE* file_input;
	FILE* file_output;
	int size = 10, counter = 0;
	char* nums = malloc(sizeof(char) * size);
	char buffer;
#pragma endregion
	// Открываем фалы, выводим сообщение об ошибке если не получилось
#pragma region Open files
	if ((file_input = fopen("INPUT.TXT", "r")) == 0) {
		printf("Возникла ошибка открытия файла INPUT.TXT");
		return;
	}
	if ((file_output = fopen("OUTPUT.TXT", "w")) == 0) {
		printf("Возникла ошибка открытия файла OUTPUT.TXT");
		return;
	}
#pragma endregion
	// Читаем файл пока не наткнемся на конец
	while (fscanf(file_input, "%c", &buffer) != EOF) {
		// Если дошли до конца строки вписываем все цифры котрые встретили в этой строки и переходим на следующую строку
		if (buffer == '\n') {
			for (size_t i = 0; i < counter; i++)
			{
				fprintf(file_output, "%c", nums[i]);
			}
			fprintf(file_output, "\n");
			counter = 0;
		}
		// Если символ в буффере не цифра то сразу переписываем в file_ouput
		else if (buffer < '0'|| buffer > '9') {
			fprintf(file_output, "%c", buffer);
		}
		// Если цифра кладем в массив
		else {
			nums[counter++] = buffer;
			//nums[counter++]=buffer; удобней в написании чем nums[counter]=buffer; counter++;
		}
		// Если в массив перестают помещаться цифры увеличиваем его в полтора раза
		if (counter + 1 == size)nums = realloc(nums, (size *= 1.5));
	}
	// Выводим цифры из последней строки
	for (size_t i = 0; i < counter; i++)
	{
		fprintf(file_output, "%c", nums[i]);
	}
	//Освобождаем память
#pragma region Free up memory
	fclose(file_input);
	fclose(file_output);
	free(nums);
#pragma endregion
	printf("Работа окончена.");
	return 0;
}