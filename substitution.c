#include <stdio.h>
#include <string.h>
#include <cs50.h>

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
    // Check key length
    // Check for non-aplhabetic characters
    // Check for repeated characters (case insensitive)
    printf("Key is: %s\n",argv[1]);
    printf("Number Of Arguments Passed: %d\n",argc);

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
