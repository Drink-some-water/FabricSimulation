#pragma once
#include <SFML/Graphics.hpp>

struct Vector3 {
	float x, y, z;
    Vector3() : x(0), y(0), z(0) {}
    Vector3(float x, float y, float z) : x(x), y(y), z(z) {}
};

class PointMass
{
public:
	PointMass(float x, float y, float z);
	void draw(sf::RenderWindow& window);

private:
	int baseRadius = 10;
	float simulateDepth(float z);
	float mass;
	float posX;
	float posY;
	float posZ;
	Vector3 velocity;
	sf::Color fillColor;
};

