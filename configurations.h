#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>

#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
#include <sstream>

sf::Color string_to_color(std::string hex_value) {
	hex_value.replace(hex_value.begin(), hex_value.begin() + 1, "");
	sf::Color ret;
	int values[6] = {0, 0, 0, 0, 0, 0};
	for (int z = 0; z < hex_value.size(); z++) {
		switch (hex_value[z]) {
		default:
			values[z] = hex_value[z] - 48;
			break;
		case 'A':
		case 'a':
			values[z] = 10;
			break;
		case 'B':
		case 'b':
			values[z] = 11;
			break;
		case 'C':
		case 'c':
			values[z] = 12;
			break;
		case 'D':
		case 'd':
			values[z] = 13;
			break;
		case 'E':
		case 'e':
			values[z] = 14;
			break;
		case 'F':
		case 'f':
			values[z] = 15;
			break;
		}
	}
	ret.r = values[0] * 16 + values[1];
	ret.g = values[2] * 16 + values[3];
	ret.b = values[4] * 16 + values[5];
	
	return ret;
}

#define FONT "assets/fonts/font.ttf"
#define SAVE "assets/dependencies/key.hash"
#define BASE "assets/dependencies/path.database"
#define STDD "assets/data/"
#define STDT "assets/templates/custom1.template"
#define STD2 "assets/templates/custom2.template"
#define TEMP "assets/dependencies/template.png"
#define NOTE "assets/dependencies/note.png"
#define CUST "assets/dependencies/custom.png"
#define PRFL "assets/dependencies/profile.png"
#define CONT "assets/dependencies/contact.png"
#define EXPF "assets/dependencies/exprofile.png"
#define SERV "assets/dependencies/server.png"
#define CLIE "assets/dependencies/client.png"
#define IMAG "assets/dependencies/image.png"
#define SOND "assets/dependencies/sound.png"
#define CONF "assets/conf/config"

#define DATA_TYPE_BASEFILE ".xyz"

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
extern sf::Color visualPink(sf::Color(247, 17, 116));

sf::Color hsvToRgb(float H, float S, float V) {
	float s = S / 100;
	float v = V / 100;
	float C = s * v;
	float X = C * (1 - abs(fmod(H / 60.0, 2) - 1));
	float m = v - C;
	float r, g, b;
	if (H >= 0 && H < 60) {
		r = C, g = X, b = 0;
	}
	else if (H >= 60 && H < 120) {
		r = X, g = C, b = 0;
	}
	else if (H >= 120 && H < 180) {
		r = 0, g = C, b = X;
	}
	else if (H >= 180 && H < 240) {
		r = 0, g = X, b = C;
	}
	else if (H >= 240 && H < 300) {
		r = X, g = 0, b = C;
	}
	else {
		r = C, g = 0, b = X;
	}
	int R = (r + m) * 255;
	int G = (g + m) * 255;
	int B = (b + m) * 255;
	return sf::Color(R, G, B, 255);
}

extern const std::vector<std::string> STANDARD_LIST = { "Notizen: " };
extern const std::vector<std::string> PROFILE_LIST =
{ "Vorname: ",
"Nachname: ",
"Geburtstag: ",
"Groesse: ",
"Gewicht: ",
"Augenfarbe: ",
"Haustiere: ",
"Hobbys: " };
extern const std::vector<std::string> CONTACT_LIST =
{ "Vorname: ",
"Nachname: ",
"Spitzname: ",
"Geburtstag: ",
"Tel. Nummer: ",
"Email: ",
"Adresse: ",
"Social Media: ",
"Notizen: " };
extern const std::vector<std::string> EXPROFILE_LIST =
{ "Vorname: ",
"Nachname: ",
"Spitzname: ",
"Geburtstag: ",
"Tel. Nummer: ",
"Email: ",
"Adresse: ",
"Ip Adresse: ",
"Social Media: ",
"Groesse: ",
"Gewicht: ",
"Augenfarbe: ",
"Haustiere: ",
"Hobbys: ",
"Notizen: " };

void readConfigFile() {

	std::vector<std::string> file;
	int size = 0;
	std::ifstream input;
	input.open(CONF, std::ios_base::in);

	if (!input.good()) {
		return;
	}
	std::string line;
	while (!input.eof()) {
		std::getline(input, line);
		file.push_back(line);
		line = "\0";
		size++;
	}
	if (size != 9) {
		exit(-1); // TODO
	}
	visualBlue = string_to_color(file[2]);
	visualYellow = string_to_color(file[4]);
	visualGreen = string_to_color(file[6]);
	visualRed = string_to_color(file[8]);
}
