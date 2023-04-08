#include "header_structs.h"
#include "header_estoque.h"

#ifndef header_vendas_h
#define header_vendas_h

int realizarVenda(int id_func)
{
    int id_produto, produtoEncontrado = 0, quantidade, cont = 1, op, opCard,opCreditCard, sucesso = 0;
    Produtos produto;
    Vendas venda;
    venda.valor_total = 0;
    venda.produto = (Produtos *)malloc(1 * sizeof(Produtos));
    venda.id_func = id_func;

    printf("=-=-=-=-=-=-=-=-=-= Menu de venda =-=-=-=-=-=-=-=-=-=\n");
    do
    {
        printf("Informe o codigo do produto: ");
        scanf("%d", &id_produto);
        produtoEncontrado = buscaProduto(id_produto, produto);

        if (!produtoEncontrado)
        {
            printf("Produto nao encontrado.\n");
            sucesso = 0;
        }
        else
        {
            printf("Informe a quantidade: ");
            scanf("%d", &quantidade);

            if (quantidade > produto.quantidade)
            {
                printf("Quantidade indisponivel.\n");
                sucesso = 0;
            }
            else
            {
                produto.quantidade -= quantidade;
                venda.produto->quantidade = quantidade;
                venda.valor_total += (produto.preco * quantidade);
                venda.produto->preco = produto.preco;
                venda.produto->identificacao_produto = produto.identificacao_produto;
                strcpy(venda.produto->nome, produto.nome);

                //pos_venda(&produto);

                printf("Venda realizada com sucesso.\n");
                cont++;
                sucesso = 1;
            }
        }
        printf("Desejam realizar outra venda? [1] - Sim [0] - Nao\n");
        scanf("%d", &op);
        if (op == 1)
        {
            venda.produto = (Produtos *)realloc(venda.produto, (cont + 1) * sizeof(Produtos));
        }
    } while (op != 0);
    printf("Valor total: %.2f\n", venda.valor_total);

    do
    {
        printf("Escolha a forma de pagamento: [1] - Dinheiro [2] - Cartao\n");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            printf("Informe o valor recebido: ");
            scanf("%f", &venda.valor_pago);
            venda.forma_pagamento = 1;
            venda.troco = venda.valor_pago - venda.valor_total;
            printf("Troco: %.2f\n", venda.troco);
            break;

        case 2:
            do
            {
                printf("Deseja Credito ou Débito? [1] - Credito [2] - Debito\n");
                scanf("%d", &opCard);
                if (opCard == 1)
                {
                    venda.forma_pagamento = 2;
                    printf("A vista ou parcelado? [1] - A vista [2] - Parcelado\n");
                    scanf("%d", &opCreditCard);
                    do
                    {
                        if (opCreditCard == 1)
                        {
                            venda.valor_pago = venda.valor_total;
                            printf("Valor pago: %.2f\n", venda.valor_pago);
                        }
                        else if (opCreditCard == 2)
                        {
                            int parcelas;
                            printf("Informe o numero de parcelas (2% de juros a cada parcela, apenas contado acima de 4 parcelas): ");
                            scanf("%d", &parcelas);
                            if (parcelas > 4)
                            {
                                venda.valor_pago = venda.valor_total + (venda.valor_total * 0.02 * parcelas);
                            }
                            else
                            {
                                venda.valor_pago = venda.valor_total;
                            }
                            printf("Valor pago: %.2f\n", venda.valor_pago);
                        }
                        else
                        {
                            printf("Opcao invalida.\n");
                        }
                    } while (opCreditCard != 1 || opCreditCard != 2);

                }
                else if (opCard == 2)
                {
                    venda.forma_pagamento = 3;
                    venda.valor_pago = venda.valor_total;
                }
                else
                {
                    printf("Opcao invalida.\n");
                }
            } while (opCard != 1 || opCard != 2);

            break;

        default:
            printf("Opcao invalida.\n");
            break;
        }
    } while (op != 1 || op != 2);

    adicionaVenda(venda);
    free(venda.produto);

    return sucesso;
}

void adicionaVenda(Vendas venda)
{
    FILE *arquivo;
    arquivo = fopen("vendas.txt", "a");

    fprintf(arquivo, "%d %d %d %d %f %f %f %f %d", venda.id_func, venda.produto->identificacao_produto, venda.produto->quantidade, venda.produto->preco, venda.valor_total, venda.valor_pago, venda.troco, venda.forma_pagamento);
    fclose(arquivo);
}

#endif
