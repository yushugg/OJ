/*
 * @filename:	hd-1235.cpp
 * @author:		yushu
 * @data:		2013.3.9
 */
#include <stdio.h>

int N;	// the sum of the input people
int score[101];	//scores
int in[2000];	//input scores

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int query;
	scanf("%d", &N);

	while (N != 0)
	{
		for (int i = 0; i < 101; ++i)
			score[i] = 0;
		for (int i = 0; i < N; ++i)
		{
			scanf("%d", &in[i]);
			++score[in[i]];
		}
		scanf("%d", &query);
		printf("%d\n", score[query]);
		scanf("%d", &N);
	}

	return 0;
}
