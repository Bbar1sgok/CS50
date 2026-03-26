#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
bool only_digits(string s);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    // 1. Check if exactly one command-line argument is provided
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // 2. Check if the argument consists only of digits
    if (!only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // 3. Convert the key string to an integer
    int k = atoi(argv[1]);

    // 4. Prompt user for plaintext
    string plaintext = get_string("plaintext:  ");

    // 5. Output the ciphertext
    printf("ciphertext: ");
    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        // Rotate and print each character one by one
        printf("%c", rotate(plaintext[i], k));
    }
    printf("\n");

    return 0;
}

// Function to check if a string contains only digits
bool only_digits(string s)
{
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}

// Function to rotate a character by n positions
char rotate(char c, int n)
{
    if (isupper(c))
    {
        // Shift ASCII to 0-25, rotate, wrap, then shift back to ASCII
        return (c - 'A' + n) % 26 + 'A';
    }
    else if (islower(c))
    {
        // Shift ASCII to 0-25, rotate, wrap, then shift back to ASCII
        return (c - 'a' + n) % 26 + 'a';
    }
    else
    {
        // Return non-alphabetical characters as they are
        return c;
    }
}
