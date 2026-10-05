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


