#include "../../stdafx.h"
#include "Jogador.h"
using namespace Entidades;
using namespace Personagens;

void Jogador::inicializa() {
}

Jogador::Jogador(sf::Vector2f tam_corpo) :
    Personagem(tam_corpo, "Jogador")
{
    //corpo.setFillColor(sf::Color::Blue);
    corpo.setPosition(10.0f, 0.0f);
    setMassa(60.0f);
    setVelocidade(sf::Vector2f(10.0f, 0.0f));

    textura = pGrafico->carregarTextura("The Invasion/assets/personagem/jogador/personagem.png");
    corpo.setTexture(&textura);
}
Jogador::~Jogador() {}

void Jogador::executar() {
    if(!colidiu_em_y)
        efeitoGravidade();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        corpo.move(-vel.x, 0.0f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        corpo.move(vel.x, 0.0f);
    }
    if (colidiu_em_y && (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space))) {
        vel.y = -10.0f;
    }

 /*
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        corpo.move(0.0f, -vel.y);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        corpo.move(0.0f, vel.y);
    }

*/
    colidiu_em_y = false;
    corpo.move(0.0f, vel.y);
}

void Jogador::colisao(Entidade* pOutra, sf::Vector2f DistanciaExtremidades, bool Colidiu_em_x) {
    if (pOutra->getTipo() == "Inimigo")
        cout << "Jogador Colidiu com Inimigo" << endl;
    if (pOutra->getTipo() == "Obstaculo") {
        sf::Vector2f posJogador = getPosition(), posOutro = pOutra->getPosition();
        if (!Colidiu_em_x) {
            if (posJogador.y < posOutro.y){
                corpo.move(0.0f, DistanciaExtremidades.y);
                colidiu_em_y = true;
                relogio.restart();
            }
            else{
                corpo.move(0.0f, -DistanciaExtremidades.y);
                //bateu a cabe�a
                //if (vel.y > 0.0f)
                    vel.y = 0.0f;
            }

        }
        else    {
            if (posJogador.x < posOutro.x)
                corpo.move(DistanciaExtremidades.x, 0.0f);
            else
                corpo.move(-DistanciaExtremidades.x, 0.0f);
        }

    }

}



