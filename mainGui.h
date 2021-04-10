#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>

#include <iostream>
#include <fstream>

#include "configurations.h"
#include "data.h"
#include "newFile.h"
#include "templates.h"
#include "networking.h"
#include "images.h"

class FileEvent {
private:
    std::string Line1;
    std::string Line2;
    std::string Line3;
    std::string Line4;
    std::string Line5;

public:
    sf::Text eventInterface;
    void registerEvent(std::string Event) {
        Line1 = Line2;
        Line2 = Line3;
        Line3 = Line4;
        Line4 = Line5;
        Line5 = Event;
        std::string tmp = Line1 + "\n" +
                          Line2 + "\n" +
                          Line3 + "\n" +
                          Line4 + "\n" +
                          Line5 + "\n";
        eventInterface.setString(tmp);
    }
};

void openFileBrowser(std::string password) {

    hideConsole();
    std::string UserID;
    std::string PassID;
    std::ifstream input(SAVE);
    if (!input) {
        return;
    }
    std::getline(input, UserID);
    std::getline(input, PassID);

    Database datab;
    datab.setPassword(password);
    datab.openDataBase();
    datab.sortDatabase();
    datab.updateDataBase();
    
    std::vector<sf::CircleShape> particles;
    std::vector<sf::Vector2f> particlePos;
    int particleCount = 2300;
    srand(GetTickCount64());
    for (int x = 0; x < particleCount; x++) {
        sf::CircleShape temp;
        temp.setPointCount(8);
        temp.setRotation(rand() % 360);
        temp.setFillColor(sf::Color(R(visualGreen.r), R(visualGreen.g), R(visualGreen.b), r(20)));
        temp.setRadius(rand() % 10 + 5);
        sf::Vector2f tmp(rand() % 5000 - 2500, rand() % 2500 - 1250);
        particlePos.push_back(tmp);
        temp.setPosition(particlePos[x]);
        particles.push_back(temp);
    }
    
    sf::Vector2f mPosition(0, 0);

    sf::Font font;
    
    if (!font.loadFromFile(FONT)) {
        showConsole();
        error("Font not found. Font must be located under \"assets/fonts/font.ttf\"");
    }

    FileEvent fEvent;
    fEvent.eventInterface.setFillColor(dark);
    fEvent.eventInterface.setFont(font);
    fEvent.eventInterface.setCharacterSize(20);
    fEvent.eventInterface.setLineSpacing(1.05);
    fEvent.eventInterface.setPosition(610, 560);
    fEvent.eventInterface.setStyle(sf::Text::Bold);

    sf::RenderWindow window(sf::VideoMode(1300, 700), "File Browser");

    Reload:

    sf::Text user("userID: " + UserID, font, 25);
    user.setPosition(5, 5);
    user.setFillColor(visualYellow);
    user.setStyle(sf::Text::Bold);
    sf::Text pass("password: " + PassID, font, 25);
    pass.setPosition(5, 45);
    pass.setFillColor(visualYellow);
    pass.setStyle(sf::Text::Bold);
    sf::Text files("files: " + std::to_string(datab.getFileCount()), font, 25);
    files.setPosition(5, 85);
    files.setFillColor(visualYellow);
    files.setStyle(sf::Text::Bold);

    sf::Text newButton("New File", font, 20);
    newButton.setPosition(390, window.getSize().y - 135);
    newButton.setFillColor(visualRed);

    sf::Text saveButton("Save File", font, 20);
    saveButton.setPosition(390, window.getSize().y - 105);
    saveButton.setFillColor(visualRed);
    
    sf::Text clearButton("Clear File", font, 20);
    clearButton.setPosition(390, window.getSize().y - 75);
    clearButton.setFillColor(visualRed);

    sf::Text standardButton("Apply Template", font, 20);
    standardButton.setPosition(390, window.getSize().y - 45);
    standardButton.setFillColor(visualRed);

    sf::RectangleShape upperLeft;
    upperLeft.setPosition(5, 5);
    upperLeft.setSize(sf::Vector2f(370, 140));
    upperLeft.setOutlineColor(darktheme);
    upperLeft.setOutlineThickness(5);
    upperLeft.setFillColor(invisible);

    sf::RectangleShape bottomLeft;
    bottomLeft.setPosition(5, 150);
    bottomLeft.setSize(sf::Vector2f(370, window.getSize().y - 155));
    bottomLeft.setOutlineColor(darktheme);
    bottomLeft.setOutlineThickness(5);
    bottomLeft.setFillColor(invisible); 

    sf::RectangleShape upperRight;
    upperRight.setPosition(380, 5);
    upperRight.setSize(sf::Vector2f(window.getSize().x - 385, window.getSize().y - 10));
    upperRight.setOutlineColor(darktheme);
    upperRight.setOutlineThickness(5);
    upperRight.setFillColor(invisible);

    sf::RectangleShape middleRight;
    middleRight.setPosition(380, window.getSize().y - 145);
    middleRight.setSize(sf::Vector2f(window.getSize().x - 385, 140));
    middleRight.setOutlineColor(darktheme);
    middleRight.setOutlineThickness(5);
    middleRight.setFillColor(invisible);

    sf::RectangleShape bottomRight;
    bottomRight.setPosition(605, window.getSize().y - 145);
    bottomRight.setSize(sf::Vector2f(window.getSize().x - 610, 140));
    bottomRight.setOutlineColor(darktheme);
    bottomRight.setOutlineThickness(5);
    bottomRight.setFillColor(invisible);

    sf::RectangleShape bottomRight2;
    bottomRight2.setPosition(window.getSize().x - 145, window.getSize().y - 145);
    bottomRight2.setSize(sf::Vector2f(140, 140));
    bottomRight2.setOutlineColor(darktheme);
    bottomRight2.setOutlineThickness(5);
    bottomRight2.setFillColor(invisible);

    sf::Texture imgTex;
    imgTex.loadFromFile(IMAG);
    sf::Sprite imgSprite;
    imgSprite.setTexture(imgTex);
    imgSprite.setPosition(window.getSize().x - 138, window.getSize().y - 138);
    imgSprite.setColor(visualRed);

    sf::Texture netTex;
    netTex.loadFromFile(SERV);
    sf::Sprite netSprite;
    netSprite.setTexture(netTex);
    netSprite.setPosition(window.getSize().x - 74, window.getSize().y - 138);
    netSprite.setColor(visualRed);

    sf::Texture sndTex;
    sndTex.loadFromFile(SOND);
    sf::Sprite sndSprite;
    sndSprite.setTexture(sndTex);
    sndSprite.setPosition(window.getSize().x - 138, window.getSize().y - 74);
    sndSprite.setColor(visualRed);

    std::vector<sf::Text> fileTexts;
    
    for (int u = 0; u < datab.getFileCount(); u++) {
        sf::Text tmp(datab.getFilePaths()[u], font, datab.getFileCount()*(-0.3) + 20);
        tmp.setFillColor(visualGreen);
        fileTexts.push_back(tmp);
    }
    for (int u = 0; u < fileTexts.size(); u++) {
        fileTexts[u].setPosition(10, ((datab.getFileCount()* -1 +50) * u) + 150);
    }
    
    std::vector<std::string> editorText;
    editorText.push_back("");
    unsigned int editorIndex = 0;

    sf::Text editorContent("Content", font, 20);
    editorContent.setPosition(390, 15);
    editorContent.setFillColor(visualBlue);

    sf::Text contentHitbox("", font, 20);
    contentHitbox.setPosition(390, 15);
    contentHitbox.setFillColor(invisible);

    fEvent.eventInterface.setFillColor(visualRed);

    std::string currentFile;

    window.setFramerateLimit(60);

    bool shaking = false;
    int shakeIndex = 20;

    sf::RectangleShape caret;
    caret.setSize(sf::Vector2f(2.5, 25));
    caret.setFillColor(visualBlue);

    float caretAlpha = 0;

    sf::Clock caretBlinkTimer;
    sf::Time caretBlinkTime = sf::milliseconds(GetCaretBlinkTime());

    sf::Clock savingTimer;

    while (window.isOpen()) {

        window.clear(background);
        if (caretBlinkTimer.getElapsedTime() >= caretBlinkTime) {
            caretBlinkTimer.restart();
            if (caretAlpha == 0) {
                caretAlpha = 255;
                goto Skip;
            } else {
                caretAlpha = 0;
            }
        }
        Skip:

        if (shaking) {
            sf::View shaken;
            shaken = window.getView();
            if (shakeIndex % 4  == 0 && shakeIndex > 0) {
                shaken.setRotation(-1);
                shakeIndex--;
            }else if (shakeIndex % 4 == 2 && shakeIndex > 0) {
                shaken.setRotation(1);
                shakeIndex--;
            }
            else if (shakeIndex > 0) {
                shaken.setRotation(0);
                shakeIndex--;
            }
            else {
                shaking = false;
                shakeIndex = 20;
                shaken.setRotation(0);
            }
            window.setView(shaken);
        }
        
        sf::Event event;
        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {
                if (savingTimer.getElapsedTime() < sf::seconds(30)) {
                    window.close();
                }else if (MessageBoxA(0, "Are your sure you want to exit? Your files may not be saved", "Unsaved Changes", MB_YESNOCANCEL) == 6) {
                    window.close();
                }
            }
            if (event.type == sf::Event::Resized) {

                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                upperRight.setSize(sf::Vector2f(event.size.width - 385, event.size.height - 10));
                bottomLeft.setSize(sf::Vector2f(370, event.size.height - 155));
                fEvent.eventInterface.setPosition(sf::Vector2f(610, event.size.height - 140));
                newButton.setPosition(390, event.size.height - 135);
                saveButton.setPosition(390, event.size.height - 105);
                clearButton.setPosition(390, event.size.height - 75);
                standardButton.setPosition(390, event.size.height - 45);
                middleRight.setPosition(380, event.size.height - 145);
                middleRight.setSize(sf::Vector2f(event.size.width- 385, 140));
                bottomRight.setPosition(605, event.size.height - 145);
                bottomRight.setSize(sf::Vector2f(event.size.width - 610, 140));
                bottomRight2.setPosition(event.size.width - 145, event.size.height - 145);
                imgSprite.setPosition(event.size.width - 138, event.size.height - 138);
                netSprite.setPosition(window.getSize().x - 74, window.getSize().y - 138);
                sndSprite.setPosition(window.getSize().x - 138, window.getSize().y - 74);

                for (int u = 0; u < fileTexts.size(); u++) {
                    fileTexts[u].setPosition(10, ((datab.getFileCount() * -1 + 50) * u) + 150);
                }

                window.setView(sf::View(visibleArea));
            }
            if (event.type == sf::Event::MouseButtonPressed)
                for (int g = 0; g < fileTexts.size(); g++)
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        if (fileTexts[g].getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {

                            editorText = datab.openFileFromDatabase(fileTexts[g].getString());
                            currentFile = fileTexts[g].getString();
                            std::string tmp = "Opened File: " + fileTexts[g].getString();
                            fEvent.registerEvent(tmp);
                            editorIndex = 0;
                        }
                    } else {
                        if (fileTexts[g].getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y) && fileTexts[g].getStyle() != sf::Text::StrikeThrough) {
                            DeleteFile:
                            if (MessageBoxA(0, "Are your sure you want to delete this file?", "Delete File?", MB_YESNOCANCEL) == 6) {
                            std::string tmp = "Deleted File: " + fileTexts[g].getString();
                            datab.removeFileFromDatabase(fileTexts[g].getString());
                            shaking = true;
                            fEvent.registerEvent(tmp);
                            fileTexts[g].setStyle(fileTexts[g].StrikeThrough);
                            }
                            else {
                                std::string tmp = "File " + fileTexts[g].getString() + " was not deleted";
                                fEvent.registerEvent(tmp);
                            }
                        }
                    }

            if (event.type == sf::Event::KeyPressed) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                        if (editorIndex + 1 >= editorText.size()) {
                            editorText.push_back("");
                            editorIndex++;
                        }
                        else {
                            editorIndex++;
                        }
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                    if (!editorIndex <= 0) {
                        editorIndex--;
                    }
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                        if (editorIndex + 1 >= editorText.size()) {
                            editorText.push_back("");
                            editorIndex++;
                        }
                        else {
                            editorIndex++;
                        }
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) && sf::Keyboard::isKeyPressed(sf::Keyboard::Tab)) {
                    if (editorText[editorIndex].size() >= 5) {
                        if (editorText[editorIndex].begin() <= editorText[editorIndex].end())
                            editorText[editorIndex].replace(editorText[editorIndex].end() - 4, editorText[editorIndex].end(), "");
                    }
                    //TODO
                    continue;
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab)) {
                    editorText[editorIndex] += "\t";
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                    sf::sleep(sf::seconds(1));
                    //TODO
                    goto SaveFile;
                }
            }
            if (event.type == sf::Event::TextEntered) {
                if (event.key.code == 8) {
                    if (editorText[editorIndex].size() >= 1 && editorText[editorIndex][0] != '\0') {
                    if(editorText[editorIndex].begin() <= editorText[editorIndex].end())
                        editorText[editorIndex].replace(editorText[editorIndex].end() - 1, editorText[editorIndex].end(), "");
                    }
                    else {
                        if (editorIndex > 1)
                            editorIndex--;
                        else editorIndex = 0;
                    }
                }
                else {
                    if (editorIndex > editorText.size()) {
                    editorText.push_back("");
                    editorText[editorIndex] += event.key.code;
                    }
                    else {
                    editorText[editorIndex] += event.key.code;
                    }
                }
            }

            if (newButton.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    std::string fName = inputBox("Enter Filename: ", "Name:");
                    if (fName.size() < 3) {
                        MessageBox(0, L"No Filename given.", L"Illegal Filename", MB_OK);
                        goto Reload;
                    }
                    for (int j = 0; j < fName.size(); j++) {
                        if (fName[j] == '\\' || fName[j] == '?' || fName[j] == '=' || fName[j] == '/' || fName[j] == ':' || fName[j] == '*' || fName[j] == '|' || fName[j] == '\"') {
                            MessageBox(0, L"File may not contain any of these characters:\n / \\ : ? * | \" ", L"Illegal Character", MB_OK);
                            goto Reload;
                        }
                    }
                    datab.addFileToDatabase(fName);
                    std::string tmp = "Created new File: " + fName;
                    currentFile = fName;
                    fEvent.registerEvent(tmp);
                    goto Reload;
                }
                newButton.setStyle(sf::Text::Bold);
            }
            else newButton.setStyle(sf::Text::Regular);

            if (saveButton.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                SaveFile:
                    savingTimer.restart();
                    datab.setFileContent(editorText);
                    datab.saveFileInDatabase(currentFile);
                    fEvent.registerEvent("Saved File");
                }
                saveButton.setStyle(sf::Text::Bold);
            }
            else saveButton.setStyle(sf::Text::Regular);

            if (clearButton.getGlobalBounds().contains((float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y)) {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    for (int c = 0; c < editorText.size(); c++) {
                        editorText[c] = "";
                    }
                    shaking = true;
                    editorIndex = 0;
                    fEvent.registerEvent("Cleared File");
                }
                clearButton.setStyle(sf::Text::Bold);
            }
            else clearButton.setStyle(sf::Text::Regular);

            if (standardButton.getGlobalBounds().contains((float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y)) {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    editorText = datab.applyTemplate();
                    editorIndex = 0;
                    fEvent.registerEvent("Applied Template");
                }
                standardButton.setStyle(sf::Text::Bold);
            }
            else standardButton.setStyle(sf::Text::Regular);

            if (netSprite.getGlobalBounds().contains((float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y)) {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    networkInterface();
            }

            if (imgSprite.getGlobalBounds().contains((float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y)) {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    imageInterface();
            }
        }

        contentHitbox.setString(editorText[editorIndex]);//TODO
        caret.setPosition(sf::Vector2f(contentHitbox.getGlobalBounds().left + contentHitbox.getGlobalBounds().width, 24.1*editorIndex + 15));
        caret.setFillColor(sf::Color(visualBlue.r, visualBlue.g, visualBlue.b, caretAlpha));

        mPosition = {(sf::Mouse::getPosition().x / 40) - 30.0f, (sf::Mouse::getPosition().y / 40) - 30.0f};

        for (int x = 0; x < particleCount; x++) {
            particles[x].setPosition(particlePos[x].x + mPosition.x, particlePos[x].y + mPosition.y);
        }
        
        std::string temp = "";
        for (int p = 0; p < editorText.size(); p++) {
            temp += editorText[p];
            temp += "\n";
        }
        editorContent.setString(temp);


        for (int x = 0; x < particleCount; x++) {
            window.draw(particles[x]);
        }
        window.draw(upperLeft);
        window.draw(bottomLeft);
        window.draw(upperRight);
        window.draw(middleRight);
        window.draw(bottomRight);
        window.draw(bottomRight2);
        window.draw(user);
        window.draw(pass);
        window.draw(files);
        for (int f = 0; f < fileTexts.size(); f++) {
            window.draw(fileTexts[f]);
        }
        window.draw(newButton);
        window.draw(saveButton);
        window.draw(clearButton);
        window.draw(standardButton);
        window.draw(imgSprite);
        window.draw(netSprite);
        window.draw(sndSprite);
        window.draw(fEvent.eventInterface);
        window.draw(editorContent);
        window.draw(caret);
        window.display();
    }
}