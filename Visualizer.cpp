#include "Visualizer.hpp"
#include <cmath>
#include <algorithm>

void Visualizer::renderWavefrontGrid(sf::RenderWindow& window, const WavefrontPoint grid[20][20], float prescriptionDiopters, float viewingDistanceMeters, float cornealRadius) {
    const float circleRadius = 12.0f;
    const float padding = 35.0f;
    const float startX = 60.0f;
    const float startY = 60.0f;
    const float centerX = 10.0f;
    const float centerY = 10.0f;

    for (int y = 0; y < 20; ++y) {
        for (int x = 0; x < 20; ++x) {
            sf::CircleShape pointShape(circleRadius);
            pointShape.setPosition(startX + x * padding, startY + y * padding);

            float dx = static_cast<float>(x) - centerX;
            float dy = static_cast<float>(y) - centerY;
            float radiusSquared = (dx * dx) + (dy * dy);

            float totalPower = prescriptionDiopters + (1.0f / viewingDistanceMeters);
            float phaseError = totalPower * radiusSquared * 0.05f;

            int lcGrayValue = static_cast<int>((std::fmod(std::abs(phaseError), 6.28318f) / 6.28318f) * 255.0f);

            pointShape.setFillColor(sf::Color(lcGrayValue, lcGrayValue, lcGrayValue));
            window.draw(pointShape);
        }
    }
}
