#include <stdio.h>

int main()
{
	int N;

	while (scanf("%d", &N) != EOF)
	{
		int sum = 0;
		int tmp;
		for (int i = 0; i < N; ++i)
		{
			scanf("%d", &tmp);
			sum += tmp;
		}
		printf("%d\n", sum);
	}

	return 0;
}
