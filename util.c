#include <stdio.h>
#include "sistema.h"

// Pergunta com resposta sim ou nao
int perguntarSimNao(char pergunta[]) {
    int resposta;

    while (1) {
        printf("%s", pergunta);

        if (scanf("%d", &resposta) != 1) {
            printf("Digite 1 para Sim ou 0 para Nao.\n");
            limparEntrada();
            continue;
        }

        limparEntrada();

        if (resposta == 0 || resposta == 1) {
            return resposta;
        }

        printf("Opcao invalida! Digite 1 ou 0.\n");
    }
}

// Limpa caracteres restantes da entrada
void limparEntrada() {
    int caractere;

    while ((caractere = getchar()) != '\n' &&
           caractere != EOF) {
        // Descarta os caracteres restantes
    }
}
