#ifndef ENTE_H
#define ENTE_H
#include "../Gerenciadores/Gerenciador_Grafico.h"

using namespace Gerenciadores;

class Ente{
    private:
        static unsigned int geraId;

    protected:
            unsigned int id;
        Gerenciador_Grafico* grafico;
    public:
        Ente();
        virtual ~Ente();
        virtual void executar();
        void imprimir_se();
};




#endif // ENTE_H
