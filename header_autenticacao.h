#ifndef header_autenticacao_h
#define header_autenticacao_h
#include"header_database.h"

int verificaLogin(char login[99], int senha){
    int cont = 0;
    int quant = size_funcionario;

    for(cont = 0; cont <= quant; cont++){
        if(strcmp(login, funcionarios_cadastrado[cont].login) == 0 && senha == funcionarios_cadastrado[cont].senha){
            return 1;           
        }
    }
    return 0;
}

void cadastroFunc(){

    Sleep(1500);
    system("cls");
    size_funcionario += 1;
    funcionarios_cadastrado = (Funcionarios *)realloc(funcionarios_cadastrado, size_funcionario * sizeof(Funcionarios));



    printf("===---==---=== Cadastro de funcionarios ===---==---===\n");
    printf("\n=-= Informe o nome do funcionario: (String)\nR: ");
    scanf("%s", funcionarios_cadastrado[size_funcionario -1].nome); //NOTA: funcionario.nome, por ser uma string, já é considerado como um ponteiro. Logo, não é necessario o '&' (Eu acho) (Para fins legais, me retenho de quaisquer problemas decorridos dessa alteração) ~Vitor
    fflush(stdin);
    printf("\n=-= Informe o login do funcionario: (String)\nR: ");
    scanf("%s", funcionarios_cadastrado[size_funcionario -1].login);
    fflush(stdin);
    printf("\n=-= Informe a senha do funcionario: (integer)\nR: ");
    scanf("%d", &funcionarios_cadastrado[size_funcionario -1].senha);
    fflush(stdin);
    printf("\n=-= Informe o salario do funcionario: (float)\nR: ");
    scanf("%f", &funcionarios_cadastrado[size_funcionario -1].salario);
    fflush(stdin);
    printf("\n=-= Informe o CPF do funcionario: (Com pontuacao)\nR: ");
    scanf("%s", funcionarios_cadastrado[size_funcionario -1].cpf);
    fflush(stdin);
    printf("\n=-= Informe o telefone do funcionario: (integer)\nR: ");
    scanf("%ld", &funcionarios_cadastrado[size_funcionario -1].telefone); //Numero do telefone é do tipo long int, logo exige um %ld.
    fflush(stdin);
    printf("\n=-= Informe o endereco do funcionario: (string)\nR: ");
    scanf("%s", funcionarios_cadastrado[size_funcionario -1].endereco.rua);
    fflush(stdin);
    printf("\n=-= Informe o bairro do funcionario: (string)\nR: ");
    scanf("%s", funcionarios_cadastrado[size_funcionario -1].endereco.bairro);
    fflush(stdin);
    printf("\n=-= Informe a cidade do funcionario: (string)\nR: ");
    scanf("%s", funcionarios_cadastrado[size_funcionario -1].endereco.cidade);
    fflush(stdin);
    printf("\n=-= Informe o CEP do funcionario: (com pontuacao)\nR: ");
    scanf("%s", funcionarios_cadastrado[size_funcionario -1].endereco.cep);
    fflush(stdin);
    printf("\n=-= Informe o numero da residencia: (integer)\nR: ");//CREIO QUE SEJA PARA SER NUMERO DO ENDEREÇO DO FINCIONARIO
    scanf("%d", &funcionarios_cadastrado[size_funcionario -1].endereco.num);
    fflush(stdin);

    printf("\n\n===---==---===Funcionario cadastrado com sucesso===---==---===\n");
    //Sleep(1500);
}


int login(Funcionarios funcionarioLogado){
        int senha, isVerified = 0, op, id_funcionario;
        char login[99];

        //Eu reescrevi a coisa que estava aqui ~Vitor

        do{
            op = 0;
            Sleep(1500);
            system("cls");
            printf("\n===================================================");
            printf("\n==-=---=-==Gestao de Posto ComeTofuWell!==-=---=-==");
            printf("\n===================================================\n");
            printf("\n=--= Escolha uma opcao:\n[1] Fazer login\n[2] Cadastrar um novo usuario\n[3] Sair\nR: ");
            scanf("%i", &op); //"op" de "opção"
            fflush(stdin);//Coloquei isso em tudo por segurança

            switch(op){
                case 1:
                    printf("\n-=- Login! -=-");

                    printf("\n=-= Informe o seu login: \nR: ");
                    scanf("%s", login);//login não exige &, pois %s já o trata como ponteiro
                    fflush(stdin);
                    printf("\n=-= Informe a sua senha: \nR: ");
                    scanf("%d", &senha);
                    fflush(stdin);
                    isVerified = verificaLogin(login, senha);
                    if(isVerified == 0){
                        printf("--=-- Login e/ou senha incorretos --=--");
                    }
                    //Sleep(1500);
                break;

                case 2:
                    cadastroFunc();
                break;

                case 3:
                    printf("\n\n-==---==- Tchau! -==---==-\n");
                    //return 0;
                break;

                default:
                    printf("\n-==---==- Opcao invalida! Tente de novo! -==---==-");
                    //Sleep(1500); //Dá um tempinho pra pessoa ler a mensagem, antes de reiniciar o programa
                break;
            }
        }while(op != 3 && isVerified == 0);
        // Só sai do loop se: Usuário sair (op == 3); ou Usuário for autenticado (isVerified == 1)

        if(isVerified != 0){
            printf("=--===--= Login realizado com sucesso =--===--=\n");
            funcionarioLogado = funcionarios_cadastrado[0];
        }

    return isVerified;
}

#endif