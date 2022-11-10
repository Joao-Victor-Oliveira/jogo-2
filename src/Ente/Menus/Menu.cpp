#include "Menu.h"

Menu::Menu():n(3){
    grafico = grafico->getInstancia();
    grafico->limpaJanela();
    if (!font.loadFromFile("arial.ttf")){
        printf("error abrindo fonte");}

    for(int i=0;i<3;i++){
        text[i].setFont(font);
        fases[i].setFont(font);}

    text[0].setString("Jogar");
    text[1].setString("Rank");
    text[2].setString("Sair");

    fases[0].setString("Voltar");
    fases[1].setString("Floresta");
    fases[2].setString("Pantano");

    for(int i=0;i<3;i++){
        text[i].setCharacterSize(24);
        text[i].setFillColor(sf::Color::White);
        text[i].setOutlineColor(sf::Color::Red);
        fases[i].setCharacterSize(24);
        fases[i].setFillColor(sf::Color::White);
        fases[i].setOutlineColor(sf::Color::Red);
    }

    text[0].setPosition(200.f,100.f);
    text[1].setPosition(200.f,300.f);
    text[2].setPosition(200.f,500.f);

    fases[0].setPosition(200.f,100.f);
    fases[1].setPosition(200.f,300.f);
    fases[2].setPosition(200.f,500.f);

}

Menu::~Menu(){
    grafico=NULL;
}

//=====================================================================================================//

#define INTERVALO 0.05
#define GROSSURA 2
//=====================================================================================================//

void Menu::executar(){
    sf::Clock relogio;
    text[n.getContador()].setOutlineThickness(GROSSURA);
    while(grafico->verificaJanelaAberta()){
        grafico->limpaJanela();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
            if(relogio.getElapsedTime().asSeconds()>INTERVALO){
                text[n.getContador()].setOutlineThickness(0);
                n--;
                text[n.getContador()].setOutlineThickness(GROSSURA);
            }
            relogio.restart();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
            if(relogio.getElapsedTime().asSeconds()>INTERVALO){
                text[n.getContador()].setOutlineThickness(0);
                n++;
                text[n.getContador()].setOutlineThickness(GROSSURA);
            }
            relogio.restart();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
            if(relogio.getElapsedTime().asSeconds()>INTERVALO){
                if(!n.getContador())
                    MostraFases();
                    //TODO criar um ranking dps
                return;
            }
            relogio.restart();
        }
        imprimir_se(0);
        grafico->mostrarConteudo();
    }
    return;
}

//=====================================================================================================//

void Menu::MostraFases(){
    sf::Clock relogio;
    fases[n.getContador()].setOutlineThickness(GROSSURA);

    grafico->limpaJanela();
    while(grafico->verificaJanelaAberta()){
        grafico->limpaJanela();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
            if(relogio.getElapsedTime().asSeconds()>INTERVALO){
                fases[n.getContador()].setOutlineThickness(0);
               n--;
                fases[n.getContador()].setOutlineThickness(GROSSURA);
            }
            relogio.restart();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
            if(relogio.getElapsedTime().asSeconds()>INTERVALO){
                fases[n.getContador()].setOutlineThickness(0);
                n++;
                fases[n.getContador()].setOutlineThickness(GROSSURA);
            }
            relogio.restart();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
            if(relogio.getElapsedTime().asSeconds()>INTERVALO){
                if(!n.getContador())
                    if(!n.getContador())
                        executar();
                    //TO DO chama a fase quabdo tiver pronto
                return;
            }
            relogio.restart();
        }
        imprimir_se(1);
        grafico->mostrarConteudo();
    }
    return;
}

void Menu::imprimir_se(int tela){
   switch(tela){
        case 0:
            grafico->desenhaElemento(text,3);
            break;
        case 1:
            grafico->desenhaElemento(fases,3);
            break;
    }
    return;
}
