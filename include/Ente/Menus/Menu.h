#ifndef MENU_H
#define MENU_H
#include "../../Ente/Ente.h"

using namespace Gerenciadores;

class Menu:protected Ente
{
    private:
    sf::Text text[3];
    sf::Text fases[3];
    sf::Font font;
    Gerenciador_Grafico* grafico;
    class Contador{
    private:
        int numero;
        int Max;
    public:
        Contador(int Max){numero=0; this->Max= Max-1;};
        ~Contador(){};
        void operator++(int){
            numero++;
            if(numero>Max)
                numero=0;};
        void operator--(int){
            numero--;
            if(numero<0)
                numero=Max;};
        int getContador(){return numero;}
    };
    Contador n;
    public:
    Menu();
    ~Menu();
    void executar();
    void MostraFases();
    void imprimir_se(int tela);
};

#endif // MENU_H
