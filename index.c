#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int bomb;
    int open;
    int neighbor;
}Celula;

// globals variables
Celula jogo[10][10];
int l, c, tam = 10;

void initializeGame() { // launch the game;
    
    for(l = 0; l < tam; l++) {
        for(c = 0; c < tam; c++) {
            jogo[l][c].bomb = 0;
            jogo[l][c].open = 0;
            jogo[l][c].neighbor = 0;
        }
    }
}

void bombSort(int n) {
    int i, bombs = 0;
    srand(time(NULL));
    
    for(i = 1; i < n; i++) {
        l = rand() % tam;
        c = rand() % tam;

        if(jogo[l][c].bomb == 0) {
            jogo[l][c].bomb = 1;
            bombs++;
        } else {
            i--;
        }
    }
}

int validCoordinates(int l, int c) {
    if(l >= 0 && l < tam && c >= 0 && c < tam) {
        return 1;
    } else {
        return 0;
    }
}

int neighboringPumps(int l, int c) {
    int amount = 0;

    if(validCoordinates(l - 1, c) && jogo[l - 1][c].bomb) {
        amount++;
    }
    if(validCoordinates(l + 1, c) && jogo[l + 1][c].bomb) {
        amount++;
    }
    if(validCoordinates(l, c + 1) && jogo[l][c + 1].bomb) {
        amount++;
    }
    if(validCoordinates(l, c - 1) && jogo[l][c - 1].bomb) {
        amount++;
    }

    return amount;
}

void countBombs() {
    for(l = 0; l < tam; l++) {
        for(c = 0; c < tam; c++) {
            jogo[l][c].neighbor = neighboringPumps(l, c);
        }
    }
}

void printGame() {
    printf("\n\n\t   ");
    for(l = 0; l < tam; l++) {
        printf("% d ", l);
    }
    printf("\n\t  -------------------------------\n");
    for(l = 0; l < tam; l++) {
        printf("\t%d |", l);
        for(c = 0; c < tam; c++) {
            if(jogo[l][c].open) {
                if(jogo[l][c].bomb) {
                    printf(" * ");
                } else {
                    printf(" %d ", jogo[l][c].neighbor);
                }
            } else {
                printf("  ");
                printf("|");
            }
        } 
        printf("\n\t  -------------------------------\n");
    }
}

int main() {

    initializeGame();
    bombSort(20);
    countBombs();
    printGame();

    return 0;
}