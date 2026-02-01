// Credit Card Problem Set 1

#include <cs50.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool check_sum(long number);

int main(void)
{
    // Prompt for input
    long number = get_long("Credit Card Number: ");
    // Check if check_sum invalid first using NOT! otherwise proceed
    if (!check_sum(number))
    {
        printf("INVALID\n");
        // stops program so no more code run after
        return 0;
    }
    // Array long enough to hold number
    char str[17];
    // Convert integer to string
    sprintf(str, "%ld", number);
    // Returns length of string
    int length = strlen(str);
    // Check for AMEX
    if ((str[0] == '3' && (str[1] == '4' || str[1] == '7')) && length == 15)
    {
        printf("AMEX\n");
    }
    // Check for MASTERCARD
    else if ((str[0] == '5' && (str[1] == '1' || str[1] == '2' || str[1] == '3' || str[1] == '4' ||
                                str[1] == '5')) &&
             length == 16)
    {
        printf("MASTERCARD\n");
    }
    // Check for VISA
    else if (str[0] == '4' && (length == 13 || length == 16))
    {
        printf("VISA\n");
    }
    // Invalid if not either of 3
    else
    {
        printf("INVALID\n");
    }
}

// check_sum function
bool check_sum(long number)
{
    int sum = 0;
    // tells us whether to double digit
    bool card = false;

    while (number > 0)
    {
        // gets right most digit
        int digit = number % 10;

        if (card)
        {
            digit *= 2;
            // Splits double digit into single
            if (digit > 9)
            {
                digit = (digit % 10) + (digit / 10);
            }
        }

        sum += digit;
        // switch between double and not double(every other digit)
        card = !card;
        // remove last digit
        number /= 10;
    }

    // return valid if mod 10 gives 0
    return (sum % 10 == 0);
}

