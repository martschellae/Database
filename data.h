#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>

#include <iostream>
#include <fstream>
#include <vector>
#include <Windows.h>

#include "configurations.h"
#include "keygen.h"
#include "templates.h"

void print(std::vector<std::string> strs) {
	std::cout << "\n---->\n";
	for (int y = 0; y < strs.size(); y++) {
		std::cout << strs[y] << "\n";
	}
}
void error(std::string msg) {
	std::cerr << "Fatal Error: " + msg + "\n";
	system("pause");
	exit(-1);
}
void showConsole() {
	ShowWindow(GetConsoleWindow(), SW_SHOW);
}
void hideConsole() {
	ShowWindow(GetConsoleWindow(), SW_HIDE);
}
std::string formatString(std::string fileName) {
	fileName = STDD + fileName + DATA_TYPE_BASEFILE;
	return fileName;
}

class Database {
private:
	std::fstream dataBaseFile;
	std::vector<std::string> dataBasePaths;
	std::fstream workFile;
	std::vector<std::string> workFileContent;
	std::string password;
public:
	void setPassword(std::string pass) {
		password = pass;
	}
	bool exists(std::string path) {
		for (int g = 0; g < dataBasePaths.size(); g++) {
			if (dataBasePaths[g] == path)return true;
		}
		return false;
	}
	unsigned int getNumber(std::string path) {
		for (int g = 0; g < dataBasePaths.size(); g++) {
			if (dataBasePaths[g] == path)return g;
		}
		return 1;
	}
	std::vector<std::string> openDataBase() {
		dataBaseFile.open(BASE, std::ios_base::in | std::ios_base::out);
		std::string line;
		if (dataBaseFile.good()) {
			while (!dataBaseFile.eof()) {
				std::getline(dataBaseFile, line);
				if (line != "" && line != "\0" && line != "\n")
					dataBasePaths.push_back(line);
			}
		}else {
			error("Database file not found. Database must be located under \"assets/dependencies/path.database\"");
		}
		dataBaseFile.close();
		return dataBasePaths;
	}
	void updateDataBase() {
		dataBaseFile.open(BASE, std::ios_base::out | std::ios_base::trunc);
		for (int g = 0; g < dataBasePaths.size(); g++) {
			dataBaseFile << dataBasePaths[g];
			dataBaseFile << "\n";
		}
		dataBaseFile.close();
	}
	int getFileCount() {
		return dataBasePaths.size();
	}
	int removeFileFromDatabase(std::string path) {
		int find = 0;
		for (int j = 0; j < dataBasePaths.size(); j++) {
			if (dataBasePaths[j] == path) {
				find = j;
			}
		}
		std::vector<std::string>::iterator place;
		place = dataBasePaths.begin() + find;
		dataBasePaths.erase(place);
		int x = std::remove(formatString(path).c_str());
		updateDataBase();
		return x;
	}
	std::vector<std::string> openFileFromDatabase(std::string path) {

		std::string rawpath = path;
		path = formatString(path);
		workFileContent.resize(0);
		workFileContent.shrink_to_fit();
		workFile.open(path, std::ios_base::in | std::ios_base::out);
		std::string line;
		if (workFile.good()) {
			while (!workFile.eof()) {
				std::getline(workFile, line);
				if (line != "" && line != "\0" && line != "\n") {
					line = vignere(line, 0, createRandomKey(password));
					workFileContent.push_back(line);	
				}
			}
			workFileContent.push_back("");
			workFile.close();
		}else {
			workFile.open(path, std::ios_base::out | std::ios_base::trunc);
			workFile.close();
			openFileFromDatabase(rawpath);

		}
		return workFileContent;
	}
	void addFileToDatabase(std::string path) {
		if (!exists(path)) {
			dataBasePaths.push_back(path);
			openFileFromDatabase(path);
			updateDataBase();
		}
	}
	void saveFileInDatabase(std::string path) {
		path = formatString(path);
		workFile.open(path, std::ios_base::out | std::ios_base::in);
		for (int g = 0; g < workFileContent.size(); g++) {
			workFile << vignere(workFileContent[g], 1, createRandomKey(password));
			workFile << "\n";
		}
		workFile.close();
	}
	void sortDatabase() {
		std::sort(dataBasePaths.begin(), dataBasePaths.end());
		updateDataBase();
	}
	std::vector<std::string> getFilePaths() {
		return dataBasePaths;
	}
	std::vector<std::string> getFileContent() {
		return workFileContent;
	}
	void setFilePaths(std::vector<std::string> paths) {
		dataBasePaths = paths;
	}
	void setFileContent(std::vector<std::string> content) {
		workFileContent = content;
	}
	std::vector<std::string> applyTemplate() {
		char result = openTemplate();
		std::vector<std::string> templateContent;
		std::fstream templateFile;
		std::string line;

		switch (result) {
		case 'n':
			templateContent = STANDARD_LIST;
			return templateContent;
		case 'p':
			templateContent = PROFILE_LIST;
			return templateContent;
		case 'c':
			templateContent = CONTACT_LIST;
			return templateContent;
		case 'e':
			templateContent = EXPROFILE_LIST;
			return templateContent;
		case '1':
			templateFile.open(STDT, std::ios_base::in | std::ios_base::out);
			if (templateFile.good()) {
				while (!templateFile.eof()) {
					std::getline(templateFile, line);
					if (line != "" && line != "\0" && line != "\n")
						templateContent.push_back(line);
				}
				templateFile.close();
			}
			else {
				templateContent = STANDARD_LIST;
			}
			return templateContent;
		case '2':
			templateFile.open(STD2, std::ios_base::in | std::ios_base::out);
			if (templateFile.good()) {
				while (!templateFile.eof()) {
					std::getline(templateFile, line);
					if (line != "" && line != "\0" && line != "\n")
						templateContent.push_back(line);
				}
				templateFile.close();
			}
			else {
				templateContent = STANDARD_LIST;
			}
			return templateContent;
		}
	}
};