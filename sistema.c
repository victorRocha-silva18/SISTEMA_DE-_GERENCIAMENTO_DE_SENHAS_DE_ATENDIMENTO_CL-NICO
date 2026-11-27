#include <stdio.h>
#include "sistema.h"

// Exibe o menu principal
void menu() {
    printf("\n");
    printf("====================================\n");
    printf(" SISTEMA DE ATENDIMENTO CLINICO\n");
    printf("====================================\n");
    printf("1 - Cadastrar paciente\n");
    printf("2 - Chamar proximo paciente\n");
    printf("3 - Finalizar atendimento\n");
    printf("4 - Mostrar painel\n");
    printf("0 - Sair\n");
    printf("------------------------------------\n");
}

// Controla o funcionamento do sistema
void executarSistema() {
    int opcao;

    do {
        menu();

        printf("Escolha uma opcao: ");

        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida! Digite apenas numeros.\n");
            limparEntrada();
            opcao = -1;
            continue;
        }

        switch (opcao) {
            case 1:
                cadastrarPaciente();
                break;

            case 2:
                chamarProximo();
                break;

            case 3:
                finalizarAtendimento();
                break;

            case 4:
                mostrarPainel();
                break;

            case 0:
                printf("Encerrando o sistema...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);
}
