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