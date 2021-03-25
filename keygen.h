#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>

#include <iostream>
#include <fstream>
#include <vector>

#include "paths.h"

char caesar(char x, int y) {
	//x += y;
	if (x + y > '~') {
		int z = x - '~' + y+ 31;
		x = z;
	}else if(x+y < ' '){
		int h = '~' - abs(y)+1;
		x = h;
	}
	else {
		x += y;
	}
	return x;
}

std::string caesar(std::string x, int y) {
	for (int f = 0; f < x.size(); f++) {
		x[f] = caesar(x[f], y);
	}
	return x;
}


class dictionary {
private:
	std::string keyword;
public:
	/*
	std::string encrypt(std::string key, std::string text) {
		std::string keywordOriginal = key;
		keyword = "\0";
		while (keyword.size() < text.size()) {
			keyword += keywordOriginal;
		}
		std::cout << "\nkeyword: " << keyword << "\n";

		for (int x = 0; x < text.size(); x++) {
			text[x] = ((text[x] + keyword[x]) % 93) + 32;
		}
		return text;
	}
	std::string decrypt(std::string key, std::string text) {
		std::string keywordOriginal = key;
		keyword = "\0";
		while (keyword.size() < text.size()) {
			keyword += keywordOriginal;
		}
		std::cout << "\nkeyword: " << keyword << "\n";

		for (int x = 0; x < text.size(); x++) {
			text[x] = ((text[x] - keyword[x] + 93) % 93)+32;
		}
		return text;
	}
	*/

};

class key {
protected:

public:

};