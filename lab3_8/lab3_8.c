#define _CRT_SECURE_NO_WARNINGS
#include <malloc.h>
#include <stdio.h>
#include <direct.h>
#include <locale.h>
#include <stdlib.h>
int main() {
	setlocale(LC_ALL, "");
	printf("��������� ������ ������\n");
#pragma region Declaring vars
	FILE* file_input;
	FILE* file_output;
	int size = 10, counter = 0;
	char* nums = malloc(sizeof(char) * size);
	char buffer;
#pragma endregion
	// ��������� ����, ������� ��������� �� ������ ���� �� ����������
#pragma region Open files
	if ((file_input = fopen("INPUT.TXT", "r")) == 0) {
		printf("�������� ������ �������� ����� INPUT.TXT");
		return;
	}
	if ((file_output = fopen("OUTPUT.TXT", "w")) == 0) {
		printf("�������� ������ �������� ����� OUTPUT.TXT");
		return;
	}
#pragma endregion
	// ������ ���� ���� �� ��������� �� �����
	while (fscanf(file_input, "%c", &buffer) != EOF) {
		// ���� ����� �� ����� ������ ��������� ��� ����� ������ ��������� � ���� ������ � ��������� �� ��������� ������
		if (buffer == '\n') {
			for (size_t i = 0; i < counter; i++)
			{
				fprintf(file_output, "%c", nums[i]);
			}
			fprintf(file_output, "\n");
			counter = 0;
		}
		// ���� ������ � ������� �� ����� �� ����� ������������ � file_ouput
		else if (buffer < '0'|| buffer > '9') {
			fprintf(file_output, "%c", buffer);
		}
		// ���� ����� ������ � ������
		else {
			nums[counter++] = buffer;
			//nums[counter++]=buffer; ������� � ��������� ��� nums[counter]=buffer; counter++;
		}
		// ���� � ������ ��������� ���������� ����� ����������� ��� � ������� ����
		if (counter + 1 == size)nums = realloc(nums, (size *= 1.5));
	}
	// ������� ����� �� ��������� ������
	for (size_t i = 0; i < counter; i++)
	{
		fprintf(file_output, "%c", nums[i]);
	}
	//����������� ������
#pragma region Free up memory
	fclose(file_input);
	fclose(file_output);
	free(nums);
#pragma endregion
	printf("������ ��������.");
	return 0;
}