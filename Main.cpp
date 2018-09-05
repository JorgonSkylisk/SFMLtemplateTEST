#include <SFML/Graphics.hpp>


// entry point for the program	
int main()
{
	// declare variable for display window
	sf::RenderWindow gamewindow;
	gamewindow.create(sf::VideoMode::getDesktopMode(), "Button Masher", 
		sf::Style::Titlebar | sf::Style::Close);

	// game loop
	while (gamewindow.isOpen())
	{
		// TODO: Check for input
		sf::Event gameEvent;
		while (gamewindow.pollEvent(gameEvent))
		{
			// Process events

			//check if event is closed
			if (gameEvent.type == sf::Event::Closed)
			{
				//close game window
				gamewindow.close();
			}
		}

		// TODO: update game state

		// TODO: Draw Graphics


	}


	return 0;
}