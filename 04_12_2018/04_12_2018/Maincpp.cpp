#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void exercise1()
{
	FILE *file = fopen("hello_world_of_files.txt", "w");
	if (file != nullptr)
	{
		for (int i = 1; i <= 10; i++)
		{
			fprintf(file, "%s %d!\n", "Hello, world of files", i);
		}
		fclose(file);
	}
}

void exercise2()
{
	char buffer[32];
	FILE *file = fopen("hello_world_of_files.txt", "r");
	if (file != nullptr)
	{
		for (int i = 1; i<=10 ; i++)
		{
			fgets(buffer, 32, file);
			printf("%s", buffer);
		}
		fclose(file);
	}
}

void exercise6(char filename[])
{
	int words = 0;
	FILE *file = fopen(filename, "r");
	if (file != nullptr)
	{
		while ( feof(file) == 0)
		{
			char i = fgetc(file);
			if (i == '\n' || i == '\0' || i == ' ')
				words++;
		}
		fclose(file);
	}
	printf("%d\n", words);
}

void exercise7(char filename[])
{
	int chars = 0;
	FILE *file = fopen(filename, "r");
	if (file != nullptr)
	{
		while (feof(file) == 0)
		{
			fgetc(file);
			chars++;
		}
		fclose(file);
	}
	printf("%d\n", chars);
}

int main()
{
	exercise1();
	exercise2();
	char string[] = "hello_world_of_files.txt";
	exercise6(string);
	exercise7(string);
	system("pause");
	return 0;
}