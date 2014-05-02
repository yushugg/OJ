/**
 *	@filename:	hd-1230.cpp
 *	@author:	yushu
 *	@date:		2013.3.7
 */
#include <stdio.h>
#include <string.h>

int prime_num[25];
int a[25], b[25];

void prime(int prime_num[])
{
    bool p = true;
    int i = 1;
    prime_num[0] = 2;
    for (int j = 3; ; j += 2)
    {
        for (int k = 2; k < j; ++k)
        {
            if (j % k == 0)
            {
                p = false;
                break;
            }
        }
        if (p)
        {
            prime_num[i++] = j;
        }
        p = true;
        if (i == 25)
            break;
    }
}

void str_to_int(char str1[], char str2[], int *a_n, int *b_n)
{
    //int a[25], b[25];
    char c[20];
    char ch;

    int i = 0, j = 0, ai = 0, bi = 0;
    //To store a[]
    while(str1[i] != '\0')
    {
        if (str1[i] != ',')
        {
            c[j++] = str1[i];
        }
        else
        {
            c[j] = '\0';
            j = 0;
            sscanf(c, "%d", &a[ai++]);
        }
        ++i;
    }

    c[j] = '\0';
    j = 0;
    sscanf(c, "%d", &a[ai++]);

    //To store b[]
    i = 0;
    while(str2[i] != '\0')
    {
        if (str2[i] != ',')
        {
            c[j++] = str2[i];
        }
        else
        {
            c[j] = '\0';
            j = 0;
            sscanf(c, "%d", &b[bi++]);
        }
        ++i;
    }

    c[j] = '\0';
    j = 0;
    sscanf(c, "%d", &b[bi++]);

    return;
}

int main()
{
    prime(prime_num);

    int a_n, b_n;
    
    char str1[1000];
    char str2[1000];
    scanf("%s", str1);
    scanf("%s", str2);

    while (strcmp(str1, "0") != 0 || strcmp(str2, "0") != 0)
    {
        str_to_int(str1, str2, &a_n, &b_n);
        for (int i = 0; i < 25; ++i)
        {
            printf("a[%d]: %d\n", i, a[i]);
            printf("b[%d]: %d\n", i, b[i]);
        }
        scanf("%s", str1);
        scanf("%s", str2);

    }

    return 0;
}
