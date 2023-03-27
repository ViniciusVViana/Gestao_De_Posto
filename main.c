#include "funcoes.h"

void main()
{

    int op, isVerified = 1;

    if (isVerified == 1)
    {
        do
        {
            printf("Bem vindo ao sistema!\n");
            printf("1 - Cadastrar novo funcionario\n");
            printf("2 - Realizar venda\n");
            printf("3 - Relatórios\n");
            printf("4 - Controle de estoque\n");
            printf("0 - Sair\n");
            printf("Digite a opcao desejada: ");
            scanf("%d", &op);

            switch (op)
            {
            case 1:
                printf("Cadastrando novo usuario...");
                /*
                   Função para cadastrar novo usuario
                */
                break;
            case 2:
                printf("Realizando venda...");
                /*
                   Função para realizar venda
                */
                break;
            case 3:
                printf("Relatorios...");
                /*
                   Função de relatorios
                   Relatorios de funcionarios, vendas, estoque
                */
                break;
            case 4:
                printf("Controle de estoque...");
                /*
                   Função para controle de estoque
                   Adicionar, remover, alterar
                */
                break;
            case 0:
                printf("Saindo do sistema...");
                break;
            default:
                printf("Opcao invalida!");
                break;
            };
            printf("%d", op);
        } while (op != 0);
    }
    else
    {
        printf("Redirecionando para a tela de login...");
        system("pause");
    };

    system("pause");
};