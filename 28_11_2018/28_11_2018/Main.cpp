#include <stdlib.h>
#include <stdio.h>

int containsSubstring(const char*bigstring, const char*substring)
{
	for (int i = 0; bigstring[i] != '\0'; i++)
	{
		if (bigstring[i] == substring[0])
		{
			for (int a = 0, j = i; bigstring[j] == substring[a]; a++, j++)
			{
				if (substring[a + 1] == '\0')
					return 1;
			}
		}
	}
	return 0;
}

int main()
{
	const char*word1 = "SrTomasin";
	const char*word2 = "Tomas";
	printf("%d\n", containsSubstring(word1, word2));
	system("pause");
	return 0;
}