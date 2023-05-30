#include "Fase1.h"
using namespace Fases;
#define JOGADOR2 "The invasion/assets/personagem/jogador/personagem2.png"

Fase1::Fase1(): POS_MIN(1000), POS_MAX(2500) {
	if(pGrafico)
        pGrafico->carregarFundo("The invasion/assets/fundo/fundo1.png");
    else
        cout << "pGrafico Nulo na construtora da fase 1" << endl;
	criarPersonagens();
	criarObstaculos();
}

Fase1::~Fase1() {
    pColisao->limpar();
    pColisao = NULL;
    pJogador1 = NULL;
    esvaziar();
    cout << "Fase 1 destruida" << endl;
}

void Fase1::executar() {
	listaPersonagens.executar();
	listaObstaculos.executar();
    pColisao->testa_colisoes();
	listaPersonagens.seDesenhe();
    listaObstaculos.seDesenhe();
    if(pJogador1)
      pGrafico->mostrarVidaJogador(pJogador1->getVida());
    listaPersonagens.verificarVida();
    //cout << pJogador1->getPosition().x << ", " <<  pJogador1->getPosition().y << endl;
}

void Fase1::esvaziar() {
	listaPersonagens.esvaziar();
	listaObstaculos.esvaziar();
}

void Fase1::construtorObstaculos(const std::string& tipo, const sf::Vector2f& tam, const sf::Vector2f& pos) {
    Entidades::Obstaculos::Obstaculo* pObstaculo = NULL;
    Entidade* pEntidade = NULL;

    if (tipo == "Caixa")
        pObstaculo = new Entidades::Obstaculos::Caixa(tam, pos);
    else if (tipo == "Espinhos")
        pObstaculo = new Entidades::Obstaculos::Espinhos(tam, pos);
    else if (tipo == "Plataforma")
        pObstaculo = new Entidades::Obstaculos::Plataforma(tam, pos);
    else {
        cout << "Erro: Tipo de obstaculo invalido" << endl;
        return;
    }

    if (pObstaculo) {
        pColisao->incluiObstaculo(pObstaculo);
        pEntidade = static_cast<Entidade*>(pObstaculo);
        listaObstaculos.inserir(pEntidade);
    }
}

void Fase1::construtorPersonagens(const std::string& tipo, Entidades::Personagens::Jogador* pJogador, const sf::Vector2f& pos) {
    Entidades::Entidade* pEntidade = NULL;
	Entidades::Personagens::Inimigo* pInimigo = NULL;

    if (tipo == "Cachorro") {
    	Entidades::Personagens::Cachorro* pCachorro = new Entidades::Personagens::Cachorro(pos);
		pInimigo = static_cast<Entidades::Personagens::Inimigo*>(pCachorro);
    }
    else if (tipo == "Soldado") {
        Entidades::Personagens::Soldado* pSoldado = new Entidades::Personagens::Soldado(pos);
        pInimigo = static_cast<Entidades::Personagens::Inimigo*>(pSoldado);
    }
    else if (tipo == "Lenhador") {
        Entidades::Personagens::Lenhador* pLenhador = new Entidades::Personagens::Lenhador(pos);
		pInimigo = static_cast<Entidades::Personagens::Inimigo*>(pLenhador);
    }
    else {
		cout << "Erro: Tipo de personagem invalido" << endl;
		return;
	}

    if (pInimigo) {
        pInimigo->setJogador(pJogador);
		pColisao->incluiInimigo(pInimigo);
		pEntidade = static_cast<Entidade*>(pInimigo);
		listaPersonagens.inserir(pEntidade);
	}
}

void Fase1::criarPersonagens() {
    Entidades::Entidade* pEntidade = NULL;
    pJogador1= new Entidades::Personagens::Jogador(sf::Vector2f(10.0f, 0.0f));
    pJogador2 = new Entidades::Personagens::Jogador(sf::Vector2f(10.0f, 0.0f), sf::Vector2f(60.0f, 80.0f), JOGADOR2);

    pEntidade = static_cast<Entidade*> (pJogador1);
    listaPersonagens.inserir(pEntidade);

    pEntidade = static_cast<Entidade*> (pJogador2);
    listaPersonagens.inserir(pEntidade);
    pColisao->setJogador(pJogador1);
    pColisao->setJogador(pJogador2);
    
    construtorPersonagens("Cachorro", pJogador1, sf::Vector2f(800.0f, 200.0f));
    construtorPersonagens("Soldado", pJogador1, sf::Vector2f(3300.0f, 0.0f));
 
    // Criacao de inimigos aleatorios
    std::srand(time(0));
    int x = POS_MIN + (rand() % (POS_MAX - POS_MIN + 1)); // Gera numeros entre 500 e 2000
    
	construtorPersonagens("Cachorro", pJogador1, sf::Vector2f(x, 0.0f));
	construtorPersonagens("Lenhador", pJogador1, sf::Vector2f(x + 100, 0.0f));
	construtorPersonagens("Cachorro", pJogador1, sf::Vector2f(x + 150, 0.0f));
	construtorPersonagens("Lenhador", pJogador1, sf::Vector2f(x + 200, 0.0f));
	construtorPersonagens("Cachorro", pJogador1, sf::Vector2f(x + 250, 0.0f));
	construtorPersonagens("Lenhador", pJogador1, sf::Vector2f(x + 300, 0.0f));
}

