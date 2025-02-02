#include "box.h"
#include <iostream>
//initialize 2d array
void Box::initialize(sf::RenderWindow& window){
rows = window.getSize().x/cellSize;
cols = window.getSize().y/cellSize;
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
std::srand(static_cast<unsigned>(std::time(0))); //initialize random seed
}

//destructor to free memory
Box::~Box() {
    for (int i = 0; i < rows; i++) {
        delete[] array[i];
    }
    delete[] array;
}


//add sands
void Box::addSand(sf::RenderWindow& window){
//handling mouse input
sf::Vector2i mousePos = sf::Mouse::getPosition(window);

int row = mousePos.y/cellSize;
int col = mousePos.x/cellSize;

if(row >= 0 && row < rows && col >= 0 && col < cols){
for(int i = 0; i < 3; i ++){
array[row][col] = 1;
if(row >= 0 && row < rows && col >= 0 && col < cols){
row++;
col++;
}
}
}
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
//check left and right
else if(array[i][j] == 1){
int rand = getRandomTwo();
if(rand == 0 && j > 0 && array[i][j] == 1 && array[i+1][j-1] == 0){
tempArray[i+1][j-1] == 1;
}
else if(rand == 1 && j < cols - 1 && array[i][j] == 1 && array[i+1][j+1] == 0){
tempArray[i+1][j+1] == 1;
}
else{
tempArray[i][j] = 1;
}
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
cell.setFillColor(sf::Color::Yellow);
}

window.draw(cell);
}
}
}

int Box::getRandomTwo() {
    return rand() % 2; 
}
