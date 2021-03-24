#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>

#include <string>
#include <fstream>
#include <iostream>
#include <functional>
#include <vector>
#include <limits>

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

sf::Font font1;
sf::Font font2;

sf::Color red = sf::Color(80, 0, 0);

void loadFonts();
sf::ConvexShape randomBack(int, int, int, int);
sf::ConvexShape randomLine(int, int, int, int);
sf::ConvexShape randMovement(sf::ConvexShape);

void loadFonts() {
	font1.loadFromFile("fonts/font1.ttf");
}
sf::ConvexShape randomBack(int pointCount, int xSize, int ySize, int brightness) {
	sf::ConvexShape polygon;
	polygon.setPointCount(pointCount);
	polygon.setOutlineThickness(2);
	polygon.setFillColor(sf::Color(30, 30, 30, 0));
	polygon.setOutlineColor(sf::Color(brightness, brightness, brightness));

	for (int x = 0; x < pointCount; x++) {
		polygon.setPoint(x, sf::Vector2f(rand() % xSize, rand() % ySize));
	}

	return polygon;
}

sf::ConvexShape randomBack(int pointCount, sf::Vector2f pos, int xSize, int ySize, int brightness) {
	sf::ConvexShape polygon;
	polygon.setPointCount(pointCount);
	polygon.setOutlineThickness(2);
	polygon.setFillColor(sf::Color(30, 30, 30, 0));
	polygon.setOutlineColor(sf::Color(brightness, brightness, brightness));
	polygon.setPosition(pos);
	for (int x = 0; x < pointCount; x++) {
		polygon.setPoint(x, sf::Vector2f(rand() % xSize, rand() % ySize));
	}

	return polygon;
}

sf::ConvexShape randomLine(int maxSize, int xSize, int ySize, int brightness) {
	sf::ConvexShape polygon;
	polygon.setPointCount(6);
	polygon.setOutlineThickness(1);
	polygon.setFillColor(sf::Color(50, 50, 50, 0));
	polygon.setOutlineColor(sf::Color(brightness, brightness, brightness));

	int randomSize = rand() % maxSize;

	polygon.setPoint(0, sf::Vector2f(0, 1));
	polygon.setPoint(1, sf::Vector2f(1, 2));
	polygon.setPoint(2, sf::Vector2f(randomSize, 2));
	polygon.setPoint(3, sf::Vector2f(randomSize + 1, 1));
	polygon.setPoint(4, sf::Vector2f(randomSize, 0));
	polygon.setPoint(5, sf::Vector2f(1, 0));

	polygon.setPosition(sf::Vector2f(rand() % xSize, rand() % ySize));
	polygon.setRotation(rand() % 360);
	polygon.rotate(rand());
	return polygon;
}

