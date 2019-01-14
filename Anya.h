#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

// Anya Class
class Anya
{
private:
	// Character Definitions
	Vector2f Anya_Position;
	Sprite Anya_Sprite;
	Texture Anya_Texture;

	// Moving Anya
	bool goLeft;
	bool goRight;
	float Anya_Speed;
public:
	// Constructor
	Anya();
	// Get Anya Sprite
	Sprite getSprite();
	// Moving Anya
	void moveLeft();
	void moveRight();
	void stopLeft();
	void stopRight();
	// Character draw update
	void update(float elapsedTime);
};
