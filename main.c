#include"header_estoque.h";
#include"header_funcionarios.h";
#include"header_vendas.h"
#include"header_relatorios.h"
#include"header_structs.h"
#include"header_autenticacao.h"



void main(){

    produto_posto = (Produtos *)malloc(size_stock * sizeof(Produtos));
    inicializacao_estoque();

    funcionarios_cadastrado = (Funcionarios *)malloc(size_funcionario * sizeof(Funcionarios));
    inicializacao_funcionarios();

    int op, isVerified, id_funcionario;
    Funcionarios funcionarioLogado;

    isVerified = login(funcionarioLogado);


    if (isVerified == 1){
        id_funcionario = funcionarioLogado.identificacao_func;
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
