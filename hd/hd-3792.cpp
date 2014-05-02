#include <stdio.h>
#include <math.h>
#include <string.h>

int primes[100000];

void pr(int primes[], int *size)
{
	int count = 0;
	primes[count++] = 2;
	for (int i = 3; i < 100000; i += 2)
	{
		bool p = true;
		for (int j = 2; j <= sqrt(double(i)); ++j)
		{
			if (i % j == 0)
			{
				p = false;
				break;
			}
		}
		if (p)
			primes[count++] = i;
	}
	*size = count;
}

int diff(int primes[], int size, int N)
{
	int count = 0;
	for (int i = 1; i < size && primes[i] <= N; ++i)
	{
		if (primes[i] - primes[i-1] == 2)
			++count;
	}
	return count;
}

int main()
{
	//freopen("out.txt", "w", stdout);
	int size;
	int N;

	memset(primes, 0, sizeof(primes));
	pr(primes, &size);

	while(scanf("%d", &N) && N >= 0)
	{
		int cnt = diff(primes, size, N);
		printf ("%d\n", cnt);
	}
	/*for (int i = 0; i < size; ++i)
		printf("%d ", primes[i]);
	printf("\n");*/

	return 0;
}
