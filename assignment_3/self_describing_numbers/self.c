#include <stdio.h>
#include <string.h>

int checkSelfDescribing(char *number, int length);

int main()
{
    FILE *file;
    file = fopen("self.in", "r");
    if (file == NULL)
    {
        printf("Error opening file");
        return 1;
    }
    int numberOfTestCases;
    fscanf(file, "%d", &numberOfTestCases);

    for (int i = 0; i < numberOfTestCases; i++)
    {
        char number[11];
        fscanf(file, "%s", number);
        int length = strlen(number);
        int result = checkSelfDescribing(number, length);
        if (result == 1)
        {
            printf("%s - Self-describing\n", number);
        }
        else
        {
            printf("%s - Not self-describing\n", number);
        }
    }
    fclose(file);
    return 0;
}

int checkSelfDescribing(char *number, int length)
{
    for (int i = 0; i < length; i++)
    {
        int count = 0;
        char numOfOccurence = number[i];
        for (int j = 0; j < length; j++)
        {
            // check if i is equal to the number at j
            if (i == (number[j] - '0'))
            {
                count++;
            }

            if (count > numOfOccurence)
            {
                return 0;
            }
        }

        if (count != numOfOccurence - '0')
        {
            return 0;
        }
    }
    return 1;
}