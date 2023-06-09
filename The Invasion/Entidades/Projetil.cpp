#include "Projetil.h"
#define VEL_INICIAL 10.0f
using namespace Entidades;
#include "../Fases/Fase.h"

Projetil::Projetil(sf::Vector2f posInimigo, Personagens::Jogador* pJogador1, Personagens::Jogador* pJogador2):
     Entidade(sf::Vector2f(15.0f, 7.5f)), vel_projetil(5.0f), pPerseguido(NULL), pFase(NULL), dano(20)
{
    ID = 8;
     corpo.setPosition(posInimigo);
    textura = pGrafico->carregarTextura(PROJETIL);
    corpo.setTexture(&textura);

    if(pJogador1 && pJogador2){
        if(fabs(corpo.getPosition().x - pJogador1->getPosition().x) < fabs(corpo.getPosition().x - pJogador2->getPosition().x))
            pPerseguido = pJogador1;
        else
            pPerseguido = pJogador2;
    }
    else if(pJogador1)
        pPerseguido = pJogador1;
    else if(pJogador2)
        pPerseguido = pJogador2;
    else
        cout << "Jogadores Nulos em Projetil" << endl;

}
Projetil::~Projetil(){

}

void Projetil::executar(){
    if(pPerseguido){
        sf::Vector2f Direcao(pPerseguido->getPosition().x - corpo.getPosition().x, pPerseguido->getPosition().y - corpo.getPosition().y);

        ///transdorma Direcao em um vetor unitario para multiplicar por velocidade e ir nessa dire��o
        sf::Vector2f DirecaoUnitaria(Direcao.x / sqrt(Direcao.x*Direcao.x + Direcao.y*Direcao.y), Direcao.y / sqrt(Direcao.x*Direcao.x + Direcao.y*Direcao.y));
        corpo.move(DirecaoUnitaria.x * vel_projetil, DirecaoUnitaria.y * vel_projetil);
    }
    else
        cout << "pPerseguido Nulo em Projetil" << endl;

}

void Projetil::setFase(Fases::Fase* pFaseAux){
    pFase = pFaseAux;
}
void Projetil::AcertouJogador(Entidades::Personagens::Jogador* pJog){
    if(pJog)
        pJog->setVida(pJog->getVida() - dano);
    ApagarProjetil();

}
void Projetil::ApagarProjetil(){
    if (pFase)
        pFase->removerProjetil(static_cast<Entidade*>(this));
    else
        cout << "pFase Nulo em ApagarProjetil do Projetil" << endl;

}
