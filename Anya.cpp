#include "pch.h"
#include "Anya.h"

// Anya Constructor: Define initial variables
Anya::Anya() {
	Anya_Speed = 400;
	Anya_Texture.loadFromFile("Anya_Stop");
	Anya_Sprite.setTexture(Anya_Texture);
	Anya_Position.x = 300;
	Anya_Position.y = 300;
}

// Get Anya actual sprite
Sprite Anya::getSprite() {
	return Anya_Sprite;
}

// Move Anya left
void Anya::moveLeft() {
	goLeft = true;
}

// Move Anya right
void Anya::moveRight() {
	goRight = true;
}

// Stop moving Anya left
void Anya::stopLeft() {
	goLeft = false;
}

// Stop moving Anya right
void Anya::stopRight() {
	goRight = false;
}

// Update Anya settings
void Anya::update(float elapsedTime) {
	// Update Anya position
	if (goLeft) {
		Anya_Position.x += Anya_Speed * elapsedTime;
	}
	if (goRight) {
		Anya_Position.x -= Anya_Speed * elapsedTime;
	}

	Anya_Sprite.setPosition(Anya_Position);
}