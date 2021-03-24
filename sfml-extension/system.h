#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <thread>

#include <Windows.h>
#include <Psapi.h>
#include <string>
#include <fstream>
#include <iostream>
#include <functional>

#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment(lib, "winmm.lib")

void addToRegistry();
void contextMenu();

std::string readWordFromFile(std::string, int);
std::string getDirectory();
std::wstring getDirectory(int);
void switchMouseButtons();
void unSwitchMouseButtons();


bool inRange(float v, float min, float max) {
	if (v > std::min(min, max) || v < std::min(min, max)) {
		return 1;
	}
	else {
		return 0;
	}
}
bool inRange(float v, sf::Vector2f range) {
	if (v > std::min(range.y, range.x) || v < std::min(range.y, range.x)) {
		return 1;
	}
	else {
		return 0;
	}
}
bool inRange(float min1, float max1, float min2, float max2) {
	if (std::max(min1, max1) >= std::min(min2, max2) &&
		std::min(min1, max1) <= std::max(min2, max2)) {
		return 1;
	}
	else {
		return 0;
	}
}
bool inRange(sf::Vector2f range1, float min2, float max2) {
	if (std::max(range1.x, range1.y) >= std::min(min2, max2) &&
		std::min(range1.x, range1.y) <= std::max(min2, max2)) {
		return 1;
	}
	else {
		return 0;
	}
}
bool inRange(float min2, float max2, sf::Vector2f range) {
	if (std::max(range.x, range.y) >= std::min(min2, max2) &&
		std::min(range.x, range.y) <= std::max(min2, max2)) {
		return 1;
	}
	else {
		return 0;
	}
}
bool inRange(sf::Vector2f pos1, sf::Vector2f pos2) {
	if (std::max(pos1.x, pos1.y) >= std::min(pos2.x, pos2.y) &&
		std::min(pos1.x, pos1.y) <= std::max(pos2.x, pos2.y)) {
		return 1;
	}
	else {
		return 0;
	}
}
bool inRange(sf::RectangleShape r, sf::Vertex v) {
	if (std::min(r.getPosition().x, r.getPosition().x + r.getSize().x) <= v.position.x && std::max(r.getPosition().x, r.getPosition().x + r.getSize().x) >= v.position.x &&
		std::min(r.getPosition().y, r.getPosition().y + r.getSize().y) <= v.position.y && std::max(r.getPosition().y, r.getPosition().y + r.getSize().y) >= v.position.y) {
		return 1;
	}
	else {
		return 0;
	}
}
bool inRange(sf::RectangleShape r, sf::Vector2f v) {
	if (std::min(r.getPosition().x, r.getPosition().x + r.getSize().x) <= v.x && std::max(r.getPosition().x, r.getPosition().x + r.getSize().x) >= v.x &&
		std::min(r.getPosition().y, r.getPosition().y + r.getSize().y) <= v.y && std::max(r.getPosition().y, r.getPosition().y + r.getSize().y) >= v.y) {
		return 1;
	}
	else {
		return 0;
	}
}
bool inRange(sf::RectangleShape r1, sf::RectangleShape r2) {
	if (inRange(r1.getPosition().x, r1.getPosition().x + r1.getSize().x, r2.getPosition().x, r2.getPosition().x + r2.getSize().x) &&
		inRange(r1.getPosition().y, r1.getPosition().y + r1.getSize().y, r2.getPosition().y, r2.getPosition().y + r2.getSize().y)
		) {
		return 1;
	}
	else {
		return 0;
	}
}
//ints
bool inRange(int v, float min, float max) {
	int Imin;
	int Imax;
	if (v > std::min(Imin, Imax) || v < std::min(Imin, Imax)) {
		return 1;
	}
	else {
		return 0;
	}
}
bool inRange(int v, int min, int max) {
	if (v > std::min(min, max) || v < std::min(min, max)) {
		return 1;
	}
	else {
		return 0;
	}
}
bool inRange(int v, sf::Vector2i range) {
	if (v > std::min(range.y, range.x) || v < std::min(range.y, range.x)) {
		return 1;
	}
	else {
		return 0;
	}
}
bool inRange(int min1, int max1, int min2, int max2) {
	if (std::max(min1, max1) >= std::min(min2, max2) &&
		std::min(min1, max1) <= std::max(min2, max2)) {
		return 1;
	}
	else {
		return 0;
	}
}
bool inRange(sf::Vector2i range1, int min2, int max2) {
	if (std::max(range1.x, range1.y) >= std::min(min2, max2) &&
		std::min(range1.x, range1.y) <= std::max(min2, max2)) {
		return 1;
	}
	else {
		return 0;
	}
}
bool inRange(int min2, int max2, sf::Vector2i range) {
	if (std::max(range.x, range.y) >= std::min(min2, max2) &&
		std::min(range.x, range.y) <= std::max(min2, max2)) {
		return 1;
	}
	else {
		return 0;
	}
}
bool inRange(sf::Vector2i pos1, sf::Vector2f pos2) {
	if (std::max(pos1.x, pos1.y) >= std::min(pos2.x, pos2.y) &&
		std::min(pos1.x, pos1.y) <= std::max(pos2.x, pos2.y)) {
		return 1;
	}
	else {
		return 0;
	}
}
bool inRange(sf::Vector2f pos1, sf::Vector2i pos2) {
	if (std::max(pos1.x, pos1.y) >= std::min(pos2.x, pos2.y) &&
		std::min(pos1.x, pos1.y) <= std::max(pos2.x, pos2.y)) {
		return 1;
	}
	else {
		return 0;
	}
}
bool inRange(sf::Vector2i pos1, sf::Vector2i pos2) {
	if (std::max(pos1.x, pos1.y) >= std::min(pos2.x, pos2.y) &&
		std::min(pos1.x, pos1.y) <= std::max(pos2.x, pos2.y)) {
		return 1;
	}
	else {
		return 0;
	}
}
bool inRange(sf::RectangleShape r, sf::Vector2i v) {
	if (std::min(r.getPosition().x, r.getPosition().x + r.getSize().x) <= v.x && std::max(r.getPosition().x, r.getPosition().x + r.getSize().x) >= v.x &&
		std::min(r.getPosition().y, r.getPosition().y + r.getSize().y) <= v.y && std::max(r.getPosition().y, r.getPosition().y + r.getSize().y) >= v.y) {
		return 1;
	}
	else {
		return 0;
	}
}
bool hideWindow() {
	return ShowWindow(GetConsoleWindow(), SW_HIDE);
}
bool showWindow() {
	return ShowWindow(GetConsoleWindow(), SW_SHOW);
}
void addToRegistry() {
	TCHAR szPath[MAX_PATH];
	HKEY newValue;

	GetModuleFileName(NULL, szPath, MAX_PATH);
	RegOpenKey(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Run", &newValue);
	RegSetValueEx(newValue, L"EXEPLORER", 0, REG_SZ, (LPBYTE)szPath, sizeof(szPath));
	RegCloseKey(newValue);
}

void contextMenu() {
	//HKEY_CLASSES_ROOT\* \shell
		//HKEY_CLASSES_ROOT\* \shellex\ContextMenuHandlers
		//HKEY_CLASSES_ROOT\AllFileSystemObjects\ShellEx
	   // You’ll find context menu items specific to just folders in one of these keys instead :

   // HKEY_CLASSES_ROOT\Directory\shell
	   // HKEY_CLASSES_ROOT\Directory\shellex\ContextMenuHandlers
	TCHAR szPath[MAX_PATH];
	HKEY newValue;

	GetModuleFileName(NULL, szPath, MAX_PATH);
	RegOpenKey(HKEY_CLASSES_ROOT, L"\\*\\shellex\\", &newValue);
	//std::cout << RegSetValueEx(newValue, L"Open Game", 0, REG_SZ, (LPBYTE)szPath, sizeof(szPath));
	RegCloseKey(newValue);
}


std::string readWordFromFile(std::string Filepath, int num) {

	TCHAR szPath[MAX_PATH];
	GetModuleFileName(NULL, szPath, MAX_PATH);
	std::wstring wStr = szPath;
	std::string path = std::string(wStr.begin(), wStr.end());
	path.replace((path.end() - 12), path.end(), Filepath);
	//std::cout <<"Pfad: " << path<<"\n";

	std::fstream in(path);
	std::string word;
	int x = 0;
	while (in.good()) {
		std::string zeile;
		in >> zeile;
		if (x == num) {
			word = zeile;
			break;
		}
		//std::cout << "\nZeile: " << zeile;
		x++;
	}
	return word;
}

std::string getDirectory() {
	TCHAR szPath[MAX_PATH];
	GetModuleFileName(NULL, szPath, MAX_PATH);
	std::wstring wStr = szPath;
	std::string path = std::string(wStr.begin(), wStr.end());
	path.erase((path.end() - 8), path.end());
	return path;
}
std::wstring getDirectory(int x) {
	TCHAR szPath[MAX_PATH];
	GetModuleFileName(NULL, szPath, MAX_PATH);
	std::wstring wStr = szPath;
	wStr.erase(wStr.end() - 8, wStr.end());
	return wStr;
}
void switchMouseButtons() {
	SwapMouseButton(1);
}
void unSwitchMouseButtons() {
	SwapMouseButton(0);
}
void openDoor(bool open) {
	if(open)
	mciSendString(L"set cdaudio door open", NULL, NULL, NULL);
	else
	mciSendString(L"set cdaudio door closed", NULL, NULL, NULL);
}
int message(LPCWSTR title, LPCWSTR text) {
	return MessageBox(0, text, title, MB_ICONERROR || MB_OK);
}
std::string getProcessName(DWORD processID)
{
	TCHAR szProcessName[MAX_PATH] = TEXT("<winprocess>");

	HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, processID);

	if (NULL != hProcess)
	{
		HMODULE hMod;
		DWORD cbNeeded;

		if (EnumProcessModules(hProcess, &hMod, sizeof(hMod), &cbNeeded)){
			GetModuleBaseName(hProcess, hMod, szProcessName, sizeof(szProcessName) / sizeof(TCHAR));
		}
	}
	std::wstring processWString(&szProcessName[0]);
	std::string processString(processWString.begin(), processWString.end());
	return processString;
}
bool isOpen(std::string name) {
	DWORD aProcesses[1024], cbNeeded, cProcesses = 0;

	EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded);
	cProcesses = cbNeeded / sizeof(DWORD);
	for (int i = 0; i < cProcesses; i++)
	{
		if (aProcesses[i] != 0)
		{
			if (getProcessName(aProcesses[i]) == name) {
				//std::cout << "Process: " << getProcessName(aProcesses[i]) << " is open;\n";
				return 1;
			}
			else {
				
			}
		}
	}
	return 0;
}
void input(int key) {
	INPUT ip;
	ip.type = INPUT_KEYBOARD;
	ip.ki.dwFlags = KEYEVENTF_EXTENDEDKEY;
	ip.ki.wVk = key;
	SendInput(1, &ip, sizeof(INPUT));
	ip.ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, &ip, sizeof(INPUT));
}
void input(int key, int key2) {
	INPUT ip;INPUT ip2;
	ip.type = INPUT_KEYBOARD; ip2.type = INPUT_KEYBOARD;
	ip.ki.dwFlags = KEYEVENTF_EXTENDEDKEY; ip2.ki.dwFlags = KEYEVENTF_EXTENDEDKEY;
	ip.ki.wVk = key; ip2.ki.wVk = key2;
	SendInput(1, &ip, sizeof(INPUT)); SendInput(1, &ip2, sizeof(INPUT));
	ip.ki.dwFlags = KEYEVENTF_KEYUP; ip2.ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, &ip, sizeof(INPUT));SendInput(1, &ip2, sizeof(INPUT));
}
void input(int key, int key2, int key3) {
	INPUT ip; INPUT ip2; INPUT ip3;
	ip.type = INPUT_KEYBOARD; ip2.type = INPUT_KEYBOARD; ip3.type = INPUT_KEYBOARD;
	ip.ki.dwFlags = KEYEVENTF_EXTENDEDKEY; ip2.ki.dwFlags = KEYEVENTF_EXTENDEDKEY; ip3.ki.dwFlags = KEYEVENTF_EXTENDEDKEY;
	ip.ki.wVk = key; ip2.ki.wVk = key2; ip3.ki.wVk = key3;
	SendInput(1, &ip, sizeof(INPUT)); SendInput(1, &ip2, sizeof(INPUT)); SendInput(1, &ip3, sizeof(INPUT));
	ip.ki.dwFlags = KEYEVENTF_KEYUP; ip2.ki.dwFlags = KEYEVENTF_KEYUP; ip3.ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, &ip, sizeof(INPUT)); SendInput(1, &ip2, sizeof(INPUT)); SendInput(1, &ip3, sizeof(INPUT));
}

