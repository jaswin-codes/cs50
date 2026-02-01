// Create mario pyramid blocks using #

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int tall;
    // Repeat until user inputs number between 1-8
    do
    {
        tall = get_int("How tall do you want pyramid: ");
    }
    while (tall < 1 || tall > 8);

    for (int i = 1; i <= tall; i++)
    {
        // Print spaces on left using tall - 1 
        for (int j = 0; j < tall - i; j++)
        {
            printf(" ");
        }
        // Print left pyramid
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }
        // Print double space in middle
        printf("  ");
        // Print right pyamid
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}

