#include"header_structs.h"
#include"header_database.h"
#include"header_estoque.h"
#include"header_autenticacao.h"
#include"header_vendas.h"
#include"header_relatorios.h"


int main(){

    produto_posto = (Produtos *)malloc(size_stock * sizeof(Produtos));
    inicializacao_estoque();//CHAMADA DA FUNÇÃO PARA INICIAR O ESTOQUE

    funcionarios_cadastrado = (Funcionarios *)malloc(size_funcionario * sizeof(Funcionarios));
    inicializacao_funcionarios();//CHAMADA DA FUNÇÃO PARA INCIAR OS FUNCIONARIOS CADASTRADOS

    int op, isVerified, id_funcionario, adicionado = 0, novo_produto = 0;
    Funcionarios funcionarioLogado;


    isVerified = login(funcionarioLogado);
    //Autenticador de funcionários. Retorna 1 caso autenticado, e 0 se o usuário desejar fechar o programa.


    if (isVerified == 1){
        id_funcionario = funcionarioLogado.identificacao_func;
        do{
            system("cls");
            printf("\n===================================================");
            printf("\n==-=---=-==Gestao de Posto ComeTofuWell!==-=---=-==");
            printf("\n===================================================\n");
            printf("\n=--= Bem vindo ao sistema!\n=-= Escolha uma opcao:\n\n");
            printf("[1] Cadastrar novos funcionarios\n");
            printf("[2] Realizar venda.\n");
            printf("[3] Gerar relatorios\n");
            printf("[4] Checar estoque\n");
            printf("[0] Sair.\nR: ");
            scanf("%d", &op) ;
            fflush(stdin);

            switch(op){
            case 1:
                printf("\n\n===---==---===Menu de funcionarios===---==---===");
                /*
                Função para cadastrar novo usuario
                */
                cadastroFunc();
                break;
            case 2:
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
                printf("Selecione a opção desejada: ");
                printf("1 - Adicionar item ao estoque.");
                printf("2 - Adicionar novo item ao estoque.");
                scanf("%i", &op);
                fflush(stdin);
                switch(op){

                case 1:
                    adicionado = adicionar_estoque();

                    if(adicionado == 1){

                        printf("Produto adicionado com sucesso!");

                    }else if(adicionado == 0){

                        printf("Houve algum erro ao adicionar o produto ao estoque");

                    };
                    break;

                case 2:
                    novo_produto = novo_estoque();

                    if(novo_produto == 1){

                        printf("Novo produto adicionado com sucesso!");

                    }else if(novo_produto == 0){

                        printf("Houve algum erro ao adicionar o novo produto ao estoque");

                    };

                    break;

                default:
                    printf("Opcao invalida.");
                    break;

                };

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
    return 0; //O compilador exije que o retorno seja do tipo int
};
