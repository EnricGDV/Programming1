#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num = 3;

	printf("%i\n", &num);
	int *ptrnum = &num;
	printf("%i\n", ptrnum);
	printf("%i\n", *ptrnum);
	*ptrnum = 5;

	system("pause");
	return 0;
}