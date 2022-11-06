#include <stdio.h>

int main()
{
    char name[10][20];
    int i;
    // collect names from input and append to name
    for (i = 0; i < 10; i++)
    {
        printf("Input student %d name: ", i + 1);
        scanf("%s", name[i]);
    }
    printf("\n");
    for (i = 0; i < 10; i++)
    {
        printf("%s\n", name[i]);
    }
    return 0;
}
