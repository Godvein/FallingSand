#pragma once
#include <SFML/Graphics.hpp>

class Box{

private:
int** array;
int rows = 50;
int cols = 50;
int cellSize = 5;
float time = 0.0f;

public:
~Box();
void initialize();
void update(float deltatime);
void draw(sf::RenderWindow& window);

};
