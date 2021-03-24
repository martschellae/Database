#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>

#include <iostream>
#include <fstream>

#include "paths.h"
#include "data.h"
#include "newFile.h"

extern sf::Color invisible(sf::Color(0, 0, 0, 0));
extern sf::Color bright(sf::Color(255, 255, 255));
extern sf::Color dark(sf::Color(180, 180, 180));
extern sf::Color darker(sf::Color(130, 130, 130));
extern sf::Color darktheme(sf::Color(47, 49, 54));
extern sf::Color darkness(sf::Color(25, 25, 25));
extern sf::Color shadow(sf::Color(22, 22, 22));
extern sf::Color background(sf::Color(20, 20, 20));

extern sf::Color visualBlue(sf::Color(92, 186, 247));
extern sf::Color visualYellow(sf::Color(220, 202, 120));
extern sf::Color visualGreen(sf::Color(78, 201, 176));
extern sf::Color visualRed(sf::Color(173, 83, 83));