sf::ConvexShape randMovement(sf::ConvexShape polygon) {
	sf::Vector2f point;//.x.y 
	for (int x = 0; x < polygon.getPointCount(); x++) {
		point = polygon.getPoint(x);
		point.x += rand() % 10;
		point.y += rand() % 10;
		polygon.setPoint(x, point);
	}
	return polygon;
}
sf::Color randRGB() {
	return sf::Color(rand()%255, rand() % 255, rand() % 255);
}
class Button {
public:
	bool checkIfPressed(sf::RenderWindow& win) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && inRange(hitbox, sf::Mouse::getPosition(win))) {
			return true;
		}
		else {
			return false;
		}
	}
	
	void setFillColor(sf::Color col) {
		hitbox.setFillColor(col);
	}
	void setOutlineColor(sf::Color col) {
		hitbox.setOutlineColor(col);
	}
	sf::Color getFillColor() {
		return hitbox.getFillColor();
	}
	sf::Color getOutlineColor() {
		return hitbox.getOutlineColor();
	}
	void setTextFillColor(sf::Color col) {
		context.setFillColor(col);
	}
	void setTextOutlineColor(sf::Color col) {
		context.setOutlineColor(col);
	}
	sf::Color getTextFillColor() {
		return context.getFillColor();
	}
	sf::Color getTextOutlineColor() {
		return context.getOutlineColor();
	}
	void draw(sf::RenderWindow& win) {
		win.draw(hitbox);
		win.draw(context);
	}
	void setSize(sf::Vector2f s) {
		hitbox.setSize(s);
	}
	void setTextSize(int s) {
		context.setCharacterSize(s);
	}
	sf::Vector2f getSize() {
		return hitbox.getSize();
	}
	int getTextSize() {
		return context.getCharacterSize();
	}
	void setText(std::string s) {
		context.setString(s);
	}
	std::string getText() {
		return context.getString();
	}
	void setPosition(sf::Vector2f s) {
		hitbox.setPosition(s);
		context.setPosition(s);
	}
	void setTextPosition(sf::Vector2f s) {
		context.setPosition(s);
	}
	void setTextRotation(int r) {
		context.setRotation(r);
	}
	sf::Vector2f getPosition() {
		return hitbox.getPosition();
	}
	sf::Vector2f getTextPosition() {
		return context.getPosition();
	}
	void setFont(std::string f) {
		btnFont.loadFromFile("fonts/" + f + ".ttf");
	}
	void applyFont() {
		context.setFont(btnFont);
	}
	void init(sf::Vector2f pos, std::string title) {
		setFont("font1");
		loadFonts();
		applyFont();
		setTextSize(20);
		setSize(sf::Vector2f(100, 40));
		setPosition(pos);
		setText(title);
		setTextFillColor(sf::Color(100, 0, 0));
		setFillColor(sf::Color(50, 0, 0));
	}
private:
	sf::RectangleShape hitbox;
	sf::Text context;
	sf::Font btnFont;
};
class Slider {
public:
	bool checkIfSlided(sf::RenderWindow& win) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && inRange(slide, sf::Mouse::getPosition(win)) &&
			slide.getPosition().x >= bar.getPosition().x && slide.getPosition().x <= bar.getPosition().x + bar.getSize().x - slide.getSize().x) {
			int m = sf::Mouse::getPosition(win).x;
			sf::Vector2f s;
			s.x = m - (slide.getSize().x/2);
			s.y = slide.getPosition().y;
			slide.setPosition(s.x, s.y);
			updateValue();
			return true;
		}else {
			if (getValue() >= bar.getSize().x - slide.getSize().x) {
				slide.setPosition(bar.getPosition().x + bar.getSize().x - slide.getSize().x, slide.getPosition().y);
			}
			if (getValue() <= 0) {
				slide.setPosition(bar.getPosition().x, slide.getPosition().y);
			}
			updateValue();
			return false;
		}
		return false;
	}
	int getValue() {
		return value;
	}
	void setValue(int f) {
		slide.setPosition(bar.getPosition().x + f, slide.getPosition().y);
		updateValue();
	}
	void updateValue() {
		value =  slide.getPosition().x - bar.getPosition().x;
	}
	void setPostion(sf::Vector2f s) {
		bar.setPosition(s);
		slide.setPosition(sf::Vector2f(s.x + value, (s.y + (bar.getSize().y/ 2) )- slide.getSize().y/2));
		context.setPosition(s.x, s.y + slide.getSize().y + 20);
	}
	sf::Vector2f getPostion() {
		return context.getPosition();
	}
	void setSize(float sz) {
		slide.setSize(sf::Vector2f(10 * sz, 30 * sz ));
		bar.setSize(sf::Vector2f(200 * sz + slide.getSize().x, 10 * sz ));
		context.setCharacterSize(20*sz);
	}
	void draw(sf::RenderWindow& win) {
		win.draw(bar);
		win.draw(slide);
		win.draw(context);
	}
	

	//SLIDE###################################################################################
	
	void setSlideSize(sf::Vector2f s) {
		slide.setSize(s);
	}
	sf::Vector2f getSlideSize() {
		return slide.getSize();
	}
	void setSlidePostion(sf::Vector2f s) {
		slide.setPosition(s);
	}
	sf::Vector2f getSlidePostion() {
		return slide.getPosition();
	}
	void setSlideFillColor(sf::Color col) {
		slide.setFillColor(col);
	}
	sf::Color getSlideFillColor() {
		return slide.getFillColor();
	}
	void setSlideOutlineColor(sf::Color col) {
		slide.setOutlineColor(col);
	}
	sf::Color getSlideOutlineColor() {
		return slide.getOutlineColor();
	}

	//Bar###############################################################################################
	void setBarFillColor(sf::Color col) {
		bar.setFillColor(col);
	}
	sf::Color getBarFillColor() {
		return bar.getFillColor();
	}
	void setBarOutlineColor(sf::Color col) {
		bar.setOutlineColor(col);
	}
	sf::Color getBarOutlineColor() {
		return bar.getOutlineColor();
	}
	void setBarSize(sf::Vector2f s) {
		s.x += slide.getSize().x;
		bar.setSize(s);
	}
	sf::Vector2f getBarSize() {
		return bar.getSize();
	}
	void setBarPostion(sf::Vector2f s) {
		bar.setPosition(s);
	}
	sf::Vector2f getBarPostion() {
		return bar.getPosition();
	}

	//TEXT##########################################################################
	void setText(std::string s) {
		context.setString(s);
	}
	std::string getText() {
		return context.getString();
	}
	void setTextPostion(sf::Vector2f s) {
		context.setPosition(s);
	}
	sf::Vector2f getTextPostion() {
		return context.getPosition();
	}
	void setTextSize(int s) {
		context.setCharacterSize(s);
	}
	int getTextSize() {
		return context.getCharacterSize();
	}
	void setTextFillColor(sf::Color col) {
		context.setFillColor(col);
	}
	sf::Color getTextFillColor() {
		return context.getFillColor();
	}
	void setTextOutlineColor(sf::Color col) {
		context.setOutlineColor(col);
	}
	sf::Color getTextOutlineColor() {
		return context.getOutlineColor();
	}
	void setFont(std::string f) {
		font1.loadFromFile("fonts/" + f + ".ttf");
	}
	void applyFont() {
		context.setFont(font1);
	}

	void init(sf::Vector2f pos, std::string title) {
		context.setFillColor(sf::Color(80, 0, 0));
		bar.setFillColor(sf::Color(80, 0, 0));
		slide.setFillColor(sf::Color(30, 30, 30));
		setSize(1);
		setPostion(pos);
		setText(title);
	}

