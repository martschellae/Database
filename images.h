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
        temp.setFillColor(sf::Color(R(visualPink.r), R(visualPink.g), R(visualPink.b), 3));
        temp.setRadius(rand() % 200 + 50);
        sf::Vector2f tmp(rand() % 5000 - 2500, rand() % 2500 - 1250);
        particlePos.push_back(tmp);
        temp.setPosition(particlePos[x]);
        particles.push_back(temp);
    }

    sf::RenderWindow window(sf::VideoMode(1300, 700), "Image Manager");

    sf::Image image;
    image.loadFromFile("assets/image.jpg");

    sf::Texture displayTexture;
    displayTexture.loadFromFile("assets/image.jpg");
    displayTexture.update(image);

    sf::Sprite display;
    display.setTexture(displayTexture);
    display.setPosition(sf::Vector2f(0, 0));
    display.setScale(window.getSize().x / displayTexture.getSize().x, window.getSize().y / displayTexture.getSize().y);

    sf::RectangleShape displayRect;
    displayRect.setFillColor(darkness);
    displayRect.setOutlineColor(visualYellow);
    displayRect.setOutlineThickness(5);
    displayRect.setSize(sf::Vector2f(window.getSize().x / 15 * 3, window.getSize().y / 20 * 9));
    displayRect.setPosition(window.getSize().x / 30, window.getSize().y / 20);

    sf::Text openFile("Open File", font, 20);
    openFile.setFillColor(visualBlue);
    openFile.setPosition(window.getSize().x / 15, window.getSize().y / 10 * 1);

    sf::Text closeFile("Close File", font, 20);
    closeFile.setFillColor(visualBlue);
    closeFile.setPosition(window.getSize().x / 15, window.getSize().y / 10 * 2);

    sf::Text encryptFile("Encrypt File", font, 20);
    encryptFile.setFillColor(visualBlue);
    encryptFile.setPosition(window.getSize().x / 15, window.getSize().y / 10 * 3);

    sf::Text decryptFile("Decrypt File", font, 20);
    decryptFile.setFillColor(visualBlue);
    decryptFile.setPosition(window.getSize().x / 15, window.getSize().y / 10 * 4);

    bool isChat = false;

    float zoom = 1.0f;
    
    float scale = 1.0f;

    sf::Vector2f imagePosition;

    while (window.isOpen()) {

        displayTexture.update(image);
        display.setTexture(displayTexture);

        window.clear(background);

        sf::Event event;
        if(window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::Resized) {
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                scale = zoom * (event.size.width / (float)displayTexture.getSize().x);
                window.setView(sf::View(visibleArea));

                displayRect.setSize(sf::Vector2f(window.getSize().x / 15 * 3, window.getSize().y / 20 * 9));
                displayRect.setPosition(window.getSize().x / 30, window.getSize().y / 20);

                openFile.setPosition(window.getSize().x / 15, window.getSize().y / 10 * 1);
                closeFile.setPosition(window.getSize().x / 15, window.getSize().y / 10 * 2);
                encryptFile.setPosition(window.getSize().x / 15, window.getSize().y / 10 * 3);
                decryptFile.setPosition(window.getSize().x / 15, window.getSize().y / 10 * 4);
            }
            if (event.type == sf::Event::MouseWheelScrolled) {
                if ((zoom + 0.05 * event.mouseWheelScroll.delta) > 0.1 && (zoom + 0.05 * event.mouseWheelScroll.delta) < 5) {
                    zoom += 0.05 * event.mouseWheelScroll.delta;
                }
                
            }
        }
        imagePosition = { (float)window.getSize().x / 2 - (float)displayTexture.getSize().x * display.getScale().x / 2 + 150, (float)window.getSize().y / 2 - (float)displayTexture.getSize().y * display.getScale().y / 2 };

        scale = zoom * (window.getSize().x / (float)displayTexture.getSize().x);

        display.setScale(scale, scale);
        display.setPosition(imagePosition);
       

        for (int x = 0; x < particleCount; x++)
            window.draw(particles[x]);

        window.draw(display);
        window.draw(displayRect);
        window.draw(openFile);
        window.draw(closeFile);
        window.draw(encryptFile);
        window.draw(decryptFile);

        window.display();
    }
}