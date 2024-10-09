#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

// Funzione per contare il numero di parole nella stringa
static size_t ft_string_counter(char const *s, char c) {
    size_t count = 0;
    int flag = 0;

    while (*s) {
        if (*s != c && flag == 0) {
            count++;
            flag = 1;
        }
        if (*s == c)
            flag = 0;
        s++;
    }
    return count;
}

// Funzione per duplicare una parola con una lunghezza specifica
static char *ft_word_dup(const char *start, size_t len) {
    char *word = (char *)malloc((len + 1) * sizeof(char));
    if (!word)
        return NULL;
    for (size_t i = 0; i < len; i++) {
        word[i] = start[i];
    }
    word[len] = '\0';
    return word;
}

// Funzione principale per dividere la stringa
char **ft_split(char const *s, char c) {
    if (!s)
        return NULL;

    size_t word_count = ft_string_counter(s, c);
    char **lines = (char **)malloc((word_count + 1) * sizeof(char *));
    if (!lines)
        return NULL;

    size_t i = 0;
    while (*s) {
        if (*s != c) {
            const char *start = s;
            size_t len = 0;
            while (*s && *s != c) {
                len++;
                s++;
            }
            lines[i] = ft_word_dup(start, len);
            if (!lines[i]) {
                // Gestione dell'errore: liberare tutte le risorse allocate
                for (size_t j = 0; j < i; j++) {
                    free(lines[j]);
                }
                free(lines);
                return NULL;
            }
            i++;
        } else {
            s++;
        }
    }
    lines[i] = NULL;
    return lines;
}

int main(void) {
    char *string = "ciao mappamondo bello";
    char c = ' ';
    char **res = ft_split(string, c);

    if (res) {
        for (size_t i = 0; res[i] != NULL; i++) {
            printf("Word %zu: %s\n", i, res[i]);
            free(res[i]);
        }
        free(res);
    }
    return 0;
}