void Fase1::criarObstaculos() {
    construtorObstaculos("Caixa", sf::Vector2f(50.0f, 50.0f), sf::Vector2f(330.0f, 0.0f));
    construtorObstaculos("Plataforma", sf::Vector2f(25000.0f, 50.0f), sf::Vector2f(0.0f, 800.0f)); // remover

    construtorObstaculos("Plataforma", sf::Vector2f(250.0f, 50.0f), sf::Vector2f(0.0f, 750.0f));
    construtorObstaculos("Plataforma", sf::Vector2f(180.0f, 50.0f), sf::Vector2f(300.0f, 600.0f));
    construtorObstaculos("Plataforma", sf::Vector2f(180.0f, 50.0f), sf::Vector2f(500.0f, 500.0f));
    construtorObstaculos("Plataforma", sf::Vector2f(180.0f, 50.0f), sf::Vector2f(300.0f, 350.0f));
    construtorObstaculos("Plataforma", sf::Vector2f(230.0f, 50.0f), sf::Vector2f(780.0f, 200.0f));
    construtorObstaculos("Espinhos", sf::Vector2f(50.0f, 50.0f), sf::Vector2f(780.0f, 165.0f));
    construtorObstaculos("Espinhos", sf::Vector2f(50.0f, 50.0f), sf::Vector2f(810.0f, 165.0f));
    construtorObstaculos("Plataforma", sf::Vector2f(230.0f, 50.0f), sf::Vector2f(780.0f, 600.0f));
    construtorObstaculos("Plataforma", sf::Vector2f(230.0f, 50.0f), sf::Vector2f(1000.0f, 600.0f));
    construtorObstaculos("Plataforma", sf::Vector2f(200.0f, 50.0f), sf::Vector2f(1300.0f, 150.0f));
    construtorObstaculos("Plataforma", sf::Vector2f(200.0f, 50.0f), sf::Vector2f(1500.0f, 150.0f));

    construtorObstaculos("Espinhos", sf::Vector2f(50.0f, 50.0f), sf::Vector2f(1450.0f, 120.0f));
    construtorObstaculos("Espinhos", sf::Vector2f(50.0f, 50.0f), sf::Vector2f(1500.0f, 120.0f));
    construtorObstaculos("Plataforma", sf::Vector2f(200.0f, 50.0f), sf::Vector2f(1700.0f, 700.0f));
    construtorObstaculos("Plataforma", sf::Vector2f(200.0f, 50.0f), sf::Vector2f(2080.0f, 600.0f));
    construtorObstaculos("Plataforma", sf::Vector2f(200.0f, 50.0f), sf::Vector2f(2260.0f, 500.0f));

    construtorObstaculos("Plataforma", sf::Vector2f(700.0f, 50.0f), sf::Vector2f(3000.0f, 600.0f)); // soldado
    construtorObstaculos("Plataforma", sf::Vector2f(200.0f, 50.0f), sf::Vector2f(2805.0f, 560.0f));
    construtorObstaculos("Plataforma", sf::Vector2f(200.0f, 50.0f), sf::Vector2f(3695.0f, 560.0f));


    // Criacao de obstaculos aleatorios
    srand(time(0));
    
    for (int i = 0; i < 3; i++) {
        int x = 1000 + (rand() % (2500 - 1000 + 1));
        int y = 0 + (rand() % (750 - 0 + 1));

        construtorObstaculos("Caixa", sf::Vector2f(50.0f, 50.0f), sf::Vector2f(x+100, 0.0f));
        construtorObstaculos("Plataforma", sf::Vector2f(230.0f, 50.0f), sf::Vector2f(x-20, y));
        construtorObstaculos("Espinhos", sf::Vector2f(50.0f, 50.0f), sf::Vector2f(x, y-40));

    }
}
