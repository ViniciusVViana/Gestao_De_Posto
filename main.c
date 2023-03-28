#include"header_structs.h"
#include"header_estoque.h"
#include"header_funcionarios.h"
#include"header_vendas.h"
#include"header_relatorios.h"

void main(){

    setlocale(LC_ALL, "Portuguese");

    int op, isVerified = 1;

    if (isVerified == 1){
        
        do{

            printf("Bem vindo ao sistema!\n");
            printf("1 - Funcionarios\n");
            printf("2 - Realizar venda.\n");
            printf("3 - Relatórios\n");
            printf("4 - Estoque\n");
            printf("0 - Sair.\n");
            printf("Digite a opcao desejada: ");
            scanf("%d", &op) ;

            switch(op){

            case 1:
                printf("Menu de funcionarios.");
                /*
                Função para cadastrar novo usuario
                */
                break;
            case 2:
                printf("Menu de venda.");
                /*
                Função para realizar venda
                */
                break;
            case 3:
                printf("Menu de relatorios.");
                /*
                Função de relatorios
                Relatorios de funcionarios, vendas, estoque
                */
                break;
            case 4:
                printf("Menu de estoque.");
                /*
                Funções de estoque
                Adicionar, editar, e remover
                */
                break;
            case 0:
                printf("Saindo do sistema...");
                break;
            default:
                printf("Opcao invalida!");
                break;
            };

        }while (op != 0);

    }else{

        printf("Redirecionando para a tela de login...");
        system("pause");

    };

};