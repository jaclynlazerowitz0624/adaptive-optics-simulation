#pragma once

//Holds physical cornea attributes post-Ortho-K treatment
struct CorneaParams {
 	float baselineRefractiveIndex; // Base index of refraction
	float decayConstant;           // Relaxation rate coefficient over time
	float currentRadius;           // Radius of curvature in millimeters 
};

// Holds spatial wave properties across a 2D optical grid
struct WavefrontPoint {
	float x;           // Grid coordinate X
	float y;           // Grid coordinate Y
	float phaseShift;  // Light phase delay calculated at this spatial point 
};

//Standard default configuartion for initial eye state initialization
namespace DefaultConfig {
       constexpr float DEFAULT_REFRACTIVE_INDEX = 1.376f;
       constexpr float DEFAULT_DECAY_CONSTANT = 0.05f;
       constexpr float DEFAULT_INITIAL_RADIUS = 7.80f; // Standard corneal radius in mm
       constexpr int GRID_SIZE = 20;                   // 20x20 simulation grid
}


