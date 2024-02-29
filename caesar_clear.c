#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char encipher(char p, int k);

int main(int argc, string argv[])
{
    int key = 0;
    string plaintext;

    if (argc == 2)
    {
        for (int i = 0, len = strlen(argv[1]); i < len; i++)
        {
            if (isdigit(argv[1][i]) == 0)
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
        key = atoi(argv[1]);

        do
        {
            plaintext = get_string("plaintext: ");
        }
        while (plaintext[0] == '\0');

        printf("ciphertext: ");
        char ciphertext;
        for (int i = 0, len = strlen(plaintext); i < len; i++)
        {
            ciphertext = encipher(plaintext[i], key);
            printf("%c", ciphertext);
        }
        printf("\n");
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}

char encipher(char p, int key)
{
    char c;

    if (key > 25)
    {
        key = key % 26;
    }
    
    if (isupper(p))
    {
        c = (p - 65 + key) % 26 + 65;
    }
    else if (islower(p))
    {
        c = (p - 97 + key) % 26 + 97;
    }
    
    return c;
}
