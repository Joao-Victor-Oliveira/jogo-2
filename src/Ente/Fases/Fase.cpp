#include "../../../include/Ente/Fases/Fase.h"

using namespace Fases;

Fase::Fase(Entidades::Jogador* jg,Gerenciadores::Gerenciador_Colisoes* gc,int obs1,int obs2,int obs3,int tam){
    jogador1=jg;
    gerenciador_colisoes = gc;
    gerenciador_colisoes->setListaPersonagens(&personagens);
    gerenciador_colisoes->setListaObstaculos(&obstaculos);
    obstaculos.inserirEntidade(static_cast<Entidades::Entidade*>(new Entidades::Piso(tam,60,tam/2,720-60/2)));
    obstaculos.inserirEntidade(static_cast<Entidades::Entidade*>(new Entidades::Obstaculo(60,1000,-30,500)));
    obstaculos.inserirEntidade(static_cast<Entidades::Entidade*>(new Entidades::Obstaculo(60,1000,tam+30,500)));
    //obstaculos.inserirEntidade(static_cast<Entidades::Entidade*>(new Entidades::Espinhos(400,640)));
    for(int i=0;i<obs1;i++)
        obstaculos.inserirEntidade(static_cast<Entidades::Entidade*>(new Entidades::Plataforma(tam/obs1*i+100,450)));
    personagens.inserirEntidade(static_cast<Entidades::Entidade*>(jogador1));

}


Fase::Fase()
{

}

Fase::~Fase()
{
    //dtor
}


void Fase::gerenciar_colisoes()
{

}
void Fase::executar()
{
    gerenciador_grafico->limpaJanela();
    while (gerenciador_grafico->verificaJanelaAberta())
    {
        sf::Event evento;
        if (gerenciador_grafico->getWindow()->pollEvent(evento))
        {
            if (evento.type == sf::Event::Closed)
                gerenciador_grafico->fecharJanela();

        }
        gerenciador_grafico->limpaJanela();
        personagens.executarEntidades();
        obstaculos.executarEntidades();
        gerenciador_colisoes->executar();
        gerenciador_grafico->mostrarConteudo();

    }
}
