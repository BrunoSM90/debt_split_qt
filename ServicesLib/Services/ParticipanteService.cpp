#include "ParticipanteService.h"

#include <InputValidator.h>
#include <iostream>

#include "Models/Participante.h"

/*--------------------------------------------------------------------------------*/

static int idParticipante = 1;
static int idProduto = 1;

using namespace std;

/*--------------------------------------------------------------------------------*/

TParticipanteService::TParticipanteService(
    TProdutoService* _prodService
) :
    prodService(_prodService)
{
    participantes = new list<TParticipante*>();
}

/*--------------------------------------------------------------------------------*/

TParticipanteService::~TParticipanteService()
{
    delete prodService;
    delete participantes;
}

/*--------------------------------------------------------------------------------*/

void TParticipanteService::CadastraParticipantes(
    const list<string>& nomesParticipantes
) 
{
    for (const string& nome : nomesParticipantes) {
        TParticipante* participante = BuscaParticipante(nome);
        if (participante == nullptr) {
            TParticipante* participante = new TParticipante(idParticipante, nome);
            participantes->push_back(participante);
            idParticipante++;
        }
    }
}

/*--------------------------------------------------------------------------------*/

void TParticipanteService::RemoveParticipante(
    const string& nome
)
{
    TParticipante* participante = BuscaParticipante(nome);
    participantes->remove(participante);
}

/*--------------------------------------------------------------------------------*/

bool TParticipanteService::ParticipanteComprouProdutos(
    const string& nome
) const
{
    TParticipante* participante = BuscaParticipante(nome);

    return participante != nullptr && participante->GetProdutosComprados().size() > 0;
}

/*--------------------------------------------------------------------------------*/

TParticipante* TParticipanteService::BuscaParticipante(
    const string& nome
) const
{
    auto find = [nome](TParticipante* participante)->bool
        {return participante->GetNome() == nome; };

    auto it = std::find_if(participantes->begin(), participantes->end(), find);

    return it != participantes->end() ? dynamic_cast<TParticipante*>(*it) : nullptr;
}

/*--------------------------------------------------------------------------------*/

void TParticipanteService::InsereProdutoComprado(
    const string& nomeParticipante,
    const string& nomeProduto,
    double valorProduto
)
{
    auto produto = new TProduto(idProduto, nomeProduto, valorProduto);
    TParticipante* participante = BuscaParticipante(nomeParticipante);
    produto->SetComprador(participante);
    participante->InsereProdutoComprado(produto);
    idProduto++;
}

/*--------------------------------------------------------------------------------*/

void TParticipanteService::RemoveProdutoComprado(
    const string nomeParticipante,
    const string nomeProduto
)
{
    TParticipante* participante = BuscaParticipante(nomeParticipante);
    list<TProduto*> produtos = participante->GetProdutosComprados();

    auto predicate = [nomeProduto](TProduto* produto) {return produto->GetNome() == nomeProduto; };

    auto it = std::find_if(produtos.begin(), produtos.end(), predicate);

    TProduto* produto = dynamic_cast<TProduto*>(*it);
    
    if (produto != nullptr) {
        participante->RemoveProdutoComprado(produto);
    }
}

/*--------------------------------------------------------------------------------*/

map<string, double> TParticipanteService::Produtos(
    const string& nomeParticipante
)
{
    map<string, double> produtos;
    TParticipante* participante = BuscaParticipante(nomeParticipante);
    for (TProduto* produto : participante->GetProdutosComprados()) {
        produtos.insert(make_pair(produto->GetNome(), produto->GetValorTotal()));
    }

    return produtos;
}

/*--------------------------------------------------------------------------------*/

list<TProduto*>& TParticipanteService::TodosProdutos(
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
