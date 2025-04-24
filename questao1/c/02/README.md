Você pode otimizar o tamanho do array `freq` se souber
**qual é o intervalo real de caracteres que deseja contar**
— especialmente se estiver lidando só com **letras
minúsculas**, **letras alfabéticas em geral**, ou **apenas
ASCII imprimível**.

---

## 🧠 Quando você **precisa de 256 posições**?

Você só precisa de `int freq[256]` se:

- Está processando qualquer **caractere ASCII completo** (0 a 255), como arquivos binários, ou entrada de teclado geral.
- Quer aceitar letras, símbolos, números, controle, tudo.

---

## ✅ Se só quiser letras minúsculas (`a` a `z`):

Use:

```c
int freq[26] = {0};
```

E indexe assim:

```c
freq[*p - 'a']++;
```

### ⚠️ Cuidado:
Você deve garantir que o caractere esteja **entre 'a' e
'z'**, senão pode acessar fora do array.

Exemplo completo:

```c
#include <stdio.h>

int main(void) {
    char *s = "abcdabcbb";
    int freq[26] = {0};

    for (char *p = s; *p != '\0'; p++) {
        if (*p >= 'a' && *p <= 'z') {
            freq[*p - 'a']++;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            printf("%c: %d\n", i + 'a', freq[i]);
        }
    }

    return 0;
}
```

---

## ✅ Outras opções de redução:

| Caso alvo                       | Tamanho ideal | Índice                      |
|-------------------------------|----------------|-----------------------------|
| Letras minúsculas `a`–`z`     | 26             | `*p - 'a'`                  |
| Letras maiúsculas `A`–`Z`     | 26             | `*p - 'A'`                  |
| Letras alfabéticas (a–z, A–Z) | 52             | mapa manual ou dupla tabela |
| Dígitos `0`–`9`               | 10             | `*p - '0'`                  |
| ASCII imprimível (`32`–`126`) | 95             | `*p - 32`                   |

---

## ✅ Conclusão:

- Use `freq[256]` se for generalista.
- Use `freq[26]` se for só letras minúsculas.
- Sempre **valide o intervalo** se for usar um array menor.

Se quiser, posso gerar uma função que conta letras independentemente de serem maiúsculas ou minúsculas (com `tolower`). Deseja?
