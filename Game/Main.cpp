#include"Main.h"
using namespace std;


int main() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "Game"); //create a window with dimension of 800Px by 600Px with title game
	sf::Event ev;
	sf::Texture texture;
	texture.loadFromFile("PacMans.png");
	//player
	player.setTexture(texture);
	player.setPosition(player.getx() ,player.gety());
	player.setOrigin(player.getwidth()/2, player.getheight() / 2);

	//target
	target.setSize(sf::Vector2f(10, 10));
	target.setPosition(xDist(rng), yDist(rng));

	//Bombs
	sf::Texture Bombt;
	Bombt.loadFromFile("Bomb.png");
	Bombt.setSmooth(true);
	for ( i = 0; i < n; ++i)
	{
		Bombs[i].setTexture(Bombt);
		while (xDist(rng)!= 400 && yDist(rng) != 300)
		{
			Bombs[i].setPosition(xDist(rng), yDist(rng));
		}
		Bombs[i].setspeed(vDist(rng),vDist(rng));
		Bombs[i].setOrigin(Bombs[i].getGlobalBounds().width / 2, Bombs[i].getGlobalBounds().width / 2);
	}
	i = 0;

	//score
	Arial.loadFromFile("arial.ttf");
	Scorett = to_string(Score);
	Scoret.setString(Scorett);
	Scoret.setFont(Arial);
	while (window.isOpen())  //main loop of the game
	{
		while (window.pollEvent(ev)) //checks for all events happening on the window
		{
			if (ev.type == sf::Event::Closed) //Check if the event is closing the window 
			{
				window.close();   //close the window
			}
			if (ev.type == sf::Event::TextEntered)
			{
				if (ev.text.unicode == '\b')
				{
					Playern.erase(Playern.size()-1,1);
				}
				else
				{
					Playern += ev.text.unicode;
				}
				PlayerName.setString(Playern);
			}
			if (ev.type == sf::Event::KeyPressed)
			{
				start = true;
			}
			
		}

		if (start && !GameOver)
		{
			window.setFramerateLimit(60);
			Playern = "";
			player.Move();
			player.clamptoscreen();

			if (player.getGlobalBounds().intersects(target.getGlobalBounds()))
			{
				target.setPosition(xDist(rng), yDist(rng));
				Score += 1;
				Scorett = to_string(Score);
				Scoret.setString(Scorett);
			}
			window.clear(); //clears the window from the contents of the last frame
			window.draw(Scoret);
			window.draw(player);
			window.draw(target);
			for (int r = 0; r <Drawn && Drawn<n; r++)
			{
				Drawn = 5 + (Score / 10);
				window.draw(Bombs[r]);
				Bombs[r].movement();
				GameOver = GameOver || player.getGlobalBounds().intersects(Bombs[r].getGlobalBounds());
			}

			window.display(); //display all that has been rendered on screen
		}
		else if (GameOver)
		{

			GO.setFont(Arial);
			GO.setString("GameOver \n Enter Your Name");
			GO.setOrigin(GO.getGlobalBounds().width / 2, GO.getGlobalBounds().height / 2);
			GO.setCharacterSize(40);
			GO.setPosition(400, 300);

			Restart.setFont(Arial);
			Restart.setString("Press Enter to Play Again And Save Your Score");
			Restart.setOrigin(Restart.getGlobalBounds().width / 2, Restart.getGlobalBounds().height / 2);
			Restart.setCharacterSize(35);
			Restart.setPosition(400, 400);

			PlayerName.setFont(Arial);
			PlayerName.setString(Playern);
			PlayerName.setOrigin(PlayerName.getGlobalBounds().width / 2, PlayerName.getGlobalBounds().height / 2);
			PlayerName.setCharacterSize(40);
			PlayerName.setPosition(400, 500);

			HighScore.setFont(Arial);
			HighScore.setString(to_string(highscore));
			HighScore.setOrigin(HighScore.getGlobalBounds().width / 2, HighScore.getGlobalBounds().height / 2);
			HighScore.setCharacterSize(40);
			HighScore.setPosition(400,200);

			window.clear();
			window.draw(GO);
			window.draw(Restart);
			window.draw(PlayerName);
			window.display();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
			{
				output.open("scores.txt",ios::app);
				output << Score<<".........................."<<Playern<<endl;
				output.close();
				reset();
				GameOver = false;
			}
		}
		else
		{
			Start.setFont(Arial);
			Start.setString("Press Any Key to Start");
			Start.setOrigin(Start.getGlobalBounds().width / 2, Start.getGlobalBounds().height / 2);
			Start.setCharacterSize(40);
			Start.setPosition(400, 300);
			window.clear();
			window.draw(Start);
			window.display();
		}
		
	}
	return 0;
}

void reset()
{
	player.setPosition(player.getx(), player.gety());
	for (i = 0; i < n; ++i)
	{
		while (xDist(rng) != 400 && yDist(rng) != 300)
		{
			Bombs[i].setPosition(xDist(rng), yDist(rng));
		}
		Bombs[i].setspeed(vDist(rng), vDist(rng));
	}
	Score = 0;
	Scorett = to_string(Score);
	Scoret.setString(Scorett);
}


