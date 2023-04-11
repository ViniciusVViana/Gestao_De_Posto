//Aqui estarão todos as funções relacionadas à leitura e escrita de arquivos
//4 tipos de relatórios: Relatório da venda atual, de produtos cadastrados, de todas as vendas já feitas e de funcionários cadastrados.

//Commit numero 100
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
    //Essa bagunça ilegível acima serve para criar um nome aleatório para o arquivo de relatório

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
