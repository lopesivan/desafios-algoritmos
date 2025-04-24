#include <stdio.h>
#include <string.h>

#define LIN 5
#define COL 5

char grid[LIN][COL] = {{'c', 'c', 'a', 's', 'a'},
                       {'c', 'a', 'c', 'd', 'e'},
                       {'m', 'a', 's', 'c', 'o'},
                       {'p', 'a', 'l', 'a', 'v'},
                       {'o', 'l', 'a', 's', 'x'}};

// Verifica se a palavra está na posição (linha, col) em uma direção
int busca_palavra(const char *palavra, int lin, int col, int dx, int dy)
{
    /* printf("palavra: (%s)\n", palavra); */
    int len = strlen(palavra);

    printf("-->(%d,%d)\n", lin, col);

    for (int i = 0; i < len; i++)
    {
        int x = lin + i * dx;
        int y = col + i * dy;

        printf("(%d,%d)\n", x, y);
        /* printf("grid(%d,%d) = %d\n", x, y, grid[x][y]); */
        /* printf("palavra(%d) = %d\n", i, palavra[i]); */

        if (x < 0 || x >= LIN || y < 0 || y >= COL)
            return 0;

        if (grid[x][y] != palavra[i])
        {
            printf("grid(%d,%d) = %d\n", x, y, grid[x][y]);
            printf("palavra(%d) = %d\n", i, palavra[i]);
            printf("BB(%d,%d)\n", x, y);
            return 0;
        }
    }
    return 1;
}

void procurar(const char *palavra)
{
    for (int i = 0; i < LIN; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            /* dx=0,  dy=1 → direita (horizontal) */
            /* dx=1,  dy=0 → baixo (vertical) */
            /* dx=1,  dy=1 → diagonal inferior-direita */
            /* dx=-1, dy=1 → diagonal superior-direita */

            // Direção: direita
            if (busca_palavra(palavra, i, j, 0, 1))
            {
                printf("Encontrou \"%s\" na horizontal em (%d,%d)\n", palavra,
                       i, j);
            }

            // Direção: baixo
            if (busca_palavra(palavra, i, j, 1, 0))
            {
                printf("Encontrou \"%s\" na vertical em (%d,%d)\n", palavra,
                       i, j);
            }

            // Direção: diagonal inferior-direita
            if (busca_palavra(palavra, i, j, 1, 1))
            {
                printf("Encontrou \"%s\" na diagonal em (%d,%d)\n", palavra,
                       i, j);
            }
        }
    }
}

int main()
{
    procurar("casa");
    procurar("pala");
    procurar("ola");
    return 0;
}
