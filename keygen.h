#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>

#include <iostream>
#include <fstream>
#include <vector>

#include "configurations.h"

char caesar(char x, int y) {
	if (y < 0) {
		y = 94 + y;
	}
	x -= 32;
	x = (x + y) % 94;
	x += 32;
	return x;
}

std::string caesar(std::string x, int y) {
	for (int f = 0; f < x.size(); f++) {
		x[f] = caesar(x[f], y);
	}
	return x;
}

std::string vignere(std::string text, bool way, std::string key) {
	std::string keyword = key;
	if (way) {
		while (keyword.size() < text.size()) {
			keyword += keyword;
		}
		std::string neu = "\0";
		for (int x = 0; x < text.size(); x++) {
			int c = keyword[x] - 32;
			neu += caesar(text[x], c);
		}
		return neu;
	}
	else {
	while (keyword.size() < text.size()) {
		keyword += keyword;
	}
	std::string neu = "\0";
	for (int x = 0; x < text.size(); x++) {
		int c = keyword[x] - 32;
		neu += caesar(text[x], -c);
	}
	return neu;
	}
}

std::string createRandomKey(unsigned int seed, unsigned int length = 128) {
	srand(seed * length);
	std::string key = "\0";

	while (key.size() < length) {
		int c = rand();
		char u = (rand() % 94) + 32;
		key += u;
	}
	return key;
}
std::string createRandomKey(std::string base, unsigned int length = 128) {
	std::hash<std::string> hasher;
	srand(hasher(base));
	std::string key = "\0";

	while (key.size() < length) {
		int c = rand();
		char u = (rand() % 94) + 32;
		key += u;
	}
	return key;
}
void encryptPicture(std::string path, std::string key) {
	std::string keyword = key;
	sf::Image old;
	if (!old.loadFromFile(path)) {
		std::cout << "datei error";
	}
	while (keyword.size() < (old.getSize().x * old.getSize().y * 3)) {
		keyword += keyword;
	}
	sf::Image new_Image;
	new_Image.create(old.getSize().x, old.getSize().y);
	
	int c = 0;
	for (int y = 0; y < old.getSize().y; y++) {
		for (int x = 0; x < old.getSize().x; x++) {
			//sf::Color worker;
			/*worker = old.getPixel(x, y);
			worker.r = (worker.r - keyword[c]) % 255;
			worker.r = (worker.r + keyword[c]) % 255;
			c++;
			worker.g = (worker.g - keyword[c]) % 255;
			worker.g = (worker.g + keyword[c]) % 255;
			c++;
			worker.b = (worker.b - keyword[c]) % 255;
			worker.b = (worker.b + keyword[c]) % 255;
			c++;
			*/
			
			new_Image.setPixel(x, y, { (UINT8)(old.getPixel(x, y).r + keyword[c]), (UINT8)(old.getPixel(x, y).g + keyword[c]), (UINT8)(old.getPixel(x, y).b + keyword[c])});
			c++;
		}
	}
	new_Image.saveToFile(path);
}
void decryptPicture(std::string path, std::string key) {
	std::string keyword = key;
	sf::Image old;
	if (!old.loadFromFile(path)) {
		std::cout << "datei error";
	}
	while (keyword.size() < (old.getSize().x * old.getSize().y * 3)) {
		keyword += keyword;
	}

	sf::Image new_Image;
	new_Image.create(old.getSize().x, old.getSize().y, {0, 0, 0});
	
	int c = 0;
	for (int y = 0; y < old.getSize().y; y++) {
		for (int x = 0; x < old.getSize().x; x++) {
			sf::Color worker;
			worker = old.getPixel(x, y);
			worker.r = (worker.r + keyword[c] * 16) % 255;
			c++;
			worker.g = (worker.g + keyword[c] * 16) % 255;
			c++;
			worker.b = (worker.b + keyword[c] * 16) % 255;
			c++;
			worker.a = 255;
			new_Image.setPixel(x, y, worker);
		}
	}
	new_Image.saveToFile(path);
}