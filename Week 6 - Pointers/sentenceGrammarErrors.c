#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *readLine();
char **splitString(char *, char, int *);
char *toLower(char *);
typedef struct
{
    char *noun;
    char *helpingVerb;
} pronoun;

int main()
{
    int wordsCount, errors = 0;
    pronoun pronouns[] = {{"he", "is"}, {"she", "is"}, {"it", "is"}, {"i", "am"}, {"you", "are"}, {"we", "are"}, {"they", "are"}};
    char *sentence;
    char **words;
    printf("Type a sentence:\n");
    sentence = readLine();
    words = splitString(sentence, ' ', &wordsCount);

    for (int i = 0; i < wordsCount; i++)
    {
        char *word = toLower(*(words + i));
        for (int j = 0; j < 7; j++)
        {
            if (!strcmp(word, pronouns[j].noun))
            {
                i++;
                if (strcmp(*(words + i), pronouns[j].helpingVerb) && (!strcmp(*(words + i), "is") || !strcmp(*(words + i), "are")))
                {
                    errors++;
                    *(words + i) = malloc(strlen(pronouns[j].helpingVerb));
                    *(words + i) = pronouns[j].helpingVerb;
                    break;
                }
                else
                    break;
            }
        }
        free(word);
    }
    if (errors)
    {
        printf("Grammatical errors: %d\n", errors);
        printf("Corrected sentence:\n");
        for (int i = 0; i < wordsCount; i++)
        {
            printf("%s ", *(words + i));
        }
        printf("\n");
    }
    else
        printf("The sentence is grammatically correct!\n");

    return 0;
}

char *readLine()
{
    int size = 1;
    char *str_ptr = (char *)malloc(size * sizeof(char));
    while ((*(str_ptr + size - 1) = getchar()) != '\n')
    {
        str_ptr = (char *)realloc(str_ptr, ++size);
    }
    *(str_ptr + size - 1) = '\0';
    return str_ptr;
}
char **splitString(char *sentence, char splitter, int *wordsCount)
{
    *wordsCount = 1;
    char *modifiedSentence = (char *)malloc(8), **str_arr;
    strcpy(modifiedSentence, sentence);

    for (int i = 0; *(modifiedSentence + i) != '\0'; i++)
    {
        if (*(modifiedSentence + i) == splitter)
        {
            *(modifiedSentence + i) = '\0';
            *(wordsCount) += 1;
        }
    }
    str_arr = (char **)malloc(8 * *(wordsCount));
    *str_arr = modifiedSentence;
    for (int i = 0, j = *wordsCount - 1; *(sentence + i) != '\0'; i++)
    {
        if (*(modifiedSentence + i) == '\0')
            *(str_arr + (*wordsCount - j--)) = (modifiedSentence + i + 1);
    }

    return str_arr;
}
char *toLower(char *word)
{
    int str_len = strlen(word);
    char *lowered = (char *)malloc(str_len + 1);
    for (int i = 0; i <= str_len; i++)
    {
        if (*(word + i) >= 65 && *(word + i) <= 90)
            *(lowered + i) = *(word + i) + 32;
        else
            *(lowered + i) = *(word + i);
    }
    return lowered;
}