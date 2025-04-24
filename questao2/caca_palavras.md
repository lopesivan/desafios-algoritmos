Vamos construir **um gerador de caça-palavras em C**,
onde você:

✅ Define o tamanho da matriz
✅ Escolhe palavras
✅ Escolhe a direção de inserção:
- Horizontal
- Vertical
- Diagonal inferior-direita (↘️)
- Diagonal superior-direita (↗️)

---

## 🧠 Estratégia:

1. Criar uma matriz `char grid[LIN][COL]` com tamanho `N×M`
2. Preencher com `'_'` ou letras aleatórias
3. Para cada palavra:
   - Escolher posição inicial
   - Escolher direção: `(dx, dy)`
   - Verificar se cabe
   - Inserir na matriz

---

## ✅ Código base para gerar a matriz e inserir palavras

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 10
#define M 10

char grid[N][M];

void inicializar_grade() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            grid[i][j] = '_'; // ou letra aleatória
}

int cabe_na_grade(const char *palavra, int x, int y, int dx, int dy) {
    int len = strlen(palavra);
    for (int i = 0; i < len; i++) {
        int xi = x + i * dx;
        int yi = y + i * dy;
        if (xi < 0 || xi >= N || yi < 0 || yi >= M)
            return 0;
        if (grid[xi][yi] != '_' && grid[xi][yi] != palavra[i])
            return 0;
    }
    return 1;
}

void inserir_palavra(const char *palavra, int x, int y, int dx, int dy) {
    int len = strlen(palavra);
    for (int i = 0; i < len; i++) {
        int xi = x + i * dx;
        int yi = y + i * dy;
        grid[xi][yi] = palavra[i];
    }
}

void mostrar_grade() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            printf("%c ", grid[i][j]);
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    inicializar_grade();

    // Inserção manual
    inserir_palavra("casa", 0, 0, 0, 1); // horizontal
    inserir_palavra("ola", 0, 0, 1, 0);  // vertical
    inserir_palavra("paz", 1, 1, 1, 1);  // diagonal ↘️
    inserir_palavra("lua", 5, 2, -1, 1); // diagonal ↗️

    mostrar_grade();
    return 0;
}
```

---

### 🧭 Direções (dx, dy):

| Direção              | dx | dy |
|----------------------|----|----|
| Horizontal direita   | 0  | 1  |
| Vertical para baixo  | 1  | 0  |
| Diagonal ↘️          | 1  | 1  |
| Diagonal ↗️          | -1 | 1  |

---

### ⚠️ Validação:
Antes de inserir, sempre use `cabe_na_grade(...)` para evitar
sobrescritas ou ultrapassar os limites.

---

Se quiser automatizar a **escolha aleatória de direção
e posição**, ou preencher o resto da matriz com letras
aleatórias depois, posso te mostrar também. Deseja seguir
por aí?
