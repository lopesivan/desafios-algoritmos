#include <stdio.h>

int main(void) {
  char *s = "abcabcbb";
  int max = 0;

  for (char *start = s; *start != '\0'; start++) {
    int count = 0;
    char seen[256] = {0}; // tabela ASCII

    for (char *end = start; *end != '\0'; end++) {

      if (seen[(unsigned char)*end])
        break; // caractere repetido encontrado

      seen[(unsigned char)*end] = 1;
      count++;
    }

    if (count > max)
      max = count;
  }

  printf("Maior substring sem repetição: %d caracteres\n", max);
  return 0;
}
