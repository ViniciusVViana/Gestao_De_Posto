#ifndef header_funcionarios_h
#define header_funcionarios_h
int verificaLogin(char login[99], int senha, Funcionarios **funcionario){
    int cont = 0;
    int quant = sizeof(funcionarios_cadastrado)/sizeof(int);

    do{
            printf("Funcionarios: %s", funcionario[cont]->login);
        if(strcmp(login, funcionario[cont]->login) == 0 && senha == funcionario[cont]->senha){
            return 1;
        }else{
            return 0;
        }
        cont ++;
    }while(cont <= quant);
}
#endif // header_funcionarios_h
