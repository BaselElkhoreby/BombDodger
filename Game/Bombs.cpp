#include"Bombs.h"

void Bomb::movement()
{
	move(xspeed, yspeed);
	if ((getPosition().x) + (getGlobalBounds().width / 2) >= 800)
	{
		setPosition(800 - (getGlobalBounds().width / 2), getPosition().y);
		xspeed = -xspeed;
	}
	else if (getPosition().x <= getGlobalBounds().width / 2)
	{
		setPosition(getGlobalBounds().width/2, getPosition().y);
		xspeed = -xspeed;
	}
	if ((getPosition().y) + (getGlobalBounds().height / 2) >= 600)
	{
		setPosition(getPosition().x, 600 - (getGlobalBounds().height / 2));
		yspeed = -yspeed;
	}
	else if (getPosition().y < (getGlobalBounds().height/2))
	{
		setPosition(getPosition().x, getGlobalBounds().height / 2);
		yspeed = -yspeed;
	}
}

void Bomb::collision(Player player)
{
	if (player.getGlobalBounds().intersects(getGlobalBounds()))
	{
		collided = true;
	}
}

float Bomb::getxspeed()
{
	return xspeed;
}

float Bomb::getyspeed()
{
	return yspeed;
}

float Bomb::getwidth()
{
	return getGlobalBounds().width;
}

float Bomb::getheight()
{
	return getGlobalBounds().height;
}

bool Bomb::iscollided()
{
	return collided;
}

void Bomb::setspeed(float xs, float ys)
{
	xspeed = xs;
	yspeed = ys;
}
