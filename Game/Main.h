#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include"Player.h"
#include<random>
#include"Bombs.h"
#include<fstream>
using namespace std;


//variables
ofstream output;
int highscore;
bool start = false;
bool GameOver = false;
sf::Font Arial;
sf::Text Scoret;
sf::Text Start;
sf::Text GO;
sf::Text Restart;
sf::Text PlayerName;
sf::Text HighScore;
string Scorett;
string Playern;
const int n = 1000;
int Score;
int Drawn = 5 + (Score / 10);
int i;
random_device rd;
mt19937 rng (rd());
uniform_int_distribution<int> xDist(0,770);
uniform_int_distribution<int> yDist(0,570);
uniform_int_distribution<int> vDist(-8, 8);
Player player;
sf::RectangleShape target;
Bomb Bombs[n];
 

// fucntion
void reset();
