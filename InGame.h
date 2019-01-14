#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class InGame {
public:
	InGame();

	// Draw InGame
	void draw(RenderWindow &window);

private:
	// Sprite and Texture for the background
	Sprite InGame_BackgroundSprite;
	Texture InGame_BackgroundTexture;
};