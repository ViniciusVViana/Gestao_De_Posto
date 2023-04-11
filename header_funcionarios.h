#ifndef header_funcionarios_h
#define header_funcionarios_h
int verificaLogin(char login[99], int senha, Funcionarios **funcionario){
    int cont = 0;
    int quant = strlen(funcionario); // Tinha que ter declarado esse quant lá em cima, não? Caso contrario, o while não funciona
    do{
            printf("Funcionarios: %s", funcionario[cont]->login);
        if(login == funcionario[cont]->login && senha == funcionario[cont]->senha){
            return 1;
        }else{
            return 0;
        }
        cont ++;

    }while(cont <= quant);
}

#endif
