#include <stdlib.h>
#include <stdio.h>

//permutations successives:
#define MAX 10
int t[MAX] = {54, 50, 21, 12, 76, 23, 78, 1, 0, 56};
int main()
{
    int i;
    int j;
    int temp; //variable temporaire pour faire un échange
    for (i = 1; i < MAX; i++)
    {
        j = i;
        if (t[i] < t[i - 1])
        {
            while (t[j] < t[j - 1])
            {
                temp = t[j - 1];
                t[j - 1] = t[j];
                t[j] = temp;
                j = j - 1;
            }
            j = i;
        }
    }
    for (i = 0; i < MAX; i++)
    {
        printf("%d" ,t[i]);
    }
    return EXIT_SUCCESS;
}





