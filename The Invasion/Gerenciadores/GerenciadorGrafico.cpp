#include "../Gerenciadores/GerenciadorGrafico.h"
#define TAM_X 1200.0f
#define TAM_Y 800.0f
using namespace Gerenciadores;

GerenciadorGrafico* GerenciadorGrafico::pGrafico = NULL;
GerenciadorGrafico::GerenciadorGrafico() : window(new sf::RenderWindow(sf::VideoMode(TAM_X, TAM_Y), "The Invasion")),
    view(sf::Vector2f(TAM_X/2.0f, TAM_Y/2.0f), sf::Vector2f(TAM_X / 2.0f, TAM_Y / 2.0f))
{
	if (window == NULL)
		std::cout << "Erro ao criar a janela" << std::endl;
    window->setView(view);
}

GerenciadorGrafico::~GerenciadorGrafico(){
	if (window){
		delete window;
		window = NULL;
	}
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

void GerenciadorGrafico::setView(sf::View view){
    window->setView(view);
}

sf::View GerenciadorGrafico::getView() {
	return view;
}

void GerenciadorGrafico::atualizarView(sf::Vector2f pos) {
	view.setCenter(pos);
	window->setView(view);
}

void GerenciadorGrafico::reiniciarView() {
	view.setCenter(TAM_X/2, TAM_Y/2);
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

void GerenciadorGrafico::carregarFundo(const char* caminho) {

	if (!tex.loadFromFile(caminho)) {
		std::cout << "Erro ao carregar a textura" << std::endl;
		return;
	}

	sprite.setTexture(tex);
	sprite.setPosition(0, 0);

	sf::Vector2u windowSize = pGrafico->getWindow()->getSize();
	sprite.setScale(
		static_cast<float>(windowSize.x) / sprite.getTexture()->getSize().x,
		static_cast<float>(windowSize.y) / sprite.getTexture()->getSize().y
	);
	getWindow()->draw(sprite);
}

void GerenciadorGrafico::atalizaFundo() {
		getWindow()->draw(sprite);
}