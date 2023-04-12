//Aqui estarão todos as funções relacionadas à leitura e escrita de arquivos
//4 tipos de relatórios: Relatório da venda atual, de produtos cadastrados, de todas as vendas já feitas e de funcionários cadastrados.


//Abaixo vão umas constantes malucas que servem pra mexer nos arquivos


//Commit numero 100
void relatorioGeral(Vendas *v, int quant, int id, int n, char *nome){
    //int c = 0;
    FILE *geral = NULL;
    //DEBUG printf("\n\nVT %f VP %f FP %i ID %i Troco %f \n ID %i Estoque %i nome %s\n", v->valor_total, v->valor_pago, v->forma_pagamento, v->id_func, v->troco, id, quant, nome);

    
    geral = fopen("RelatorioGeral.txt", "a");
    
    //printf("\nAppending\n");
    //fflush(geral);
    fprintf(geral, "\n|-----------------------------------------------|\n");
    //fflush(geral);
    fprintf(geral, "|Nome: %s\t\tID: %i\n|Quantidade: %i\t\tValor total: %.2f\t\n|Funcionário: %i", nome, id, quant, v->valor_total, v->id_func);
    //fflush(geral);
    fprintf(geral, "\n|-----------------------------------------------|");
    
    fclose(geral);

    //for(c = 0; c < n; c++){
    //    printf("");
    //}

}

//void relatorioProdutos(){


//}




int relatorioMain(){
    int op = 0;
    do{
        Sleep(1500);
        system("cls");
        printf("\n\n===---==---=== Menu de relatorios ===---==---===");
        printf("\n\n=--= Escolha uma opcao:\n");
        printf("[1] Relatorio de todas as vendas ja feitas\n[2] Relatorio de produtos cadastrados\n[3]Sair\nR: ");
        scanf("%i", &op);
        switch(op){
            case 1:
                printf("\n\n=--= Relatorio gerado! Ele pode ser encontrado dentro do arquivo RelatorioGeral.txt!");
            break;

            case 2:
                //relatorioProds();
            break;

            case 3:
            printf("\n\n-=- Voltando...");
            Sleep(500);
            break;

            default:
            printf("\n\n-=-=- Input invalido! -=-=-");
            Sleep(1000);
        }

    }while(op != 4);
    return 0;
}


int geradorBeloeMoral(char *gera){
    char buffer[20], filename[20], temp[20];
    strcpy(filename, "relatorio");
    int value = rand();
    srand(time(NULL));
    value = rand() * value; //Cria um numero aleatorio
    //printf("%i", value);
    snprintf(buffer, 20, "%d", value); //Transforma o numero aleatorio numa string
    strcat(filename, buffer);
    strcat(filename, ".txt"); //Cria o nome de um arquivo .txt
    strcpy(gera, filename);
    return 0;
    //Essa bagunça ilegível acima serve para criar um nome aleatório para o arquivo de relatório.
    //Dessa forma, os arquivos novos não vão deletar os antigos...
    //... em 99.99% dos casos ...
}

void inicializaCupom(char *gera, Vendas *v){

    FILE *inicial = NULL;
    inicial = fopen(gera, "w+");
    if(inicial == 0){
        printf("\nErro inesperado! O arquivo nao pode ser criado :^( \n");
        Sleep(500);
    }
        time_t t = time(NULL);
        struct tm *tm = localtime(&t);
        char s[64];
        size_t ret = strftime(s, sizeof(s), "%c", tm);
        assert(ret);
        
        fprintf(inicial, "|===============================================|\n");
        fprintf(inicial, "|\t     ✈ Rede ComeTofuWell ✈     \t|\n");
        fprintf(inicial, "|===============================================|\n");
        fprintf(inicial, "|    Rua Universitária, 1619 - Universitário    |\n");
        fprintf(inicial, "|\t\t   Cascavel/PR   \t\t|\n");
        fprintf(inicial, "|\t\t (45) 99985-2607\t\t|\n");
        fprintf(inicial, "|-----------------------------------------------|\n");
        fprintf(inicial, "| \tData e Hora: %s \t\t|\n", s);
        fprintf(inicial, "|\t      Atendente: %i\t\t|\n", v->id_func);
        fprintf(inicial, "|\t\t\t\t\t\t|\n");
        fprintf(inicial, "|\t      Relatorio da Venda:\t\t|\n");
        fprintf(inicial, "|-----------------------------------------------|\n");
        fprintf(inicial, "|Produto:\tPreco: \t\tQtd:\tTotal:\t|\n");
        //printf("Gerou");
    fclose(inicial);
}

