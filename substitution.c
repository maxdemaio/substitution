#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>


// Encipher protoype
string encipher(string plaintext, string key);

int main(int argc, string argv[])
{
    // Check number of command line arguments
    if(argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return (1);
    }

    // Initialize variables
    string key = argv[1];
    long keyLength = strlen(key);
    int i;
    int j;

    // Convert key to uppercase
    for (i = 0; i < keyLength; i++)
    {
        if(key[i] >= 'a' && key[i] <= 'z')
        {
            // ASCII conversion
            key[i] = key[i] -32;
        }
    }

    // Print some statistics
    printf("Key is: %s\n", key);
    printf("Number Of Arguments Passed: %d\n", argc);
    printf("Length of key is: %lu\n", keyLength);

    // *** Validate the provided key ***

    // Check key length
    if (keyLength != 26)
    {
        printf("Key must contain 26 characters.\n");
        return (1);
    }
    printf("Key is valid length!\n");

    // Check for non-alphabetic characters
    for (i = 0; i < keyLength; i++)
    {
        // If character is alphabetic, continue
        if (isalpha(key[i]) != 0)
        {
            continue;
        }
        // Character error encountered
        else
        {
            printf("Key contains non-valid characters!\n");
            return (1);
        }
    }
    printf("Characters are valid!\n");

    // Check for repeated characters (case insensitive)
    for (i = 0; i < keyLength; i++) // Iterate over each char in key
    {
        char letter = key[i];
       // Iterate over each char after key[i]
        for(j = i+ 1; j < keyLength + 1; j++)
        {
            // Duplicate encountered
            if ( key[i] == key[j])
            {
                printf("Key must not contain repeated characters.\n");
                return (1);
            }
        }
    }
    printf("No duplicate characters in key!\n");

    // Get plaintext input from user
    string plainText = get_string("plain text: ");

    // Enchipher the provided plaintext
    printf("ciphertext: %s\n", encipher(plainText, key));
}


// Encipher function
string encipher(string plainText, string key)
{

    // Allocate memory for the size of the provided plaintext
    int plainTextLength = strlen(plainText);
    char *eText;
    eText = (char *)malloc(plainTextLength);

    // Initialize variables
    long keyLength = strlen(key);
    bool found;
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i;
    int j;

    // Loop over all characters of plaintext
    for (i = 0; i < plainTextLength; i++)
    {
        // Set found default to False (used to preserve non-alphabetical chars)
        found = 0;
        // Loop over the alphabet to see where plaintext[i] is located, then map that char to the key
        for (j = 0; j < keyLength; j++)
        {
            // Mapped uppercase or lower case letter (checking ASCII)
            if (plainText[i] == alphabet[j] || (int)plainText[i] == (int)alphabet[j] + 32)
            {
                // Mapped lowercase letter
                if (islower(plainText[i]))
                {
                    eText[i] = tolower(key[j]);
                    found = 1; // found a match
                    break;
                }
                // Mapped uppercase letter
                else
                {
                    eText[i] = key[j];
                    found = 1;
                    break;
                }
            }
        }
        // if not alphabetic char, still print it
        if (found == 0)
        {
            eText[i] = plainText[i];
        }
    }
    return (eText);
}
