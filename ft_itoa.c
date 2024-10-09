#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

// Funzione per capovolgere una stringa
static void reverse(char *str, int len) {
    int start = 0;
    int end = len - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

char *ft_itoa(int n) {
    int cont = 0;
    int flag = 0;
    unsigned int x;

    // Gestione del numero negativo
    if (n < 0) {
        flag = 1;
        x = (unsigned int)(-n); // Converte n in positivo senza problemi di overflow
    } else {
        x = (unsigned int)n;
    }

    // Conta il numero di cifre
    unsigned int tmp = x;
    do {
        tmp /= 10;
        cont++;
    } while (tmp != 0);

    // Aggiunge spazio per il segno negativo, se necessario
    if (flag) {
        cont++;
    }

    // Allocazione della memoria
    char *str = (char *)malloc((cont + 1) * sizeof(char));
    if (!str)
        return NULL;

    // Conversione in stringa
    int i = 0;
    do {
        str[i++] = (x % 10) + '0';
        x /= 10;
    } while (x != 0);

    // Aggiunge il segno meno, se necessario
    if (flag) {
        str[i++] = '-';
    }

    // Aggiunge il terminatore nullo
    str[i] = '\0';

    // Capovolge la stringa per ottenere il numero nel giusto ordine
    reverse(str, i);

    return str;
}

int main(void) {
    int test_cases[] = {0, 1, -1, 10, -10, 123, -123, 2147483647, -2147483648};
    int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

    for (int i = 0; i < num_tests; i++) {
        char *res = ft_itoa(test_cases[i]);
        if (res) {
            printf("Numero: %d -> Stringa: %s\n", test_cases[i], res);
            free(res);
        } else {
            printf("Errore nell'allocazione della memoria per il numero %d\n", test_cases[i]);
        }
    }

    return 0;
}
