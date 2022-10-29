#pragma once
#include <SFML/Graphics.hpp>
#include"Player.h"
class Bomb : public sf::Sprite
{
public:

	void movement();
	void collision(Player player);
	float getxspeed();
	float getyspeed();
	float getwidth();
	float getheight();
	bool iscollided();
	void setspeed(float xs,float ys);

private:
	float xspeed;
	float yspeed;
	bool collided = false;
};
