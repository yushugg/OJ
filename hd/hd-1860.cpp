/*
* @filename:	hd-1860.cpp
* @author:		yushu
* @data:		2013.3.9
*/

#include <stdio.h>
#include <string.h>

char query[5];
char str[80];
int alphabet[5];

int main()
{
	int c;	//to get '\n's

	memset(alphabet, 0, sizeof(alphabet));
	c = getchar();
	while (c != '#')
	{
		int size;
		query[0] = c;
		for (size = 1; size < 5; ++size)
		{
			if ((c = getchar()) == '\n')
				break;
			else
				query[size] = c;
		}

		//c = getchar();
		for (int i = 0; i < 80; ++i)
		{
			if ((c = getchar()) == '\n')
				break;
			else
			{
				for (int j = 0; j <= size; ++j)
				{
					if (query[j] == c)
						alphabet[j]++;
				}
			}
		}

		for (int i = 0; i < size; ++i)
		{
			printf("%c %d\n", query[i], alphabet[i]);
		}
		//c = getchar();
		memset(alphabet, 0, sizeof(alphabet));
		c = getchar();
	}

	return 0;
}
