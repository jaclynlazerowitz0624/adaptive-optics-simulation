#pragma once
#include <SFML/Graphics.hpp>
#include "OpticsState.hpp"
#include "InputHandler.hpp"

class Overlay {
private:
	sf::Font font;
	sf::Text diagnosticText;

public:
	Overlay();
	bool loadFont(const std::string& fontPath);
	void renderDisgnostics(sf::RenderWindow& window, float fps, float timeHours, const CorneaParams& cornea, const SimulationControls& controls);
};
