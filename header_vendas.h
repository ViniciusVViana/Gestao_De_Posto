#ifndef header_vendas_h
#define header_vendas_h

int realizarVenda(int id_func)
{
    char relatorio[20];
    
    int nvendidos = geradorBeloeMoral(relatorio);
    

    int id_produto, produtoEncontrado = 0, quantidade, pag, qtotal = 0, cont = 1, op, opCard, opCreditCard, sucesso = 0, produtosVendidos = 0;
    // Variaveis auxiliares para a venda
    Produtos produto;     // Variavel auxiliar para armazenar o produto caso encontrado
    int vendaSucesso = 0; // Variavel auxiliar para verificar se a venda foi realizada com sucesso

    Vendas venda;                                             // Variavel auxiliar para armazenar os dados da venda
    venda.valor_total = 0;                                    // Inicializando o valor total da venda
    venda.produto = (Produtos *)malloc(1 * sizeof(Produtos)); // Alocando memoria para o vetor de produtos da venda
    venda.id_func = id_func;                                  // Armazenando o id do funcionario que realizou a venda

    printf("=-=-=-=-=-=-=-=-=-= Menu de venda =-=-=-=-=-=-=-=-=-= \n");
    do
    {
        printf("=--= Informe o codigo do produto:\nR: ");
        scanf("%d", &id_produto);
        produtoEncontrado = buscaProduto(id_produto, &produto); // Buscando o produto no estoque

        if (!produtoEncontrado)
        {
            printf("-=- Produto nao encontrado.\n");
            sucesso = 0; // Caso o produto nao seja encontrado, a venda nao sera realizada
        }
        else
        {
            printf("=-= Informe a quantidade:\nR: ");
            scanf("%d", &quantidade);

            if (quantidade > produto.quantidade)
            {
                printf("-=- Quantidade indisponivel.\n");
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
                printf("\n=--= Venda realizada com sucesso!\n\n");
                cont++;
                sucesso = 1;
                produtosVendidos++;
                qtotal = qtotal + venda.produto->quantidade;
                descontar_estoque(produto.identificacao_produto, quantidade);
                relatorioGeral(&venda, venda.produto->quantidade, venda.produto->identificacao_produto, nvendidos, venda.produto->nome);
                
                if (access(relatorio, F_OK) == 0) { //Checa se o arquivo existe
                    // Ele existe
                }else{
                    // Nao existe, entao ele cria o cupom fiscal
                    inicializaCupom(relatorio, &venda);
                }
                AppendCupom(relatorio, venda.produto->nome, venda.produto->quantidade, venda.produto->preco);
            }
        }
        
        printf("=--= Deseja continuar a venda? \n[1] Sim \n[0] Nao\nR: ");
        nvendidos = nvendidos + 1;//Para gerar relatorio
        scanf("%d", &op);
        if (op == 1)
        {
            venda.produto = (Produtos *)realloc(venda.produto, (cont + 1) * sizeof(Produtos));
            // Alocando mais memoria para o vetor de produtos da venda caso o usuario queira continuar a venda
        }
    } while (op != 0);
    printf("\n=--= Valor total: %.2f\n", venda.valor_total); // Imprimindo o valor total da venda

    do
    {
        printf("\n=--= Escolha a forma de pagamento: \n[1] Dinheiro\n[2] Cartao\nR: ");
        scanf("%d", &op);
        pag = op;
        switch (op) // Verificando a forma de pagamento
        {
        case 1: // Caso a forma de pagamento seja dinheiro
            printf("\n=-= Informe o valor recebido:\nR: ");
            scanf("%f", &venda.valor_pago);
            venda.forma_pagamento = 1;
            if (venda.valor_pago < venda.valor_total) // Verificando se o valor pago eh suficiente
            {
                printf("\n-=- Valor insuficiente.\n");
                vendaSucesso = 0;
            }

            else
            {
                venda.troco = venda.valor_pago - venda.valor_total; // Calculando o troco
                printf("\n=-= Troco: %.2f\n", venda.troco);
                vendaSucesso = 1;
            }

            break;

        case 2: // Caso a forma de pagamento seja cartao
            do
            {
                printf("\n=--= Deseja Credito ou Débito? \n[1] Credito \n[2] Debito \n[3] Cancelar \nR: ");
                scanf("%d", &opCard);
                if (opCard == 1)
                {
                    venda.forma_pagamento = 2;
                    printf("\n=--= A vista ou parcelado?\n [1]A vista \n[2] Parcelado \n[3] Cancelar\nR: ");
                    scanf("%d", &opCreditCard);
                    do
                    {
                        if (opCreditCard == 1)
                        {
                            venda.valor_pago = venda.valor_total;

                            printf("\n=-= Valor pago: %.2f\n", venda.valor_pago);
                            vendaSucesso = 1;
                        }
                        else if (opCreditCard == 2)
                        {
                            int parcelas;
                            printf("\n=--= Informe o numero de parcelas (2%% de juros a cada parcela, apenas contado acima de 4 parcelas):\nR: ");
                            // Na parte "2% de juros" o compilador tava achando que deveria ser inserido um numero decimal (% d -> %d), então eu troquei para %%, para ele printar apenas "%"
                            
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
                            printf("\n=-= Valor pago: %.2f\n", venda.valor_pago); // Imprimindo o valor total a ser pago
                            vendaSucesso = 1;
                        }
                        else if (opCreditCard == 3) // Caso o usuario queira cancelar a operacao
                        {
                            printf("\n-=- Operacao cancelada.\n");
                            vendaSucesso = 0;
                            break;
                        }
                        else
                        {
                            printf("\n-=- Opcao invalida.\n");
                        }
                    } while ((opCreditCard != 1 || opCreditCard != 2) && vendaSucesso == 0);
                }
                else if (opCard == 2) // Caso o usuario queira pagar com debito
                {
                    venda.forma_pagamento = 3;
                    venda.valor_pago = venda.valor_total;
                    printf("\n=-= Valor pago: %.2f\n", venda.valor_pago);
                    vendaSucesso = 1;
                }
                else if (opCard == 3) // Caso o usuario queira cancelar a operacao
                {
                    printf("\n-=- Operacao cancelada.\n");
                    vendaSucesso = 0;
                    break;
                }
                else
                {
                    printf("\n-=- Opcao invalida.\n");
                }
            } while ((opCard != 1 || opCard != 2) && vendaSucesso == 0);

            break;

        default:
            printf("\n-=- Opcao invalida.\n");
            break;
        }
    } while ((op != 1 || op != 2) && sucesso == 1 && vendaSucesso == 0);

    
    FinalizaCupom(relatorio, qtotal, venda.valor_pago, pag);
    printf("\n=--= A nota fiscal esta no arquivo %s !", relatorio);
    free(venda.produto); // Liberando a memoria alocada para o vetor de produtos da venda

    system("pause");

    return sucesso; // Retornando 1 caso a venda seja realizada com sucesso e 0 caso contrario
}

#endif
