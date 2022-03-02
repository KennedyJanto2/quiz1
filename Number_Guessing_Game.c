/*
1. Create a while loop for the game until player exits
    1.a. create all necessary variables: player selection, guesses count, random number
    1.a. reads max from file
2. In loop, if player press 1, game starts
    2.a. create inner while loop for guessing game
    2.b. loop until player finds number
    2.c. takes input from player as string to test for q, else turn to int
3. if player press 2, change max
    3.a. writes new max to file
4. if player press 3, quit while loop
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

int main(){
    //start of game
    int choice = 1;

    //initialize number max saved from previous
    FILE *fp;
    fp = fopen("max.txt", "r");
    int max = 10;
    fscanf(fp, "%d", &max);
    fclose(fp);
    
    //initialize random generator
    time_t t;
    srand((unsigned) time(&t));
    
    int guesses = 0; //keeps track of guesses
    bool fail = false; //if player quits game

    while(choice != 3){
        //prints menu
        printf("\nPress 1 to play a game\nPress 2 to change the max number\nPress 3 to quit\n");
        //gets user choice
        scanf("%d", &choice);

        //game of guess
        if(choice == 1){
            int randomNum = rand() % max + 1; //creates random number
            int guess = 0;  //will hold int version of guess
            char input[] = "0"; //hold char version of guess
            int count = 0; //keeps track of guesses
            do{
                printf("\nGuess a number:\n");
                scanf("%s", &input); //takes in guess

                if(strcmp(input,"q") == 0){ //checks if player wants to quit
                    fail = true;
                    break;
                }
                else{       
                    guess = atoi(input); //convert input to int for game
                }

                if(guess > randomNum){ //guess is too high
                    printf("Too high\n");
                    count++;
                }   
                else if(guess < randomNum){ //guess is too low
                    printf("Too low\n");
                    count++;
                }
                else{ //game ends and guesses updated
                    printf("That is Correct!\n");
                    count++;
                    guesses += count; //updates number of guesses
                    count = 0; //reset count
                    break;
                }
            }while(guess != randomNum);
        }
        else if(choice == 2){ //change max of randomNumber
            printf("Enter new max (must be greater than 0):");
            scanf("%d", &max);

            //update saved max num in file
            fp = fopen("max.txt", "w");
            fprintf(fp, "%d", max);
            fclose(fp);
        }
        else if(choice == 3){ //guits game
            printf("Thank you for playing\n");
            if(fail == true){ //if player quit, then they lost
                printf("You lost");
            }
            else{ //if player won, print ammount of guesses
              printf("You won, Ammount of guesses is %d", guesses);  
            }
        }
    }

    fclose(fp);
    return 0;
}