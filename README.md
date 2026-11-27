# Sistema de Gerenciamento de Senhas de Atendimento Clínico

## Sobre o projeto

O **Sistema de Gerenciamento de Senhas de Atendimento Clínico** é um projeto desenvolvido em linguagem C com o objetivo de simular o gerenciamento de filas de atendimento em uma clínica.

O sistema permite cadastrar pacientes, classificá-los de acordo com critérios de prioridade, gerar senhas, chamar o próximo paciente e acompanhar a situação dos atendimentos por meio de um painel.

O projeto também utiliza a **modularização**, dividindo o código em diferentes arquivos para organizar as funcionalidades e facilitar a manutenção.

## Funcionalidades

- Cadastro de pacientes.
- Classificação automática por categoria de atendimento.
- Geração de senhas individuais por categoria.
- Chamada do próximo paciente respeitando a prioridade.
- Finalização de atendimentos.
- Exibição de painel com informações da fila.
- Validação de entradas do usuário.
- Organização do código em módulos independentes.

## Regras de classificação

Os pacientes são organizados em três categorias:

| Categoria | Critérios |
|---|---|
| **Urgente (U)** | Pacientes com idade superior a 80 anos. |
| **Preferencial (P)** | Gestantes, lactantes, pessoas com necessidades especiais, pessoas com obesidade, mulheres a partir de 60 anos e homens a partir de 65 anos. |
| **Normal (N)** | Pacientes que não se enquadram nos critérios anteriores. |

### Ordem de atendimento

A prioridade de chamada segue esta ordem:

1. **Urgente (U)**
2. **Preferencial (P)**
3. **Normal (N)**

Dentro de cada categoria, os pacientes são chamados na ordem em que foram cadastrados, seguindo o critério FIFO (*First In, First Out*).

As senhas são geradas separadamente para cada categoria, utilizando os prefixos U, P e N.

## Organização dos arquivos

O projeto está dividido da seguinte maneira:

```text
SISTEMA_DE_GERENCIAMENTO_DE_SENHAS/
│
├── include/
│   └── sistema.h
│
├── src/
│   ├── main.c
│   ├── sistema.c
│   ├── pacientes.c
│   ├── fila.c
│   ├── painel.c
│   └── util.c
│
└── README.md
```

### Responsabilidade de cada arquivo

| Arquivo | Responsabilidade |
|---|---|
| `main.c` | Ponto de entrada do programa. |
| `sistema.c` | Gerencia o menu e a execução do sistema. |
| `pacientes.c` | Realiza o cadastro, a classificação e a geração de senhas. |
| `fila.c` | Gerencia a chamada e a finalização dos atendimentos. |
| `painel.c` | Exibe as informações e o estado atual da fila. |
| `util.c` | Contém funções auxiliares para entrada de dados. |
| `sistema.h` | Reúne as estruturas, variáveis compartilhadas e declarações das funções. |

## Ferramentas e tecnologias utilizadas

- **Linguagem C:** utilizada no desenvolvimento da lógica e das funcionalidades do sistema.
- **OnlineGDB:** ambiente online utilizado para escrever, compilar e executar o código, além de realizar os testes do programa.
- **GitHub:** plataforma utilizada para armazenar e organizar os arquivos do projeto.
- **ChatGPT:** ferramenta de apoio utilizada na compreensão dos conceitos, modularização, organização e revisão do código.

## Conceitos aplicados

Durante o desenvolvimento, foram trabalhados conceitos fundamentais da programação em C:

- Estruturas de dados (`struct`).
- Variáveis e tipos de dados.
- Condicionais e estruturas de repetição.
- Funções e modularização.
- Manipulação de vetores.
- Variáveis globais e compartilhamento de dados entre módulos.
- Gerenciamento de filas e regras de prioridade.
- Validação de entradas do usuário.

## Objetivo acadêmico

O projeto foi desenvolvido como exercício prático de programação em linguagem C, com o propósito de aplicar os conhecimentos adquiridos durante os estudos e desenvolver uma solução organizada para o gerenciamento de filas de atendimento.

Além da implementação das funcionalidades, o desenvolvimento permitiu trabalhar a divisão do código em módulos, a reutilização de funções e a organização de um projeto com múltiplos arquivos.