private:
	int value = 0;
	sf::RectangleShape bar;
	sf::RectangleShape slide;
	sf::Text context;
};
class Background {
public:
	void setColor(sf::Color col) {
		back.setFillColor(col);
	}
	void draw(sf::RenderWindow &rw) {
		back.setPosition(0, 0);
		float sizeX = rw.getSize().x, sizeY = rw.getSize().x;
		back.setSize(sf::Vector2f(sizeX, sizeY));
		rw.draw(back);
	}

private:
	sf::RectangleShape back;
};
class Data {
private:
	float fvalue;
	long long lvalue;
	std::string name;
	sf::Color col;
public:
	Data(float fk, long long lk, std::string nk, sf::Color c) {
		fvalue = fk, lvalue = lk, name = nk, col = c;
	}
	void setFvalue(float f) {
		fvalue = f;
	}
	void setLvalue(long long l) {
		lvalue = l;
	}
	void setName(std::string s) {
		name = s;
	}
	float getFvalue() {
		return fvalue;
	}
	long long getLvalue() {
		return lvalue;
	}
	std::string getName() {
		return name;
	}
	void setColor(sf::Color c) {
		col = c;
	}
	sf::Color getColor() {
		return col;
	}
};
class Graph {
public:
	Graph() {}

	Graph(std::vector<Data> pData) {
		data = pData;
	}
	int getSize() {
		return data.size();
	}
	float getFloatValue(unsigned int place) {
		return data[place].getFvalue();
	}
	sf::Color getColorValue(unsigned int place) {
		return data[place].getColor();
	}
	long long getLongValue(unsigned int place) {
		return data[place].getLvalue();
	}
	std::string getName(unsigned int place) {
		return data[place].getName();
	}
	void setFloatValue(unsigned int place, float f) {
		return data[place].setFvalue(f);
	}
	void setLongValue(unsigned int place, long long l) {
		data[place].setLvalue(l);
	}
	void setName(unsigned int place, std::string n) {
		data[place].setName(n);
	}
	void setColor(unsigned int place, sf::Color c) {
		data[place].setColor(c);
	}
	void addEmptySlots(unsigned int s) {
		Data empty(0.0f, 0, "empty", sf::Color(255, 255, 255));
		for(int i = 0; i < s; i++)
		data.push_back(empty);
	}
	void addSlot(float f, long l, std::string m, sf::Color c) {
		Data empty(f, l, m, c);
		data.push_back(empty);
	}
	void normalizeName(std::string name) {
		for (int i = 0; i < data.size(); i++)
			data[i].setName(name);
	}
	float maxFloatValue() {
		float max = 0;
		for (int i = 0; i < data.size(); i++) {
			if (data[i].getFvalue() > max) {
				max = data[i].getFvalue();
			}
		}
		return max;
	}
	long long maxLongValue() {
		long long max = 0;
		for (int i = 0; i < data.size(); i++) {
			if (data[i].getLvalue() > max) {
				max = data[i].getLvalue();
			}
		}
		return max;
	}
	float minFloatValue() {
		float min = maxFloatValue();
		for (int i = 0; i < data.size(); i++) {
			if (data[i].getFvalue() < min) {
				min = data[i].getFvalue();
			}
		}
		return min;
	}
	long long minLongValue() {
		long long min = maxLongValue();
		for (int i = 0; i < data.size(); i++) {
			if (data[i].getLvalue() < min) {
				min = data[i].getLvalue();
			}
		}
		return min;
	}
	float avgFloatValue() {
		float sum = 0;
		for (int i = 0; i < data.size(); i++) {
			sum += data[i].getFvalue();
		}
		return sum / data.size();
	}
	long long avgLongValue() {
		long long sum = 0;
		for (int i = 0; i < data.size(); i++) {
			sum += data[i].getLvalue();
		}
		return sum / data.size();
	}
	void printGraph() {
		if (data.size() < 2)return;
	for (int c = 0; c < data.size(); c++) {
		std::cout << "V[" << c << "]: Name: " << data[c].getName() <<"\t\tf: " << getFloatValue(c)
			<< "\t\tl: " << getLongValue(c) << "\n";
	}
	std::cout << "\nAverage of all Floats: " << avgFloatValue();
	std::cout << "\nHighest Float: " << maxFloatValue();
	std::cout << "\nLowest  Float: " << minFloatValue();
	std::cout << "\n\nAverage of all Longs: " << avgLongValue();
	std::cout << "\nHighest Long: " << maxLongValue();
	std::cout << "\nLowest  Long: " << minLongValue();
	}

