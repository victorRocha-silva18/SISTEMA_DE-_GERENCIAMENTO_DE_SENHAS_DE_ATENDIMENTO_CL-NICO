#include <stdio.h>
#include "sistema.h"

// Variaveis globais do modulo de pacientes
Paciente pacientes[MAX_PACIENTES];

int totalPacientes = 0;
int contadorNormal = 0;
int contadorPreferencial = 0;
int contadorUrgente = 0;


// Procura uma vaga livre
int encontrarVagaLivre() {
    int i;

    for (i = 0; i < MAX_PACIENTES; i++) {
        if (pacientes[i].ativo == 0) {
            return i;
        }
    }

    return -1;
}


// Cadastro de paciente
void cadastrarPaciente() {
    Paciente p;
    int vaga;

    vaga = encontrarVagaLivre();

    if (vaga == -1) {
        printf("\nLimite de 50 pacientes atingido!\n");
        printf("Libere um paciente para realizar outro cadastro.\n");
        return;
    }

    printf("\n--- CADASTRO DE PACIENTE ---\n");

    // Genero
    printf("Genero (F/M/I - indeterminado): ");
    scanf(" %c", &p.genero);

    if (p.genero != 'F' && p.genero != 'f' &&
        p.genero != 'M' && p.genero != 'm' &&
        p.genero != 'I' && p.genero != 'i') {

        printf("Genero invalido!\n");
        limparEntrada();
        return;
    }

    limparEntrada();

    // Idade
    printf("Idade: ");

    if (scanf("%d", &p.idade) != 1 ||
        p.idade < 0 || p.idade > 120) {

        printf("Idade invalida!\n");
        limparEntrada();
        return;
    }

    limparEntrada();

    // Gestante
    if (p.genero == 'F' || p.genero == 'f') {
        p.gestante = perguntarSimNao(
            "Gestante? (1-Sim / 0-Nao): ");
    } else {
        p.gestante = 0;
    }

    // Lactante
    p.lactante = perguntarSimNao(
        "Lactante? (1-Sim / 0-Nao): ");

    // Necessidade especial
    p.necessidadeEspecial = perguntarSimNao(
        "Possui necessidade especial? (1-Sim / 0-Nao): ");

    // Obesidade
    p.obesidade = perguntarSimNao(
        "Possui obesidade? (1-Sim / 0-Nao): ");

    // Marca paciente como ativo e ainda nao chamado
    p.ativo = 1;
    p.chamado = 0;

    // Classifica o paciente
    p.categoria = classificarPaciente(p);

    // Gera o numero da senha
    p.numeroSenha = gerarSenha(p.categoria);

    // Armazena na primeira vaga livre
    pacientes[vaga] = p;

    totalPacientes++;

    printf("\nPaciente cadastrado com sucesso!\n");
    printf("Senha gerada: %c%03d\n",
           p.categoria, p.numeroSenha);
    printf("Vaga ocupada: %d de %d\n",
           vaga + 1, MAX_PACIENTES);
    printf("Pacientes atualmente cadastrados: %d\n",
           totalPacientes);
}


// Classifica o paciente conforme as regras de prioridade
char classificarPaciente(Paciente p) {

    // Prioridade urgente
    if (p.idade > 80) {
        return 'U';
    }

    // Prioridade preferencial por condicoes
    if (p.gestante == 1 ||
        p.lactante == 1 ||
        p.necessidadeEspecial == 1 ||
        p.obesidade == 1) {
        return 'P';
    }

    // Mulheres a partir de 60 anos
    if ((p.genero == 'F' || p.genero == 'f') &&
        p.idade >= 60) {
        return 'P';
    }

    // Homens a partir de 65 anos
    if ((p.genero == 'M' || p.genero == 'm') &&
        p.idade >= 65) {
        return 'P';
    }

    return 'N';
}


// Gera senhas independentes para cada categoria
int gerarSenha(char categoria) {

    if (categoria == 'N') {
        contadorNormal++;
        return contadorNormal;
    }

    if (categoria == 'P') {
        contadorPreferencial++;
        return contadorPreferencial;
    }

    if (categoria == 'U') {
        contadorUrgente++;
        return contadorUrgente;
    }

    return 0;
}
