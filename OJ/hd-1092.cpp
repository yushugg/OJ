#include <stdio.h>

int main()
{
	int N;
	while (scanf("%d", &N) && N != 0)
	{
		int sum = 0;
		int in;
		for (int i = 0; i < N; ++i)
		{
			scanf("%d", &in);
			sum += in;
		}
		printf("%d\n", sum);
	}

	return 0;
}
