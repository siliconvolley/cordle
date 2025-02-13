#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utils.h"
#include "word_list.h"
#include "game_logic.h"

int chances = 6, wordFound = 0;
char entered_string[5], tempMain[10], temp[5];

int main() {
    int num;
    char *buff;

    srand(time(0));

    // Chooses a random word from the word list
    num = random_number();
    get_string(num, &buff);

    strcpy(tempMain, buff);

    //printf("DEBUG: %s\n", buff);

    printf("\n");
    disp_title();
    printf("\n");

    printf("A random 5-letter word has been chosen.\n");
    printf("You have %d chances!\n\n", chances);

    check_string(); 
    if (wordFound == 0)
        printf("The right word is %s", buff);

    return 0;
}
