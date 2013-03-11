#include <stdio.h>
#include <string.h>
#include <algorithm>

char a[2000], b[2000], sum[2000], aa[2000], bb[2000];

int main()
{
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; ++i)
	{
		scanf("%s %s", aa, bb);
		int a_size = strlen(aa);
		int b_size = strlen(bb);

		memcpy(a, aa, sizeof(aa));
		memcpy(b, bb, sizeof(bb));

		// 先Reverse，然后相加
		int c = 0;
		int tmp;
		std::reverse(a, a+a_size);
		std::reverse(b, b+b_size);

		int j;
		int max = a_size > b_size ? a_size : b_size;
		for (j = 0; j < max; ++j)
		{
			if (j >= a_size)
				a[j] = '0';
			if (j >= b_size)
				b[j] = '0';

			tmp = ((a[j] - '0') + (b[j] - '0') + c);
			if (tmp >= 10)
			{
				tmp -= 10;
				c = 1;
			}
			else
				c = 0;
			sum[j] = '0' + tmp;
		}
		if (c == 1)
			sum[j++] = c + '0';
		std::reverse(sum, sum+j);
		printf("Case %d:\n%s + %s = ", i+1, aa, bb);
		for (int k = 0; k < j; ++k)
			printf("%c", sum[k]);
		printf("\n");
		if (i != T-1)
			printf("\n");
	}

	return 0;
}
