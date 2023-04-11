#ifndef header_autenticacao_h
#define header_autenticacao_h

int login(Funcionarios funcionarioLogado){
        int senha, isVerified = 0, op, id_funcionario;
        char login[99];
        
        //Eu reescrevi a coisa que estava aqui ~Vitor
        
        do{
            op = 0;
            system("cls");
            printf("\n===================================================");
            printf("\n==-=---=-==Gestao de Posto ComeTofuWell!==-=---=-==");
            printf("\n===================================================\n");
            printf("\nEscolha uma opcao:\n[1] Fazer login\n[2] Cadastrar um novo usuario\n[3] Sair\nR: ");
            scanf("%i", &op); //"op" de "opção"
            fflush(stdin);//Coloquei isso em tudo por segurança

            switch(op){
                case 1:
                    printf("\nLogin!");
                    
                    printf("\nInforme o seu login: \nR: ");
                    scanf("%s", login);//login não exige &, pois %s já o trata como ponteiro 
                    fflush(stdin);
                    printf("\nInforme a sua senha: \nR: ");
                    scanf("%d", &senha);
                    fflush(stdin);
                    isVerified = verificaLogin(login, senha, &funcionarios_cadastrado);
                    
                break;

                case 2:
                    printf("\nCadastrando novo usuario!");
                    //cadastroFunc();
                break;

                case 3:
                    printf("\n\nTchau!\n");
                    //return 0;
                break;

                default:
                    printf("\nOpcao invalida! Tente de novo!");
                    Sleep(3000); //Dá um tempinho pra pessoa ler a mensagem, antes de reiniciar o programa
                break;
            }
        }while(op != 3 && isVerified == 0); 
        // Só sai do loop se: Usuário sair (op == 3); ou Usuário for autenticado (isVerified == 1)

        if(isVerified != 0){
            printf("Login realizado com sucesso.\n");
            funcionarioLogado = funcionarios_cadastrado[0];
        }

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
    scanf("%ld", &funcionario.telefone); //Numero do telefone é do tipo long int, logo exige um %ld.
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


//Código anterior do verificador de login:

/*
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
        //;//

        //isVerified = op == 0 ? 0 : 1; //Fala protugues seu alienigena

        return isVerified;
        */