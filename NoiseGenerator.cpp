#include "NoiseGenerator.hpp"

NoiseGenerator::NoiseGenerator(float mean, float stddev)
	: generator(std::random_device{}()), distribution(mean, stddev){}

float NoiseGenerator::getSample() {
	//AP Statistics Gaussian distribution implementation
	return distribution(generator);
}

void NoiseGenerator::applyGridNoise(WavefrontPoint grid[20][20]) {
	for (int y = 0; y < 20; ++y) {
		for (int x = 0; x < 20; ++x) {
			grid[y][x].phaseShift += getSample();
		}
	}
}
