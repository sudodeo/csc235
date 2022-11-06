// accept names from 10 students and print all names

#include <stdio.h>

int main()
{
    char name[10][20];
    int i;
    for (i = 0; i < 10; i++)
    {
        printf("Input student %d name: ", i + 1);
        scanf("%s", name[i]);
    }
    for (i = 0; i < 10; i++)
    {
        printf("%s\n", name[i]);
    }
    return 0;
}
