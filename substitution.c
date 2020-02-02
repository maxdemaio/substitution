#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

// TO DO
// Get key (command line argument pass into main, case insensitive, 26 long, alphabetic characters)
// Validate key
// Get plaintext
// Encipher
// Print cipher

// Encipher protoype
string encipher(string plaintext);

// (number of command line arguments, string of command line arguments)
int main(int argc, string argv[])
{
    string key = argv[1];
    long keyLength = strlen(key);
    int i;

    printf("Key is: %s\n", key);
    printf("Number Of Arguments Passed: %d\n", argc);
    printf("Length of key is: %lu\n", keyLength);


    // Check key length
    if (keyLength != 26)
    {
        printf("Key does not have a valid length!\n");
        return (1);
    }
    printf("Key is valid length!\n");


    // Check for non-aplhabetic characters
    for ( i = 0; i < keyLength; i++)
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

    // Get plaintext input from user
    string plaintext = get_string("plain text: \n");

    // Enchipher
    return 0;
}


string encipher(string plaintext)
{
    // For each alphabetic character, determine which character it maps to
    // Preserve case
    // Leave non-alphabetic characters as is
    string encipherText = "hi";
    return(encipherText);
}
