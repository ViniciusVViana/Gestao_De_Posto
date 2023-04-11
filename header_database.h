#ifndef header_database_h
#define header_database_h

//ESSA FUNÇÃO INICIALIZA O ESTOQUE COM OS PRODUTOS "BASES"
void inicializacao_estoque(){

    strcpy(produto_posto[0].nome,"Gasolina comum");
    produto_posto[0].identificacao_produto = 1111;
    produto_posto[0].quantidade = 1000;
    produto_posto[0].preco = 5.51;
    produto_posto[0].cat.identificacao_categoria_pai = 1;
    produto_posto[0].cat.identificacao_categoria = 1;
    strcpy(produto_posto[0].cat.nome_categoria,"Combustivel");

    strcpy(produto_posto[1].nome,"Gasolina aditivada");
    produto_posto[1].identificacao_produto = 1112;
    produto_posto[1].quantidade = 1000;
    produto_posto[1].preco = 5.51;
    produto_posto[1].cat.identificacao_categoria_pai = 1;
    produto_posto[1].cat.identificacao_categoria = 1;
    strcpy(produto_posto[1].cat.nome_categoria,"Combustivel");

    strcpy(produto_posto[2].nome,"Etanol");
    produto_posto[2].identificacao_produto = 1120;
    produto_posto[2].quantidade = 1000;
    produto_posto[2].preco = 4.87;
    produto_posto[2].cat.identificacao_categoria_pai = 1;
    produto_posto[2].cat.identificacao_categoria = 2;
    strcpy(produto_posto[2].cat.nome_categoria,"Combustivel");

    strcpy(produto_posto[3].nome,"Diesel");
    produto_posto[3].identificacao_produto = 1130;
    produto_posto[3].quantidade = 1000;
    produto_posto[3].preco = 5.94;
    produto_posto[3].cat.identificacao_categoria_pai = 1;
    produto_posto[3].cat.identificacao_categoria = 3;
    strcpy(produto_posto[3].cat.nome_categoria,"Combustivel");

    strcpy(produto_posto[4].nome, "Doritos");
    produto_posto[4].identificacao_produto = 2111;
    produto_posto[4].quantidade = 50;
    produto_posto[4].preco = 9.99;
    produto_posto[4].cat.identificacao_categoria_pai = 1;
    produto_posto[4].cat.identificacao_categoria = 1;
    strcpy(produto_posto[4].cat.nome_categoria,"Salgados");

    strcpy(produto_posto[5].nome, "Baconzitos");
    produto_posto[5].identificacao_produto = 2112;
    produto_posto[5].quantidade = 50;
    produto_posto[5].preco = 9.99;
    produto_posto[5].cat.identificacao_categoria_pai = 1;
    produto_posto[5].cat.identificacao_categoria = 1;
    strcpy(produto_posto[5].cat.nome_categoria,"Salgados");

    strcpy(produto_posto[6].nome, "Cebolitos");
    produto_posto[6].identificacao_produto = 2113;
    produto_posto[6].quantidade = 50;
    produto_posto[6].preco = 9.99;
    produto_posto[6].cat.identificacao_categoria_pai = 1;
    produto_posto[6].cat.identificacao_categoria = 1;
    strcpy(produto_posto[6].cat.nome_categoria,"Salgados");

    strcpy(produto_posto[7].nome, "Coca-cola-lata");
    produto_posto[7].identificacao_produto = 2121;
    produto_posto[7].quantidade = 50;
    produto_posto[7].preco = 3.50;
    produto_posto[7].cat.identificacao_categoria_pai = 1;
    produto_posto[7].cat.identificacao_categoria = 2;
    strcpy(produto_posto[7].cat.nome_categoria,"Bebidas");

    strcpy(produto_posto[8].nome, "Skol-lata");
    produto_posto[8].identificacao_produto = 2122;
    produto_posto[8].quantidade = 50;
    produto_posto[8].preco = 3.50;
    produto_posto[8].cat.identificacao_categoria_pai = 1;
    produto_posto[8].cat.identificacao_categoria = 2;
    strcpy(produto_posto[8].cat.nome_categoria,"Bebidas");

    strcpy(produto_posto[9].nome, "Antartica-lata");
    produto_posto[9].identificacao_produto = 2123;
    produto_posto[9].quantidade = 50;
    produto_posto[9].preco = 3.50;
    produto_posto[9].cat.identificacao_categoria_pai = 1;
    produto_posto[9].cat.identificacao_categoria = 2;
    strcpy(produto_posto[9].cat.nome_categoria,"Bebidas");

    strcpy(produto_posto[10].nome, "Trident");
    produto_posto[10].identificacao_produto = 2131;
    produto_posto[10].quantidade = 50;
    produto_posto[10].preco = 2.79;
    produto_posto[10].cat.identificacao_categoria_pai = 1;
    produto_posto[10].cat.identificacao_categoria = 3;
    strcpy(produto_posto[10].cat.nome_categoria,"Doces");

    strcpy(produto_posto[11].nome, "Halls");
    produto_posto[11].identificacao_produto = 2132;
    produto_posto[11].quantidade = 50;
    produto_posto[11].preco = 1.79;
    produto_posto[11].cat.identificacao_categoria_pai = 1;
    produto_posto[11].cat.identificacao_categoria = 3;
    strcpy(produto_posto[11].cat.nome_categoria,"Doces");

    strcpy(produto_posto[12].nome, "Carregador de celular");
    produto_posto[12].identificacao_produto = 2241;
    produto_posto[12].quantidade = 50;
    produto_posto[12].preco = 12.50;
    produto_posto[12].cat.identificacao_categoria_pai = 2;
    produto_posto[12].cat.identificacao_categoria = 4;
    strcpy(produto_posto[12].cat.nome_categoria,"Eletronicos");

    strcpy(produto_posto[13].nome, "Lanterna");
    produto_posto[13].identificacao_produto = 2242;
    produto_posto[13].quantidade = 50;
    produto_posto[13].preco = 23.90;
    produto_posto[13].cat.identificacao_categoria_pai = 2;
    produto_posto[13].cat.identificacao_categoria = 4;
    strcpy(produto_posto[13].cat.nome_categoria,"Eleronicos");

    strcpy(produto_posto[14].nome, "Fone de ouvido");
    produto_posto[14].identificacao_produto = 2243;
    produto_posto[14].quantidade = 50;
    produto_posto[14].preco = 17.90;
    produto_posto[14].cat.identificacao_categoria_pai = 2;
    produto_posto[14].cat.identificacao_categoria = 4;
    strcpy(produto_posto[14].cat.nome_categoria,"Eleronicos");

};

