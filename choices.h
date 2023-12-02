#include <stdio.h>

#ifndef CHOICES
    #define CHOICES
    #include "choices.h"
#endif
#ifndef LIB
    #define LIB
    #include "lib.h"
#endif

/*
    This file holds all the choices and global variables in it.
*/

#define NAMELIMIT 15

//Player Variables
    char name[NAMELIMIT+1];
    int health = 15;
    int strength = 5;
    int money = 0;

//Choice variables
    char over = 0;
    char end = 0;
    unsigned long choice = 0; //Calls the right function based on where you are in the array
    char response[50]; //String Response

//######################################################################################################################################################

void choiceStart(void) {

    printf("Would you like to walk down the path or look through the forest?");
    do{
        
        printf("\n\033[0;36m(Look / Path): \033[0m");
        getLine(response, 50);
        lower(response);

        if(!strcmp(response, "look")) {
            over = 1;
            choice = 1;
        }
        else if(!strcmp(response, "path")) {
            over = 1;
            choice = 2;
        }
        else if(!strcmp(response, "check")) {
            over = 0;
            printStats();
        }
        else if(!strcmp(response, "help")) {
            over = 0;
            printCommands();
        }
        else if(!strcmp(response, "rules")) {
            over = 0;
            printRules();
        }
        else if(!strcmp(response, "okusa")) {
            over = 0;
            money++;
            health++;
            printf("\"OK, USA.\"\n");
            printStats();
        }
        else if(!strcmp(response, "kill me")) {
            over = 0;
            money++;
            loseHealth(500);
        }
        else {
            printf("\nEnter a valid response.");
            over = 0;
        }
    } while(!over);
}

//######################################################################################################################################################

void choice1(void) {
        printf("\nYou look through the forest and see a dim light in the distance.\nWould you like to go towards it or go back to the path?");
        do{
            
            printf("\n\033[0;36m(Light / Path): \033[0m");
            getLine(response, 50);
            lower(response);

            if(!strcmp(response, "light")) {
                over = 1;
                choice = 3;
            }
            else if(!strcmp(response, "path")) {
                over = 1;
                choice = 2;
            }
            else if(!strcmp(response, "check")) {
                over = 0;
                printStats();
            }
            else if(!strcmp(response, "help")) {
                over = 0;
                printCommands();
            }
            else {
                printf("\nEnter a valid response.");
                over = 0;
            }
        } while(!over);
}

//######################################################################################################################################################

void choice2(void) {
        printf("\nYou walk down the path for about 4 minutes before seeing the front entrance of a village.\n");
        printf("You look up to see a massive sign that reads the words \"Morgun Village\".\n");
        printf("You look around farther and see that the village isn\'t too big and would only be able to house around a dozen people.\n");
        printf("You feel as though the town is quite gloomy.\nYou would think it was abandoned if it wasn't for the dim light you could see coming from the window of a house near the far end of the village.\n");
        printf("Then you hear a crackling coming from the back end of the village.\n");
        printf("Would you like to go towards the noise or hide in one of the houses?");
        do{
            
            printf("\n\033[0;36m(Noise / House): \033[0m");
            getLine(response, 50);
            lower(response);

            if(!strcmp(response, "noise")) {
                over = 1;
            }
            else if(!strcmp(response, "house")) {
                over = 1;
            }
            else if(!strcmp(response, "check")) {
                over = 0;
                printStats();
            }
            else if(!strcmp(response, "help")) {
                over = 0;
                printCommands();
            }
            else if(!strcmp(response, "rules")) {
                over = 0;
                printRules();
            }
            else if(!strcmp(response, "rules")) {
                over = 0;
                printRules();
            }    
            else {
                printf("\nEnter a valid response.");
                over = 0;
            }
        } while(!over);
    }

//######################################################################################################################################################

void choice3(void) {
        printf("\nYou walk through the forest towards the bright light.\n");
        printf("Since you were focused on the light you ended up stumbling and scraping your knee.\n");
        loseHealth(1);
        printf("");

        printf("Would you like to go towards the noise or hide in one of the houses?");
        do{
            
            printf("\n\033[0;36m(Noise / House): \033[0m");
            getLine(response, 50);
            lower(response);

            if(!strcmp(response, "noise")) {
                over = 1;
            }
            else if(!strcmp(response, "house")) {
                over = 1;
            }
            else if(!strcmp(response, "check")) {
                over = 0;
                printStats();
            }
            else if(!strcmp(response, "help")) {
                over = 0;
                printCommands();
            }
            else if(!strcmp(response, "rules")) {
                over = 0;
                printRules();
            }
            else {
                printf("\nEnter a valid response.");
                over = 0;
            }
        } while(!over);
}