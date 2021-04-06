#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>

#include <iostream>
#include <fstream>

#include "configurations.h"
#include "data.h"

std::string inputBox(std::string caption, std::string text, const unsigned int xSize = 700) {

    sf::Font font;
    font.loadFromFile(FONT);

    sf::RenderWindow window(sf::VideoMode(xSize, 75), caption);

    sf::Text name(text, font, 30);
    name.setPosition(10, 20);
    name.setFillColor(dark);

    std::string fileName;

    sf::Text userInput("", font, 30);
    userInput.setPosition(120, 20);
    userInput.setFillColor(dark);

    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
                return fileName;
            }
            if (event.type == sf::Event::TextEntered)
            {
                if (event.key.code == 8) {
                    if (fileName.size() >= 1) {
                        fileName.replace(fileName.end() - 1, fileName.end(), "");
                        userInput.setString(fileName);
                    }
                }
                else if (event.key.code == 13) {
                    return fileName;
                }
                else {
                    fileName += event.text.unicode;
                    userInput.setString(fileName);
                }
            }
        }

        window.clear(sf::Color(20, 20, 20));
        window.draw(name);
        window.draw(userInput);
        window.display();
    }
}