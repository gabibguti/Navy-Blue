#include "pch.h"
#include "Engine.h"

Engine::Engine()
{
	// Create game window
	m_Window.create(VideoMode(1000, 600),
		"Navy Blue",
		Style::Default);

	// Get menu items area inside window
	int i;
	for (i = 0; i < MAX_MENU_ITEMS; i++) {
		menuItemStartAreaInWindow[i] = menu.getMenuItemStartArea(i);
		menuItemEndAreaInWindow[i] = menu.getMenuItemEndArea(i);
	}

}

void Engine::startGame() {
	while (m_Window.isOpen()) {
		// Detect if the window is closed
		// And then shuts down the program
		sf::Event event;
		while (m_Window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				// Someone closed the window- bye
				m_Window.close();
		}

		// Handle inputs
		input();

		// Clear everything from the last run of the while loop
		m_Window.clear();

		// Draw menu
		if (menuIsOpen) {
			menu.draw(m_Window);
		}

		// Draw InGame
		if (!menuIsOpen) {
			inGame.draw(m_Window);
		}

		// Show everything we just drew
		m_Window.display();
	}
}
