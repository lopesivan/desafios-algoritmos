#include <stdio.h>

int main(void)
{
    char *s = "abcdabcbb";
    int max = 0;

    for (char *start = s; *start != '\0'; start++)
    {
        int count = 0;
        char seen[256] = {0}; // tabela ASCII

        printf("start: %c\n", *start);
        for (char *end = start; *end != '\0'; end++)
        {
            printf("end: %c\n", *end);
            printf("seen[%u] = %d\n", (unsigned char)*end,
                   seen[(unsigned char)*end]);

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