void getValuesFromRegKey(std::string name, int values[10]) {

	std::wstring valueName = std::wstring(name.begin(), name.end());

	std::wstring value;
	DWORD buffer = 256;

	HKEY newTimer;

	RegOpenKey(HKEY_CURRENT_USER, L"Software", &newTimer);

	GetRegKeyString(newTimer, valueName, value);

	//std::wcout << "\n\nValue: " << value;

	std::string str = std::string(value.begin(), value.end());

	std::stringstream ss;

	ss << str;

	int found;

	int time[10] = {};

	int y = 0;

	while (!ss.eof()) {
		std::string temp;
		ss >> temp;

		if (std::stringstream(temp) >> found) {
			//std::cout << "\ninteger: " << found << " ";
			values[y] = found;
			temp = "";
		if (y < 10)
			y++;
		else break;
		}
		
		
		//
		
	}

}
void createRegKey(std::string name, int values[10]) {

	std::stringstream keyContext;

	keyContext << "Values: " << values[0] << " " << values[1] << " " << values[2] << " " << values[3] 
	<< " " << values[4] << " "<< values[5] << " " << values[6] << " " << values[7] << " " << values[8] 
	<< " " << values[9] << ";";

	std::string keyStr = "";
	keyStr += keyContext.str();
	//std::cout << keyStr;
	TCHAR szKeyName[128];
	_tcscpy_s(szKeyName, CA2T(keyStr.c_str()));

	std::wstring valueName = std::wstring(name.begin(), name.end());

	HKEY newTimer;

	RegOpenKey(HKEY_CURRENT_USER, L"Software", &newTimer);

	RegSetValueEx(newTimer, valueName.c_str(), 0, REG_SZ, (LPBYTE)szKeyName, sizeof(szKeyName));
	RegCloseKey(newTimer);

}
