#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // Check that a key has been given
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Check the key is the correct length
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 letters\n");
        return 1;
    }

    // Check the key only contains letters
    for (int i = 0, j = strlen(argv[1]); i < j; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Key must only contain letters\n");
            return 1;
        }
    }

    // Check the key has no repeated characters
    for (int i = 0, j = strlen(argv[1]); i < j; i++)
    {
        for (int k = i + 1; k < j; k++)
        {
            if (tolower(argv[1][i]) == tolower(argv[1][k]))
            {
                printf("Key must not contain duplicate letters\n");
                return 1;
            }
        }
    }

    string plain_text = get_string("plaintext: ");
    char cipher_text[strlen(plain_text)];

    for (int i = 0, j = strlen(plain_text); i < j; i++)
    {
        if (isalpha(plain_text[i]) && plain_text[i] >= 'a' && plain_text[i] <= 'z')
        {
            cipher_text[i] = tolower(argv[1][(int) plain_text[i] - 97]);
        }
        else if (isalpha(plain_text[i]) && plain_text[i] >= 'A' && plain_text[i] <= 'Z')
        {
            cipher_text[i] = toupper(argv[1][(int) plain_text[i] - 65]);
        }
        else
        {
            cipher_text[i] = plain_text[i];
        }
    }
    printf("ciphertext: ");
    for (int i = 0, j = strlen(plain_text); i < j; i++)
    {
        printf("%c", cipher_text[i]);
    }
    printf("\n");
    return 0;
}