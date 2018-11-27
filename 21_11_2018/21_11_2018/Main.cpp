#include <stdlib.h>
#include <stdio.h>

int containsWord(const char*sentence, const char*word)
{
	for (int i = 0; sentence[i] != '\0'; i++)
	{
		if (sentence[i] == word[0])
		{
			for (int a = 0, j = i; sentence[j] == word[a]; a++, j++)
			{
				if (word[a+1] == '\0')
					return 1;
			}
		}
	}
	return 0;
}

void exercise1()
{
	const char*sentence = "Hola me llamo Ralph";
	const char*word = "llamo";
	printf("%d\n", containsWord(sentence, word));
}

void exercise2()
{
	int bitmask5 = (1 << 7) | (1 << 4) | 1;
	int bitmask6 = (1 << 6) | (1 << 4) | (1 << 2) | 1;
	int bitmask7 = ~(1 << 7);
	int bitmask8 = ~((1 << 7) | (1 << 3));
}

void exercise3()
{
	int var1 = 6;
	int var2 = 54;
	int var3 = 38;
	int var4 = 98;

	var1 = var1 | (1 | (1<<4));
	var2 = var2 ^ ((1 << 3) | (1 << 7));
	var3 = var3 & (1 << 5);
	var4 = var4 ^~ ((1 << 2) | (1 << 6));
}

int main()
{
	exercise1();
	exercise2();
	exercise3();
	system("pause");
	return 0;
}