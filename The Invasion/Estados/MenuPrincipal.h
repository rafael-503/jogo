#pragma once
#include "Estado.h"
#include "../Fases/Fase1.h"


namespace Estados{

    class MenuPrincipal: public Estado{
        private:
            bool Tela_inicial;
            sf::Text BotaoJogar;
            sf::Text BotaoRanking;
            sf::Text BotaoSair;
            sf::Text BotaoFase1_Jogador1;
            sf::Text BotaoFase1_Jogador2;
            sf::Text BotaoFase2_Jogador1;
            sf::Text BotaoFase2_Jogador2;

        public:
            MenuPrincipal();
            ~MenuPrincipal();
            void PrimeiroExecutar();
            void executar();
            void TeclaPressionada(const sf::Keyboard::Key tecla);

    };


}

