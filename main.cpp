
#include <SFML/Graphics.hpp>
#include <iostream>
#include "OpticsState.hpp"
#include "PhysicsEngine.hpp"
#include "NoiseGenerator.hpp"
#include "Visualizer.hpp"
#include "InputHandler.hpp"

int main () {
	//Create an SFML window for the simulation 
	sf:: RenderWindow window(sf::VideoMode(800,600), "Adaptive Optics Simulation");
	std::cout << "[System Initialized]: Adaptive Optics Engine Ready." << std::endl;

	//Decalre state variables and clocks (before the loop)
	WavefrontPoint grid[20][20];
	NoiseGenerator noiseGen(0.0f, 0.02f);

	//Initialize spatial grid with default post-treatment corneal geometry
	PhysicsEngine::generateWavefrontGrid(grid, DefaultConfig::DEFAULT_INITIAL_RADIUS);
	noiseGen.applyGridNoise(grid);

	CorneaParams cornea = {
		DefaultConfig::DEFAULT_REFRACTIVE_INDEX,
		DefaultConfig::DEFAULT_DECAY_CONSTANT,
		DefaultConfig::DEFAULT_INITIAL_RADIUS
	};

	SimulationControls controls;

	sf::Clock deltaClock;
	float elapsedTimeInHours = 0.0f;

	//Initial wavefront grid generation
	PhysicsEngine::generateWavefrontGrid(grid, cornea.currentRadius);
	noiseGen.applyGridNoise(grid);

	while (window.isOpen()) {
	sf:: Time dt = deltaClock.restart();

	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			window.close();

		//Declare InputHandler, controls, and cornea
		InputHandler::handleInput(event, controls, cornea);
}

	//Advance Simulation time accumulator if active
	if (!controls.isPaused) {
		elapsedTimeInHours += (dt.asSeconds() * 0.1f) * controls.timeScale;
		cornea.currentRadius = PhysicsEngine::calculateCornealRadius(
			DefaultConfig::DEFAULT_INITIAL_RADIUS,
			cornea.decayConstant,
			elapsedTimeInHours
		   );
	}

	//Recalculate 2D phase shift matrix with updated corneal curvature
	PhysicsEngine::generateWavefrontGrid(grid, cornea.currentRadius);

	window.clear(sf::Color::Black);

	//Inject dynamic Gaussian sensor noise pass in certain circumstances
	if (controls.noiseEnabled) {
		noiseGen.applyGridNoise(grid);
	}

	//Render 20x20 phase grid onto 800x800 pixel canvas (padding: 35px, node radius: 12px) 
	Visualizer::renderWavefrontGrid(window, grid);

	window.display();
   }
	return 0;
}
