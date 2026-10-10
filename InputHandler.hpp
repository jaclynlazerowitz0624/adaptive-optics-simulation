#pragma once
#include <SFML/Graphics.hpp>
#include "OpticsState.hpp"

struct SimulationControls {
	bool isPaused = false;
	float timeScale = 1.0f;
	bool noiseEnabled = true;
};

class InputHandler {
public:
	//Intercepts key presses to modify live simulation state parameters
	static void handleInput(const sf::Event& event, SimulationControls& controls, CorneaParams& cornea);
};
