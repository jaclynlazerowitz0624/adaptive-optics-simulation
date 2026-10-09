#pragma once
#include <SFML/Graphics.hpp>
#include "OpticsState.hpp"

class Visualizer {
public:
	//Renders the 20x20 wavefront phase shift grid onto an SFML Render-Window
	static void renderWavefrontGrid(sf::RenderWindow& window, const WavefrontPoint grid[20][20]);
};
