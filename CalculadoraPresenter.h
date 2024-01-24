#ifndef CALCULADORAPRESENTER_H
#define CALCULADORAPRESENTER_H

#include <string>
#include <list>
#include <vector>

/*--------------------------------------------------------------------------------*/

class TCalculadoraPresenter {

public:
    TCalculadoraPresenter();

    ~TCalculadoraPresenter() = default;

    int ShowWindow(
        int argc,
        char* argv[]
    );

    void CadastraParticipantes(
        std::vector<std::string>* participantes
    );

private:

};

/*--------------------------------------------------------------------------------*/

#endif