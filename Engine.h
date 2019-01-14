#pragma once
#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "InGame.h"

using namespace sf;

class Engine
{
private:
	Menu menu;
	InGame inGame;

	// A regular RenderWindow
	RenderWindow m_Window;

	// Control menu open/close
	bool menuIsOpen = true;

	// Handle user inputs
	void input();

	// Menu item area inside window
	Vector2f menuItemStartAreaInWindow[MAX_MENU_ITEMS];
	Vector2f menuItemEndAreaInWindow[MAX_MENU_ITEMS];

	// Menu item area on screen
	Vector2i menuItemStartArea[MAX_MENU_ITEMS];
	Vector2i menuItemEndArea[MAX_MENU_ITEMS];

	// Mouse position on screen
	Vector2i mousePosition;

	// Game window position on screen
	Vector2i gameWindowPosition;
	
public:
	// The Engine constructor
	Engine();

	// Starts the game
	void startGame();
};
