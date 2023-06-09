#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../stdafx.h"

namespace Gerenciadores {
	class GerenciadorGrafico {
	private:
		sf::RenderWindow* window;
		static GerenciadorGrafico* pGrafico;
		GerenciadorGrafico();
		sf::View view;
		sf::Sprite sprite;
		sf::Texture tex;

	public:
		~GerenciadorGrafico();
		static GerenciadorGrafico* getGerenciadorGrafico();
		sf::RenderWindow* getWindow();
		void limparJanela();
		void desenharElemento(sf::RectangleShape corpo);
		void desenharElemento(sf::Text texto);
		void mostrarElementos();
		void fecharJanela();
		void setView(sf::View view);
		sf::View getView() const;
		void atualizarView(const sf::Vector2f& jogadorPos);
		void reiniciarView();
		const bool verificarJanelaAberta();
		sf::Texture carregarTextura(const char* caminho);
		void carregarFundo(const char* caminho);
		void atalizaFundo();
		void mostrarVidaJogador(int vida1, int vida2 = 0, bool eh_1_jogador = false, sf::Color color = sf::Color::White);
        sf::Vector2u getSize() const;
	};
}