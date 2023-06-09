#pragma once
#include "../stdafx.h"
#include "../Estados/Menu.h"
#include "../Estados/MenuPrincipal.h"
#include "../Estados/EstadoJogar.h"
#include "../Estados/MenuPause.h"
#include "../Estados/GameOver.h"
#include "../Estados/Ranking.h"
#include "../Estados/MenuSalvarPontuacao.h"
#include "../Fases/Fase1.h"
#include <map>

typedef map< string, Estados::Menu*> MapaStringEstado;

namespace Gerenciadores{

    class GerenciadorEstado{
        private:
            MapaStringEstado mapEstados;
            string EstadoAtual;
            //singleton
            GerenciadorEstado();

        public:
            static GerenciadorEstado* pGEstados;
            ~GerenciadorEstado();
            static GerenciadorEstado* getGerenciadorEstado();
            void executarEstadoAtual();
            void setEstadoAtual(string estadoAux);
			void TeclaPressionada(const sf::Keyboard::Key tecla);
			void ReiniciarEstadoJogar();
            void guardarPontuacao();
            string getStringEstadoAtual() const;
            void crieEexecuteEstadoJogar(bool eh_fase1 = true, bool eh_1_jogador = true);
            void apagueEstadoJogar();
            void salvarFase();
            void RecuperareExecutarFase();
    };
}