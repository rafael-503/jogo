#include "../stdafx.h"
#include "Entidade.h"
using namespace Entidades;


Entidade::Entidade(sf::Vector2f tam_corpo) :
    Ente(), corpo(tam_corpo)
{
}

Entidade::~Entidade() {}

sf::RectangleShape Entidade::getCorpo() {
    return corpo;
}

const sf::Vector2f Entidade::getPosition() const {
    return corpo.getPosition();
}
const sf::Vector2f Entidade::getSize() const {
    return corpo.getSize();

}
void Entidade::colisao(Entidade* pOutra, sf::Vector2f DistExt, bool Colidiu_em_x) {


}
string Entidade::getTipo() {
    return Tipo;
}

void Entidade::setVelocidade(sf::Vector2f v) {
    vel = v;
}
