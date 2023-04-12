//Aqui estarão todos as funções relacionadas à leitura e escrita de arquivos
//4 tipos de relatórios: Relatório da venda atual, de produtos cadastrados, de todas as vendas já feitas e de funcionários cadastrados.


//Abaixo vão umas constantes malucas que servem pra mexer nos arquivos
const char* RELATORIO_GERAL_OUT = "(%d, %s, %f, %f, %f, %d, %d, %f)\n";



//Commit numero 100
int relatorioGeral(){
    FILE *geral;
    fopen_s(&geral, "RelatorioGeral.dat", "a+");
        if(file==NULL){
            return 1;
        }
        fprintf_s(file, RELATORIO_GERAL_OUT);


    return 0;
}

void relatorioFunc(){


}

void relatorioProds(){


}




int relatorioMain(){
    int op = 0;
    do{
        sleep(1500);
        system("cls");
        printf("\n\n===---==---=== Menu de relatorios ===---==---===");
        printf("\n\n=--= Escolha uma opcao:\n");
        printf("[1] Relatorio de todas as vendas ja feitas\n[2] Relatorio de Funcionarios\n[3] Relatorio de produtos cadastrados\n[4]Sair\nR: ");
        scanf("%i", op);
        switch(op){
            case 1:
                printf("\n\n=--= Relatorio gerado! Ele pode ser encontrado dentro do arquivo RelatorioGeral.dat!");
            break;

            case 2:
                relatorioFunc();
            break;

            case 3:
                relatorioProds();
            break;

            case 4:
            printf("\n\n-=- Voltando...");
            sleep(500);
            break;

            default:
            printf("\n\n-=-=- Input invalido! -=-=-");
            sleep(1000);
        }

    }while(op != 4);
    return 0;
}

int relatorioMono(/*Provavelmente vai receber uma struct com os dados da venda como parâmetro*/){

    srand(time(NULL));
    char buffer[20], filename[20];
    strcpy(filename, "relatorio");
    int value = rand();
    srand(time(NULL));
    value = rand() * value;
    printf("%i", value);
    snprintf(buffer, 20, "%d", value);
    strcat(filename, buffer);
    strcat(filename, ".txt");
    printf("\n%s", filename);
    //Essa bagunça ilegível acima serve para criar um nome aleatório para o arquivo de relatório.
    //Dessa forma, os arquivos novos não vão deletar os antigos

    FILE *fprt;
    fprt = fopen(filename, "w");

    if(fprt == 0){
        printf("\nErro inesperado! O arquivo nao pode ser criado :^( \n");
        return 1;
    }
    fprintf(fprt, "|===============================================|\n");
    fprintf(fprt, "|\t     ✈ Rede ComeTofuWell ✈     \t|\n");
    fprintf(fprt, "|===============================================|\n");
    fprintf(fprt, "|    Rua Universitária, 1619 - Universitário    |\n");
    fprintf(fprt, "|\t\t   Cascavel/PR   \t\t|\n");
    fprintf(fprt, "|\t\t (45) 99985-2607\t\t|\n");
    fprintf(fprt, "|-----------------------------------------------|\n");
    fprintf(fprt, "| Data: (data)\t\tHorário: (hora)\t\t|\n");
    fprintf(fprt, "| Atendente: (atendente)\t\t\t|\n");
    fprintf(fprt, "|\t\t\t\t\t\t|\n");
    fprintf(fprt, "|\t       Relatorio da Venda:\t\t|\n");
    fprintf(fprt, "|-----------------------------------------------|\n");
    fprintf(fprt, "|Produto:\tCat: \t\tPreco:\tQtd:\t|\n");
    fprintf(fprt, "|p1      \tSalg.\t\trs    \tx1  \t|\n");
    fprintf(fprt, "|-----------------------------------------------|\n");
    fprintf(fprt, "| Preco Total:\t\t\tQtd. Total:\t|\n");
    fprintf(fprt, "| rsTotal:\t\t\t xTotal:\t|\n");
    fprintf(fprt, "|===============================================|\n");
    fprintf(fprt, "| Metodo de Pagamento: (metodo) \t \t|\n");
    fprintf(fprt, "|\t\t\t\t\t\t|\n");
    fprintf(fprt, "|__________Obrigado Pela PrEferencia!___________|\n");

    fclose(fprt);
    return 0;
}
