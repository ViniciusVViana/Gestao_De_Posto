#include"header_structs.h"
#include"header_database.h"
#include"header_estoque.h"
#include"header_autenticacao.h"
#include"header_relatorios.h"
#include"header_vendas.h"

int main(){

    srand(time(NULL));
    produto_posto = (Produtos *)malloc(size_stock * sizeof(Produtos));
    inicializacao_estoque();

    funcionarios_cadastrado = (Funcionarios *)malloc(size_funcionario * sizeof(Funcionarios));
    inicializacao_funcionarios();

    int op, isVerified = 0, id_funcionario, adicionado = 0, novo_produto = 0;
    Funcionarios funcionarioLogado;

    while(isVerified == 0){

        isVerified = login(funcionarioLogado);
        //Autenticador de funcionários. Retorna 1 caso autenticado, e 0 se o usuário desejar fechar o programa.


        if (isVerified == 1){
            id_funcionario = funcionarioLogado.identificacao_func;
            do{
                op = 0;
                Sleep(1500);

                system("cls");
                printf("\n===================================================");
                printf("\n==-=---=-==Gestao de Posto ComeTofuWell!==-=---=-==");
                printf("\n===================================================\n");
                printf("\n=--= Bem vindo ao sistema!\n=-= Escolha uma opcao:\n\n");
                printf("[1] Cadastrar novos funcionarios\n");
                printf("[2] Realizar venda.\n");
                printf("[3] Gerar relatorios\n");
                printf("[4] Checar estoque\n");
                printf("[0] Logout.\nR: ");
                scanf("%d", &op) ;
                fflush(stdin);

                switch(op){
                case 1:
                    //printf("\n\n===---==---=== Menu de funcionarios ===---==---==="); esse printf é desnecessario
                    /*
                    Função para cadastrar novo usuario
                    */
                    cadastroFunc();
                    break;
                case 2:
                    realizarVenda(id_funcionario);
                    break;
                case 3:
                    /*
                    Função de relatorios
                    Relatorios de funcionarios, vendas, estoque
                    */
                    relatorioMain();
                    break;
                case 4:

                    printf("\n\n===---==---=== Menu de estoque ===---==---===\n");
                    printf("\n=--= Selecione a opção desejada:\n");
                    printf("[1] Adicionar item ao estoque\n");
                    printf("[2] Adicionar novo item ao estoque\nR: ");
                    scanf("%i", &op);
                    fflush(stdin);
                    switch(op){

                    case 1:
                        adicionado = adicionar_estoque();

                        if(adicionado == 1){

                            printf("\n\n=--= Produto adicionado com sucesso!");

                        }else if(adicionado == 0){

                            printf("\n\n-==- Houve algum erro ao adicionar o produto ao estoque!");

                        };
                        break;

                    case 2:
                        novo_produto = novo_estoque();

                        if(novo_produto == 1){

                            printf("\n\n=--=--= Novo produto adicionado com sucesso! =--=--=");

                        }else if(novo_produto == 0){

                            printf("\n\n-==-==- Houve algum erro ao adicionar o novo produto ao estoque -==-==-");

                        };

                        break;

                    default:
                        printf("\n\n-=- Opcao invalida.");
                        break;

                    };

                    break;
                case 0:
                    printf("\n\n-=--=- Saindo do sistema...");
                    break;
                default:
                    printf("\n\n-=- Opcao invalida!");
                    break;
                };

            }while (op != 0);

            isVerified = 0;

        }

    };
    /* free(funcionarioLogado); */
    return 0; //O compilador exije que o retorno seja do tipo int
};
