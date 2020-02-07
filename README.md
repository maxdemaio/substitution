# substitution
Encrypt a message using a simple substitution cipher

## How it works:
Picture the characters of the alphabet in one single string. Now imagine jumbling those characters up, this is your "key" you will use to encrypt plaintext. Using the key, you take any plaintext message and swap each character based on its position in the alphabet in relationship to the key.

For example, using the key `DWUSXNPQKEGCZFJBTLYROHIAVM`, which is portrayed in the table below, would encypt the plaintext `The quick brown fox jumps over the lazy dog.` to `Rqx tokug wljif nja eozby jhxl rqx cdmv sjp.`

### Example substitution schema:

| A | B | C | D | E | F | G | H | I | J | K | L | M |
|---|---|---|---|---|---|---|---|---|---|---|---|---|
| D | W | U | S | X | N | P | Q | K | E | G | C | Z |

| N | O | P | Q | R | S | T | U | V | W | X | Y | Z |
|---|---|---|---|---|---|---|---|---|---|---|---|---|
| F | J | B | T | L | Y | R | O | H | I | A | V | M |

### Executing the program with the example above:
```console
~/substitution/ $ make substitution 
clang -ggdb3 -O0 -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow    substitution.c  -lcrypt -lcs50 -lm -o substitution
~/substitution/ $ ./substitution DWUSXNPQKEGCZFJBTLYROHIAVM
plain text: The quick brown fox jumps over the lazy dog.
ciphertext: Rqx tokug wljif nja eozby jhxl rqx cdmv sjp.
```
### Quick overview of how substitution.c works (without diving into the helper functions):
```c
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
```
