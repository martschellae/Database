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
	std::vector<int> real;
	std::vector<int> alias;
	std::string keyword;
public:
	std::string encrypt(std::string keyword, std::string text) {
		int in = 0;
		for (int x = 0; x < text.size(); x++) {
			text[x] = caesar(text[x], abs(keyword[in]-text[in]));
			in++;
		}
		return text;
	}
	std::string decrypt(std::string keyword, std::string text) {
		int in = 0;
		for (int x = 0; x < text.size(); x++) {
			text[x] = caesar(text[x], -(abs(keyword[in])-'~'));
			in++;
		}
		return text;
	}
};

class key {
protected:

public:

};