#include <stdio.h>
#include <string.h>

#define LIN 20
#define COL 10

char grid[LIN][COL] = {{'c', 'a', 's', 'a', 'w', 'x', 'h', 'o', 'a', 'q'},
                       {'o', 'b', 'h', 'b', 'c', 'w', 'r', 'b', 'l', 's'},
                       {'l', 'z', 'l', 'h', 'a', 'v', 'p', 'e', 'w', 'l'},
                       {'a', 'j', 'k', 'v', 'p', 'i', 's', 'd', 'w', 't'},
                       {'v', 'w', 'w', 'f', 'z', 'a', 'b', 'q', 'z', 'm'},
                       {'k', 'q', 'o', 'v', 'u', 'o', 'z', 'm', 'v', 'p'},
                       {'z', 'c', 'y', 'l', 'y', 't', 'u', 'q', 'w', 'c'},
                       {'l', 'u', 'p', 'h', 'z', 'o', 'h', 'a', 'h', 'a'},
                       {'p', 'a', 'd', 'a', 'r', 'i', 'a', 'i', 'm', 's'},
                       {'x', 'l', 'o', 'v', 'z', 'o', 'o', 'u', 'f', 'a'},
                       {'n', 's', 'h', 'e', 'a', 'g', 'u', 'j', 'g', 'b'},
                       {'s', 'u', 'v', 't', 'v', 'k', 'r', 'm', 's', 'd'},
                       {'y', 'r', 'r', 'm', 'm', 'q', 'b', 'c', 'm', 'i'},
                       {'p', 'b', 'a', 'y', 'f', 'c', 'e', 'c', 'm', 'm'},
                       {'a', 'g', 'h', 'a', 'a', 'e', 'm', 'r', 'q', 'g'},
                       {'d', 'q', 'p', 'q', 'e', 'l', 'i', 'h', 'o', 'x'},
                       {'a', 'f', 'a', 's', 'e', 'g', 'w', 'k', 'i', 'i'},
                       {'r', 'n', 'z', 'g', 'o', 'p', 'k', 'c', 'i', 'c'},
                       {'i', 'h', 'u', 'i', 'z', 'y', 'u', 'i', 'g', 'k'},
                       {'a', 'x', 'p', 'f', 'p', 'v', 'l', 'm', 'g', 't'}};

// Verifica se a palavra está na posição (linha, col) em uma direção
int busca_palavra(const char *palavra, int lin, int col, int dx, int dy)
{
    /* printf("palavra: (%s)\n", palavra); */
    int len = strlen(palavra);

    for (int i = 0; i < len; i++)
    {
        int x = lin + i * dx;
        int y = col + i * dy;

        if (x < 0 || x >= LIN || y < 0 || y >= COL)
            return 0;

        if (grid[x][y] != palavra[i])
        {
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
            /* ### 🧭 Direções (dx, dy):
            | Direção              | dx | dy |
            |----------------------|----|----|
            | Horizontal direita   | 0  | 1  |
            | Vertical para baixo  | 1  | 0  |
            | Diagonal ↘️          | 1  | 1  |
            | Diagonal ↗️          | -1 | 1  |
            */

            // Direção: Horizontal direita
            if (busca_palavra(palavra, i, j, 0, 1))
            {
                printf("Encontrou \"%s\" na Horizontal direita (→) em "
                       "(%d,%d)\n",
                       palavra, i, j);
            }

            // Direção: Vertical para baixo
            if (busca_palavra(palavra, i, j, 1, 0))
            {
                printf("Encontrou \"%s\" na Vertical para baixo (↓) em "
                       "(%d,%d)\n",
                       palavra, i, j);
            }

            // Direção: Diagonal ↘️
            if (busca_palavra(palavra, i, j, 1, 1))
            {
                printf("Encontrou \"%s\" na Diagonal inferior-direita (↘️) em "
                       "(%d,%d)\n",
                       palavra, i, j);
            }

            // Direção: Diagonal ↗️
            if (busca_palavra(palavra, i, j, -1, 1))
            {
                printf("Encontrou \"%s\" na Diagonal superior-direita (↗️) em "
                       "(%d,%d)\n",
                       palavra, i, j);
            }
        }
    }
}

int main()
{
    procurar("paz");
    procurar("casa");
    procurar("ola");
    procurar("lua");
    procurar("padaria");
    printf("\n"
           "c a s a _ _ _ _ _ _\n"
           "o _ _ _ _ _ _ _ _ _\n"
           "l _ _ _ _ _ _ _ _ _\n"
           "a _ _ _ p _ _ _ _ _\n"
           "_ _ _ _ _ a _ _ _ _\n"
           "_ _ _ _ u _ z _ _ _\n"
           "_ _ _ l _ _ _ _ _ c\n"
           "_ _ _ _ _ _ _ _ _ a\n"
           "p a d a r i a _ _ s\n"
           "_ _ _ _ _ _ _ _ _ a\n"
           "_ _ _ _ _ _ _ _ _ _\n"
           "_ _ _ _ _ _ _ _ _ _\n"
           "_ _ _ _ _ _ _ _ _ _\n"
           "_ _ _ _ _ _ _ _ _ _\n"
           "_ _ _ _ _ _ _ _ _ _\n"
           "_ _ _ _ _ _ _ _ _ _\n"
           "_ _ _ _ _ _ _ _ _ _\n"
           "_ _ _ _ _ _ _ _ _ _\n"
           "_ _ _ _ _ _ _ _ _ _\n"
           "_ _ _ _ _ _ _ _ _ _\n");
    return 0;
}