//ESSA FUNÇÃO INICIALIZA OS CADASTROS DOS FUNCIONARIOS
void inicializacao_funcionarios(){

    //CADASTRO DO ADMIN
    funcionarios_cadastrado[0].identificacao_func = 1;
    strcpy(funcionarios_cadastrado[0].login, "admin");
    funcionarios_cadastrado[0].senha = 123;
    strcpy(funcionarios_cadastrado[0].nome, "admin");

    //CADASTRO FUNCIONARIOS VINICIUS
    funcionarios_cadastrado[1].identificacao_func = 2;
    funcionarios_cadastrado[1].senha = 222;
    funcionarios_cadastrado[1].salario = 1250.00;
    funcionarios_cadastrado[1].telefone = 998445946;
    funcionarios_cadastrado[1].endereco.num = 355;
    strcpy(funcionarios_cadastrado[1].endereco.cep, "85819-010");
    strcpy(funcionarios_cadastrado[1].endereco.cidade, "Cascavel");
    strcpy(funcionarios_cadastrado[1].endereco.bairro, "Turisparque");
    strcpy(funcionarios_cadastrado[1].endereco.rua, "Prates");
    strcpy(funcionarios_cadastrado[1].cpf, "120.699,349-93");
    strcpy(funcionarios_cadastrado[1].nome, "Vinicius Vieira Viana");
    strcpy(funcionarios_cadastrado[1].login, "vini");

    //CADASTRO FUNCIONARIOS DEITOS
    funcionarios_cadastrado[2].identificacao_func = 3;
    funcionarios_cadastrado[2].senha = 333;
    funcionarios_cadastrado[2].salario = 1250.00;
    funcionarios_cadastrado[2].telefone = 998011876;
    funcionarios_cadastrado[2].endereco.num = 345;
    strcpy(funcionarios_cadastrado[2].endereco.cep, "85829-210");
    strcpy(funcionarios_cadastrado[2].endereco.cidade, "Cascavel");
    strcpy(funcionarios_cadastrado[2].endereco.bairro, "Centro");
    strcpy(funcionarios_cadastrado[2].endereco.rua, "penis");
    strcpy(funcionarios_cadastrado[2].cpf, "634.346.349-39");
    strcpy(funcionarios_cadastrado[2].nome, "Guilherme Augusto Deitos");
    strcpy(funcionarios_cadastrado[2].login, "deitos");

    //CADASTRO FUNCIONARIOS VITOR
    funcionarios_cadastrado[3].identificacao_func = 4;
    funcionarios_cadastrado[3].senha = 444;
    funcionarios_cadastrado[3].salario = 1250.00;
    funcionarios_cadastrado[3].telefone = 999852607;
    funcionarios_cadastrado[3].endereco.num = 645;
    strcpy(funcionarios_cadastrado[3].endereco.cep, "83419-012");
    strcpy(funcionarios_cadastrado[3].endereco.cidade, "lider");
    strcpy(funcionarios_cadastrado[3].endereco.bairro, "lider");
    strcpy(funcionarios_cadastrado[3].endereco.rua, "lider");
    strcpy(funcionarios_cadastrado[3].cpf, "534.734,123-93");
    strcpy(funcionarios_cadastrado[3].nome, "Vitor Mayorca Camargo");
    strcpy(funcionarios_cadastrado[3].login, "lider");

    //CADASTRO FUNCIONARIOS WEBERSON
    funcionarios_cadastrado[4].senha = 555;
    funcionarios_cadastrado[4].identificacao_func = 5;
    funcionarios_cadastrado[4].salario = 1250.00;
    funcionarios_cadastrado[4].telefone = 998258142;
    funcionarios_cadastrado[4].endereco.num = 764;
    strcpy(funcionarios_cadastrado[4].endereco.cep, "65437-010");
    strcpy(funcionarios_cadastrado[4].endereco.cidade, "weber");
    strcpy(funcionarios_cadastrado[4].endereco.bairro, "weber");
    strcpy(funcionarios_cadastrado[4].endereco.rua, "weber");
    strcpy(funcionarios_cadastrado[4].cpf, "836.746,147-44");
    strcpy(funcionarios_cadastrado[4].nome, "Weberson Moreli Junior");
    strcpy(funcionarios_cadastrado[4].login, "weber");

};

#endif
