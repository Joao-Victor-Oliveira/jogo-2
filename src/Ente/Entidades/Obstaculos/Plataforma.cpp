#include "../../../../include/Ente/Entidades/Obstaculos/Plataforma.h"

using namespace Entidades;

Plataforma::Plataforma(int Px,int Py):Obstaculo(100,30,Px,Py)
{
    corpo.setFillColor(sf::Color::White);
    setTextura("imagens/Obstaculos/Plataforma.png");
}


Plataforma::~Plataforma()
{}
