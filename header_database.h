#include"header_structs.h"

void teste(){

    struct Produtos* produto = (struct Produtos*)malloc(1 * sizeof(struct Produtos));

    printf("Insira algo: ");
    scanf("%s", produto[0].nome);
    printf("%s", produto[0].nome);

};