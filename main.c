#include <stdio.h>
#include <string.h>

#ifndef CHOICES
    #define CHOICES
    #include "choices.h"
#endif
#ifndef LIB
    #define LIB
    #include "lib.h"
#endif


int main(void) {

    extern char over; //Checks to see if each choice is over
    extern unsigned long choice;
    extern char end;

    //Player Variables
    extern char name[];
    extern int health, strength, money;


    printCommands();

    printf("\n%c[4mWelcome to Morgun Village%c[0m\n", 27, 27);

    printf("\n\nWould you like to start?\n");

    //Begin check
#pragma region
    do{
        printf("\033[0;36m(Y / N): \033[0m");

        getLine(response, 50);
        lower(response);

        if(!strcmp(response, "y")) {
            over = 1;
        }
        else if(!strcmp(response, "n"))
            return 1;
        else {
            printf("Enter something valid.\n");
            over = 0;
        }
    } while(!over);
#pragma endregion
    
    //Name
#pragma region
    do{
        printf("What's your name: ");
        if(getLine(name, NAMELIMIT)) {
            over = 1;
        }
        else {
            printf("\nName was too long, enter a shorter name.\n");
            over = 0;
        }
    } while(!over);
#pragma endregion

    printf("\nYou wake up in a dark forest.\nAll you can remember is that your name is \033[0;33m%s\033[0m.\n", name); //weird text is to change the color of the text.


    //GameLoop
    while(!end) {
        switch(choice) {
            case 0:
                choiceStart();
                break;
            case 1:
                choice1();
                break;
            case 2:
                choice2();
                break;
            case 3:
                choice3();
                break;
            case 4:
                break;
            case 5:
                break;
        }
    }

    health > 0 ? printf("\n\nThe End.") : printf("\n\nYou Died.");

    return 1;
}