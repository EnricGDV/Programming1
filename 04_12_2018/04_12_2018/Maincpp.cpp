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

void exercise5()
{
	Enemy buffer1{};
	Enemy buffer2{};
	Enemy buffer3{};
	FILE *file = fopen("Enemies.txt", "r");
	if (file != nullptr)
	{
		fscanf(file, "%s%f%f%d", buffer1.name, &buffer1.x, &buffer1.y, &buffer1.health, sizeof(buffer1.x), sizeof(buffer1.y), sizeof(buffer1.y));
		fscanf(file, "%s%f%f%d", buffer2.name, &buffer2.x, &buffer2.y, &buffer2.health, sizeof(buffer2.x), sizeof(buffer2.y), sizeof(buffer2.y));
		fscanf(file, "%s%f%f%d", buffer3.name, &buffer3.x, &buffer3.y, &buffer3.health, sizeof(buffer3.x), sizeof(buffer3.y), sizeof(buffer3.y));

		fclose(file);
	}
}

void exercise8()
{
	char buffer[120];
	FILE *file1 = fopen("Enemies.txt", "rb");
	if (file1 != nullptr)
	{
		for (int i = 0; i <= 3; i++)
		{
			fgets(buffer, 32, file1);
			if (i == 0) 
			{
				FILE *file2 = fopen("New.txt", "wb");
				if (file2 != nullptr)
				{
					fprintf(file2, "%s", buffer);
					fclose(file2);
				}
			}
			else
			{
				FILE *file2 = fopen("New.txt", "ab");
				if (file2 != nullptr)
				{
					fprintf(file2, "%s", buffer);
					fclose(file2);
				}
			}
		}
		fclose(file1);
	}
}

void exercise9()
{
	FILE *file = fopen("hello_world_of_files.txt", "rb");
	if (file != nullptr)
	{
		
	}
}

void exercise10()
{
	char buffer[320];
	FILE *file1 = fopen("hello_world_of_files.txt", "r");
	if (file1 != nullptr)
	{
		for (int i = 1; i <= 10; i++)
		{
			fgets(buffer, 32, file1);

			if (i == 1)
			{
				FILE *file3 = fopen("Merge.txt", "w");
				if (file3 != nullptr)
				{
					fprintf(file3, "%s", buffer);
					fclose(file3);
				}
			}
			else
			{
				FILE *file3 = fopen("Merge.txt", "a");
				if (file3 != nullptr)
				{
					fprintf(file3, "%s", buffer);
					fclose(file3);
				}
			}
		}
		fclose(file1);
	}

	FILE *file2 = fopen("Enemies.txt", "r");
	if (file2 != nullptr)
	{
		for (int i = 0; i <= 3; i++)
		{
			fgets(buffer, 32, file2);

			FILE *file3 = fopen("Merge.txt", "a");
			if (file3 != nullptr)
			{
				fprintf(file3, "%s", buffer);
			}

			fclose(file3);
		}
		fclose(file2);
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
	exercise5();

	exercise8();
	exercise10();

	system("pause");
	return 0;
}