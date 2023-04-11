#ifndef header_vendas_h
#define header_vendas_h

int realizarVenda(int id_func)
{
    int id_produto, produtoEncontrado = 0, quantidade, cont = 1, op, opCard,opCreditCard, sucesso = 0;
    Produtos produto;
    int vendaSucesso = 0;
    
    Vendas venda;
    venda.valor_total = 0;
    venda.produto = (Produtos *)malloc(1 * sizeof(Produtos));
    venda.id_func = id_func;

    printf("===---==---=== Menu de Vendas ===---==---===\n");
    do
    {
        printf("\n=--= Informe o codigo do produto: (integer)\nR: ");
        scanf("%d", &id_produto);
        produtoEncontrado = buscaProduto(id_produto, &produto);

        if (!produtoEncontrado)
        {
            printf("\n\n -=--=- Produto nao encontrado! -=--=- \n");
            sucesso = 0;
        }
        else
        {
            printf("\n\n=--= Informe a quantidade (integer):\nR: ");
            scanf("%d", &quantidade);

            if (quantidade > produto.quantidade)
            {
                printf("\n\n-=--=- Quantidade indisponivel! -=--=-\n");
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

                printf("\n\n=-==-= Venda realizada com sucesso! =-==-=\n");
                cont++;
                sucesso = 1;
            }
        }
        printf("\n\n=-=-= Deseja realizar outra venda? =-=-=\n[1] Sim\n[0] Nao\nR: ");
        scanf("%d", &op);
        if (op == 1)
        {
            venda.produto = (Produtos *)realloc(venda.produto, (cont + 1) * sizeof(Produtos));
        }
    } while (op != 0);
    printf("\n\n=-==-= Valor total: %.2f\n =-==-=", venda.valor_total);

    do
    {
        printf("\n\n=-=-= Escolha a forma de pagamento:\n[1] Dinheiro\n[2] Cartao\nR: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            printf("\n\n=--= Informe o valor recebido:\nR: ");
            scanf("%f", &venda.valor_pago);
            venda.forma_pagamento = 1;
            if(venda.valor_pago < venda.valor_total)
{
                printf("\n-=- Valor insuficiente.\n");
                vendaSucesso = 0;
}

            else
                {
                    venda.troco = venda.valor_pago - venda.valor_total;
                    printf("\n=--= Troco: %.2f\n", venda.troco);
                    vendaSucesso = 1;
                }
            
            break;

        case 2:
            do
            {
                printf("\n\n=-=-= Deseja Credito ou Débito?\n[1] Credito\n[2] Debito\n[3] Cancelar\nR: ");
                scanf("%d", &opCard);
                if (opCard == 1)
                {
                    venda.forma_pagamento = 2;
                    printf("\n\n=--= A vista ou parcelado?\n[1] A vista \n[2] Parcelado\n[3] Cancelar\nR: ");
                    scanf("%d", &opCreditCard);
                    do
                    {
                        if (opCreditCard == 1)
                        {
                            venda.valor_pago = venda.valor_total;

                            printf("\n\n=-= Valor pago: %.2f\n", venda.valor_pago);
                            vendaSucesso = 1;
                        }
                        else if (opCreditCard == 2)
                        {
                            int parcelas;
                            printf("\n\n=--= Informe o numero de parcelas (2%% de juros a cada parcela, apenas contado acima de 4 parcelas):\nR: "); //Na parte "2% de juros" o compilador tava achando que deveria ser inserido um numero decimal (% d -> %d), então eu troquei para %%, para ele printar apenas "%"
                            scanf("%d", &parcelas);
                            if (parcelas > 4)
                            {
                                venda.valor_pago = venda.valor_total + (venda.valor_total * 0.02 * parcelas);
                         
                            }
                            else
                            {
                                venda.valor_pago = venda.valor_total;
                            }
                            printf("\n\n=-= Valor pago: %.2f\n", venda.valor_pago);
                            vendaSucesso = 1;
                        }
                        else if (opCreditCard == 3)
                        {
                            printf("\n\n -==- Operacao cancelada.\n");
                            vendaSucesso = 0;
                            break;
                        }
                        else
                        {
                            printf("\n -==- Opcao invalida! -==-\n");
                        }
                    } while ((opCreditCard != 1 || opCreditCard != 2) && vendaSucesso == 0);

                }
                else if (opCard == 2)
                {
                    venda.forma_pagamento = 3;
                    venda.valor_pago = venda.valor_total;
                    printf("Valor pago: %.2f\n", venda.valor_pago);
                    vendaSucesso = 1;

                }
                else if (opCard == 3)
                {
                    printf("Operacao cancelada.\n");
                    vendaSucesso = 0;
                    break;
                }
                else
                {
                    printf("Opcao invalida.\n");
                }
            } while ((opCard != 1 || opCard != 2) && vendaSucesso == 0 );

            break;

        default:
            printf("Opcao invalida.\n");
            break;
        }
    } while ((op != 1 || op != 2) && sucesso == 1 && vendaSucesso == 0);

    free(venda.produto);

    return sucesso;
}


#endif
