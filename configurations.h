#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>

#include <iostream>
#include <fstream>

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


#define DATA_TYPE_BASEFILE ".xyz"
#define DATA_TYPE_KEYFILE ".key"

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

}
