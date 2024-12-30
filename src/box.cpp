#include "box.h"

//initialize 2d array
void Box::initialize(){
array = new int*[rows];

for(int i = 0; i < rows; i++){
array[i] = new int[cols];
}

//set default to 0
for(int i = 0; i < rows; i++){
for(int j = 0; j < cols; j++){
array[i][j] = 0;
}
}
}

void Box::update(float& deltatime){
if(deltatime > 1){
}

}

//cell draw according to array
void Box::draw(sf::RenderWindow& window){
for(int i = 0; i < rows; i++){
for(int j = 0; j < cols; j++){
sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize));
cell.setPosition(j * cellSize, i * cellSize);
if(array[i][j] == 0){
cell.setFillColor(sf::Color::Black);
}
else{
cell.setFillColor(sf::Color::White);
}

window.draw(cell);
}
}
}
