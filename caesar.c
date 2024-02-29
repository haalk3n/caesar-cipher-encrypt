#include <cs50.h> // MADE USING THE CS50 package for user inputs
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

        // We prompt the user for Plaintext, but if they don't write anything, ask until they do
        do
        {
            plaintext = get_string("plaintext: ");
        }
        while (plaintext[0] == '\0');

        // We make a For loop with the encipher() function
        // We use the For loop inside 2 printf statements
        printf("ciphertext: ");
        char ciphertext;
        for (int i = 0, len = strlen(plaintext); i < len; i++)
        {
            ciphertext = encipher(plaintext[i], key);
            printf("%c", ciphertext);
        }
        printf("\n");
    }
    // Here is the "else" for the original "if", if argc is not 2, program will not run
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}

char encipher(char p, int key)
{
    // The basic cipher formula: c[i] = (p[i] + k) % 26
    char c; // C is the ciphered letter, P is the plaintext letter

    // We make sure the key value does not go past 26 (total amount of letters)
    if (key > 25)
    {
        key = key % 26;
    }
    
    // We check each character and encipher it only if it's a letter (Upper or Lower case)
    if (isupper(p))
    {
        c = (p - 65 + key) % 26 + 65;
    }
    else if (islower(p))
    {
        c = (p - 97 + key) % 26 + 97;
    }
    
    // Return the enciphered letter
    return c;
}
