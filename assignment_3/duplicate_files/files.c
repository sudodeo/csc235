#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *file = fopen("files.in", "r");

    if (file == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    int numberOfTestCases;
    fscanf(file, "%d", &numberOfTestCases);

    char line[16];

    for (int i = 0; i < numberOfTestCases; i++)
    {

        while (fgets(line, sizeof(line), file))
        {

            if (atoi(line) != 0)
            {

                int fileGroup = atoi(line);
                char *oldName = malloc(sizeof(char) * 10);
                int oldID;

                for (int j = 0; j < fileGroup; j++)
                {
                    fgets(line, sizeof(line), file);

                    // separate text and number in line
                    char *name = strtok(line, " ");
                    char *number = strtok(NULL, " ");

                    int ID = atoi(number);

                    if (strcmp(oldName, name) == 0)
                    {
                        if (oldID > ID)
                        {
                            oldID = ID;
                        }
                    }

                    else
                    {
                        oldName = name;
                        oldID = ID;
                    }
                }
                printf("ID: %d\n", oldID);
            }
        }
    }

    fclose(file);

    return 0;
}