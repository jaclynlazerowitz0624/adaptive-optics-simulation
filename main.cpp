
#include <SFML/Graphics.hpp>
#include <iostream>
#include "OpticState.hpp"
#include "PhysicsEngine.hpp"
#include "NoiseGenerator.hpp"


int main () {
	//Create an SFML window for the simulation 
	sf:: RenderWindow window(sf::VideoMode(800,600), "Adaptive Optics Simulation");
	std::cout << "[System Initialized]: Adaptive Optics Engine Ready." << std::endl;

	//Initialize 2D grid and noise engine
	WavefrontPoint grid[20][20];
	NoiseGenerator noiseGen(0.0f, 0.02f);

	//Generate Initial wavefront grid and put in Gaussian noise
	PhysicsEngine::generateWavefrontGrid(grid, DefaultConfig::DEFAULT_INITIAL_RADIUS);
	noiseGen.applyGridNoise(grid);

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
