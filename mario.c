#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;

    // Prompt user for height between 1 and 8
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // Render the pyramid
    for (int i = 0; i < height; i++)
    {
        // Print leading spaces for right-alignment
        for (int j = 0; j < height - 1 - i; j++)
        {
            printf(" ");
        }

        // Print hashes for the staircase
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }

        // Move to the next line
        printf("\n");
    }
}
