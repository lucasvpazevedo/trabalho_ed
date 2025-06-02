#include <stdio.h>
#include "../include/paciente.h"

int main() {
    struct ListaPacientes banco;
    char opcao;

    lerArquivo(&banco);

    while (1) {
        printf("\nMENU\n");
        printf("1 - Buscar paciente\n");
        printf("2 - Ver todos\n");
        printf("Q - Sair\n");
        printf("Opcao: ");
        scanf(" %c", &opcao);

        switch (opcao) {
            case '1':
                buscar(banco);
                break;
            case '2':
                mostrarTodos(banco);
                break;
            case 'Q':
            case 'q':
                printf("Saindo...\n");
                return 0;
            default:
                printf("Invalido\n");
        }
    }

    return 0;
}
