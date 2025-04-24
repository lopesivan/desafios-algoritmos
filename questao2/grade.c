#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 10
#define M 10

char grid[N][M];

void inicializar_grade()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            grid[i][j] = '_'; // ou letra aleatória
            /* grid[i][j] = 'a' + rand() % 26; */
        }
}

int cabe_na_grade(const char *palavra, int x, int y, int dx, int dy)
{
    int len = strlen(palavra);
    for (int i = 0; i < len; i++)
    {
        int xi = x + i * dx;
        int yi = y + i * dy;
        if (xi < 0 || xi >= N || yi < 0 || yi >= M)
            return 0;
        if (grid[xi][yi] != '_' && grid[xi][yi] != palavra[i])
            return 0;
    }
    return 1;
}

void inserir_palavra(const char *palavra, int x, int y, int dx, int dy)
{
    int len = strlen(palavra);
    for (int i = 0; i < len; i++)
    {
        int xi = x + i * dx;
        int yi = y + i * dy;
        grid[xi][yi] = palavra[i];
    }
}

void mostrar_grade()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            printf("%c ", grid[i][j]);
        printf("\n");
    }
}

int main()
{
    srand(time(NULL));
    inicializar_grade();

    // Inserção manual
    inserir_palavra("casa", 0, 0, 0, 1);    // horizontal
    inserir_palavra("ola", 1, 0, 1, 0);     // vertical
    inserir_palavra("paz", 3, 4, 1, 1);     // diagonal ↘️
    inserir_palavra("lua", 6, 3, -1, 1);    // diagonal ↗️
    inserir_palavra("padaria", 8, 0, 0, 1); // horizontal

    mostrar_grade();
    return 0;
}
