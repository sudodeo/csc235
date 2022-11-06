#include <stdio.h>

void reverse_sentence(char *sentence);

int main()
{
    char sentence[100];

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    reverse_sentence(sentence);
    printf("\n");

    return 0;
}
// using recursion to reverse string
void reverse_sentence(char *sentence)
{
    if (*sentence != '\0')
    {
        reverse_sentence(sentence + 1);
        printf("%c", *sentence);
    }
}