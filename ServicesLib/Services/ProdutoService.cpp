#include "ProdutoService.h"

#include <InputValidator.h>
#include <iostream>

#include "Models/Participante.h"
#include "Models/Produto.h"

/*--------------------------------------------------------------------------------*/

using namespace std;

/*--------------------------------------------------------------------------------*/

void TProdutoService::CriaProdutosComprados(
    TParticipante* participante,
    const size_t nProdutosComprados
) 
{
    list<TProduto*>* const listaProdutos = new list<TProduto*>();

    for (size_t i = 0; i < nProdutosComprados; i++) {
        TProduto* const produto = &CriaProduto(nProdutosComprados, i);
        produto->SetComprador(participante);
        participante->InsereProdutoComprado(produto);
    }
}

/*--------------------------------------------------------------------------------*/

TProduto& TProdutoService::CriaProduto(
    const size_t nProdutosComprados,
    const size_t index
) 
{
    string nomeProduto = "";
    double valorTotal = 0.0;

    cout << "Nome do produto (" << index + 1 << "/" << nProdutosComprados << "): ";
    cin >> nomeProduto;

    cout << "Valor total do produto (" << index + 1 << "/" << nProdutosComprados << "): ";
    cin >> valorTotal;
    NumberValidator validator(cin);
    validator.ValidaFloat(valorTotal);

    cout << "\n\n";

    //auto produto = new TProduto(idProduto, nomeProduto, valorTotal);

    //idProduto++;

    //return *produto;
    return TProduto();
}

/*--------------------------------------------------------------------------------*/

list<TProduto*>& TProdutoService::TodosProdutos(
    const list<TParticipante*>* participantes
) 
{
    auto produtos = new list<TProduto*>();
    for (TParticipante* participante : *participantes) {
        for (TProduto* produto : participante->GetProdutosComprados()) {
            produtos->push_back(produto);
        }
    }

    return *produtos;
}

/*--------------------------------------------------------------------------------*/
