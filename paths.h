#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>

#include <iostream>

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