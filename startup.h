#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>

#include <iostream>
#include <fstream>

#include "paths.h"
#include "data.h"
#include "colors.h"

int check(std::string username, std::string password) {

    std::string compareUser;
    std::string comparePass;
    std::ifstream input(SAVE);
    if (!input) {
        showConsole();
        error("Hash File not found. Hash file must be located under \"assets/dependencies/key.hash\"");
        hideConsole();
    }
    std::getline(input, compareUser);
    std::getline(input, comparePass);
    
    std::hash<std::string> hashPass;
    std::hash<std::string> hashUser;

    if (compareUser == std::to_string(hashUser(username)) && comparePass == std::to_string(hashPass(password))) {
        return 1;
    }
    return -1;
}

std::string login() {

    hideConsole();

    std::vector<sf::CircleShape> particles;
    std::vector<sf::Vector2f> particlePos;
    int particleCount = 100;
    srand(GetTickCount64());
    for (int x = 0; x < particleCount; x++) {
        sf::CircleShape temp;
        temp.setPointCount(6);
        temp.setRotation(rand() % 360);
        temp.setFillColor(sf::Color(R(220), R(202), R(120), rand()%50+10));
        temp.setRadius(rand() % 200 + 5);
        sf::Vector2f tmp(rand() % 1400 - 700, rand() % 300 - 150);
        particlePos.push_back(tmp);
        temp.setPosition(particlePos[x]);
        particles.push_back(temp);
    }

    sf::Font font;

    if (!font.loadFromFile(FONT)) {
        showConsole();
        error("Font not found. Font must be located under \"assets/fonts/font.ttf\"");
    }

    sf::RenderWindow window(sf::VideoMode(700, 150), "Login", sf::Style::Titlebar | sf::Style::Close);

    sf::Text user("Username:", font, 30);
    user.setPosition(10, 20);
    user.setFillColor(background);
    user.setStyle(sf::Text::Italic);
    sf::Text pass("Password:", font, 30);
    pass.setPosition(10, 80);
    pass.setFillColor(background);
    pass.setStyle(sf::Text::Italic);

    bool userTarget = true;
    bool passTarget = false;

    std::string password;
    std::string username;

    sf::Text userInput("", font, 30);
    userInput.setPosition(200, 20);
    userInput.setFillColor(background);
    sf::Text passInput("", font, 30);
    passInput.setPosition(200, 85);
    passInput.setFillColor(background);

    while (window.isOpen())
    {
        window.clear(sf::Color(200, 200, 200));
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                exit(-1);
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if (user.getGlobalBounds().contains({ (float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y })) {
                    userTarget = true, passTarget = false;
                }
                if (pass.getGlobalBounds().contains({ (float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y })) {
                    userTarget = false, passTarget = true;
                }
            }
            if (event.type == sf::Event::TextEntered)
            {
                if (userTarget) {
                    if (event.key.code == 8) {
                        if (username.size() >= 1) {
                            username.replace(username.end() - 1, username.end(), "");
                            userInput.setString(username);
                        }
                    }
                    else if (event.key.code == 13) {
                        userTarget = false;
                        passTarget = true;
                    }
                    else {
                    username += event.text.unicode;
                    userInput.setString(username);
                    }
                    
                }else if (passTarget) {
                    if (event.key.code == 8) {
                        if (password.size() >= 1) {
                            password.replace(password.end() - 1, password.end(), "");
                            std::string p = passInput.getString();
                            p.replace(p.end() - 1, p.end(), "");
                            passInput.setString(p);
                        }
                    }
                    else if (event.key.code == 13 && username != "\0") {
                        if (check(username, password) == 1) {
                            return password;
                        }
                        exit(-1);
                        
                    }
                    else {
                        password += event.text.unicode;
                        std::string p = passInput.getString();
                        p += "*";
                        passInput.setString(p);
                    }
                }
            }

        }
        if (userTarget) {
            user.setFillColor(darkness);
            pass.setFillColor(background);
        }
        else {
            user.setFillColor(background);
        }
        if (passTarget) {
            pass.setFillColor(darkness);
            user.setFillColor(background);
        }
        else {
            pass.setFillColor(background);
        }

        for (int x = 0; x < particleCount; x++) {
            window.draw(particles[x]);
        }
        window.draw(user);
        window.draw(userInput);
        window.draw(pass);
        window.draw(passInput);
        window.display();
    }
    exit(-1);
    return "error";
}