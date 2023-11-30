#include <stdio.h>
#ifndef CHOICES
    #define CHOICES
    #include "choices.h"
#endif

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

void printCommands(void) {
    
    printBorder();

    printf("\nList of commands:\n\n");
    printf("Check: Displays a list of your current stats such as strength, health, ect.\n");
    printf("Help: Displays a list of the commands.\n");


    printf("\nColors: \n\n");
    printf("\033[0;36m#\033[0m = A question awaiting input.\n\033[0;33m#\033[0m = Text that was inputted by you.\n\n");

    printBorder();
}