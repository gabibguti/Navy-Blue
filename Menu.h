#pragma once
#include <SFML/Graphics.hpp>

#define MAX_MENU_ITEMS 2

using namespace sf;

class Menu {
public:
	Menu();

	// Draw menu
	void draw(RenderWindow &window);

	// Selecting menu items
	Vector2f getMenuItemStartArea(int index);
	Vector2f getMenuItemEndArea(int index);
	void selectMenuItem(int index);
	void unselectAll();
	bool checkMouseoverMenuItem(Vector2i mousePosition, Vector2i menuItemStartArea, Vector2i menuItemEndArea);
	int getSelectedItemIndex();

private:
	// Menu Items
	int selectedItemIndex;
	Font font;
	Text menuOptions[MAX_MENU_ITEMS];
	Text title;

	// Sprite and Texture for the background
	Sprite m_BackgroundSprite;
	Texture m_BackgroundTexture;
};