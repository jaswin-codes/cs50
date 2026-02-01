// A program that enables you to encrypt messages using a substitution cipher by providing a
// command-line argument.

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Command-line argument for key
int main(int argc, string argv[])
{
    // Validation for false and out of acceptable key
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    string key = argv[1];
    if (strlen(key) != 26)
    {
        printf("Usage: Key must contain 26 characters.\n");
        return 1;
    }
    int letters[26] = {0};
    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Usage: Key must only contain alphabetical characters.\n");
            return 1;
        }
        // Convert to lowercase and put characters into array
        int index = tolower(key[i]) - 'a';
        // if index of array filled, meaning repeated characters so stop code
        if (letters[index] == 1)
        {
            printf("Key must not contain repeated characters.\n");
            return 1;
        }
        letters[index] = 1;
    }
    // Prompt to get plaintext
    string plain = get_string("plain text: ");
    // Print ciphertext
    printf("ciphertext: ");

    for (int i = 0; i < strlen(plain); i++)
    {
        char letter = plain[i];
        int index;
        // Check for lowercase and uppercase letters else numbers to preserve
        if (islower(letter))
        {
            index = letter - 'a';
            printf("%c", tolower(key[index]));
        }
        else if (isupper(letter))
        {
            index = letter - 'A';
            printf("%c", toupper(key[index]));
        }
        else
        {
            printf("%c", letter);
        }
    }
    printf("\n");
    return 0;
}
