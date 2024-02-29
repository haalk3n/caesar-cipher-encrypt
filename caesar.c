#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char encipher(char p, int k);

int main(int argc, string argv[])
{
    // We initialize the Key and Plaintext to be used later
    int key = 0;
    string plaintext;

    // We check for only 1 terminal argument (argc = 1 by default, +1 terminal argument)
    if (argc == 2)
    {
        // We make a loop to check through the terminal argument
        for (int i = 0, len = strlen(argv[1]); i < len; i++)
        {
            // We check to see if each character inside the argv[1] array is a digit
            if (isdigit(argv[1][i]) == 0)
            {
                // If ANY character inside argv[1] is NOT a digit, the program ends
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
        // Otherwise, if all characters are digits, then we turn argv[1] from String to Int and assign the value to KEY
        // It takes the literal String, not ASCII value, and turns it into an Int
        key = atoi(argv[1]);
        //printf("Key: %i\n", key);

        // We prompt the user for Plaintext, but if they don't write anything, ask until they do
        do
        {
            plaintext = get_string("plaintext: ");
        }
        while (plaintext[0] == '\0');

        // TODO: Implement cipher here
        // make for loop with encipher() function
        //printf("ciphertext: %c\n", ciphertext(encipher(plaintext[i], key), plaintext, key));

        printf("ciphertext: ");
        char ciphertext;
        for (int i = 0, len = strlen(plaintext); i < len; i++)
        {
            ciphertext = encipher(plaintext[i], key);
            printf("%c", ciphertext);
        }
        //ciphertext[strlen(plaintext)] = '\0';
        printf("\n");
    }
    // Here is the "else" for the original "if", if argc is not 2, program will not run
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}

char encipher(char p, int k)
{
    // The cipher formula: c[i] = (p[i] + k) % 26

    char c;

    if (k > 25)
    {
        k = k % 26;
    }

    if (isupper(p))
    {
        c = (p - 65 + k) % 26 + 65;
    }
    else if (islower(p))
    {
        c = (p - 97 + k) % 26 + 97;
    }
    else
    {
        c = p;
    }

    return c;
}
