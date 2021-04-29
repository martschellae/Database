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
		y = 95 + y;
	}
	x -= 32;
	x = (x + y) % 95;
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
	std::string newString = "\0";

	if (way) {
		while (keyword.size() < text.size()) {
			keyword += keyword;
		}

		for (int x = 0; x < text.size(); x++) {
			int c = keyword[x] - 32;
			newString += caesar(text[x], c);
		}
		return newString;
	}
	else {
		while (keyword.size() < text.size()) {
			keyword += keyword;
		}

		for (int x = 0; x < text.size(); x++) {
			int c = keyword[x] - 32;
			newString += caesar(text[x], -c);
		}
		return newString;
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
	srand(hasher(base) * length);
	std::string key = "\0";

	while (key.size() < length) {
		int c = rand();
		char u = (rand() % 95) + 32;
		key += u;
	}
	return key;
}
void encryptPicture(std::string path, std::string key) {
	std::string keyword = key;
	sf::Image old;
	if (!old.loadFromFile(path)) {
		MessageBox(0, L"Invalid Filename", L"Error", MB_OK);
	}
	while (keyword.size() < (old.getSize().x * old.getSize().y * 3)) {
		keyword += keyword;
	}
	sf::Image new_Image;
	new_Image.create(old.getSize().x, old.getSize().y, {255, 255, 255});
	
	int c = 0;
	for (int y = 0; y < old.getSize().y; y++) {
		for (int x = 0; x < old.getSize().x; x++) {
			UINT8 r = old.getPixel(x, y).r + keyword[c] * 8;
			UINT8 g = old.getPixel(x, y).g + keyword[c] * 8;
			UINT8 b = old.getPixel(x, y).b + keyword[c] * 8;

			new_Image.setPixel(x, y, {r, g, b});
			c++;
		}
	}
	new_Image.saveToFile(path);
}
void decryptPicture(std::string path, std::string key) {
	std::string keyword = key;
	sf::Image old;
	if (!old.loadFromFile(path)) {
		MessageBox(0, L"Invalid Filename", L"Error", MB_OK);
	}
	while (keyword.size() < (old.getSize().x * old.getSize().y * 3)) {
		keyword += keyword;
	}

	sf::Image new_Image;
	new_Image.create(old.getSize().x, old.getSize().y, {255, 255, 255});
	
	int c = 0;
	for (int y = 0; y < old.getSize().y; y++) {
		for (int x = 0; x < old.getSize().x; x++) {
			UINT8 r = old.getPixel(x, y).r - keyword[c] * 8;
			UINT8 g = old.getPixel(x, y).g - keyword[c] * 8;
			UINT8 b = old.getPixel(x, y).b - keyword[c] * 8;

			//if(r > 250 || r < 5)
			//std::cout << "R: " << std::to_string(r) << "\tG: " << std::to_string(g) << "\tB: " << std::to_string(b) << "\n";
			new_Image.setPixel(x, y, {r, g, b});
			c++;
		}
	}
	new_Image.saveToFile(path);
}