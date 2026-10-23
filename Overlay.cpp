#include "Overlay.hpp"
#include <sstream>
#include <iomanip>

Overlay::Overlay() {
	diagnosticText.setCharacterSize(14);
	diagnosticText.setFillColor(sf::Color::Green);
	diagnosticText.setPosition(10.0f, 10.0f);
}

bool Overlay::loadFont(const std::string& fontPath) {
	return font.loadFromFile(fontPath);
}

void Overlay::renderDiagnostics(sf::RenderWindow& window, float fps, float timeHours, const CorneaParams& cornea, const SimulationControls& controls) {
	diagnosticText.setFont(font);

	std::ostringstream ss;
	ss << std::fixed << std::setprecision(2);
	ss << "--- DIAGNOSTICS TELEMETRY ---\n";
	ss << "FPS: " << fps << "\n";
	ss << "Simulated Time: " << timeHours << " hrs\n";
	ss << "Corneal Radius: " << cornea.currentRadius << " mm\n";
	ss << "Decay Constant (lambda): " << cornea.decayConstant << "\n";
	ss << "Status: " << (controls.isPaused ? "PAUSED" : "RUNNING") << "\n";
	ss << "Noise Injection: " << (controls.noiseEnabled ? "ON" : "OFF") << "\n";
	ss << "[Space] Pause | [R] Reset | [N] Noise | [E] Export | [Up/Down] Speed";

	diagnosticText.setString(ss.str());
	window.draw(diagnosticText);
}
