#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* input_string();
char** Words(char *str);
int grammer_checker(char *str);
int words_count(char *str);


int main()
{
    char *str = input_string();
    int errors = grammer_checker(str);
    printf("Grammatical Errors: %d\n", errors);
    printf("Corrected Sentence: %s\n", str);

    return 0;
}

char* input_string()
{
    char* str = (char*)malloc(sizeof(char) * 1);
    char c;
    int counter = 0;

    printf("Enter a string: ");

    while((c = getchar()) != '\n')
    {
        str = realloc(str, sizeof(char) * (counter + 1));
        *(str + counter) = c;
        counter++;
    }
    str = realloc(str, sizeof(char) * (counter + 1));
    *(str + counter) = '\0';
    return str;
}

int words_count(char *str)
{
    int i = 0;
    int white_spaces = 0;

    for(i = 0; i <= strlen(str); i++)
    {
        if((*(str+i) == ' ') || (*(str+i) == '\0'))
        {
            white_spaces++;
        }
    }

    return white_spaces;
}

char** Words(char *str)
{
    char *strng = (char*)malloc(sizeof(char) * strlen(str));
    char *substr = (char*)malloc(sizeof(char) * 1);
    char *verb = (char*)malloc(sizeof(char) * 1);

    int i = 0;
    int substr_len = 0;
    int word = 0;
    
    strcpy(strng, str);

    int count = words_count(strng);


    char **words = (char**)malloc(sizeof(char) * count);

    words[0] = strtok(strng, " ");
    while(words[i] != NULL)
    {
        //printf("'%s'\n", words[i]);
        i++;
        words[i] = strtok(NULL, " ");
    }
    return words;
}

int grammer_checker(char *str)
{
    int errors = 0;
    int count = words_count(str);
    char *words_array[count];
    char words_manp[count][20];
    char **word_ptr = Words(str);
    int i = 0;
    int j = 1;
    for(i = 0; i < count; i++)
    {
        words_array[i] = *(word_ptr + i);
        strcpy(words_manp[i], *(word_ptr + i));
        int k = 0;
        for(k = 0; k <= strlen(words_manp[i]); k++)
        {
            words_manp[i][k] = tolower(words_array[i][k]);
        }
    }
    for(i = 0; i < count; i++)
    {

        if(strcmp(*(words_manp+i), "we") == 0)
        {
            if(strcmp(*(words_manp+j), "are") != 0)
            {
                errors++;
                words_array[j] = "are";
            }
            else
            {
                //printf("true");
            }
        }
        else if((strcmp(*(words_manp+i), "he") == 0) || (strcmp(*(words_manp+i), "she") == 0) || (strcmp(*(words_manp+i), "it") == 0))
        {
            if(strcmp(*(words_manp+j), "is") != 0)
            {
                //printf("false");
                errors++;
                strcpy(*(words_array+j), "is");
            }
            else
            {
                //printf("true");
            }
        }
        j++;
    }

    *str = NULL;
    
    for(i = 0; i < count; i++)
    {
        strcat(str, words_array[i]);
        strcat(str, " ");
    }


    return errors;
}
