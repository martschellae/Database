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

class ParticleSystem : public sf::Drawable, public sf::Transformable
{
public:

    ParticleSystem(unsigned int count) :
        m_particles(count),
        m_vertices(sf::Points, count),
        m_lifetime(sf::seconds(3.f)),
        m_emitter(0.f, 0.f)
    {
    }

    void setEmitter(sf::Vector2f position)
    {
        m_emitter = position;
    }

    void update(sf::Time elapsed)
    {
        for (std::size_t i = 0; i < m_particles.size(); ++i)
        {
            // update the particle lifetime
            Particle& p = m_particles[i];
            p.lifetime -= elapsed;

            // if the particle is dead, respawn it
            if (p.lifetime <= sf::Time::Zero)
                resetParticle(i);

            // update the position of the corresponding vertex
            m_vertices[i].position += p.velocity * elapsed.asSeconds();

            // update the alpha (transparency) of the particle according to its lifetime
            float ratio = p.lifetime.asSeconds() / m_lifetime.asSeconds();
            m_vertices[i].color.a = static_cast<sf::Uint8>(ratio * 255);
        }
    }

private:

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        // apply the transform
        states.transform *= getTransform();

        // our particles don't use a texture
        states.texture = NULL;

        // draw the vertex array
        target.draw(m_vertices, states);
    }

private:

    struct Particle
    {
        sf::Vector2f velocity;
        sf::Time lifetime;
    };

    void resetParticle(std::size_t index)
    {
        // give a random velocity and lifetime to the particle
        float angle = (std::rand() % 360) * 3.14f / 180.f;
        float speed = (std::rand() % 50) + 50.f;
        m_particles[index].velocity = sf::Vector2f(std::cos(angle) * speed, std::sin(angle) * speed);
        m_particles[index].lifetime = sf::milliseconds((std::rand() % 2000) + 1000);

        // reset the position of the corresponding vertex
        m_vertices[index].position = m_emitter;
    }

    std::vector<Particle> m_particles;
    sf::VertexArray m_vertices;
    sf::Time m_lifetime;
    sf::Vector2f m_emitter;
};

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


    sf::Color pick = sf::Color::Red;
    sf::VertexArray colorPalette(sf::Quads, 4);
    colorPalette[0].color = sf::Color::White;
    colorPalette[0].position = { 0, 0 };
    colorPalette[1].color = pick;
    colorPalette[1].position = { 1000, 0 };
    colorPalette[2].color = pick;
    colorPalette[2].position = { 1000, 1000 };
    colorPalette[3].color = sf::Color::Black;
    colorPalette[3].position = { 0, 1000 };

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
                zoom += 0.05 * event.mouseWheelScroll.delta;
            }
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            image.setPixel((UINT)mouseOnImagePos.x, (UINT)mouseOnImagePos.y-1, sf::Color::Black);
            image.setPixel((UINT)mouseOnImagePos.x-1, (UINT)mouseOnImagePos.y, sf::Color::Black);
            image.setPixel((UINT)mouseOnImagePos.x-1, (UINT)mouseOnImagePos.y-1, sf::Color::Black);
            image.setPixel((UINT)mouseOnImagePos.x-1, (UINT)mouseOnImagePos.y+1, sf::Color::Black);
            image.setPixel((UINT)mouseOnImagePos.x, (UINT)mouseOnImagePos.y, sf::Color::Black);
            image.setPixel((UINT)mouseOnImagePos.x+1, (UINT)mouseOnImagePos.y - 1, sf::Color::Black);
            image.setPixel((UINT)mouseOnImagePos.x+1, (UINT)mouseOnImagePos.y+1, sf::Color::Black);
            image.setPixel((UINT)mouseOnImagePos.x+1, (UINT)mouseOnImagePos.y, sf::Color::Black);
            image.setPixel((UINT)mouseOnImagePos.x, (UINT)mouseOnImagePos.y+1, sf::Color::Black);
        }
        imagePosition = { (float)window.getSize().x / 2 - (float)displayTexture.getSize().x * display.getScale().x / 2, (float)window.getSize().y / 2 - (float)displayTexture.getSize().y * display.getScale().y / 2 };

        scale = zoom * (window.getSize().x / (float)displayTexture.getSize().x);

        display.setPosition(imagePosition);
        display.setScale(scale, scale);

        for (int x = 0; x < particleCount; x++)
            window.draw(particles[x]);

        window.draw(display);
        window.draw(menuBar);
        //window.draw(colorPalette);
        window.display();
    }
}
