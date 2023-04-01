#include <stdio.h>
#include <stdlib.h>
#include "word_list.h"
#include <time.h>
#include <string.h>
#include <unistd.h>

int lower = 0, upper = 999, count = 1, chances = 6, wordFound = 0;
char entered_string[5], tempMain[10], temp[5];
char title[] = "welcome to improvised wordle";

int randomNumber(int lower, int upper, int count){                  //Random Number Generator
		int num = (rand() % (upper - lower + 1)) + lower;
        //printf("Random Number Generated : %d", num);
        return num;
}

//To check the entered string

void disp_title(){                                                  //To display the title of the game
    int i;
    int t=2;
    char arr[]="\\|/-";
    int j=0;
    while(t--){
    for (i = 0; i < strlen(title); i++) {
       // printf("[%s]\r", &title[i]);
        if(title[i]==' ')
            continue;
        else
            title[i]=title[i]-32; 
        printf("%s...%c\r",title,arr[j]);
        fflush(stdout);
        usleep(50000);
        title[i]=title[i]+32;
        j++;
        
        if(j==4)
            j=0;
        }
    }
    printf("\n");
}

void yellow(char c){                                                //Print in Yellow Background
    printf("\033[30;43m");
    printf(" %c ", c);  
}

void green(char c){                                                 //Print in Green Background
    printf("\033[30;42m");
    printf(" %c ", c);  
}

void check() {
    int *status;
    char single; // *checkBuffer;
    int flag;
    while(chances--){
        scanf("%s", temp);
        
        for(int i=0; i<5; i++){
            if(tempMain[i] == temp[i]){
                green(temp[i]);
                printf("\033[0m ");
                // printf("True (Debug)\n");
            }

            else{
                single = temp[i];
                flag = 0;
                for(int j=0; j<=5; j++){
                    if(i != j){
                        if(tempMain[j] == single){
                            flag = 1;
                        }
                    }
                }

                if(flag == 1){
                    yellow(temp[i]);
                    printf("\033[0m ");
                    // printf("False 01 (Debug)\n");
                }
                if(flag == 0){
                    printf("\033[0m");
                    printf(" %c ", temp[i]);
                    printf("\033[0m ");
                    // printf("False 02 (Debug)\n");
                }
            }
            flag = 0;
        }
        printf("\033[0m \n\n");
        if(strcmp(tempMain, temp) == 0){
            printf("Right Word! You Won!\n");
            wordFound = 1;
            return;
        }
    }
}

void main(){
    int num;
    char *buff;

    srand(time(0));

    //Choose a random word from the word list

    num = randomNumber(lower, upper, count);  
    get_string(num, &buff);

    strcpy(tempMain, buff);

    //printf("(Debug) %s\n", buff);
    
    //Main game Begins

    printf("\n");
    disp_title(); //Display the Title
    printf("\n");

    printf("A random 5-letter word has been chosen.\n");
    
    printf("You have %d chances!\n\n", chances);

    check(chances);
    if(wordFound == 0)
        printf("The right word is %s",buff);
    
}