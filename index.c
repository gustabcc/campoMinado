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

int main() {

    initializeGame();
    bombSort(20);

    return 0;
}