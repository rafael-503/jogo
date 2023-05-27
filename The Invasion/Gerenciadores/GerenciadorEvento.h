#pragma once
#include "GerenciadorGrafico.h"

namespace Gerenciadores {

    class GerenciadorEstado;

    class GerenciadorEvento {
        private:
            static GerenciadorGrafico* pGrafico;
            GerenciadorEstado* pGEstado;

            //padr�o de projeto singleton
            static GerenciadorEvento* pEvento;
            GerenciadorEvento();
        public:
            ~GerenciadorEvento();
            static GerenciadorEvento* getGerenciadorEvento();
            void executar();
            void verificarEventos();
    };

}


