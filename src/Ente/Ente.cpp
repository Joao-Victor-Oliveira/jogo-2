#include "Ente.h"



unsigned int Ente::geraId=0;

Ente::Ente()
{
    grafico = grafico->getInstancia();
    id = geraId;
    geraId++;
}

Ente::~Ente()
{

}

void Ente::executar()
{

}

void Ente::imprimir_se()
{

}
