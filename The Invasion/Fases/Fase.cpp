#include "Fase.h"
using namespace Fases;

Fase::Fase(): eh_1_jogador(true), pColisao(pColisao->getGerenciador_Colisoes()), pJogador1(NULL), pJogador2(NULL), relogioAtirar(){
	pColisao->limpar();
}

Fase::~Fase() {

	pColisao = NULL;
	listaObstaculos.esvaziar();
	listaPersonagens.esvaziar();
}

void Fase::gerenciarColisoes() {
	//pColisao->Calcula_colisao(listaPersonagens, listaObstaculos);
}
void Fase::TeclaPressionada(const sf::Keyboard::Key tecla){
    if(pJogador1){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            pJogador1->Mover_Se(false, false);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            pJogador1->Mover_Se(true, false);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            pJogador1->Mover_Se(false, true);
        setPosicaoJogador(pJogador1->getPosition());
    }
    else
        cout << "pJogador1 Nulo" << endl;


    if (pJogador2) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            pJogador2->Mover_Se(false, false);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            pJogador2->Mover_Se(true, false);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            pJogador2->Mover_Se(false, true);
        setPosicaoJogador(pJogador2->getPosition());
    }
}
void Fase::setPosicaoJogador(const sf::Vector2f& jogadorPos) {
    pGrafico->atualizarView(jogadorPos);
}
void Fase::removerProjetil(Entidade* pEnti){
    listaPersonagens.remover(pEnti);
    pColisao->removerProjetil(static_cast<Projetil*>(pEnti));
}




void Fase::AdicionarProjetil(sf::Vector2f pos){

    Entidades::Projetil* pProjetil = NULL;
    pProjetil = new Entidades::Projetil(pos, pJogador1, pJogador2);
    Entidade* pEntidade = NULL;
    if(pProjetil)
        pEntidade = static_cast<Entidades::Entidade*> (pProjetil);
    else
        cout << "erro ao criar Projetil" << endl;
    listaPersonagens.inserir(pEntidade);
    pColisao->incluiProjetil(pProjetil);
    pProjetil->setFase(this);

}
void Fase::SalvarFase(){
    std::ofstream GravadorFase("Fase.txt", ios::out);
    if (!GravadorFase){
        cerr << "Arquivo n�o pode ser aberto" << endl;
        fflush (stdin);
        getchar ();
        return;
    }
    listaPersonagens.GravarSe(&GravadorFase);
    listaObstaculos.GravarSe(&GravadorFase);

    GravadorFase.close();

}
void Fase::CarregarSe(){
    ifstream RecuperadorFase("Fase.txt", ios::in);

    if(!RecuperadorFase){
        cerr << "Arquivo n�o pode ser aberto" << endl;
        fflush(stdin);
        getchar();
        return;
    }
    listaPersonagens.CarregarSe(&RecuperadorFase, this);
    listaObstaculos.CarregarSe(&RecuperadorFase, this);
    RecuperadorFase.close();
    getchar();
}
void Fase::CarregarEntidades(int id, sf::Vector2f pos){
    //if(id == 1)
    //    construtorPersonagens("", NULL, pos);
    if(id == 2)
        construtorPersonagens("Lenhador", NULL, pos);
    else if(id == 3)
        construtorPersonagens("Cachorro", NULL, pos);
    else if(id == 4)
        construtorPersonagens("Soldado", NULL, pos);
    else if(id == 5)
        construtorObstaculos("Plataforma", pos);
    else if(id == 6)
        construtorObstaculos("Caixa", pos);
    else if(id == 7)
        construtorObstaculos("Espinhos", pos);
  //  else if(id == 7)
       // Projetil

}




