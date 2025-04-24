#include <stdio.h>
#include <string.h>

int main(void) {
  const char *s =
      "abavvsfhdjb "
      "bdgdfdfdndndhdfgdfgsjhskdduydegwabcabababcababahdhdhabcdgdrrfefe";
  const char *q = "abc";

  const char *pos = strstr(s, q); // busca a substring

  if (pos) {
    printf("Substring encontrada na posição: %ld\n", pos - s);
  } else {
    printf("Substring não encontrada.\n");
  }

  return 0;
}
