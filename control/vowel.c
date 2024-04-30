#include<stdio.h>

int isWordEnd(int);

void vowel()
{
    char input[150];
    int wordStart = -1;
    int wordEnd = -1;
    int wordFound = 0;

    printf("Write a sentence please:");
    fgets(input, 150, stdin);


    for(int i = 0; i < 150; i++)
    {
        int hasVowelResult = 0;

        if(wordStart == -1 && (input[i] > 96 && input[i] < 123))
        {
            wordStart = i;
        }

        if(wordStart > -1 && isWordEnd(input[i]))
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

        if(input[i] == '\0')
        {
            break;
        }
    }

    printf("The input has %d words with all the vowels\n", wordFound);

}

int isWordEnd(int letter)
{
    if(letter == 32 || letter == 10 || letter == 13 || letter == 0)
    {
        return 1;
    }

    return 0;
}

int hasVowels(char word[], int start, int end)
{
    int a_vowel = 0, e_vowel = 0, i_vowel = 0, o_vowel = 0, u_vowel = 0;

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
