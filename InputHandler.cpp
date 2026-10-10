#include "InputHandler.hpp"

void InputHandler::handleInput(const sf::Event& event, SimulationControls& controls, CorneaParams& cornea) {
	if (event.type == sf::Event::KeyPressed) {
		//Spacebar -- toggles simulation pause state
		if (event.key.code == sf::Keyboard::Space) {
			controls.isPaused = !controls.isPaused;
}
		//Key R -- resets corneal parameters to baseline initial defaults
		else if (event.key.code == sf::Keyboard::R) {
			cornea.currentRadius = DefaultConfig::DEFAULT_INITIAL_RADIUS;
}

		//Key N -- toggles Gaussian noise injection
		else if (event.key.code == sf::Keyboard::N) {
			controls.noiseEnabled = !controls.noiseEnabled;
		}
	}
}
