#pragma once
#include "../../stdafx.h"
#include <SFML/Graphics.hpp>
#include "Personagem.h"

#define JOGADOR "The invasion/assets/personagem/jogador/personagem.png"
#define JOGADOR2 "The invasion/assets/personagem/jogador/personagem2.png"

namespace Entidades {
    namespace Personagens {

        class Inimigo;
        class Jogador : public Personagem {
        private:
            sf::Clock relogioColisao;
            sf::Vector2f vel_padrao;
            int forca;
            int pontuacao;

        public:
            Jogador(sf::Vector2f pos, sf::Vector2f tam_corpo = sf::Vector2f(80.0f, 80.0f), const char* text= JOGADOR);
            ~Jogador();
            void executar();
            void Mover_Se(bool Direita, bool pulo, float velY = -13.0f);
            void Atacar(Inimigo* pInimigo);
            void setPontuacao(int AuxPontuacao);
            int getPontuacao() const;
            void salvar();
            void CarregarSe(string atributos);
            void setJogador2(bool eh_jogador2 = true);
        };
    }
}