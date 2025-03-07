#include <iostream>
#include <SFML/Graphics.hpp>
#include "box.h"

int main(){
const int window_width = 1000;
const int window_height = 800;
sf::RenderWindow window(sf::VideoMode(window_width, window_height), "Falling Sand");
sf::View view(sf::FloatRect(0, 0, window_width, window_height));
window.setView(view);

//box setup
Box box;
box.initialize(window);

//deltaclock
sf::Clock deltaClock;

while(window.isOpen()){

sf::Event event;

while(window.pollEvent(event)){

if(event.type == sf::Event::Closed){
window.close();
}
//event loop
}
//game loop
//on mouse click
if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
box.addSand(window);
}

//delta time calculation
float deltatime = deltaClock.restart().asSeconds();
box.update(deltatime);

//update window size
sf::Vector2u windowSize = window.getSize();
sf::View view(sf::FloatRect(0, 0, windowSize.x, windowSize.y));
window.setView(view);

window.clear(sf::Color::Black);
box.draw(window);
window.display();
}

return 0;
}

