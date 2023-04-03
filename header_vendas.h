#include "header_structs.h"
#include "header_estoque.h"

int realizarVenda(int id_func)
{
    int id_produto, produtoEncontrado = 0, quantidade, cont = 1, op, sucesso = 0;
    Produtos *venda, **produto;
    produto = &produto_posto;
    venda = (Produtos *)malloc(1 * sizeof(Produtos));

    printf("=-=-=-=-=-=-=-=-=-= Menu de venda =-=-=-=-=-=-=-=-=-=\n");
    do
    {
        printf("Informe o codigo do produto: ");
        scanf("%d", &id_produto);
        produtoEncontrado = buscaProduto(id_produto, &produto, &produto_posto);

        if (!produtoEncontrado)
        {
            printf("Produto nao encontrado.\n");
            sucesso = 0;
        }
        else
        {
            printf("Informe a quantidade: ");
            scanf("%d", &quantidade);

            if (quantidade > produto->quantidade)
            {
                printf("Quantidade indisponivel.\n");
                sucesso = 0;
            }
            else
            {
                produto->quantidade -= quantidade;
                venda->identificacao_produto = produto->identificacao_produto;
                venda->quantidade = quantidade;
                venda->preco = produto->preco;
                printf("Venda realizada com sucesso.\n");
                cont++;
                sucesso = 1;
            }
        }
        printf("Desejam realizar outra venda? [1] - Sim [0] - Nao\n");
        scanf("%d", &op);
        if (op == 1)
        {
            venda = (Produtos *)realloc(venda, (i + 1) * sizeof(Produtos));
        }
    } while (op != 0);

    adicionaVenda(venda, cont, id_func);
    free(venda);

    return sucesso;
}