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

}

int main()
{
	exercise1();
	system("pause");
	return 0;
}