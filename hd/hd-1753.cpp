#include <stdio.h>
#include <string.h>
#include <algorithm>

char a[500], b[500];
char a_int[500], a_dec[500];
char b_int[500], b_dec[500];
char sum_int[500], sum_dec[500];
int sum_int_size, sum_dec_size;

int main()
{
	while (scanf("%s %s", a, b) != EOF)
	{
		sscanf(a, "%[^.].%s", a_int, a_dec);
		sscanf(b, "%[^.].%s", b_int, b_dec);

		int a_int_size = strlen(a_int);
		int a_dec_size = strlen(a_dec);
		int b_int_size = strlen(b_int);
		int b_dec_size = strlen(b_dec);

		/*printf("a_int: %s\t%d\na_dec: %s\t%d\nb_int: %s\t%d\nb_dec: %s\t%d\n",
			a_int, a_int_size, a_dec, a_dec_size, b_int, b_int_size, b_dec, b_dec_size);*/

		std::reverse(a_int, a_int+a_int_size);
		std::reverse(a_dec, a_dec+a_dec_size);
		std::reverse(b_int, b_int+b_int_size);
		std::reverse(b_dec, b_dec+b_dec_size);

		int c = 0;
		int i;
		for (i = 0; i < std::max(a_int_size, b_int_size); ++i)
		{
			if (i >= a_int_size)
				a_int[i] = '0';
			if (i >= b_int_size)
				b_int[i] = '0';

			int tmp = c + (a_int[i] - '0') + (b_int[i] - '0');
			if (tmp >= 10)
			{
				tmp -= 10;
				c = 1;
			}
			else
				c = 0;

			sum_int[i] = tmp + '0';
		}
		if (c == 1)
			sum_int[i++] = '1';
		sum_int_size = i;

		c = 0;
		for (i = 0; i < std::max(a_dec_size, b_dec_size); ++i)
		{
			if (i >= a_dec_size)
				a_dec[i] = '0';
			if (i >= b_dec_size)
				b_dec[i] = '0';

			int tmp = c + (a_dec[i] - '0') + (b_dec[i] - '0');
			if (tmp >= 10)
			{
				tmp -= 10;
				c = 1;
			}
			else
				c = 0;

			sum_dec[i] = tmp + '0';
		}
		if (c == 1)
			sum_dec[i++] = '1';
		sum_dec_size = i;

		std::reverse(sum_int, sum_int+sum_int_size);
		std::reverse(sum_dec, sum_dec+sum_dec_size);

		printf("%s.%s\n", sum_int, sum_dec);

		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(a_int, 0, sizeof(a_int));
		memset(b_int, 0, sizeof(b_int));
		memset(a_dec, 0, sizeof(a_dec));
		memset(b_dec, 0, sizeof(b_dec));
	}

	return 0;
}
