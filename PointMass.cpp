#include "PointMass.h"

PointMass::PointMass(float x, float y, float z) : mass(1), posX(x), posY(y), posZ(z), baseRadius(3), velocity(Vector3()), fillColor(sf::Color::White) {}

void PointMass::draw(sf::RenderWindow& window) {
	sf::CircleShape circle(simulateDepth(posZ));
	circle.setPosition(posX, posY);
	circle.setFillColor(fillColor);
	window.draw(circle);
}

float PointMass::simulateDepth(float z) {
	float scaleFactor = 1.0f + z * 0.1f;
	return baseRadius * scaleFactor;
}