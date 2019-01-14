#include "pch.h"
#include "Menu.h"

Menu::Menu() {
	font.loadFromFile("28 Days Later.ttf");

	// Set Menu Background
	m_BackgroundTexture.loadFromFile("MenuBackground.jpg");
	m_BackgroundSprite.setTexture(m_BackgroundTexture);

	// Set title
	title.setFont(font);
	title.setString("NAVY BLUE");
	title.setCharacterSize(70);
	title.setFillColor(Color::White);
	title.setPosition(Vector2f(100, 60));

	// Set menu options
	int i;
	for (i = 0; i < MAX_MENU_ITEMS; i++) {
		menuOptions[i].setFont(font);
		menuOptions[i].setFillColor(Color::White);
	}

	// Window: 1000 x 600

	menuOptions[0].setString("Play");
	menuOptions[0].setPosition(Vector2f(300, 300));

	menuOptions[1].setString("Exit");
	menuOptions[1].setPosition(Vector2f(700, 300));

	selectedItemIndex = -1;
}

void Menu::draw(RenderWindow &window) {
	// Draw Background
	window.draw(m_BackgroundSprite);
	// Draw Title
	window.draw(title);
	// Draw Menu Options
	int i;
	for (i = 0; i < MAX_MENU_ITEMS; i++) {
		window.draw(menuOptions[i]);
	}
}

void Menu::selectMenuItem(int index) {
	// Change selected item index and change menu item text color to selected
	selectedItemIndex = index;
	menuOptions[selectedItemIndex].setFillColor(Color::Cyan);
}

void Menu::unselectAll() {
	// Change selected item index to none and change all menu items text color to unselected
	selectedItemIndex = -1;
	int i;
	for (i = 0; i < MAX_MENU_ITEMS; i++) {
		menuOptions[i].setFillColor(Color::White);
	}
}

Vector2f Menu::getMenuItemStartArea(int index) {
	// Get menu item top left position in window
	return menuOptions[index].getPosition();
}

Vector2f Menu::getMenuItemEndArea(int index) {
	// Get menu item bottom right position in window
	Vector2f menuItemPos = menuOptions[index].getPosition();
	FloatRect menuItemBounds = menuOptions[index].getLocalBounds();
	Vector2f endArea;
	endArea.x = menuItemBounds.width + menuItemPos.x;
	endArea.y = menuItemBounds.height + menuItemPos.y;
	return endArea;
}

bool Menu::checkMouseoverMenuItem(Vector2i mousePosition, Vector2i menuItemStartArea, Vector2i menuItemEndArea) {
	// Check is mouse position is inside a menu item area
	if (mousePosition.x >= menuItemStartArea.x &&
		mousePosition.x <= menuItemEndArea.x &&
		mousePosition.y >= menuItemStartArea.y &&
		mousePosition.y <= menuItemEndArea.y) {
		return true;
	}
	return false;
}

int Menu::getSelectedItemIndex() {
	return selectedItemIndex;
}