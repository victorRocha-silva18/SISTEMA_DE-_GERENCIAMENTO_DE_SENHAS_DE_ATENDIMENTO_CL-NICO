#include <stdio.h>
#include "sistema.h"

// Chama o proximo paciente conforme a prioridade
void chamarProximo() {
    int i;
    int escolhido = -1;
    int maiorPrioridade = 0;

    printf("\n--- CHAMADA DE PACIENTE ---\n");

    for (i = 0; i < MAX_PACIENTES; i++) {

        if (pacientes[i].ativo == 1 &&
            pacientes[i].chamado == 0) {

            int prioridade;

            if (pacientes[i].categoria == 'U') {
                prioridade = 3;
            } else if (pacientes[i].categoria == 'P') {
                prioridade = 2;
            } else {
                prioridade = 1;
            }

            if (prioridade > maiorPrioridade) {
                maiorPrioridade = prioridade;
                escolhido = i;
            }

            else if (prioridade == maiorPrioridade &&
                     escolhido != -1 &&
                     pacientes[i].numeroSenha <
                     pacientes[escolhido].numeroSenha) {
                escolhido = i;
            }
        }
    }

    if (escolhido == -1) {
        printf("Nao ha pacientes aguardando chamada.\n");
        return;
    }

    // Marca como chamado
    pacientes[escolhido].chamado = 1;

    printf("\nProximo paciente:\n");
    printf("Senha: %c%03d\n",
           pacientes[escolhido].categoria,
           pacientes[escolhido].numeroSenha);

    if (pacientes[escolhido].categoria == 'U') {
        printf("Classificacao: URGENTE\n");
    } else if (pacientes[escolhido].categoria == 'P') {
        printf("Classificacao: PREFERENCIAL\n");
    } else {
        printf("Classificacao: NORMAL\n");
    }
}


// Finaliza o atendimento e libera a vaga
void finalizarAtendimento() {
    char categoria;
    int numero;
    int i;

    printf("\n--- FINALIZAR ATENDIMENTO ---\n");
    printf("Digite a senha do paciente (ex: U001): ");

    if (scanf(" %c%d", &categoria, &numero) != 2) {
        printf("Senha invalida!\n");
        limparEntrada();
        return;
    }

    limparEntrada();

    // Converte a categoria para maiuscula
    if (categoria >= 'a' && categoria <= 'z') {
        categoria = categoria - 32;
    }

    // Valida categoria e numero
    if ((categoria != 'U' &&
         categoria != 'P' &&
         categoria != 'N') ||
         numero <= 0) {
        printf("Senha invalida!\n");
        return;
    }

    // Procura o paciente pela senha
    for (i = 0; i < MAX_PACIENTES; i++) {

        if (pacientes[i].ativo == 1 &&
            pacientes[i].categoria == categoria &&
            pacientes[i].numeroSenha == numero) {

            // Verifica se o paciente foi chamado
            if (pacientes[i].chamado == 0) {
                printf("Este paciente ainda nao foi chamado.\n");
                return;
            }

            // Libera o paciente
            pacientes[i].ativo = 0;
            pacientes[i].chamado = 0;

            totalPacientes--;

            printf("\nAtendimento finalizado com sucesso!\n");
            printf("Senha liberada: %c%03d\n",
                   categoria, numero);
            printf("Vaga %d liberada para novo cadastro.\n",
                   i + 1);
            printf("Pacientes atualmente cadastrados: %d\n",
                   totalPacientes);

            return;
        }
    }

    printf("Paciente nao encontrado ou ja finalizado.\n");
}
