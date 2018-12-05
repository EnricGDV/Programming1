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

int stringsAreEqual(char string1 [], char string2 [])
{
	for (int i = 0; string1[i] == string2[i]; i++)
	{
		if (string1[i] == '\0' || string2[i] == '\0')
			return 1;
	}
	return 0;
}

void exercise3()
{
	FILE *file = fopen("adding_file.txt", "a");
	if (file != nullptr)
	{
		char buffer[32];
		char end[] = "end";
		while (stringsAreEqual(buffer, end) != 1) 
		{
			printf("Introduce a word: ");
			scanf_s("%s", buffer, sizeof(buffer));
			fprintf(file, "%s\n", buffer);
		}
	}
}

struct Enemy {
	char name[16];
	float x, y;
	int health;
};
Enemy Kim = { "Kim", 3.5, 0.4, 10 };
Enemy Trixie = { "Trixie", 1.0, 1.0, 5 };
Enemy Katya = { "Yekaterina", 10.0, 4.0, 8 };

void exercise4(int enemynum, Enemy group [])
{
	FILE *file = fopen("Enemies.txt", "w");
	if (file != nullptr)
	{
		for (int i = 0; i < enemynum; i++)
		{
			fprintf(file, "%s %f %f %d\n", group[i].name, group[i].x, group[i].y, group[i].health);
		}
		fclose(file);
	}
}

void exercise5(int enemynum, Enemy group [])
{
	Enemy buffer{};
	FILE *file = fopen("Enemies.txt", "r");
	if (file != nullptr)
	{
		for (int i = 0; i < enemynum; i++)
		{
			fread(buffer, "%s %f %f %d", group[i].name, group[i].x, group[i].y, group[i].health);
			group[i]
		}
		fclose(file);
	}
}

int main()
{
	exercise1();
	exercise2();
	char string[] = "hello_world_of_files.txt";
	exercise6(string);
	exercise7(string);
	//exercise3();

	Enemy group[] = { Kim, Trixie, Katya };
	exercise4(3, group);

	system("pause");
	return 0;
}