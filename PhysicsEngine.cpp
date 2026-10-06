#include "PhysicsEngine.hpp"
#include <cmath>
#include <cassert>

float PhysicsEngine::calculateCornealRadius(float initialRadius, float lambda, float timeInHours) {

	//Guard against negative time inputs
	if (timeInHours < 0.0f) return initialRadius;

	float currentRadius = initialRadius * std::exp(-lambda * timeInHours);

	//Ensure radius stays within physical human corneal bounds (~6.5mm to 9.0mm)
	assert(currentRadius > 0.0f && "Corneal radius must be positive");

	return currentRadius;

	//Snell's Law implementation (AP Physics 2 / Wave Optics concept)
	float PhysicsEngine::calculateRefractedAngle (float n1, float n2, float incidentAngleRad) {
		float sinTheta2 = (n1 / n2) * std::sin(incidentAngleRad);
		return std::asin(sinTheta2);
	}
}

