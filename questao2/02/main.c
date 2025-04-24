#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALFABETO 26
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

typedef struct TrieNode
{
    struct TrieNode *children[ALFABETO];
    bool is_end_of_word;
    char *word;
} TrieNode;

TrieNode *criar_no()
{
    TrieNode *node = (TrieNode *)malloc(sizeof(TrieNode));
    for (int i = 0; i < ALFABETO; i++)
        node->children[i] = NULL;
    node->is_end_of_word = false;
    node->word = NULL;
    return node;
}

void inserir_trie(TrieNode *root, const char *palavra)
{
    TrieNode *atual = root;
    for (int i = 0; palavra[i]; i++)
    {
        int idx = palavra[i] - 'a';
        if (idx < 0 || idx >= ALFABETO)
            return;
        if (!atual->children[idx])
            atual->children[idx] = criar_no();
        atual = atual->children[idx];
    }
    atual->is_end_of_word = true;
    atual->word = strdup(palavra);
}

int dx[] = {0, 1, 1, -1};
int dy[] = {1, 0, 1, 1};

void busca(TrieNode *node, int x, int y, int dir, int step,
           int visitado[LIN][COL])
{
    int xi = x + dx[dir] * step;
    int yi = y + dy[dir] * step;

    if (xi < 0 || xi >= LIN || yi < 0 || yi >= COL || visitado[xi][yi])
        return;

    char ch = grid[xi][yi];
    if (ch < 'a' || ch > 'z')
        return;
    int idx = ch - 'a';

    if (!node->children[idx])
        return;

    visitado[xi][yi] = 1;
    node = node->children[idx];

    if (node->is_end_of_word)
        printf("Encontrou \"%s\" em (%d,%d) na direção %d\n", node->word, x,
               y, dir);

    busca(node, x, y, dir, step + 1, visitado);
    visitado[xi][yi] = 0;
}

void procurar_varias(TrieNode *root)
{
    int visitado[LIN][COL];
    for (int i = 0; i < LIN; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            char ch = grid[i][j];
            if (ch < 'a' || ch > 'z')
                continue;
            int idx = ch - 'a';
            if (root->children[idx])
            {
                for (int d = 0; d < 4; d++)
                {
                    memset(visitado, 0, sizeof(visitado));
                    if (root->children[idx]->is_end_of_word)
                        printf("Encontrou \"%s\" em (%d,%d) na direção %d\n",
                               root->children[idx]->word, i, j, d);
                    busca(root->children[idx], i, j, d, 1, visitado);
                }
            }
        }
    }
}

int main()
{
    TrieNode *root = criar_no();
    inserir_trie(root, "casa");
    inserir_trie(root, "lua");
    inserir_trie(root, "ola");
    inserir_trie(root, "padaria");
    inserir_trie(root, "paz");

    procurar_varias(root);
    return 0;
}
