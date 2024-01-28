#include "ParticipanteService.h"

#include <InputValidator.h>
#include <iostream>

#include "Models/Participante.h"

/*--------------------------------------------------------------------------------*/

static int idParticipante = 1;

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
