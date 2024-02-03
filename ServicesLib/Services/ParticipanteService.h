#ifndef PARTICIPANTESERVICE_H
#define PARTICIPANTESERVICE_H

#include <string>
#include <list>
#include <map>

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

    void InsereProdutoComprado(
        const std::string& nomeParticipante,
        const std::string& nomeProduto,
        double valorProduto
    );

    void RemoveProdutoComprado(
        const std::string nomeParticipante,
        const std::string nomeProduto
    );

    std::map<std::string, double> Produtos(
        const std::string& nomeParticipante
    );

    //const &??
    std::list<TProduto*>& TodosProdutos(
        const std::list<TParticipante*>* participantes
    );

private:
    TParticipante* BuscaParticipante(
        const std::string& nome
    ) const;

    TProdutoService* prodService;

    std::list<TParticipante*>* participantes;
};

#endif