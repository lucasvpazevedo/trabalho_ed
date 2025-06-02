#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/paciente.h"

void lerArquivo(struct ListaPacientes *banco) {
    FILE *f = fopen("bd_paciente.csv", "r");
    if (f == NULL) {
        printf("Erro ao abrir arquivo\n");
        exit(1);
    }

    char linha[300];
    banco->qtd = 0;
    fgets(linha, sizeof(linha), f);

    while (fgets(linha, sizeof(linha), f)) {
        if (banco->qtd >= MAX) break;
        struct Paciente p;
        char *tok = strtok(linha, ",");
        p.id = atoi(tok);

        tok = strtok(NULL, ",");
        strcpy(p.cpf, tok);

        tok = strtok(NULL, ",");
        strcpy(p.nome, tok);

        tok = strtok(NULL, ",");
        p.idade = atoi(tok);

        tok = strtok(NULL, ",\n");
        strcpy(p.data, tok);

        banco->lista[banco->qtd] = p;
        banco->qtd++;
    }

    fclose(f);
}

void mostrarTodos(struct ListaPacientes banco) {
    printf("\nLISTA DE PACIENTES\n");
    for (int i = 0; i < banco.qtd; i++) {
        struct Paciente p = banco.lista[i];
        printf("%d %s %s %d %s\n", p.id, p.cpf, p.nome, p.idade, p.data);
    }
}

void buscar(struct ListaPacientes banco) {
    int opcao;
    char busca[100];
    printf("\n1 - Nome\n2 - CPF\n3 - Voltar\n");
    scanf("%d", &opcao);
    getchar();

    if (opcao == 3) return;

    printf("Digite: ");
    fgets(busca, sizeof(busca), stdin);
    busca[strcspn(busca, "\n")] = 0;

    for (int i = 0; i < banco.qtd; i++) {
        struct Paciente p = banco.lista[i];
        if ((opcao == 1 && strncmp(p.nome, busca, strlen(busca)) == 0) ||
            (opcao == 2 && strncmp(p.cpf, busca, strlen(busca)) == 0)) {
            printf("%d %s %s %d %s\n", p.id, p.cpf, p.nome, p.idade, p.data);
        }
    }
}
