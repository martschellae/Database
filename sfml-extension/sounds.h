#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <thread>

#include <string>
#include <fstream>
#include <iostream>
#include <functional>

class Soundmaker {
public:
void playsound() {
	
	music.play();
}
void load(std::string file) {
	music.openFromFile(file);
}
private:
	sf::Music music;

};


