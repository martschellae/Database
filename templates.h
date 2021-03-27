#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>

#include <iostream>
#include <fstream>

#include "configurations.h"
#include "data.h"

int r(int x) {
    int y = (x - 20) + rand() % 40;
    return y;
}
int R(int x) {
    int y = (x - 40) + rand() % 80;
    return y;
}

char openTemplate() {

    sf::Font font;
    font.loadFromFile(FONT);

    std::vector<sf::CircleShape> particles;
    std::vector<sf::Vector2f> particlePos;
    int particleCount = 15000;
    srand(GetTickCount64());
    for (int x = 0; x < particleCount; x++) {
        sf::CircleShape temp;
        temp.setPointCount(8);
        temp.setRotation(rand() % 360);
        temp.setFillColor(sf::Color(R(visualRed.r), R(visualRed.g), R(visualRed.b), r(20)));
        temp.setRadius(rand() % 10 + 5);
        sf::Vector2f tmp(rand() % 10000 - 5000, rand() % 5000 - 2500);
        particlePos.push_back(tmp);
        temp.setPosition(particlePos[x]);
        particles.push_back(temp);
    }

    sf::Vector2f mPosition(0, 0);

    sf::RenderWindow window(sf::VideoMode(1000, 800), "Template Manager:");

    sf::Text choose("Choose\nTemplate:", font, 45);
    choose.setPosition(window.getSize().x / 18, window.getSize().y / 90);
    choose.setFillColor(visualYellow);

    sf::Text note("Note", font, 30);
    note.setPosition(window.getSize().x / 9 * 4, window.getSize().y / 9*2);
    note.setFillColor(visualBlue);
    sf::Text noteDescription("Creates a normal note", font, 15);
    noteDescription.setPosition(window.getSize().x / 9 * 4, window.getSize().y / 18 * 5);
    noteDescription.setFillColor(visualGreen);

    sf::Text profile("Profile", font, 30);
    profile.setPosition(window.getSize().x / 9 * 4, window.getSize().y / 9 * 3);
    profile.setFillColor(visualBlue);
    sf::Text profileDescription("Creates a profile of a person", font, 15);
    profileDescription.setPosition(window.getSize().x / 9 * 4, window.getSize().y / 18 * 7);
    profileDescription.setFillColor(visualGreen);

    sf::Text contact("Contact", font, 30);
    contact.setPosition(window.getSize().x / 9 * 4, window.getSize().y / 9 * 4);
    contact.setFillColor(visualBlue);
    sf::Text contactDescription("Creates a contact including phone number and e-Mail", font, 15);
    contactDescription.setPosition(window.getSize().x / 9 * 4, window.getSize().y / 18 * 9);
    contactDescription.setFillColor(visualGreen);

    sf::Text exProfile("Extended Profile", font, 30);
    exProfile.setPosition(window.getSize().x / 9 * 4, window.getSize().y / 9 * 5);
    exProfile.setFillColor(visualBlue);
    sf::Text exProfileDescription("Creates a more accurate profile of a person", font, 15);
    exProfileDescription.setPosition(window.getSize().x / 9 * 4, window.getSize().y / 18 * 11);
    exProfileDescription.setFillColor(visualGreen);

    sf::Text custom("Custom", font, 30);
    custom.setPosition(window.getSize().x / 9 * 4, window.getSize().y / 9 * 6);
    custom.setFillColor(visualBlue);
    sf::Text customDescription("Loads your Custom File Template", font, 15);
    customDescription.setPosition(window.getSize().x / 9 * 4, window.getSize().y / 18 * 13);
    customDescription.setFillColor(visualGreen);

    sf::Text custom2("Custom_2", font, 30);
    custom2.setPosition(window.getSize().x / 9 * 4, window.getSize().y / 9 * 7);
    custom2.setFillColor(visualBlue);
    sf::Text custom2Description("Loads your second Custom File Template", font, 15);
    custom2Description.setPosition(window.getSize().x / 9 * 4, window.getSize().y / 18 * 15);
    custom2Description.setFillColor(visualGreen);

    sf::Texture templateTex;
    templateTex.loadFromFile(TEMP);
    sf::Sprite templateSprite;
    templateSprite.setTexture(templateTex);
    templateSprite.setPosition(window.getSize().x / 18 * 2, window.getSize().y / 9 * 2);
    templateSprite.setScale(2, 2);

    sf::Texture noteTex;
    noteTex.loadFromFile(NOTE);
    sf::Sprite noteSprite;
    noteSprite.setTexture(noteTex);
    noteSprite.setPosition(window.getSize().x / 9 * 3, window.getSize().y / 9 * 2);

    sf::Texture profileTex;
    profileTex.loadFromFile(PRFL);
    sf::Sprite profileSprite;
    profileSprite.setTexture(profileTex);
    profileSprite.setPosition(window.getSize().x / 9 * 3, window.getSize().y / 9 * 3);

    sf::Texture contactTex;
    contactTex.loadFromFile(CONT);
    sf::Sprite contactSprite;
    contactSprite.setTexture(contactTex);
    contactSprite.setPosition(window.getSize().x / 9 * 3, window.getSize().y / 9 * 4);

    sf::Texture exProfileTex;
    exProfileTex.loadFromFile(EXPF);
    sf::Sprite exProfileSprite;
    exProfileSprite.setTexture(exProfileTex);
    exProfileSprite.setPosition(window.getSize().x / 9 * 3, window.getSize().y / 9 * 5);

    sf::Texture customTex;
    customTex.loadFromFile(CUST);
    sf::Sprite customSprite;
    customSprite.setTexture(customTex);
    customSprite.setPosition(window.getSize().x / 9 * 3, window.getSize().y / 9 * 6);

    sf::Texture custom2Tex;
    custom2Tex.loadFromFile(CUST);
    sf::Sprite custom2Sprite;
    custom2Sprite.setTexture(custom2Tex);
    custom2Sprite.setPosition(window.getSize().x / 9 * 3, window.getSize().y / 9 * 7);

    while (window.isOpen())
    {
        window.clear(background);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::Resized)
            {
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                choose.setPosition(window.getSize().x / 18, window.getSize().y / 90);

                note.setPosition(window.getSize().x / 9 * 4, window.getSize().y / 9 * 2);
                noteDescription.setPosition(window.getSize().x / 9 * 4, window.getSize().y / 18 * 5);

                profile.setPosition(window.getSize().x / 9 * 4, window.getSize().y / 9 * 3);
                profileDescription.setPosition(window.getSize().x / 9 * 4, window.getSize().y / 18 * 7);

                contact.setPosition(window.getSize().x / 9 * 4, window.getSize().y / 9 * 4);
                contactDescription.setPosition(window.getSize().x / 9 * 4, window.getSize().y / 18 * 9);

                exProfile.setPosition(window.getSize().x / 9 * 4, window.getSize().y / 9 * 5);
                exProfileDescription.setPosition(window.getSize().x / 9 * 4, window.getSize().y / 18 * 11);

                custom.setPosition(window.getSize().x / 9 * 4, window.getSize().y / 9 * 6);
                customDescription.setPosition(window.getSize().x / 9 * 4, window.getSize().y / 18 * 13);

                custom2.setPosition(window.getSize().x / 9 * 4, window.getSize().y / 9 * 7);
                custom2Description.setPosition(window.getSize().x / 9 * 4, window.getSize().y / 18 * 15);

                templateSprite.setPosition(window.getSize().x / 18 * 2, window.getSize().y / 9 * 2);
                noteSprite.setPosition(window.getSize().x / 9 * 3, window.getSize().y / 9 * 2);
                profileSprite.setPosition(window.getSize().x / 9 * 3, window.getSize().y / 9 * 3);
                contactSprite.setPosition(window.getSize().x / 9 * 3, window.getSize().y / 9 * 4);
                exProfileSprite.setPosition(window.getSize().x / 9 * 3, window.getSize().y / 9 * 5);
                customSprite.setPosition(window.getSize().x / 9 * 3, window.getSize().y / 9 * 6);
                custom2Sprite.setPosition(window.getSize().x / 9 * 3, window.getSize().y / 9 * 7);

                window.setView(sf::View(visibleArea));
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if (note.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
                    return 'n';
                }
                if (profile.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
                    return 'p';
                }
                if (contact.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
                    return 'c';
                }
                if (exProfile.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
                    return 'e';
                }
                if (custom.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
                    return '1';
                }
                if (custom2.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
                    return '2';
                }
            }
        }
        mPosition = { (sf::Mouse::getPosition().x / 40) - 30.0f, (sf::Mouse::getPosition().y / 40) - 30.0f };

        for (int x = 0; x < particleCount; x++) {
            particles[x].setPosition(particlePos[x].x + mPosition.x, particlePos[x].y + mPosition.y);
        }
        
        for (int x = 0; x < particleCount; x++) {
            window.draw(particles[x]);
        }
        window.draw(choose);

        window.draw(note);
        window.draw(noteDescription);

        window.draw(profile);
        window.draw(profileDescription);

        window.draw(contact);
        window.draw(contactDescription);

        window.draw(exProfile);
        window.draw(exProfileDescription);

        window.draw(custom);
        window.draw(customDescription);

        window.draw(custom2);
        window.draw(custom2Description);


        window.draw(templateSprite);
        window.draw(noteSprite);
        window.draw(profileSprite);
        window.draw(contactSprite);
        window.draw(exProfileSprite);
        window.draw(customSprite);
        window.draw(custom2Sprite);
        
        window.display();
    }
    return 'n';
}