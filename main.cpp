#include "PointMass.h"
#include <vector>

static void drawGrid(std::vector<PointMass>& pointMasses, int shiftX, int shiftY, int numX, int numY, float angle, float spacing) {
    float offsetX = (numX - 1) * spacing / 2.0f;
    float offsetY = (numY - 1) * spacing / 2.0f;
    for (int y = 0; y < numY; ++y) {
        for (int x = 0; x < numX; ++x) {
            float posX = x * spacing - offsetX;
            float posY = y * spacing - offsetY;
            // Offset each row by a small amount
            posX += y * 10.0f * std::tan(angle);
            pointMasses.emplace_back(posX + shiftX, posY + shiftY, 0);
        }
    }
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Fabric Simulation");
    std::vector<PointMass> pointMasses;
    
    int shiftX = window.getSize().x / 2;
    int shiftY = window.getSize().y / 2;
    drawGrid(pointMasses, shiftX, shiftY, 10, 10, 0.1f, 40.0f);
      
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed) {
                //pointMasses.emplace_back(event.mouseButton.x, event.mouseButton.y, 0);
            }
        }

        window.clear();
        for (auto& mass : pointMasses) {
            mass.draw(window);
        }
        window.display();
    }

    return 0;
}

