#include "Cachorro.h"
using namespace Entidades;
using namespace Personagens;

Cachorro::Cachorro(sf::Vector2f pos, sf::Vector2f tam_corpo) : Inimigo(tam_corpo), manso(true){
    ID = 3;
    corpo.setPosition(pos);

    if (num %2 == 0)
        manso = false;

    if (manso) {
        textura = pGrafico->carregarTextura(CACHORRO2);
        corpo.setTexture(&textura);
    }
    else {
        textura = pGrafico->carregarTextura(CACHORRO);
        corpo.setTexture(&textura);
    }
}

Cachorro::~Cachorro() {}

void Cachorro::danar(Jogador* pJog) {
    if (pJog) {
        if(clockInteracao.getElapsedTime().asSeconds() > 5.0f){
            if (manso)
                pJog->setVida(pJog->getVida() - 2);
            else
                pJog->setVida(pJog->getVida() - 7);
            clockInteracao.restart();
        }
    }
}

void Cachorro::salvar(){
    ofstream GravadorCachorro("data/Cachorro.txt", ios_base::app);
    if (GravadorCachorro.is_open()) {
        GravadorCachorro << getPosition().x << ' ' << getPosition().y << ' ' << vida << ' ' << manso <<  endl;
        GravadorCachorro.close();
    }
    else
        cout << "Erro ao abrir o arquivo." << std::endl;
}

void Cachorro::CarregarSe(string atributos){
    std::istringstream iss(atributos);
    float posX, posY;
    iss >>  posX >> posY >> vida >> manso;
    if (!iss.fail()) {
        setPosition(sf::Vector2f(posX, posY));
    }
    else
        cout << "Erro ao converter os valores em CarregarSe" << endl;
}