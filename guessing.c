#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    
        printf("             OOOOOOOOOOO                       \n");
        printf("         OOOOOOOOOOOOOOOOOOO                    \n");
        printf("      OOOOOO  OOOOOOOOO  OOOOOO                 \n");
        printf("    OOOOOO      OOOOO      OOOOOO       Welcome \n");
        printf("  OOOOOOOO  #   OOOOO  #   OOOOOOOO     To The  \n");
        printf(" OOOOOOOOOO    OOOOOOO    OOOOOOOOOO    Guess   \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO   The     \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO   Number  \n");
        printf("OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO   Game    \n");
        printf(" OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO            \n");
        printf("  OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO             \n");
        printf("    OOOOO   OOOOOOOOOOOOOOO   OOOO              \n");
        printf("      OOOOOO   OOOOOOOOO   OOOOOO               \n");
        printf("         OOOOOO         OOOOOO                  \n");
        printf("             OOOOOOOOOOOO                       \n");


    int seconds = time(0);
    srand(seconds);

    int randomNumber = rand();

    int secretnumber = randomNumber % 100;
    int try;
    int attempts = 1;
    double score = 1000;
    int chances;
    int correct = 0;

    int level;
    printf("What is the difficult level?\n");
    printf("(1) easy (2) normal (3) Difficult\n\n");
    printf("Choose: ");
    scanf("%d", &level);

    switch(level) {
    case 1:
        chances = 20;
        break;
    case 2: 
        chances = 10;
        break;
    default : 
        chances = 5;
        break;
    }


    for (int i = 1; i <= chances; i++)
    {
        printf("Number of attempts: %d \n", attempts);
        printf("\nTry to guess the number from 0 to 100\n");
        scanf("%d", &try);
        printf("\n\nYou tried %d \n", try);

        if (try < 0)
        {
            printf("You can't use negative numbers\n");

            continue;
        }

        correct = (try == secretnumber);
        int greater = try > secretnumber;

        if (correct)
        {

            break;
        }
        else if (greater)
        {
            printf("Your number is greater than the secret number\n");
        }
        else
        {
            printf("Your number is smaller than the secret number\n");
        }

        attempts++;

        double lostscore = abs(try - secretnumber) / 2.0;
        score = score - lostscore;
    }

    printf("End of the game!\n");

    if (correct) {
        printf("You won!!!\n");
        printf("Points made: %.1f \n", score);
        printf("You won the game with %d attempts", attempts);
    }
    else
    {
        printf("You lost! try again!");
    }
}