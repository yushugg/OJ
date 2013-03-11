#include <stdio.h>

int main()
{
	int M, N;
	scanf("%d", &N);

	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &M);

		int sum = 0;
		for (int j = 0; j < M; ++j)
		{
			int tmp;
			scanf("%d", &tmp);
			sum += tmp;
		}
		printf("%d\n", sum);
	}

	return 0;
}
