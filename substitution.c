#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

// TO DO
// Get key (command line argument pass into main, case insensitive, 26 long, alphabetic characters)
// Validate key
// Get plaintext
// Encipher
// Print cipher

// Encipher protoype
string encipher(string plaintext);

// Main function (number of command line arguments, string of command line arguments)
int main(int argc, string argv[])
{
    string key = argv[1];
    long keyLength = strlen(key);
    int i;
    int j;

    printf("Key is: %s\n", key);
    printf("Number Of Arguments Passed: %d\n", argc);
    printf("Length of key is: %lu\n", keyLength);


// Validate the provided key

    // Check command line arguments
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return (1);
    }

    // Check key length
    if (keyLength != 26)
    {
        printf("Key must contain 26 characters.\n");
        return (1);
    }
    printf("Key is valid length!\n");

    // Check for non-aplhabetic characters
    for (i = 0; i < keyLength; i++)
    {
        // If character is alphabetic, continue
        if (isalpha(key[i]) != 0)
        {
            continue;
        }
        // Character error
        else
        {
            printf("Key contains non-valid characters!\n");
            return (1);
        }
    }
    printf("Characters are valid!\n");

    // Check for repeated characters (case insensitive)
    for(i = 0; i < keyLength; i++) // Iterate over each char in key
    {
        char letter = key[i];
       // Iterate over each char after key[i]
        for(j = i+ 1; j < keyLength + 1; j++)
        {
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

    // Enchipher
    printf("cipher text: %s\n", encipher(plainText));
}

// Encipher Function
string encipher(string plainText)
{
    int i;
    int j;
    bool found;
    char *eText;
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVQXYZ";

    // Allocate memory for the size of the provided plainText
    eText = (char *)malloc(plainTextLength);

    // Loop over all characters of plainText
    for (i = 0; i < plainTextLength; i++)
    {
        // Set found default to False
        found = 0;
        for (j = 0; j < keyLength; j++)
        {
            // Mapped uppercase or lower case letter
            if(plainText[i] == alphabet[j] || (int)plainText[i] == (int)alphabet[j] + 32)
            {
                // Mapped lowercase letter
                if(islower(plainText[i]))
                {
                    eText[i] = tolower(key[j]);
                }
                // Mapped uppercase letter
                else
                {
                    eText[i] = key[j];
                }
                // found a match
                found = 1;
            }
        }
        // if not alphabetic char, still print it
        if(found == 0)
        {
            eText[i] = plainText[i];
        }

    }
    printf("%s\n", eText);
    return(encipherText);
}
