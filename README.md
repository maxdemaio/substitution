# substitution
Encrypt a message using a simple substitution cipher

Using the key `DWUSXNPQKEGCZFJBTLYROHIAVM`, for example, would encypt the plaintext `The quick brown fox jumps over the lazy dog.` to `Rqx tokug wljif nja eozby jhxl rqx cdmv sjp.`

Example substitution schema:
------
| A | B | C | D | E | F | G | H | I | J | K | L | M |
|---|---|---|---|---|---|---|---|---|---|---|---|---|
| D | W | U | S | X | N | P | Q | K | E | G | C | Z |

| N | O | P | Q | R | S | T | U | V | W | X | Y | Z |
|---|---|---|---|---|---|---|---|---|---|---|---|---|
| F | J | B | T | L | Y | R | O | H | I | A | V | M |

Executing the program with the example above:
```console
~/substitution/ $ make substitution 
clang -ggdb3 -O0 -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow    substitution.c  -lcrypt -lcs50 -lm -o substitution
~/substitution/ $ ./substitution DWUSXNPQKEGCZFJBTLYROHIAVM
plain text: The quick brown fox jumps over the lazy dog.
ciphertext: Rqx tokug wljif nja eozby jhxl rqx cdmv sjp.
```
