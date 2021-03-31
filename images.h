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

    sf::Clock time;

    sf::Font font;
    font.loadFromFile(FONT);

    std::vector<sf::CircleShape> particles;
    std::vector<sf::Vector2f> particlePos;
    int particleCount = 2300;
    srand(GetTickCount64());
    for (int x = 0; x < particleCount; x++) {
        sf::CircleShape temp;
        temp.setPointCount(rand() % 2 + 4);
        temp.setRotation(rand() % 360);
        temp.setFillColor(sf::Color(R(173), R(83), R(83), 3));
        temp.setRadius(rand() % 200 + 50);
        sf::Vector2f tmp(rand() % 5000 - 2500, rand() % 2500 - 1250);
        particlePos.push_back(tmp);
        temp.setPosition(particlePos[x]);
        particles.push_back(temp);
    }

    sf::RenderWindow window(sf::VideoMode(1300, 700), "Image Manager");

    sf::Text chatTitle("Chat:", font, 20);
    chatTitle.setPosition(655, 10);
    chatTitle.setFillColor(visualBlue);

    sf::RectangleShape chatRect;
    chatRect.setPosition(650, 5);
    chatRect.setSize(sf::Vector2f(645, 690));
    chatRect.setOutlineColor(darktheme);
    chatRect.setOutlineThickness(5);
    chatRect.setFillColor(invisible);

    sf::RectangleShape statusRect;
    statusRect.setPosition(5, 5);
    statusRect.setSize(sf::Vector2f(640, 300));
    statusRect.setOutlineColor(darktheme);
    statusRect.setOutlineThickness(5);
    statusRect.setFillColor(invisible);

    sf::RectangleShape actionsRect;
    actionsRect.setPosition(5, 310);
    actionsRect.setSize(sf::Vector2f(640, window.getSize().y - 315));
    actionsRect.setOutlineColor(darktheme);
    actionsRect.setOutlineThickness(5);
    actionsRect.setFillColor(invisible);

    sf::Text disButton("Dis", font, 30);
    disButton.setFillColor(visualRed);
    disButton.setPosition(445, 265);

    sf::Text connectButton("connect", font, 30);
    connectButton.setFillColor(visualGreen);
    connectButton.setPosition(500, 265);

    sf::Text StatusInformation("", font, 20);
    StatusInformation.setPosition(5, 5);
    StatusInformation.setFillColor(visualYellow);

    std::string chatMessage = "";
    sf::Text chatText("Enter Message", font, 20);
    chatText.setPosition(655, window.getSize().y - 30);

    chat c;
    c.text.setFont(font);
    c.text.setPosition(655, 35);
    c.text.setCharacterSize(15);
    c.text.setFillColor(visualRed);
    c.setLineCount(35);

    window.setFramerateLimit(30);

    bool isChat = false;

    while (window.isOpen()) {

        window.clear(background);
        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::Resized) {
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                window.setView(sf::View(visibleArea));
                chatRect.setSize(sf::Vector2f(event.size.width - 655, event.size.height - 10));
                actionsRect.setSize(sf::Vector2f(640, event.size.height - 315));
                chatText.setPosition(655, window.getSize().y - 30);
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if (chatRect.getGlobalBounds().contains({ (float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y })) {
                    isChat = true;
                }
                else isChat = false;
            }
            if (event.type == sf::Event::TextEntered) {
                if (isChat) {
                    if (event.key.code == 8) {
                        if (chatMessage.size() >= 1) {
                            chatMessage.replace(chatMessage.end() - 1, chatMessage.end(), "");
                            chatText.setString(chatMessage);
                        }
                    }
                    else if (event.key.code == 13) {
                        c.width = 200;
                        c.addLine(("[YOU]: " + chatMessage));
                        sf::Packet p;
                        p << chatMessage;
                        chatMessage = "";
                        chatText.setString("Enter Message");
                    }
                    else {
                        chatMessage += event.text.unicode;
                        chatText.setString(chatMessage);
                    }
                }
            }
        }

        for (int x = 0; x < particleCount; x++)
            window.draw(particles[x]);

        window.draw(statusRect);
        window.draw(chatRect);
        window.draw(actionsRect);
        window.draw(chatTitle);
        window.draw(chatText);
        window.draw(c.getText());
        window.draw(StatusInformation);
        window.display();
    }
}
