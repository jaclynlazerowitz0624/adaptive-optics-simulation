#pragma once
#include "OpticsState.hpp"

class PhysicsEngine {
public:
	//Calculate coerneal radius at time t using exponential decay
static float calculateCornealRadius(float initialRadius, float lambda, float timeInHours);

static float calculateRefractedAngle(float n1, float n2, float incidentAngleRad);

static void generateWavefrontGrid(WavefrontPoint grid [20][20], float cornealRadius);

};
