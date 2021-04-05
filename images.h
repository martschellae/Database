#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>

#include <iostream>
#include <fstream>

#include "configurations.h"
#include "data.h"
#include "newFile.h"
#include "templates.h"
#include "networking.h"

void imageInterface() {

    showConsole();
    sf::Clock time;

    sf::Font font;
    font.loadFromFile(FONT);

    std::vector<sf::CircleShape> particles;
    std::vector<sf::Vector2f> particlePos;
    int particleCount = 1000;
    srand(GetTickCount64());
    for (int x = 0; x < particleCount; x++) {
        sf::CircleShape temp;
        temp.setPointCount(rand() % 2 + 4);
        temp.setRotation(rand() % 360);
        temp.setFillColor(sf::Color(R(visualPink.r), R(visualPink.g), R(visualPink.b), 1));
        temp.setRadius(rand() % 200 + 50);
        sf::Vector2f tmp(rand() % 5000 - 2500, rand() % 2500 - 1250);
        particlePos.push_back(tmp);
        temp.setPosition(particlePos[x]);
        particles.push_back(temp);
    }

    sf::RenderWindow window(sf::VideoMode(1300, 700), "Image Manager");

    sf::RectangleShape menuBar;
    menuBar.setPosition(5, window.getSize().y / 2 - 100);
    menuBar.setSize(sf::Vector2f(64, 200));
    menuBar.setOutlineColor(visualRed);
    menuBar.setOutlineThickness(5);
    menuBar.setFillColor(invisible);

    sf::Image image;
    image.loadFromFile("assets/image.jpg");

    sf::Texture displayTexture;
    displayTexture.loadFromFile("assets/image.jpg");
    displayTexture.update(image);

    sf::Sprite display;
    display.setTexture(displayTexture);
    display.setPosition(sf::Vector2f(0, 0));
    display.setScale(window.getSize().x / displayTexture.getSize().x, window.getSize().y / displayTexture.getSize().y);

    bool isChat = false;

    float zoom = 1.0f;
    
    float scale = 1.0f;

    sf::Vector2f imagePosition;

    sf::Vector2f mouseOnImagePos;

    while (window.isOpen()) {

        displayTexture.update(image);
        display.setTexture(displayTexture);

        mouseOnImagePos = { (sf::Mouse::getPosition(window).x - display.getGlobalBounds().left) / scale , (sf::Mouse::getPosition(window).y - display.getGlobalBounds().top) / scale };

        window.clear(background);
        sf::Event event;
        if(window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::Resized) {
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                scale = zoom * (event.size.width / (float)displayTexture.getSize().x);
                window.setView(sf::View(visibleArea));
                menuBar.setPosition(5, event.size.height / 2-100);
            }
            //if (event.type == sf::Event::MouseButtonPressed) {
               // image.setPixel((UINT)mouseOnImagePos.x, (UINT)mouseOnImagePos.y, sf::Color::Black);
            //}
            if (event.type == sf::Event::MouseWheelScrolled) {
                if((zoom + 0.05 * event.mouseWheelScroll.delta) > 0.25 && (zoom + 0.05 * event.mouseWheelScroll.delta) < 2)
                zoom += 0.05 * event.mouseWheelScroll.delta;
            
            }
        }
        imagePosition = { (float)window.getSize().x / 2 - (float)displayTexture.getSize().x * display.getScale().x / 2, (float)window.getSize().y / 2 - (float)displayTexture.getSize().y * display.getScale().y / 2 };

        scale = zoom * (window.getSize().x / (float)displayTexture.getSize().x);

        display.setPosition(imagePosition);
        display.setScale(scale, scale);

        for (int x = 0; x < particleCount; x++)
            window.draw(particles[x]);

        window.draw(display);
        window.draw(menuBar);
        window.display();
    }
}
