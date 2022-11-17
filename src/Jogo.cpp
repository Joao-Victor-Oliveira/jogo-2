#include "../include/Jogo.h"


#include <iostream>
#define MAX 5
#define MIN 3
#define RANDOM (rand()%(MAX-MIN))+MIN

Jogo::Jogo():
gerenciador_grafico(Gerenciadores::Gerenciador_Grafico::getInstancia()),
//personagens(),
//gerenciador_colisoes(&personagens, &obstaculos),
jogador(sf::Vector2f(70, 70), sf::Vector2f(600, 100), sf::Vector2f(1.0, 1.0)),
fase(&jogador,&gerenciador_colisoes,RANDOM,RANDOM,RANDOM,1280),
menu(&fase)
{
    /*obstaculos.inserirEntidade(static_cast<Entidades::Entidade*>(&plataforma));
    obstaculos.inserirEntidade(static_cast<Entidades::Entidade*>(new Entidades::Plataforma(400,200)));
    obstaculos.inserirEntidade(static_cast<Entidades::Entidade*>(new Entidades::Ninho(600,340)));
    personagens.inserirEntidade(static_cast<Entidades::Entidade*>(&jogador));*/
}

Jogo::~Jogo()
{
    //dtor
}

void Jogo::executar()
{
    menu.executar();
/*
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
        gerenciador_colisoes.executar();
        gerenciador_grafico->mostrarConteudo();

    }
*/
}
