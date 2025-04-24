#include <stdio.h>

int main(void) {
  char *s = "abcdabcbb";
  int freq[256] = {0}; // Tabela ASCII (de 0 a 255)

  // Contagem de frequência
  for (char *p = s; *p != '\0'; p++) {
    freq[(unsigned char)*p]++;
  }

  // Impressão dos caracteres que aparecem (frequência > 0)
  for (int i = 0; i < 256; i++) {
    if (freq[i] > 0) {
      printf("freq[%d] = %d (%c)\n", i, freq[i], i);
    }
  }

  return 0;
}
