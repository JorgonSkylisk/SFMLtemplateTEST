#include <SFML/Graphics.hpp>
// Library needed for playing music and sound effects
#include <SFML/Audio.hpp>

// entry point for the program	
int main()
{
	//**************************
	//********game setup********
	//**************************
	// declare variable for display window
	sf::RenderWindow gamewindow;
	gamewindow.create(sf::VideoMode::getDesktopMode(), "Button Masher", 
		sf::Style::Titlebar | sf::Style::Close);

	//create button sprite
	sf::Texture buttonTexture;
	buttonTexture.loadFromFile("graphics/button.png");

	sf::Sprite buttonSprite;
	buttonSprite.setTexture(buttonTexture);
	
	//set sprite coords
	buttonSprite.setPosition(
		gamewindow.getSize().x / 2 - buttonTexture.getSize().x / 2,
		gamewindow.getSize().y / 2 - buttonTexture.getSize().y / 2
	);

	// create music object
	sf::Music gameMusic;
	gameMusic.openFromFile("audio/music.ogg");
	gameMusic.play();

	// create font
	sf::Font gameFont;
	gameFont.loadFromFile("fonts/mainFont.ttf");

	//create title
	sf::Text titleText;
	titleText.setFont(gameFont);
	titleText.setString("Button Masher!");
	titleText.setPosition(gamewindow.getSize().x / 2 - titleText.getLocalBounds().width / 2, 30);

	//create author text
	sf::Text authorText;
	authorText.setFont(gameFont);
	authorText.setString("By Uncle Phil");
	authorText.setCharacterSize(50);
	authorText.setFillColor(sf::Color::Magenta);
	authorText.setStyle(sf::Text::Italic | sf::Text::Bold);
	authorText.setPosition(gamewindow.getSize().x / 2 - authorText.getLocalBounds().width / 2, 200);

	//*************************
	//******* game loop *******
	//*************************
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
		gamewindow.clear(sf::Color::Transparent);

		//draw everything
		gamewindow.draw(buttonSprite);
		gamewindow.draw(titleText);
		gamewindow.draw(authorText);


		//display window content
		gamewindow.display();

	}


	return 0;
}