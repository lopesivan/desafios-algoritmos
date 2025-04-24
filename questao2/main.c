#include <stdio.h>
#include <string.h>

#define LIN 5
#define COL 5

char grid[LIN][COL] = {
    {'c', 'a', 's', 'a', 't'},
    {'a', 'b', 'c', 'd', 'e'},
    {'m', 'a', 'r', 'c', 'o'},
    {'p', 'a', 'l', 'a', 'v'},
    {'o', 'l', 'a', 's', 'x'}
};

// Verifica se a palavra está na posição (linha, col) em uma direção
int busca_palavra(const char *palavra, int lin, int col, int dx, int dy) {
    int len = strlen(palavra);
    for (int i = 0; i < len; i++) {
        int x = lin + i * dx;
        int y = col + i * dy;
        if (x < 0 || x >= LIN || y < 0 || y >= COL)
            return 0;
        if (grid[x][y] != palavra[i])
            return 0;
    }
    return 1;
}

void procurar(const char *palavra) {
    for (int i = 0; i < LIN; i++) {
        for (int j = 0; j < COL; j++) {
            // Direções: direita, baixo
            if (busca_palavra(palavra, i, j, 0, 1)) {
                printf("Encontrou \"%s\" na horizontal em (%d,%d)\n", palavra, i, j);
            }
            if (busca_palavra(palavra, i, j, 1, 0)) {
                printf("Encontrou \"%s\" na vertical em (%d,%d)\n", palavra, i, j);
            }
        }
    }
}

int main() {
    procurar("casa");
    procurar("pala");
    procurar("ola");
    return 0;
}
