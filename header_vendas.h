#ifndef header_vendas_h
#define header_vendas_h

int realizarVenda(int id_func)
{
    int id_produto, produtoEncontrado = 0, quantidade, cont = 1, op, opCard, opCreditCard, sucesso = 0, produtosVendidos = 0;
    // Variaveis auxiliares para a venda
    Produtos produto;     // Variavel auxiliar para armazenar o produto caso encontrado
    int vendaSucesso = 0; // Variavel auxiliar para verificar se a venda foi realizada com sucesso

    Vendas venda;                                             // Variavel auxiliar para armazenar os dados da venda
    venda.valor_total = 0;                                    // Inicializando o valor total da venda
    venda.produto = (Produtos *)malloc(1 * sizeof(Produtos)); // Alocando memoria para o vetor de produtos da venda
    venda.id_func = id_func;                                  // Armazenando o id do funcionario que realizou a venda

    printf("=-=-=-=-=-=-=-=-=-= Menu de venda =-=-=-=-=-=-=-=-=-=\n");
    do
    {
        printf("Informe o codigo do produto: ");
        scanf("%d", &id_produto);
        produtoEncontrado = buscaProduto(id_produto, &produto); // Buscando o produto no estoque

        if (!produtoEncontrado)
        {
            printf("Produto nao encontrado.\n");
            sucesso = 0; // Caso o produto nao seja encontrado, a venda nao sera realizada
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
                printf("Venda realizada com sucesso.\n");
                cont++;
                sucesso = 1;
                produtosVendidos++;
                descontar_estoque(produto.identificacao_produto, quantidade);

            }
        }
        printf("Deseja continuar a venda? [1] - Sim [0] - Nao\n");
        scanf("%d", &op);
        if (op == 1)
        {
            venda.produto = (Produtos *)realloc(venda.produto, (cont + 1) * sizeof(Produtos));
            // Alocando mais memoria para o vetor de produtos da venda caso o usuario queira continuar a venda
        }
    } while (op != 0);
    printf("Valor total: %.2f\n", venda.valor_total); // Imprimindo o valor total da venda

    do
    {
        printf("Escolha a forma de pagamento: [1] - Dinheiro [2] - Cartao\n");
        scanf("%d", &op);

        switch (op) // Verificando a forma de pagamento
        {
        case 1: // Caso a forma de pagamento seja dinheiro
            printf("Informe o valor recebido: ");
            scanf("%f", &venda.valor_pago);
            venda.forma_pagamento = 1;
            if (venda.valor_pago < venda.valor_total) // Verificando se o valor pago eh suficiente
            {
                printf("Valor insuficiente.\n");
                vendaSucesso = 0;
            }

            else
            {
                venda.troco = venda.valor_pago - venda.valor_total; // Calculando o troco
                printf("Troco: %.2f\n", venda.troco);
                vendaSucesso = 1;
            }

            break;

        case 2: // Caso a forma de pagamento seja cartao
            do
            {
                printf("Deseja Credito ou Débito? [1] - Credito [2] - Debito [3] - Cancelar \n");
                scanf("%d", &opCard);
                if (opCard == 1)
                {
                    venda.forma_pagamento = 2;
                    printf("A vista ou parcelado?\n [1] - A vista \n [2] - Parcelado \n [3] - Cancelar\n");
                    scanf("%d", &opCreditCard);
                    do
                    {
                        if (opCreditCard == 1)
                        {
                            venda.valor_pago = venda.valor_total;

                            printf("Valor pago: %.2f\n", venda.valor_pago);
                            vendaSucesso = 1;
                        }
                        else if (opCreditCard == 2)
                        {
                            int parcelas;
                            printf("Informe o numero de parcelas (2%% de juros a cada parcela, apenas contado acima de 4 parcelas): "); // Na parte "2% de juros" o compilador tava achando que deveria ser inserido um numero decimal (% d -> %d), então eu troquei para %%, para ele printar apenas "%"
                            scanf("%d", &parcelas);

                            if (parcelas > 4) // Verificando se o numero de parcelas eh maior que 4 para aplicar o juros
                            {
                                venda.valor_pago = venda.valor_total + (venda.valor_total * 0.02 * parcelas);
                                // Calculando o valor total a ser pago com juros
                            }
                            else
                            {
                                venda.valor_pago = venda.valor_total;
                            }
                            printf("Valor pago: %.2f\n", venda.valor_pago); // Imprimindo o valor total a ser pago
                            vendaSucesso = 1;
                        }
                        else if (opCreditCard == 3) // Caso o usuario queira cancelar a operacao
                        {
                            printf("Operacao cancelada.\n");
                            vendaSucesso = 0;
                            break;
                        }
                        else
                        {
                            printf("Opcao invalida.\n");
                        }
                    } while ((opCreditCard != 1 || opCreditCard != 2) && vendaSucesso == 0);
                }
                else if (opCard == 2) // Caso o usuario queira pagar com debito
                {
                    venda.forma_pagamento = 3;
                    venda.valor_pago = venda.valor_total;
                    printf("Valor pago: %.2f\n", venda.valor_pago);
                    vendaSucesso = 1;
                }
                else if (opCard == 3) // Caso o usuario queira cancelar a operacao
                {
                    printf("Operacao cancelada.\n");
                    vendaSucesso = 0;
                    break;
                }
                else
                {
                    printf("Opcao invalida.\n");
                }
            } while ((opCard != 1 || opCard != 2) && vendaSucesso == 0);

            break;

        default:
            printf("Opcao invalida.\n");
            break;
        }
    } while ((op != 1 || op != 2) && sucesso == 1 && vendaSucesso == 0);

    free(venda.produto); // Liberando a memoria alocada para o vetor de produtos da venda

    system("pause");

    return sucesso; // Retornando 1 caso a venda seja realizada com sucesso e 0 caso contrario
}

#endif
