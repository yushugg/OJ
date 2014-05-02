#include <stdio.h>

int main()
{
	int N, M;

	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &M);
		int sum = 0;
		int tmp;
		for (int j = 0; j < M; ++j)
		{
			scanf("%d", &tmp);
			sum += tmp;
		}

		printf("%d\n", sum);
		if (i != N-1)
			printf("\n");
	}

	return 0;
}
