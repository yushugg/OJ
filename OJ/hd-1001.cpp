#include <stdio.h>

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int N;
	//int sum = 0;

	/*if (scanf("%d", &N) != EOF)
	{
	for (int i = 1; i <= N; ++i)
	sum += i;*/
	//printf("%d\n", sum);
	while (scanf("%d", &N) != EOF)
	{
		//printf("\n");
		int sum = 0;
		for (int i = 1; i <= N; ++i)
			sum += i;
		printf("%d\n\n", sum);
	}
	//}

	return 0;
}
