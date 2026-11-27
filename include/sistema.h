#ifndef SISTEMA_H
#define SISTEMA_H

// Limite de pacientes
#define MAX_PACIENTES 50

// Estrutura de dados do paciente
typedef struct {
    int idade;
    char genero;
    int gestante;
    int lactante;
    int necessidadeEspecial;
    int obesidade;
    int ativo;
    int chamado;
    char categoria;
    int numeroSenha;
} Paciente;

// Variaveis compartilhadas entre os modulos
extern Paciente pacientes[MAX_PACIENTES];

extern int totalPacientes;
extern int contadorNormal;
extern int contadorPreferencial;
extern int contadorUrgente;

// Funcoes do sistema
void menu();
void executarSistema();

// Funcoes de pacientes
void cadastrarPaciente();
int encontrarVagaLivre();
char classificarPaciente(Paciente p);
int gerarSenha(char categoria);

// Funcoes da fila
void chamarProximo();
void finalizarAtendimento();

// Funcao do painel
void mostrarPainel();

// Funcoes auxiliares
int perguntarSimNao(char pergunta[]);
void limparEntrada();

#endif
