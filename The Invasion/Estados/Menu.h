#pragma once
#include "../Ente.h"
#include <list>

namespace Estados{

    class Menu: public Ente{
        protected:
            sf::Font font;
            Gerenciadores::GerenciadorGrafico* pGrafico;
            bool executando;

        public:
            Menu();
            virtual ~Menu();
            void setExecutando(bool ativo);
            virtual void TeclaPressionada(const sf::Keyboard::Key tecla) = 0;
            virtual void PrimeiroExecutar() = 0;
            virtual void executar() = 0;
            virtual void guardarPontuacao(int num);
            void carregarFase2();
    };
}