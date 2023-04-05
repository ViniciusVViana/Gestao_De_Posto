#include"header_estoque.h";
#include"header_funcionarios.h";
#include"header_vendas.h"
#include"header_relatorios.h"
#include"header_structs.h"
#include"header_autenticacao.h"



void main(){

    Produtos *produto_posto;

    produto_posto = (Produtos *)malloc(size_stock * sizeof(Produtos));
    incializacao_estoque(&produto_posto);

    int op, isVerified, id_funcionario;
    Funcionarios *funcionarioLogado;
    funcionarioLogado = (Funcionarios *)malloc(1 * sizeof(Funcionarios));

    isVerified = login();


    if (isVerified == 1){
        id_funcionario = funcionario->identificacao_func;
        do{

            printf("\nBem vindo ao sistema!\n");
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
                cadastroFunc();
                break;
            case 2:
                printf("Menu de venda.");
                realizarVenda(id_funcionario);
                break;
            case 3:
                printf("Menu de relatorios.");
                /*
                Função de relatorios
                Relatorios de funcionarios, vendas, estoque
                */
                break;
            case 4:
                printf("Menu de estoque.\n");

                break;
            case 0:
                printf("Saindo do sistema...");
                break;
            default:
                printf("Opcao invalida!");
                break;
            };

        }while (op != 0);

    }

    /* free(funcionarioLogado); */

};