	void displayGraph(sf::Color primary, sf::Color secondary, const std::string title = "Graph") {
		if (data.size() < 2) {
			return;
		}
		window.create(sf::VideoMode(windowSizeX, windowSizeY), title);

		float floatScaleFactor = 1;

		floatScaleFactor = static_cast<float>((sizeY - 10.0f) / maxFloatValue());

		sf::RectangleShape pillar;

		pillar.setOutlineColor(secondary);

		sf::Font font;
		font.loadFromFile("fonts/font1.ttf");
		sf::Text text("", font, 20);
		text.setFillColor(secondary);
		text.setPosition(sf::Vector2f(5, 0));
		Button sort1;
		sort1.init(sf::Vector2f(5, 80), "Sort <");
		sort1.setFillColor(sf::Color(0, 0, 0, 0));
		sort1.setTextFillColor(secondary);
		Button sort2;
		sort2.init(sf::Vector2f(5, 120), "Sort >");
		sort2.setFillColor(sf::Color(0, 0, 0, 0));
		sort2.setTextFillColor(secondary);
		Button sort3;
		sort3.init(sf::Vector2f(5, 160), "RGB <");
		sort3.setFillColor(sf::Color(0, 0, 0, 0));
		sort3.setTextFillColor(secondary);
		Button sort4;
		sort4.init(sf::Vector2f(5, 200), "RGB >");
		sort4.setFillColor(sf::Color(0, 0, 0, 0));
		sort4.setTextFillColor(secondary);

		int pillarsize = sizeX / data.size();

		while (window.isOpen())
		{
			window.clear(primary);
			for (int x = 0; x < data.size(); x++) {
				pillar.setFillColor(data[x].getColor());
				pillar.setSize(sf::Vector2f(pillarsize, -data[x].getFvalue() * floatScaleFactor));
				pillar.setPosition(x * pillarsize + windowSizeX - sizeX, windowSizeY-1);
				window.draw(pillar);
			}
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					sf::Vector2i localPos = sf::Mouse::getPosition(window);
					if (localPos.y > windowSizeY - sizeY && localPos.y < windowSizeY && localPos.x > windowSizeX - sizeX  && localPos.x < windowSizeX-1) {
						int p = abs((localPos.x + sizeX-windowSizeX) / pillarsize);
						text.setString("FValue: " + std::to_string(data.at(p).getFvalue()) + 
									   "\nRGB: " + std::to_string(data.at(p).getColor().r) + ", " + std::to_string(data.at(p).getColor().g) + ", " + std::to_string(data.at(p).getColor().b) +
									   "\nName: " + data.at(p).getName());
						
					}
				}
			}
			if (sort1.checkIfPressed(window)){
				std::vector<Data> dataBuffer{};
				for (int c = 0; c < data.size(); c++) {
					dataBuffer.push_back(data[c]);
				}
				std::stable_sort(dataBuffer.begin(), dataBuffer.end(), [](Data x, Data y){ return x.getFvalue() < y.getFvalue(); });
				data = dataBuffer;
				displayGraph(primary, secondary, "< Sorted Graph");
			}
			if (sort2.checkIfPressed(window)) {
				std::vector<Data> dataBuffer{};
				for (int c = 0; c < data.size(); c++) {
					dataBuffer.push_back(data[c]);
				}
				std::stable_sort(dataBuffer.begin(), dataBuffer.end(), [](Data x, Data y) { return x.getFvalue() > y.getFvalue(); });
				data = dataBuffer;
				displayGraph(primary, secondary, "> Sorted Graph");
			}
			if (sort3.checkIfPressed(window)) {
				std::vector<Data> dataBuffer{};
				for (int c = 0; c < data.size(); c++) {
					dataBuffer.push_back(data[c]);
				}
				std::stable_sort(dataBuffer.begin(), dataBuffer.end(), [](Data x, Data y) { return x.getColor().r + x.getColor().g + x.getColor().b < y.getColor().r + y.getColor().g + y.getColor().b; });
				data = dataBuffer;
				displayGraph(primary, secondary, "RGB < Sorted Graph");
			}
			if (sort4.checkIfPressed(window)) {
				std::vector<Data> dataBuffer{};
				for (int c = 0; c < data.size(); c++) {
					dataBuffer.push_back(data[c]);
				}
				std::stable_sort(dataBuffer.begin(), dataBuffer.end(), [](Data x, Data y) { return x.getColor().r + x.getColor().g + x.getColor().b > y.getColor().r + y.getColor().g + y.getColor().b; });
				data = dataBuffer;
				displayGraph(primary, secondary, "RGB > Sorted Graph");
			}
			

			sort1.draw(window);
			sort2.draw(window);
			sort3.draw(window);
			sort4.draw(window);
			window.draw(text);
			window.display();
		}

	}
private:

	std::vector<Data> data {};

	std::vector<float> bufferFloat{};
	std::vector<long> bufferLong{};
	std::vector<std::string> bufferName{};


	int sizeX = 1000, sizeY = 400, windowSizeY = 500, windowSizeX = 1100;

	std::string stdName;
	
	sf::RenderWindow window;
};