void AppendCupom(char *gera, char *nome, int quant, float preco){
    
    FILE *inicial = NULL;
    inicial = fopen(gera, "a");
    if(inicial == 0){
        printf("\nErro inesperado! O arquivo nao pode ser criado :^( \n");
        Sleep(500);
    }
    fprintf(inicial, "|%s\t%.2f \t\t%i\t%.2f\t|\n", nome, preco, quant, (preco * ((float)quant)));
    fclose(inicial);
}


void FinalizaCupom(char *gera, int qtotal, float preco, int metodo){
    FILE *inicial = NULL;
    inicial = fopen(gera, "a");
    if(inicial == 0){
        printf("\nErro inesperado! O arquivo nao pode ser criado :^( \n");
        Sleep(500);
    }
    fprintf(inicial, "|-----------------------------------------------|\n");
    fprintf(inicial, "| Qtd. Total:\t\t\t %i:\t|\n", qtotal);
    fprintf(inicial, "| Preco Total:\t\t\t %.2f\t|\n", preco);
    fprintf(inicial, "|-----------------------------------------------|\n");
    fprintf(inicial, "|===============================================|\n");
    fprintf(inicial, "|\tMetodo de Pagamento: %i \t \t|\n", metodo);
    fprintf(inicial, "|__________Obrigado Pela PrEferencia!___________|\n");
    fclose(inicial);
}
/*
int relatorioMono(Vendas *v, int quant, int id, int n, char *nome){
    char filename = "Text.txt"
    FILE *geral = NULL;
    geral = fopen(filename, "w");

    if(geral == 0){
        printf("\nErro inesperado! O arquivo nao pode ser criado :^( \n");
        return 1;
    }
    fprintf(geral, "|===============================================|\n");
    fprintf(geral, "|\t     ✈ Rede ComeTofuWell ✈     \t|\n");
    fprintf(geral, "|===============================================|\n");
    fprintf(geral, "|    Rua Universitária, 1619 - Universitário    |\n");
    fprintf(geral, "|\t\t   Cascavel/PR   \t\t|\n");
    fprintf(geral, "|\t\t (45) 99985-2607\t\t|\n");
    fprintf(geral, "|-----------------------------------------------|\n");
    fprintf(geral, "| Data: (data)\t\tHorário: (hora)\t\t|\n");
    fprintf(geral, "| Atendente: (atendente)\t\t\t|\n");
    fprintf(geral, "|\t\t\t\t\t\t|\n");
    fprintf(geral, "|\t       Relatorio da Venda:\t\t|\n");
    fprintf(geral, "|-----------------------------------------------|\n");
    fprintf(geral, "|Produto:\tCat: \t\tPreco:\tQtd:\t|\n");
    fprintf(geral, "|p1      \tSalg.\t\trs    \tx1  \t|\n");
    fprintf(geral, "|-----------------------------------------------|\n");
    fprintf(geral, "| Preco Total:\t\t\tQtd. Total:\t|\n");
    fprintf(geral, "| rsTotal:\t\t\t xTotal:\t|\n");
    fprintf(geral, "|===============================================|\n");
    fprintf(geral, "| Metodo de Pagamento: (metodo) \t \t|\n");
    fprintf(geral, "|\t\t\t\t\t\t|\n");
    fprintf(geral, "|__________Obrigado Pela PrEferencia!___________|\n");

    fclose(geral);
    return 0;
}
*/

