#pragma once
#include <random>

class NoiseGenerator {
private:
	std::mt19937 generator;
	std::normal_distribution<float> distribution;

public:
	NoiseGenerator(float mean, float stddev);
	float getSample();
};
