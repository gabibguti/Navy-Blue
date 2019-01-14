#include "pch.h"
#include "Engine.h"
#include <iostream>

using namespace std;

void Engine::input() {
	// Handle the player quitting
	if (Keyboard::isKeyPressed(Keyboard::Escape))
	{
		m_Window.close();
	}

	// Get mouse position on screen
	mousePosition = Mouse::getPosition();

	// Get game window position on screen 
	gameWindowPosition = m_Window.getPosition();
	
	// Transform to get menu items area on screen
	int i;
	for (i = 0; i < MAX_MENU_ITEMS; i++) {
		Vector2f startArea = menuItemStartAreaInWindow[i];
		Vector2f endArea = menuItemEndAreaInWindow[i];
		menuItemStartArea[i] = Vector2i(gameWindowPosition.x + startArea.x, gameWindowPosition.y + startArea.y);
		menuItemEndArea[i] = Vector2i(gameWindowPosition.x + endArea.x, gameWindowPosition.y + endArea.y);
	}

	// Adjust menu items area to fit better
	for (i = 0; i < MAX_MENU_ITEMS; i++) {
		menuItemStartArea[i].x += 10;
		menuItemStartArea[i].y += 35;
		menuItemEndArea[i].x += 10;
		menuItemEndArea[i].y += 35;
	}

	bool menuItemSelected = false;

	// Check mouseover menu items
	for (i = 0; i < MAX_MENU_ITEMS; i++) {
		if (menu.checkMouseoverMenuItem(mousePosition, menuItemStartArea[i], menuItemEndArea[i])) {
			// Mouseover menu item area, then select menu item
			menu.selectMenuItem(i);
			menuItemSelected = true;
			break;
		}
	}

	// Mouse over a menu item
	if (menuItemSelected) {
		// Check left click
		if (Mouse::isButtonPressed(Mouse::Button::Left)) {
			switch (menu.getSelectedItemIndex())
			{
			case 0:
				// Play
				menuIsOpen = false;
				break;
			case 1:
				// Exit
				m_Window.close();
				break;
			default:
				break;
			}
		}
	}
	else {
		// Mouse not over any menu items
		menu.unselectAll();
	}
		
}