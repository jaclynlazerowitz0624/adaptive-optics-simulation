
#include <SFML/Graphics.hpp>
#include <iostream>

int main () {
//Create an SFML window for the simulation 
sf:: RenderWindow window(sf::VideoMode(800,600), "Adaptive Optics Simulation");
std::cout << "[System Initialized]: Adaptive Optics Engine Ready." << std::endl;
while (window.isOpen()) {
sf:: Event event;
while (window.pollEvent(event)) {
if (event.type == sf::Event::Closed)
window.close();
}
window.clear(sf::Color::Black);
window.display();
}
return 0;
}
