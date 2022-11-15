#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    // read text from adam.in
    FILE *file;
    file = fopen("adam.in", "r");
    if (file == NULL)
    {
        printf("Error opening file");
        exit(1);
    }
    int testCases;
    fscanf(file, "%d", &testCases);
    printf("Text read from file: %d \n", testCases);

    for (int i = 0; i < testCases; i++)
    {
        char steps[100];
        int totalSteps = 0;
        fscanf(file, "%s", steps);
        for (int j = 0; j < strlen(steps); j++)
        {
            if (toupper(steps[j]) == 'D')
            {
                break;
            }
            else if (toupper(steps[j]) == 'U')
            {
                totalSteps++;
            }
        }
        printf("Total steps for \"%s\": %d \n", steps, totalSteps);
    }

    fclose(file);
    return 0;
}