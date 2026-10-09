#include "Visualizer.hpp"
#include <cmath>
#include <algorithm>

void Visualizer::renderWavefrontGrid(sf::RenderWindow& window, const WavefrontPoint grid[20][20]) {
	const float circleRadius = 12.0f;
	const float padding = 35.0f;
	const float startX = 60.0f;
	const float startY = 60.0f;

	for (int y = 0; y < 20; ++y) {
		for (int x = 0; x < 20; ++x) {
			sf::CircleShape pointShape(circleRadius);

			//Map 2D array index to screen pixel coordinates 
			pointShape.setPosition(startX + x * padding, startY + y * padding);

			//Normalize phase shift [0.0, 1.0] and map to 8-bit color intensity (0 to 255)
			float normalizedPhase = std::clamp(grid[y][x].phaseShift, 0.0f, 1.0f);
			sf::Uint8 intensity = static_cast<sf::Uint8>(normalizedPhase * 255.0f);

			//Set color gradient: Cyan profile scaling with wavefront distortion
			pointShape.setFillColor(sf::Color(0, intensity, intensity));

			window.draw(pointShape);
		}
	}
}
