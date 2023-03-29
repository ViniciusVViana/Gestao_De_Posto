#include"header_estoque.h"
#include"header_funcionarios.h"
#include"header_vendas.h"
#include"header_relatorios.h"
#include"header_structs.h"


int login(Funcionarios funcionarioLogado){
    
        int senha, isVerified = 0, op;
        char login[99];
        Funcionarios *funcionario;
        funcionario = (Funcionarios *)malloc(1 * sizeof(Funcionarios));
    
        do{
    
            printf("Informe o seu login: ");
            scanf("%s", &login);
            printf("Informe a sua senha: ");
            scanf("%d", &senha);
    
            isVerified = verificaLogin(id_funcionario, senha, &funcionario);
    
            if (isVerified == 0){
                printf("Login ou senha incorretos.\n");
                printf("[1] Tentar novamente \n[2] Esqueci minha senha \n[3] Cadastrar novo usuario\n");
                scanf("%d", &op);

                switch(op){
                    case 1:
                        printf("Tentando novamente.\n");
                        break;
                    case 2:
                        printf("Esqueci minha senha.\n");
                        break;
                    case 3:
                        printf("Cadastrar novo usuario.\n");
                        break;
                    default:
                        printf("Opcao invalida.\n");
                        break;
                }

            }else{
                printf("Login realizado com sucesso.\n");
                funcionarioLogado = funcionario;
            };
    
        }while (isVerified == 0);
    
        return isVerified;
}

void main(){

    setlocale(LC_ALL, "Portuguese");

    int op, isVerified = 1, id_funcionario;
    Funcionarios *funcionarioLogado;
    funcionarioLogado = (Funcionarios *)malloc(1 * sizeof(Funcionarios));

    isVerified = login(funcionarioLogado);
    

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
                break;
            case 2:
                printf("Menu de venda.");
                realizarVenda();
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

                tamanho_estoque();

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

    free(funcionarioLogado);

};