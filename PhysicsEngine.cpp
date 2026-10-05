#include "PhysicsEngine.hpp"
#include <cmath>

float PhysicsEngine::calculateCornealRadius(float initialRadius, float lambda, float timeInHours) {
	//Exponnetial decay model linking directly to AP Calculus AB rate modeling
	return initialRadius * std::exp(-lambda * timeInHours);
}
