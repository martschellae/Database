#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>

#include <iostream>
#include <fstream>

#include "configurations.h"
#include "data.h"

int captcha() {
    Reload:
    hideConsole();
    std::vector<sf::CircleShape> particles;
    std::vector<sf::Vector2f> particlePos;
    int particleCount = 1000;
    srand(GetTickCount64());
    for (int x = 0; x < particleCount; x++) {
        sf::CircleShape temp;
        temp.setPointCount(6);
        temp.setRotation(rand() % 360);
        temp.setFillColor(sf::Color(R(220), R(202), rand()%255, rand()%50));
        temp.setRadius(rand() % 20 + 5);
        sf::Vector2f tmp(rand() % 600 - 300, rand() % 600 - 300);
        particlePos.push_back(tmp);
        temp.setPosition(particlePos[x]);
        particles.push_back(temp);
    }

    sf::Font font;

    if (!font.loadFromFile(FONT)) {
        showConsole();
        error("Font not found. Font must be located under \"assets/fonts/font.ttf\"");
    }

    sf::RenderWindow window(sf::VideoMode(300, 300), "CAPTCHA", sf::Style::Titlebar | sf::Style::Close);

    std::string inputString;

    std::string randomtext;
    srand(GetTickCount64());
    for (int g = 0; g < 5; g++) {
        randomtext += rand() % 45 + 49;
    }

    sf::Text display[5];
    for (int g = 0; g < 5; g++) {
        display[g].setFont(font);
        display[g].setString(randomtext[g]);
        display[g].setPosition(200/ 5 * g + 50, 150);
        display[g].rotate(rand() % 90 - 45);
        display[g].setFillColor(bright);
    }

    sf::Text userInput("", font, 30);
    userInput.setPosition(50, 200);
    userInput.setFillColor(bright);
    userInput.setLetterSpacing(6.2);

    while (window.isOpen())
    {
        window.clear(sf::Color(0, 0, 0));
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                return -1;
            }
            if (event.type == sf::Event::TextEntered)
            {
                if (event.key.code == 8) {
                    if (inputString.size() >= 1) {
                        inputString.replace(inputString.end() - 1, inputString.end(), "");
                        userInput.setString(inputString);
                    }
                }
                else if (event.key.code == 13) {
                    if (inputString == randomtext) {
                        return 1;
                    }else {
                        goto Reload;
                    }
                }
                else {
                    inputString += event.text.unicode;
                    userInput.setString(inputString);
                }
            }
        }

        for (int g = 0; g < 5; g++) {
            window.draw(display[g]);
        }
        for (int x = 0; x < particleCount; x++) {
            window.draw(particles[x]);
        }
        window.draw(userInput);
        window.display();
    }
    return -1;
}