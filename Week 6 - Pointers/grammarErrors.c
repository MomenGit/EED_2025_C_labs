#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *readLine();
char **splitString(char *, char, int *);
char *toLower(char *);
int isItQ(char *word);

int main()
{
    int wordsCount, errors = 0, isItQuestion = 0;
    char *sentence;
    char **words;
    printf("Type a sentence:\n");
    sentence = readLine();
    words = splitString(sentence, ' ', &wordsCount);

    for (int i = 0; i < wordsCount; i++)
    {
        char *word = toLower(*(words + i));
        isItQuestion = 1;
        if (!strcmp(word, "is"))
        {
            if (isItQ(*(words + i - 1)))
            {
                isItQuestion = 0;
                i++;
            }
            if (!(!strcmp(toLower(*(words + i - isItQuestion)), "he") || !strcmp(toLower(*(words + i - isItQuestion)), "she") || !strcmp(toLower(*(words + i - isItQuestion)), "it")))
            {
                *(words + i) = (!strcmp(*(words + i - isItQuestion), "I")) ? "am" : "are";
                errors++;
            }
        }
        else if (!strcmp(word, "are"))
        {
            if (isItQ(*(words + i - 1)))
            {
                isItQuestion = 0;
                i++;
            }
            if (!(!strcmp(toLower(*(words + i - isItQuestion)), "we") || !strcmp(toLower(*(words + i - isItQuestion)), "they") || !strcmp(toLower(*(words + i - isItQuestion)), "you")))
            {
                *(words + i) = (!strcmp(*(words + i - 1), "I")) ? "am" : "is";
                errors++;
            }
        }
        else if (!strcmp(word, "am"))
        {
            if (isItQ(*(words + i - 1)))
            {
                isItQuestion = 0;
                i++;
            }
            if (strcmp(toLower(*(words + i - 1)), "I"))
            {
                if (!strcmp(toLower(*(words + i - isItQuestion)), "we") || !strcmp(toLower(*(words + i - isItQuestion)), "they") || !strcmp(toLower(*(words + i - isItQuestion)), "you"))
                    *(words + i) = "are";
                else
                    *(words + i) = "is";
                errors++;
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

int isItQ(char *word)
{
    if (!strcmp(word, "What") || !strcmp(word, "How") || !strcmp(word, "When") || !strcmp(word, "Why") || !strcmp(word, "Where"))
        return 1;
    return 0;
}