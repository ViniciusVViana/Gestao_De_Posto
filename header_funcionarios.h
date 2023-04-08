#include "header_autenticacao.h"
#include "header_structs.h"

#ifndef header_funcionarios_h
#define header_funcionarios_h
int verificaLogin(char login[99], int senha, Funcionarios **funcionario){
    int cont = 0;

    do{
            printf("Funcionarios: %s", funcionario[cont]->login);
        if(login == funcionario[cont]->login && senha == funcionario[cont]->senha){
            return 1;
        }else{
            return 0;
        }
        cont ++;
        int quant = strlem(funcionario);
    }while(cont <= quant);
}  

#endif