#pragma once
#include <SFML/Graphics.hpp>
#include "OpticsState.hpp"
#ifndef VISUALIZER_HPP
#define VISUALIZER_HPP
#include "PhysicsEngine.hpp"

class Visualizer {
public:
	//Renders the 20x20 wavefront phase shift grid onto an SFML Render-Window
	void renderWavefrontGrid(sf::RenderWindow& window, const WavefrontPoint grid[20][20], float prescriptionDiopters, float viewingDistanceMeters, float cornealRadius);
};

#endif
