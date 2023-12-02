#include <stdio.h>
#ifndef CHOICES
    #define CHOICES
    #include "choices.h"
#endif

/*
    This file holds all the miscellaneous functions I need.
*/

char get1() {

    char c[50], temp;
    unsigned char check = 0;
    
    while((temp = getchar()) != '\n') {

        if(!check)
            c[check++] = temp; 
    }

    return c[0];
}

int getLine(char s[], unsigned long max) {

    char c;
    unsigned long i = 0;
    while((c = getchar()) != '\n') {
        
        if(i >= max) {
            s[i] = '\0';
            while((getchar()) != '\n')
                ;
            return 0;
        }

        s[i++] = c;
    }

    s[i] = '\0';

    return 1; 
}

void lower(char s[]) {

    for(int i = 0; s[i] != '\0'; i++) {
        if(s[i] >= 'A' && s[i] <= 'Z') {
            s[i] -= ('A' - 'a');
        }
    }
}

//Printing Commands

void printBorder(void) {

    printf("##############################################\n");
}

void printStats(void) {
    
    extern int health, strength, money;
    printBorder();
    printf("\nStats:\n\n");
    printf("Health: %d\nStrength: %d\nMoney: %d\n\n", health, strength, money);
    printBorder();
}

void printRules(void) {

    printBorder();

    printf("\nList of rules:\n\n");
    //Death
    printf("Death: If your health reaches 0 at the end of a turn you die\n");
    printf("You can still heal before the turn ends to avoid bleeding out and dying.\n");

    printBorder();
}

void printCommands(void) {
    
    printBorder();

    printf("\nList of commands:\n\n");
    printf("Check: Displays a list of your current stats such as strength, health, ect.\n");
    printf("Help: Displays a list of the commands.\n");
    printf("Rules: Displays a list of rules for the game.\n");


    printf("\nColors: \n\n");
    printf("\033[0;36m#\033[0m = A question awaiting input.\n\033[0;33m#\033[0m = Text that was inputted by you.\n");
    printf("\033[0;31m#\033[0m = You lost health.\n\033[0;32m#\033[0m = You gained health.\n\n");

    printBorder();
}

void printHealth(void) {

    extern int health;
    printf("\nYou have %d health.\n");
}


//Gain / Lose health
void loseHealth(int amount) {

    extern int health;
    extern char end;

    printf("\033[0;31m-%d health.\033[0m\n", amount);
    health -= amount;
    (health>0) ? end = 0 : (end = 1);
}

void gainHealth(int amount) {

    extern int health;
    extern char end;

    printf("\033[0;33m+%d health.\033[0m\n", amount);
    health += amount;
    (health > 0) ? end = 0 : (end = 1);
    
}