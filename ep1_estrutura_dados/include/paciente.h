#ifndef PACIENTE_H
#define PACIENTE_H

#define MAX 100

// Estrutura de paciente
struct Paciente {
    int id;
    char cpf[20];
    char nome[100];
    int idade;
    char data[20];
};

// Lista de pacientes
struct ListaPacientes {
    struct Paciente lista[MAX];
    int qtd;
};

// Funções
void lerArquivo(struct ListaPacientes *banco);
void mostrarTodos(struct ListaPacientes banco);
void buscar(struct ListaPacientes banco);

#endif
