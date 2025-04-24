#include <stdio.h>
#include <string.h>

int main(void) {
  const char *s = "hhhhhh abc abc abc dabcef abc";
  const char *q = "abc";
  int count = 0;

  const char *p = s;

  while ((p = strstr(p, q)) != NULL) {
    count++;
    p += 1; // avança um caractere para permitir sobreposição (ou use p +=
            // strlen(q); para não contar sobrepostas)
  }

  printf("Total de ocorrências: %d\n", count);

  return 0;
}
