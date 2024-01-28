#ifndef PARTICIPANTESERVICE_H
#define PARTICIPANTESERVICE_H

#include <string>
#include <list>

#include "Services/ProdutoService.h"

/*--------------------------------------------------------------------------------*/

class TParticipante;

/*--------------------------------------------------------------------------------*/

class TParticipanteService {

public:
    TParticipanteService(
        TProdutoService* _prodService
    );

    ~TParticipanteService();

    void CadastraParticipantes(
        const std::list<std::string>& nomesParticipantes
    );

    void RemoveParticipante(
        const std::string& nome
    );

    bool ParticipanteComprouProdutos(
        const std::string& nome
    ) const;

private:
    TParticipante* BuscaParticipante(
        const std::string& nome
    ) const;

    TProdutoService* prodService;

    std::list<TParticipante*>* participantes;
};

#endif