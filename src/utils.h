#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char TITLE[] = "welcome to improvised wordle";
int lower = 0;
int upper = 999;
int count = 1;

//Random Number Generator
int random_number(){
    int num = (rand() % (upper - lower + 1)) + lower;
    //printf("DEBUG: Random Number Generated : %d", num);
    return num;
}

// Delay for blinking effect in title animation
void sleep_microseconds(long microseconds) {
    struct timespec ts;
    ts.tv_sec = microseconds / 1000000;
    ts.tv_nsec = (microseconds % 1000000) * 1000;
    nanosleep(&ts, NULL);
}

//To display the title of the game
void disp_title(){                                                  
    int i;
    int t = 2;
    char arr[] = "\\|/-";
    int j = 0;
    while(t--){
    for (i = 0; i < strlen(TITLE); i++) {
       // printf("DEBUG: [%s]\r", &TITLE[i]);
        if(TITLE[i] == ' ')
            continue;
        else
            TITLE[i] = TITLE[i] - 32; 
        printf("%s...%c\r", TITLE, arr[j]);
        fflush(stdout);
        sleep_microseconds(50000);
        TITLE[i] = TITLE[i] + 32;
        j++;
        
        if(j == 4)
            j = 0;
        }
    }
    printf("\n");
}

//Print in Yellow Background
void yellow(char c){                                                
    printf("\033[30;43m");
    printf(" %c ", c);  
}

//Print in Green Background
void green(char c){                                                 
    printf("\033[30;42m");
    printf(" %c ", c);  
}

#endif
