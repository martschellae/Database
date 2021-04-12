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
#include "images.h"

extern enum errorType {
	error_database_corrupted = 1,
	error_files_missing = 2,
	error_bad_config_format = 3
};
void throwError(errorType eT) {

	sf::Font font;

	if (!font.loadFromFile(FONT)) {
		showConsole();
		error("Font not found. Font must be located under \"assets/fonts/font.ttf\"");
	}

	sf::Cursor cur;
	cur.loadFromSystem(sf::Cursor::ArrowWait);

    std::vector<sf::CircleShape> particles;
    std::vector<sf::Vector2f> particlePos;
    int particleCount = 1000;
    srand(GetTickCount64());
    for (int x = 0; x < particleCount; x++) {
        sf::CircleShape temp;
        temp.setPointCount(6);
        temp.setRotation(rand() % 180);
        temp.setFillColor(sf::Color(r(173), r(83), r(83), 50));
        temp.setRadius(rand() % 100 + 155);
        sf::Vector2f tmp(rand() % 5000 - 2500, rand() % 2500 - 1250);
        particlePos.push_back(tmp);
        temp.setPosition(particlePos[x]);
        particles.push_back(temp);
    }

	sf::RenderWindow window(sf::VideoMode(1300, 700), "An Errror Occured.");
	window.setMouseCursor(cur);

    sf::Text oops("Oops.", font, 90);
    oops.setFillColor(darkness);
    oops.setPosition(25, 10);

    sf::Text smth("Something went wrong here.", font, 30);
    smth.setFillColor(darkness);
    smth.setPosition(315, 70);

    sf::Text error("", font, 30);
    error.setFillColor(darkness);
    error.setPosition(25, 120);

    sf::Text admin("If youre not able to fix this, contact an Administrator. You can close this window at any time.", font, 20);
    admin.setFillColor(darkness);
    admin.setPosition(25, window.getSize().y - 35);

    switch (eT) {
    case error_database_corrupted:
        error.setString(error_message_database_corrupted);
        break;
    case error_files_missing:
        error.setString(error_message_files_missing);
        break;
    case error_bad_config_format:
        error.setString(error_message_bad_config_format);
        break;
    }

    while (window.isOpen()) {

        window.clear(background);

        sf::Event event;
        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {
                    window.close();
            }
            if (event.type == sf::Event::Resized) {
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                window.setView(sf::View(visibleArea));
                admin.setPosition(25, window.getSize().y - 35);
            }
        }

        for (int x = 0; x < particleCount; x++) {
            window.draw(particles[x]);
        }
        window.draw(oops);
        window.draw(smth);
        window.draw(error);
        window.draw(admin);
        window.display();
    }

}