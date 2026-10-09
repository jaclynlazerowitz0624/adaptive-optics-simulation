#pragma once
#include <random>
#include "OpticsState.hpp"

class NoiseGenerator {
private:
	std::mt19937 generator;
	std::normal_distribution<float> distribution;

public:
	NoiseGenerator(float mean, float stddev);
	float getSample();
	void applyGridNoise(WavefrontPoint grid[20][20]);
};
