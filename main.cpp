#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "OpticsState.hpp"
#include "PhysicsEngine.hpp"
#include "NoiseGenerator.hpp"
#include "Visualizer.hpp"
#include "InputHandler.hpp"
#include "Overlay.hpp"

int main() {
    float prescriptionDiopters = 0.0f;
    float viewingDistanceMeters = 1.0f;

    std::cout << "=== ADAPTIVE OPTICS SIMULATION SETUP ===" << std::endl;
    std::cout << "Enter prescription in Diopters (e.g., -2.5 for nearsighted, +1.5 for farsighted): ";
    std::cin >> prescriptionDiopters;

    std::cout << "Enter viewing distance in meters (e.g., 2.0): ";
    std::cin >> viewingDistanceMeters;

    std::cout << "\n[System Initialized]: Adaptive Optics Engine Ready." << std::endl;
    std::cout << "Prescription: " << prescriptionDiopters << " D | Distance: " << viewingDistanceMeters << " m\n" << std::endl;

    sf::RenderWindow window(sf::VideoMode(800, 800), "Adaptive Optics Simulation");
    window.setFramerateLimit(60);

    WavefrontPoint grid[20][20];
    NoiseGenerator noiseGen(0.0f, 0.02f);

    CorneaParams cornea = {
        DefaultConfig::DEFAULT_REFRACTIVE_INDEX,
        0.08f,
        DefaultConfig::DEFAULT_INITIAL_RADIUS
    };

    SimulationControls controls;
    Overlay overlay;
    Visualizer visualizer;

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
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            InputHandler::handleInput(event, controls, cornea);
        }

        if (keyCooldown.getElapsedTime().asMilliseconds() > 200) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
                controls.isPaused = !controls.isPaused;
                keyCooldown.restart();
            }

	    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
		elapsedTimeInHours = 0.0f;
		cornea.currentRadius = DefaultConfig::DEFAULT_INITIAL_RADIUS;
		keyCooldown.restart();
		std:: cout << "[System]: Simulation reset successfully." << std::endl;
	    }

	    if (sf::Keyboard::isKeyPressed(sf::Keyboard::N)) {
		controls.noiseEnabled = !controls.noiseEnabled;
		keyCooldown.restart();
	    }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
                std::ofstream logFile("optics_log.csv", std::ios::app);
                logFile << elapsedTimeInHours << "," << currentFps << "," << cornea.currentRadius << "\n";
                std::cout << "[System]: Telemetry exported to optics_log.csv" << std::endl;
                keyCooldown.restart();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                controls.timeScale += 0.5f;
                keyCooldown.restart();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                controls.timeScale = std::max(0.1f, controls.timeScale - 0.5f);
                keyCooldown.restart();
            }
        }

        if (!controls.isPaused) {
            elapsedTimeInHours += (dt.asSeconds() * 0.1f) * controls.timeScale;
            cornea.currentRadius = PhysicsEngine::calculateCornealRadius(
                DefaultConfig::DEFAULT_INITIAL_RADIUS,
                0.05f,
                elapsedTimeInHours
            );
        }

        PhysicsEngine::generateWavefrontGrid(grid, cornea.currentRadius);

        if (controls.noiseEnabled) {
            noiseGen.applyGridNoise(grid);
        }

        window.clear(sf::Color::Black);

        visualizer.renderWavefrontGrid(window, grid, prescriptionDiopters, viewingDistanceMeters, cornea.currentRadius);

        overlay.renderDiagnostics(window, currentFps, elapsedTimeInHours, cornea, controls);

        window.display();
    }

    return 0;
}
