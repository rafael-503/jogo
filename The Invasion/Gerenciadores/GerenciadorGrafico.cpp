#include "../Gerenciadores/GerenciadorGrafico.h"
#define TAM_X 1200.0f
#define TAM_Y 800.0f
using namespace Gerenciadores;

GerenciadorGrafico* GerenciadorGrafico::pGrafico = NULL;
GerenciadorGrafico::GerenciadorGrafico() : window(new sf::RenderWindow(sf::VideoMode(TAM_X, TAM_Y), "The Invasion")),
    view(sf::FloatRect(0.0f, 0.0f, TAM_X, TAM_Y)), pTextFundo(NULL)
{
	if (window == NULL)
		std::cout << "Erro ao criar a janela" << std::endl;
   // window->setView(view);

}

GerenciadorGrafico::~GerenciadorGrafico(){
	if (window){
		delete window;
		window = NULL;
	}
	if(pTextFundo)
        delete pTextFundo;
}

GerenciadorGrafico* GerenciadorGrafico::getGerenciadorGrafico(){
	if(pGrafico == NULL)
		pGrafico = new GerenciadorGrafico();
	return pGrafico;
}

sf::RenderWindow* GerenciadorGrafico::getWindow() {
	return window;
}

void GerenciadorGrafico::limparJanela() {
	window->clear();
}

void GerenciadorGrafico::desenharElemento(sf::RectangleShape corpo) {
	window->draw(corpo);
}
void GerenciadorGrafico::desenharElemento(sf::Text texto){
    window->draw(texto);
}
void GerenciadorGrafico::desenharElemento(sf::Sprite sprite){
    window->draw(sprite);
}
void GerenciadorGrafico::setView(sf::View view){
    window->setView(view);
}


void GerenciadorGrafico::mostrarElementos() {
	window->display();
}


void GerenciadorGrafico::fecharJanela() {
	window->close();
}

const bool GerenciadorGrafico::verificarJanelaAberta() {
	return window->isOpen();
}

sf::Texture GerenciadorGrafico::carregarTextura(const char* caminho){
	sf::Texture textura;
	if (!textura.loadFromFile(caminho))
        std::cout << "Erro ao carregar a textura" << std::endl;
	return textura;
}

sf::Sprite GerenciadorGrafico::carregarFundo(const char* caminho) {
	//sprite.setTexture(pGrafico->carregarTextura(caminho.c_str()));
    pTextFundo = new sf::Texture(carregarTextura(caminho));

	sf::Sprite sprite(*pTextFundo);
   // pSprite->setTexture(textura);
	sprite.setPosition(0.0f, 0.0f);

	sf::Vector2u windowSize = pGrafico->getWindow()->getSize();
	sprite.setScale(
		static_cast<float>(windowSize.x) / sprite.getTexture()->getSize().x,
		static_cast<float>(windowSize.y) / sprite.getTexture()->getSize().y
	);
	return sprite;
}
