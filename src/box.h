#pragma once
#include <SFML/Graphics.hpp>

class Box{

private:
int** array;
int rows = 380;
int cols = 200;
int cellSize = 5;
float time = 0.0f;

public:
~Box();
void initialize(sf::RenderWindow& window);
void addSand(sf::RenderWindow& window);
void update(float deltatime);
void draw(sf::RenderWindow& window);

};
