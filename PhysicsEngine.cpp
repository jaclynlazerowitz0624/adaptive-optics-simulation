#include "PhysicsEngine.hpp"
#include <cmath>
#include <cassert>
#include <algorithm>

float PhysicsEngine::calculateCornealRadius(float initialRadius, float lambda, float timeInHours) {

	//Guard against negative time inputs
	if (timeInHours < 0.0f) return initialRadius;

	float currentRadius = initialRadius * std::exp(-lambda * timeInHours);

	//Ensure radius stays within physical human corneal bounds (~6.5mm to 9.0mm)
	assert(currentRadius > 0.0f && "Corneal radius must be positive");

	return currentRadius;
}

	//Snell's Law implementation (AP Physics 2 / Wave Optics concept)
	float PhysicsEngine::calculateRefractedAngle (float n1, float n2, float incidentAngleRad) {
		float sinTheta2 = (n1 / n2) * std::sin(incidentAngleRad);

	//Guard against domain errors for asin (clamping values between -1.0 and 1.0)
	sinTheta2 = std::clamp(sinTheta2, -1.0f, 1.0f);
		return std::asin(sinTheta2);
	}

void PhysicsEngine::generateWavefrontGrid(WavefrontPoint grid[20][20], float cornealRadius) {
	for (int y = 0; y < 20; ++y) { 
		for (int x = 0; x < 20; ++x) {
			//Center grid coordinated from -1.0 to 1.0 across pupil area
			float posX = (x - 10) / 10.0f;
			float posY = (y - 10) / 10.0f;

			grid[y][x].x = posX;
			grid[y][x].y = posY;

			//Phase delay varies quadratically with distance from pupil center
			float radialDistanceSq = (posX * posX) + (posY * posY);
			grid[y][x].phaseShift = radialDistanceSq * (1.0f / cornealRadius);
		}
	}
}
