#include "pch.h"
#include "InGame.h"

InGame::InGame() {
	// Set InGame Background
	InGame_BackgroundTexture.loadFromFile("InGameBackground.jpg");
	InGame_BackgroundSprite.setTexture(InGame_BackgroundTexture);
}

void InGame::draw(RenderWindow &window) {
	// Draw InGame Background
	window.draw(InGame_BackgroundSprite);
}