#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>

#include <iostream>
#include <fstream>

#include "paths.h"
#include "data.h"
#include "colors.h"

std::string processMessage(sf::Packet p, bool rce) {
	std::string input;
	p >> input;
	if (input.size() >= 1) {
		if (input[0] == '/') {
			input.replace(input.begin(), input.begin()+1, "");
			if (rce) {
				system(input.c_str());
				return "Command: " + input + " executed sucessfully";
			}
			else {
				return "Remote Code Execution turned off. Could not execute command";
			}
		}
		else {
			return "[PARTNER]: " + input;
		}

	} else {
		return "Message too short. Could not process";
	}
	return "Some big Error happened here.";
}