#include <SFML/Graphics.hpp>
// Library needed for playing music and sound effects
#include <SFML/Audio.hpp>
#include <string>

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

	// active gameplay variable
	bool playing = false;

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
	//gameMusic.play();

	//create sound object
	sf::SoundBuffer clickBuffer;
	clickBuffer.loadFromFile("audio/buttonclick.ogg");
	sf::Sound clickSound;
	clickSound.setBuffer(clickBuffer);

	//create announcer sound object
	sf::SoundBuffer announcerBuffer;
	announcerBuffer.loadFromFile("audio/announcer.ogg");
	sf::Sound announcerSound;
	announcerSound.setBuffer(announcerBuffer);

	//create missed sound object
	sf::SoundBuffer MissedClickBuffer;
	MissedClickBuffer.loadFromFile("audio/missClick.ogg");
	sf::Sound MissedClickSound;
	MissedClickSound.setBuffer(MissedClickBuffer);

	//create gameover sound
	sf::SoundBuffer gameOverBuffer;
	gameOverBuffer.loadFromFile("audio/gameover.ogg");
	sf::Sound gameOverSound;
	gameOverSound.setBuffer(gameOverBuffer);

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

	//create score
	int score = 0;
	sf::Text scoreText;
	scoreText.setFont(gameFont);
	scoreText.setString("Score: " + std::to_string(score));
	scoreText.setCharacterSize(16);
	scoreText.setFillColor(sf::Color::White);
	scoreText.setPosition(30, 30);

	//create start prompt text
	sf::Text promptText;
	promptText.setFont(gameFont);
	promptText.setString("Click the button to start the game!");
	promptText.setCharacterSize(24);
	promptText.setFillColor(sf::Color::Green);
	promptText.setPosition(gamewindow.getSize().x / 2 - promptText.getLocalBounds().width / 2, 600);

	//create timer
	sf::Text timerText;
	timerText.setFont(gameFont);
	timerText.setString("Time Remaining: 0");
	timerText.setCharacterSize(16);
	timerText.setFillColor(sf::Color::White);
	timerText.setPosition(gamewindow.getSize().x - timerText.getLocalBounds().width - 30, 30);
	sf::Time timeLimit = sf::seconds(10.0f);
	sf::Time timeRemaining = timeLimit;
	sf::Clock gameClock;


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

			if (gameEvent.type == sf::Event::MouseButtonPressed)
			{
				if (buttonSprite.getGlobalBounds().contains(gameEvent.mouseButton.x, gameEvent.mouseButton.y))
				{
					if (playing == true)
					{
						score = score + 1;
					}
					else
					{
						playing = true;
						score = 0;
						timeRemaining = timeLimit;
						promptText.setString("Click the button as fast as you can!");
						announcerSound.play();
					}
					//play sound fx
					clickSound.play();
				}
				else
				{
					MissedClickSound.play();
				}
			}


			//check if event is closed
			if (gameEvent.type == sf::Event::Closed)
			{
				//close game window
				gamewindow.close();
			}
		}

		// TODO: update game state
		//score setup
		scoreText.setString("Score: " + std::to_string(score));

		//setup timer
		sf::Time frameTime = gameClock.restart();
		if (playing == true)
		{
			timeRemaining = timeRemaining - frameTime;
			if (timeRemaining.asSeconds() <= 0)
			{
				playing = false;
				promptText.setString("Your final score was: " + std::to_string(score) + ". Click the button to start a new game!");
				gameOverSound.play();
			}
		}
		timerText.setString("Time Remaining: " + std::to_string((int)timeRemaining.asSeconds()));



		// TODO: Draw Graphics
		gamewindow.clear(sf::Color::Transparent);

		//draw everything
		gamewindow.draw(buttonSprite);
		gamewindow.draw(titleText);
		gamewindow.draw(authorText);
		gamewindow.draw(scoreText);
		gamewindow.draw(timerText);
		gamewindow.draw(promptText);


		//display window content
		gamewindow.display();

	}


	return 0;
}