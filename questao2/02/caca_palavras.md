Seu algoritmo atual percorre a **matriz inteira (LIN × COL ×
4 direções)** para cada palavra — o que funciona bem para
matrizes pequenas, mas pode ser **otimizado** para situações
maiores ou com muitas palavras.

---

## 🧠 Primeiro: seu algoritmo atual (resumo)

Para cada célula `(i, j)`, e para cada palavra, tenta
encontrar a palavra nas direções:

- → direita
- ↓ para baixo
- ↘ diagonal inferior-direita
- ↗ diagonal superior-direita

Isso dá uma **complexidade O(LIN × COL × D × L)** por palavra:

- LIN × COL → tamanho da matriz
- D = 4 → número de direções
- L → comprimento da palavra

---

## ⚡ Agora: ideias para otimização

### ✅ 1. **Pré-filtrar por primeira letra**
Antes de tentar todas as direções, só testa células onde
o caractere **bate com o primeiro caractere da palavra**:

```c
if (grid[i][j] == palavra[0]) {
    // agora sim testa direções
}
```

⬅️ Essa simples checagem já corta muitos testes desnecessários.

---

### ✅ 2. **Compactar as direções com um loop**

Ao invés de 4 `if`s separados, usa uma tabela de direções e faz:

```c
int dirs[4][2] = {
    {0, 1},   // →
    {1, 0},   // ↓
    {1, 1},   // ↘
    {-1, 1},  // ↗
};

for (int d = 0; d < 4; d++) {
    if (busca_palavra(palavra, i, j, dirs[d][0], dirs[d][1])) {
        // imprime posição e direção
    }
}
```

Mais limpo e evita repetição.

---

### ✅ 3. **Prefix Trie (avançado)**

Para múltiplas palavras, um **Trie (árvore de prefixo)** pode ser usado:

- Ao invés de verificar uma palavra por vez,
- Você percorre a matriz e **caminha em um Trie** de palavras válidas
- Isso permite buscar **várias palavras ao mesmo tempo**

✅ Usado em **Wordament**, **Boggle**, etc.

---

### ✅ 4. **Stop early**

Se você não precisa de todas as ocorrências, só a **primeira**, pode:

```c
if (busca_palavra(...)) {
    return;
}
```

---

## 🧪 Benchmark mental:

Com pré-filtragem por primeira letra, você reduz a busca
para só onde há potencial real.

Com Trie, você ganha **drasticamente** quando há **muitas
palavras e sobreposições**.

---
