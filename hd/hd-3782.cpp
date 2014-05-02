#include <stdio.h>

int main()
{
	int N;

	while (scanf("%d", &N) && N != 0)
	{

		//core
		int count = 0;
		while (N != 1)
		{
			if (N % 2 == 0)
			{
				N /= 2;
			}
			else
			{
				N = (3*N + 1) / 2;
			}
			++count;
		}
		printf("%d\n", count);
	}

	return 0;
}
