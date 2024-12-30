#include "box.h"
#include <iostream>
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
array[1][10] = 1;
}

//destructor to free memory
Box::~Box() {
    for (int i = 0; i < rows; i++) {
        delete[] array[i];
    }
    delete[] array;
}

//update cell
void Box::update(float deltatime){
time += deltatime;

//every 0.05 seconds
if(time > 0.05f){
//temprorary array to check cell and create next cell
int** tempArray = new int*[rows];
for(int i = 0; i < rows; i++){
tempArray[i] = new int[cols];
}

//intittialize tempArray to 0
for(int i = 0; i < rows; i++){
for(int j = 0; j < cols; j++){
tempArray[i][j] = 0;
}
}

//check the original array and make changes to tempArray
for(int i = 0; i < rows-1; i++){
for(int j = 0; j < cols; j++){
if(array[i][j] == 1 && array[i+1][j] == 0 ){
tempArray[i+1][j] = 1;
}
else if(array[i][j] == 1){
tempArray[i][j] = 1;
}
}
}

//explicitly check the last row to prevent falling off bounds
for(int j = 0; j < cols; j++){
if(array[rows-1][j] == 1){
tempArray[rows - 1][j] = 1;
}
}

//copy tempArray to original array
for(int i = 0; i < rows; i++){
for(int j = 0; j < cols; j++){
array[i][j] = tempArray[i][j];
}
}

//delete tempArray
for(int i = 0; i < rows; i++){
delete[] tempArray[i];
}
delete[] tempArray;

//reset time
time = 0.0f;
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
