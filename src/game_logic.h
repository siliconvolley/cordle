#include <stdio.h>
#include <string.h>
#include "utils.h"

extern int chances, wordFound;
extern char entered_string[5], tempMain[10], temp[5];

static void check_string() { 
    int *status;
    char single;
    int flag;
    while (chances--) {
        scanf("%s", temp);

        for (int i = 0; i < 5; i++) {
            if (tempMain[i] == temp[i]) {
                green(temp[i]);
                printf("\033[0m ");
            } else {
                single = temp[i];
                flag = 0;
                for (int j = 0; j <= 5; j++) {
                    if (i != j) {
                        if (tempMain[j] == single) {
                            flag = 1;
                        }
                    }
                }

                if (flag == 1) {
                    yellow(temp[i]);
                    printf("\033[0m ");
                }
                if (flag == 0) {
                    printf("\033[0m");
                    printf(" %c ", temp[i]);
                    printf("\033[0m ");
                }
            }
            flag = 0;
        }
        printf("\033[0m \n\n");
        if (strcmp(tempMain, temp) == 0) {
            printf("Right Word! You Won!\n");
            wordFound = 1;
            return;
        }
    }
}
