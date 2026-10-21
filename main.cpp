#include <SFML/Graphics.hpp>
#include <iostream>
#include "OpticsState.hpp"
#include "PhysicsEngine.hpp"
#include "NoiseGenerator.hpp"
#include "Visualizer.hpp"
#include "InputHandler.hpp"
#include "Overlay.hpp"

int main() {
sf::RenderWindow window(sf::VideoMode(800, 800), "Adaptive Optics Simulation");
window.setFramerateLimit(60);
std::cout << "[System Initialized]: Adaptive Optics Engine Ready." << std::endl;

WavefrontPoint grid[20][20];
NoiseGenerator noiseGen(0.0f, 0.02f);

CorneaParams cornea = {
DefaultConfig::DEFAULT_REFRACTIVE_INDEX,
0.08f,
DefaultConfig::DEFAULT_INITIAL_RADIUS;
SimulationControls controls;

Overlay overlay;
if (!overlay.loadFont("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf")) {
std::cout << "[Warning]: Could not load DejaVuSans.ttf font for HUD overlay." << std::endl;
}

sf::Clock deltaClock;
sf::Clock fpsClock;
sf::Clock keyCooldown;
int frameCount = 0;
float currentFps = 0.0f;
float elapsedTimeInHours = 0.0f;

PhysicsEngine::generateWavefrontGrid(grid, cornea.currentRadius);
noiseGen.applyGridNoise(grid);

while (window.isOpen()) {
sf::Time dt = deltaClock.restart();

frameCount++;
if (fpsClock.getElapsedTime().asSeconds() >= 1.0f) {
currentFps = static_cast<float>(frameCount) / fpsClock.restart().asSeconds();
frameCount = 0;
}

sf::Event event;
while (window.pollEvent(event)) {
if (event.type == sf::Event::Closed)
window.close();

InputHandler::handleInput(event, controls, cornea);
}

// Direct keyboard polling fallback for Chromebook compatibility
if (keyCooldown.getElapsedTime().asMilliseconds() > 200) {
if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
controls.isPaused = !controls.isPaused;
keyCooldown.restart();
}
if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
controls.resetRequested = true;
keyCooldown.restart();
}
if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)) {
controls.noiseEnabled = !controls.noiseEnabled;
keyCooldown.restart();
}
}

if (controls.resetRequested) {
elapsedTimeInHours = 0.0f;
cornea.currentRadius = DefaultConfig::DEFAULT_INITIAL_RADIUS;
controls.resetRequested = false;
std::cout << "[System]: Simulation state reset." << std::endl;
}

if (!controls.isPaused) {
elapsedTimeInHours += (dt.asSeconds() * 0.1f) * controls.timeScale;
cornea.currentRadius = PhysicsEngine::calculateCornealRadius(
DefaultConfig::DEFAULT_INITIAL_RADIUS,
cornea.decayConstant,
elapsedTimeInHours
);
}

PhysicsEngine::generateWavefrontGrid(grid, cornea.currentRadius);

if (controls.noiseEnabled) {
noiseGen.applyGridNoise(grid);
}

window.clear(sf::Color::Black);
Visualizer::renderWavefrontGrid(window, grid);
overlay.renderDiagnostics(window, currentFps, elapsedTimeInHours, cornea, controls);
window.display();
}

return 0;
}
