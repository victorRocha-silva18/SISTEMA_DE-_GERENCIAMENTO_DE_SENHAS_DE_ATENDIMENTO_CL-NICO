#include <stdio.h>
#include "sistema.h"

// Exibe o painel de acompanhamento
void mostrarPainel() {
    int i;
    int aguardando = 0;
    int emAtendimento = 0;
    int normais = 0;
    int preferenciais = 0;
    int urgentes = 0;

    printf("\n");
    printf("============================================\n");
    printf("       PAINEL DE ATENDIMENTO CLINICO\n");
    printf("============================================\n");

    // Conta pacientes ativos por categoria e status
    for (i = 0; i < MAX_PACIENTES; i++) {

        if (pacientes[i].ativo == 1) {

            if (pacientes[i].chamado == 0) {
                aguardando++;
            } else {
                emAtendimento++;
            }

            if (pacientes[i].categoria == 'N') {
                normais++;
            } else if (pacientes[i].categoria == 'P') {
                preferenciais++;
            } else if (pacientes[i].categoria == 'U') {
                urgentes++;
            }
        }
    }

    // Resumo geral
    printf("\n--- RESUMO GERAL ---\n");
    printf("Pacientes ativos:       %d / %d\n",
           totalPacientes, MAX_PACIENTES);
    printf("Aguardando chamada:     %d\n", aguardando);
    printf("Em atendimento:          %d\n", emAtendimento);
    printf("Vagas disponiveis:     %d\n",
           MAX_PACIENTES - totalPacientes);

    // Distribuicao por prioridade
    printf("\n--- FILAS POR PRIORIDADE ---\n");
    printf("Urgentes:                %d\n", urgentes);
    printf("Preferenciais:           %d\n", preferenciais);
    printf("Normais:                 %d\n", normais);

    // Lista de pacientes ativos
    printf("\n--- LISTA DE PACIENTES ---\n");

    if (totalPacientes == 0) {
        printf("Nenhum paciente cadastrado.\n");
    } else {
        printf("%-10s %-15s %-12s\n",
               "Senha", "Categoria", "Status");
        printf("--------------------------------------------\n");

        for (i = 0; i < MAX_PACIENTES; i++) {

            if (pacientes[i].ativo == 1) {

                printf("%c%03d      ",
                       pacientes[i].categoria,
                       pacientes[i].numeroSenha);

                if (pacientes[i].categoria == 'U') {
                    printf("%-15s ", "Urgente");
                } else if (pacientes[i].categoria == 'P') {
                    printf("%-15s ", "Preferencial");
                } else {
                    printf("%-15s ", "Normal");
                }

                if (pacientes[i].chamado == 1) {
                    printf("Em atendimento\n");
                } else {
                    printf("Aguardando\n");
                }
            }
        }
    }

    printf("\n============================================\n");
}
