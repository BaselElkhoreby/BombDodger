#include"Player.h"

int Player::getheight() const
{
	return height;
}

int Player::getwidth() const
{
	return width;
}

int Player::getx()
{
	return x;
}

int Player::gety()
{
	return y;
}

void Player::setspeed(float nspeed)
{
	speed = nspeed;
}

float Player::getspeed()
{
	return speed;
}

void Player::clamptoscreen()
{
	if ((getPosition().x)+(width/2) >= 800)
	{
		setPosition(800 - (width / 2), getPosition().y);
	}

	else if (getPosition().x <= width/2)
	{
		setPosition(width/2, getPosition().y);
	}
	if ((getPosition().y) + (height / 2) >= 600)
	{
		setPosition(getPosition().x, 600 - (height / 2));
	}
	else if (getPosition().y < (height/2))
	{
		setPosition(getPosition().x,height/2);
	}
}

/*void Player::Draw(sf::RenderWindow &window)
{
	RectangleShape rect(sf::Vector2f(width, height));
	rect.setPosition(x, y);
	rect.setFillColor(sf::Color::Yellow);
	rect.setOrigin(width / 2, width / 2);
	window.draw(rect);
}*/

void Player::Move()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		Player::move(0, -speed);
		setRotation(-90);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		Player::move(0, speed);
		setRotation(90);
	}
	 if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		 Player::move(speed, 0);
		 setRotation(0);
	}
	 if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		 Player::move(-speed,0);
		 setRotation(-180);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)&& sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		 
		setRotation(-135);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)&&sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{

		setRotation(-225);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)&& sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{

		setRotation(-45);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)&& sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{

		setRotation(45);
	}
}
