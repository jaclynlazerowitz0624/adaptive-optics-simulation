#include "InputHandler.hpp"
#include <algorithm>

void InputHandler::handleInput(const sf::Event& event, SimulationControls& controls, CorneaParams& cornea) {
	if (event.type == sf::Event::KeyPressed) {
		//Spacebar -- toggles simulation pause state
		if (event.key.code == sf::Keyboard::Space) {
			controls.isPaused = !controls.isPaused;
}
	if (event.type == sf::Event::MouseButtonPressed) {
		if (event.mouseButton.button == sf::Mouse::Left) {
			std::cout << "[Input: Click detected at X: "
				<< event.mouseButton.x << ", Y: " << event.mouseButton.y << std::endl;
		}
	}
}


		//Key R -- resets corneal parameters to baseline initial defaults
		else if (event.key.code == sf::Keyboard::R) {
			cornea.currentRadius = DefaultConfig::DEFAULT_INITIAL_RADIUS;
			cornea.decayConstant = DefaultConfig::DEFAULT_DECAY_CONSTANT;
}

		//Key N -- toggles Gaussian noise injection
		else if (event.key.code == sf::Keyboard::N) {
			controls.noiseEnabled = !controls.noiseEnabled;
		}

		//Up arrow -- accelerates the time progression rate
		else if (event.key.code == sf::Keyboard::Up) {
			controls.timeScale = std::min(controls.timeScale + 0.5f, 10.0f);
	}
		//Down arrow -- decelerates the time progression rate
		else if (event.key.code == sf::Keyboard::Down) {
			controls.timeScale = std::max(controls.timeScale - 0.5f, 0.1f);
		}
	}
}
