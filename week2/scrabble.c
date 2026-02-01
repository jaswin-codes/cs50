// Scrabble game where letters in word gets converted to points and winner is output.

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int word_points(string word);

int main(void)
{
    // Prompt for words
    string player1 = get_string("Player 1: ");
    string player2 = get_string("Player 2: ");

    // Turn word to score using function
    int score1 = word_points(player1);
    int score2 = word_points(player2);

    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int word_points(string word)
{
    // array for points of each alphabet
    int points[26] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                      1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    int score = 0;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        // changes all character to lowercase to be simple
        char lower_char = tolower(word[i]);
        // subtracts letter/char with 'a' using ASCII eg 'c'-'a' = 2
        // This 2 is now checked in the array  which is the third place hence 3 points
        score += points[lower_char - 'a'];
    }
    return score;
}
