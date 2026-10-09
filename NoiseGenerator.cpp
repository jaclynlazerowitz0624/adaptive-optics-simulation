#include "NoiseGenerator.hpp"

NoiseGenerator::NoiseGenerator(float mean, float stddev)
	: generator(std::random_device{}()), distribution(mean, stddev){}

float NoiseGenerator::getSample() {
	//AP Statistics Gaussian distribution implementation
	return distribution(generator);
}
