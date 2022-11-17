#ifndef FASE_H
#define FASE_H

#include "../Ente.h"
#include "SFML/Graphics.hpp"

#include "../Entidades/Personagens/Jogador.h"
#include "../Entidades/Personagens/Inimigo.h"
#include "../../Listas/ListaEntidades.h"
#include "../../Gerenciadores/Gerenciador_Grafico.h"
#include "../../Gerenciadores/Gerenciador_Colisoes.h"
#include "../Entidades/Obstaculos/Plataforma.h"
#include "../Entidades/Obstaculos/Espinhos.h"
#include "../Entidades/Obstaculos/Ninho.h"
#include "../Entidades/Obstaculos/Piso.h"

namespace Fases {

    class Fase : public Ente {
    private:
        Entidades::Jogador* jogador1;
        Listas::ListaEntidades personagens;
        Listas::ListaEntidades obstaculos;
        Gerenciadores::Gerenciador_Colisoes* gerenciador_colisoes;

    public:
        Fase();

        Fase(Entidades::Jogador* jg,Gerenciadores::Gerenciador_Colisoes* gc,int obs1,int obs2,int obs3,int tam);

        virtual ~Fase();

        void gerenciar_colisoes();

        virtual void executar();
    };

}

#endif // FASE_H
