
#include "header_autenticacao.h"
#include "header_structs.h"

int verificaLogin(char login[99], int senha, Funcionarios **funcionario){
    int cont = 0;
    do{
        if(login == funcionario[cont].login && senha == funcionario[cont].senha){
            return 1;
        }else{
            return 0;
        }
        cont ++;
    }while(cont <= strlem(funcionario));
}
