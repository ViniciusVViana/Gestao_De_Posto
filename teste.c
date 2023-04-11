#include <stdio.h>
#include <stdlib.h>

int main(){
    struct Vendas{
        float valor_total;
        float valor_pago;
        int forma_pagamento;
        int id_func;
        float troco;
    };

    struct Vendas teste;

    scanf("%f", &teste.valor_pago);

    printf("%f", teste.valor_pago);



};