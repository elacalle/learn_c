#include<stdio.h>

void vowel()
{
    char input[150];
    int wordStart = -1;
    int wordEnd = -1;
    int wordFound = 0;
    int test = 0;

    printf("Escriba su texto aqui:");
    fgets(input, 150, stdin);


    for(int i = 0; input[i] != '\0'; i++)
    {
        int hasVowelResult = 0;

        if(wordStart == -1 && (input[i] > 96 && input[i] < 123))
        {
            wordStart = i;
        }

        test = input[i];

        if(wordStart > -1 && (input[i] == 32 || input[i] == 10 || input[i] == 13))
        {
            wordEnd = i - 1;
        }

        if(wordStart > -1 && wordEnd > -1)
        {
            hasVowelResult = hasVowels(input, wordStart, wordEnd);

            if(hasVowelResult)
            {
                wordFound++;
            }

            wordStart = -1;
            wordEnd = -1;
        }
    }

    printf("The input was: %d\n", wordFound);

}

int hasVowels(char word[], int start, int end)
{
    int a_vowel = 0, e_vowel = 0 , i_vowel = 0, o_vowel = 0, u_vowel = 0;

    for (int i = start; i <= end; i++)
    {
        switch(word[i])
        {
        case 'a':
            a_vowel = 1;
            break;
        case 'e':
            e_vowel = 1;
            break;
        case 'i':
            i_vowel = 1;
            break;
        case 'o':
            o_vowel = 1;
            break;
        case 'u':
            u_vowel = 1;
            break;
        }
    }

    return a_vowel && e_vowel && i_vowel && o_vowel && u_vowel ? 1: 0;
}
