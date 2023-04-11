#ifndef header_autenticacao_h
#define header_autenticacao_h

int login(Funcionarios funcionarioLogado){
        int senha, isVerified = 0, op, id_funcionario;
        char login[99];
        do{

            printf("Informe o seu login: ");
            scanf("%s", login);//O login não exige &, pois %s já o trata como ponteiro ~Vitor
            printf("Informe a sua senha: ");
            scanf("%d", &senha);

            isVerified = verificaLogin(login, senha, &funcionarios_cadastrado);

            if (isVerified == 0){
                printf("Login ou senha incorretos.\n");
                printf("[1] Tentar novamente \n[2] Cadastrar novo usuario \n[0] Sair");
                scanf("%d", &op);

                switch(op){
                    case 1:
                        system("cls");
                        break;
                    case 2:
                        printf("Cadastrar novo usuario.\n");
                        cadastroFunc();
                        break;
                    case 0:
                        printf("Saindo.\n");
                        isVerified = 1;
                        break;
                    default:
                        printf("Opcao invalida.\n");
                        break;
                }

            }else{
                printf("Login realizado com sucesso.\n");
                funcionarioLogado = funcionarios_cadastrado[0];

            };

        }while (isVerified == 0);

        isVerified = op == 0 ? 0 : 1; //Fala protugues seu alienigena

        return isVerified;
}


void cadastroFunc(){

    Funcionarios funcionario;

    printf("Cadastro de funcionarios.\n");
    printf("Informe o nome do funcionario: ");
    scanf("%s", funcionario.nome); //NOTA: funcionario.nome, por ser uma string, já é considerado como um ponteiro. Logo, não é necessario o '&' (Eu acho) (Para fins legais, me retenho de quaisquer problemas decorridos dessa alteração) ~Vitor
    printf("Informe o login do funcionario: ");
    scanf("%s", funcionario.login);
    printf("Informe a senha do funcionario: ");
    scanf("%d", &funcionario.senha);
    printf("Informe o salario do funcionario: ");
    scanf("%f", &funcionario.salario);
    printf("Informe o CPF do funcionario: ");
    scanf("%s", funcionario.cpf);
    printf("Informe o telefone do funcionario: ");
    scanf("%d", &funcionario.telefone);
    printf("Informe o endereco do funcionario: ");
    scanf("%s", funcionario.endereco.rua);
    printf("Informe o bairro do funcionario: ");
    scanf("%s", funcionario.endereco.bairro);
    printf("Informe a cidade do funcionario: ");
    scanf("%s", funcionario.endereco.cidade);
    printf("Informe o CEP do funcionario: ");
    scanf("%s", funcionario.endereco.cep);
    printf("Informe o numero de telefone do funcionario: ");//CREIO QUE SEJA PARA SER NUMERO DO ENDEREÇO DO FINCIONARIO
    scanf("%d", &funcionario.endereco.num);

    printf("Funcionario cadastrado com sucesso.\n");

}

#endif
