#pragma once
#include<SFML/Graphics.hpp>
class Player : public sf::Sprite
{
public:
	/*in here there will be the getters and setters for the value of the player*/
	//getters and setters
	int getheight()const;
	int getwidth()const;
	int getx();
	int gety();
	void setspeed(float nspeed);
	float getspeed();
	void clamptoscreen(); //a memeber fucntion to prevent the player from going off screen
	//void Draw(sf::RenderWindow &window);
	void Move();
	

private:
	//r in here we will define all values needed for the player

static constexpr float height = 32.f;
static constexpr float width = 32.f; //width and height are static const expr since i don't want to change their values later
 //x and y are the coordinates of the player
float speed = 7; //this is the speed at which the player moves
float RotAngle = 0.f;
float x = 400.f;
float y = 300.f;
};
