#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>

#include <iostream>
#include <fstream>

#include "configurations.h"
#include "data.h"
#include "messages.h"

class chat {
public:
    sf::Text text;
    std::vector<std::string> lines;
    int linecount = 20;
    int width = 200;

    void addLine(std::string s) {

            if (lines.size() < linecount) {
                lines.push_back(s);
            }
            else {
                for (int x = 1; x < lines.size(); x++) {
                    lines[x - 1] = lines[x];
                }
                lines.pop_back();
                lines.push_back(s);
            }
    }
    void setLineCount(int z) {
        linecount = z;
    }
    sf::Text getText() {
        std::string tmp;
        for (int y = 0; y < lines.size(); y++) {
            tmp += lines[y] + "\n";
        }
        text.setString(tmp);
        return text;
    }
};

struct Type {
    bool rce = true;
	bool isServer;
	bool isClient;
	sf::IpAddress adress;
	unsigned short port;
};
class Networker {
public: 	
    sf::TcpListener tcpListener;
    sf::TcpSocket tcpServer;
	sf::TcpSocket tcpSocket;
    
    sf::IpAddress target;
	unsigned short targetPort = 55000;

	unsigned short myPort = 55000;

	sf::Packet send;
	sf::Packet receive;

    sf::Socket::Status status = sf::Socket::Status::NotReady;

	void setTargetPort(unsigned short p) {
		targetPort = p;
	}
	unsigned short getTargetPort() {
		return targetPort;
	}
	void setMyPort(unsigned short p) {
		myPort = p;
	}
	unsigned short getMyPort() {
		return myPort;
	}
    void setIp(sf::IpAddress ip) {
        target = ip;
    }
    sf::IpAddress getIp() {
        return target;
    }
    sf::Socket::Status connect() {
        status = tcpSocket.connect(target, targetPort);
        return status;
    }
    sf::Socket::Status connect(sf::Time timeout) {
        status = tcpSocket.connect(target, targetPort, timeout);
        return status;
    }
    void disconnect() {
        tcpSocket.disconnect();
    }
    sf::Socket::Status listen(){
        status = tcpListener.listen(myPort);
        return status;
    }
    sf::Socket::Status accept() {
        status = tcpListener.accept(tcpServer);
        return status;
    }
    sf::Socket::Status sendAsClient(sf::Packet p) {
        send = p;
        return tcpSocket.send(send);
    }
    sf::Socket::Status sendAsServer(sf::Packet p) {
        send = p;
        return tcpServer.send(send);
    }
    sf::Socket::Status receiveAsClient() {
        status = tcpSocket.receive(receive);
        return status;
    }
    sf::Socket::Status receiveAsServer() {
        status = tcpServer.receive(receive);
        return status;
    }
    sf::IpAddress recvInternIp() {
        return tcpServer.getRemoteAddress().getLocalAddress();
    }
    sf::IpAddress recvExternIp() {
        return tcpServer.getRemoteAddress().getPublicAddress();
    }

};

Type networkManager() {

    Type ret;

    bool step2 = false;

    sf::Font font;
    font.loadFromFile(FONT);

    std::vector<sf::CircleShape> particles;
    std::vector<sf::Vector2f> particlePos;
    int particleCount = 1500;
    srand(GetTickCount64());
    for (int x = 0; x < particleCount; x++) {
        sf::CircleShape temp;
        temp.setPointCount(8);
        temp.setRotation(rand() % 360);
        temp.setFillColor(sf::Color(R(173), R(83), R(83), r(20)));
        temp.setRadius(rand() % 10 + 5);
        sf::Vector2f tmp(rand() % 10000 - 5000, rand() % 5000 - 2500);
        particlePos.push_back(tmp);
        temp.setPosition(particlePos[x]);
        particles.push_back(temp);
    }

    sf::Vector2f mPosition(0, 0);

    sf::RenderWindow window(sf::VideoMode(1000, 800), "Network Manager:");

    sf::Text choose("Choose\nTemplate:", font, 45);
    choose.setPosition(window.getSize().x / 18, window.getSize().y / 90);
    choose.setFillColor(visualYellow);

    sf::Text clientText("Client", font, 30);
    clientText.setPosition(window.getSize().x / 9 * 4, window.getSize().y / 9 * 2);
    clientText.setFillColor(visualBlue);
    sf::Text noteDescription("Creates a Tcp Client", font, 15);
    noteDescription.setPosition(window.getSize().x / 9 * 4, window.getSize().y / 18 * 5);
    noteDescription.setFillColor(visualGreen);

    sf::Text serverText("Server", font, 30);
    serverText.setPosition(window.getSize().x / 9 * 4, window.getSize().y / 9 * 3);
    serverText.setFillColor(visualBlue);
    sf::Text profileDescription("Creates a Tcp Server", font, 15);
    profileDescription.setPosition(window.getSize().x / 9 * 4, window.getSize().y / 18 * 7);
    profileDescription.setFillColor(visualGreen);

    sf::Text RCE("RCE", font, 30);
    RCE.setPosition(window.getSize().x / 9 * 2, window.getSize().y / 9 * 7);
    RCE.setFillColor(dark);

    sf::CircleShape inner(25);
    inner.setPointCount(4);
    inner.setRotation(45);
    inner.setPosition(window.getSize().x / 18 * 9, window.getSize().y / 18 * 13.6);
    inner.setFillColor(visualGreen);
    sf::CircleShape outer(25);
    outer.setPointCount(4);
    outer.setRotation(45);
    outer.setPosition(window.getSize().x / 18 * 9, window.getSize().y / 18 * 13.6);
    outer.setFillColor(invisible);
    outer.setOutlineThickness(5);
    outer.setOutlineColor(visualYellow);

    sf::Texture templateTex;
    templateTex.loadFromFile(TEMP);
    sf::Sprite templateSprite;
    templateSprite.setTexture(templateTex);
    templateSprite.setPosition(window.getSize().x / 18 * 2, window.getSize().y / 9 * 2);
    templateSprite.setScale(2, 2);

    sf::Texture clientTexture;
    clientTexture.loadFromFile(CLIE);
    sf::Sprite clientSprite;
    clientSprite.setTexture(clientTexture);
    clientSprite.setPosition(window.getSize().x / 9 * 3, window.getSize().y / 9 * 2);

    sf::Texture serverTexture;
    serverTexture.loadFromFile(SERV);
    sf::Sprite serverSprite;
    serverSprite.setTexture(serverTexture);
    serverSprite.setPosition(window.getSize().x / 9 * 3, window.getSize().y / 9 * 3);

    sf::Text ip("Ip Adress: ", font, 30);
    ip.setPosition(window.getSize().x / 9 * 2, window.getSize().y / 9 * 3);
    ip.setFillColor(bright);
    ip.setStyle(sf::Text::Italic);
    sf::Text port("Port: ", font, 30);
    port.setPosition(window.getSize().x / 9 * 2, window.getSize().y / 9 * 5);
    port.setFillColor(dark);
    port.setStyle(sf::Text::Italic);

    bool ipTarget = true;
    bool portTarget = false;

    std::string ipAdressString = "localhost";
    std::string portString = "53001";

    sf::Text ipInput(ipAdressString, font, 30);
    ipInput.setPosition(window.getSize().x / 9 * 4, window.getSize().y / 9 * 3);
    ipInput.setFillColor(visualGreen);
    sf::Text portInput(portString, font, 30);
    portInput.setPosition(window.getSize().x / 9 * 4, window.getSize().y / 9 * 5);
    portInput.setFillColor(visualYellow);

    while (window.isOpen())
    {
        window.clear(background);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                ret.isClient = true;
                ret.isServer = false;
                ret.adress = sf::IpAddress::LocalHost;
                ret.port = 53001;
                return ret;
            }
            if (event.type == sf::Event::Resized)
            {
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                choose.setPosition(window.getSize().x / 18, window.getSize().y / 90);

                clientText.setPosition(window.getSize().x / 9 * 4, window.getSize().y / 9 * 2);
                noteDescription.setPosition(window.getSize().x / 9 * 4, window.getSize().y / 18 * 5);

                serverText.setPosition(window.getSize().x / 9 * 4, window.getSize().y / 9 * 3);
                profileDescription.setPosition(window.getSize().x / 9 * 4, window.getSize().y / 18 * 7);

                templateSprite.setPosition(window.getSize().x / 18 * 2, window.getSize().y / 9 * 2);
                clientSprite.setPosition(window.getSize().x / 9 * 3, window.getSize().y / 9 * 2);
                serverSprite.setPosition(window.getSize().x / 9 * 3, window.getSize().y / 9 * 3);

                ip.setPosition(window.getSize().x / 9 * 2, window.getSize().y / 9 * 3);
                port.setPosition(window.getSize().x / 9 * 2, window.getSize().y / 9 * 5);

                ipInput.setPosition(window.getSize().x / 9 * 4, window.getSize().y / 9 * 3);
                portInput.setPosition(window.getSize().x / 9 * 4, window.getSize().y / 9 * 5);

                RCE.setPosition(window.getSize().x / 9 * 2, window.getSize().y / 9 * 7);
                inner.setPosition(window.getSize().x / 18 * 9, window.getSize().y / 18 * 13.6);
                outer.setPosition(window.getSize().x / 18 * 9, window.getSize().y / 18 * 13.6);

                window.setView(sf::View(visibleArea));
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if (!step2) {
                    if (clientText.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
                        ret.isClient = true;
                        ret.isServer = false;
                        step2 = true;
                    }
                    if (serverText.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
                        ret.isServer = true;
                        ret.isClient = false;
                        step2 = true;
                    }
                } else {
                    if (ip.getGlobalBounds().contains({ (float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y })) {
                        ipTarget = true, portTarget = false;
                        
                    }
                    if (port.getGlobalBounds().contains({ (float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y })) {
                        ipTarget = false, portTarget = true;
                    }
                    if (inner.getGlobalBounds().contains({ (float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y })) {
                        if (ret.rce) {
                            ret.rce = false;
                            continue;
                        }
                        else {
                            ret.rce = true;
                        }
                    }
                }
            }
            if (event.type == sf::Event::TextEntered)
            {
                if (ipTarget) {
                    if (event.key.code == 8) {
                        if (ipAdressString.size() >= 1) {
                            ipAdressString.replace(ipAdressString.end() - 1, ipAdressString.end(), "");
                            ipInput.setString(ipAdressString);
                        }
                    }
                    else if (event.key.code == 13) {
                        ipTarget = false;
                        portTarget = true;
                    }
                    else {
                        ipAdressString += event.text.unicode;
                        ipInput.setString(ipAdressString);
                    }

                }
                else if (portTarget) {
                    if (event.key.code == 8) {
                        if (portString.size() >= 1) {
                            portString.replace(portString.end() - 1, portString.end(), "");
                            std::string p = portInput.getString();
                            p.replace(p.end() - 1, p.end(), "");
                            portInput.setString(p);
                        }
                    }
                    else if (event.key.code == 13) {
                        if (portString != "\0" && ipAdressString != "\0") {
                        ret.adress = ipAdressString;
                        ret.port = std::stoi(portString);
                        }
                        else {
                            ret.adress = sf::IpAddress::LocalHost;
                            ret.port = 55001;
                        }
                        return ret;
                    }
                    else {
                        portString += event.text.unicode;
                        portInput.setString(portString);
                    }
                }
            }
        }
        mPosition = { (sf::Mouse::getPosition().x / 40) - 30.0f, (sf::Mouse::getPosition().y / 40) - 30.0f };

        if (ipTarget) {
            ip.setFillColor(bright);
            port.setFillColor(dark);
        }else if (!ipTarget) {
            ip.setFillColor(dark);
            port.setFillColor(bright);
        }
        for (int x = 0; x < particleCount; x++) {
            particles[x].setPosition(particlePos[x].x + mPosition.x, particlePos[x].y + mPosition.y);
        }

        for (int x = 0; x < particleCount; x++) {
            window.draw(particles[x]);
        }
        if (!step2) {
        window.draw(choose);

        window.draw(clientText);
        window.draw(noteDescription);

        window.draw(serverText);
        window.draw(profileDescription);

        //window.draw(udpClient);
        //window.draw(contactDescription);

        window.draw(templateSprite);
        window.draw(clientSprite);
        window.draw(serverSprite);
        //window.draw(contactSprite);
        }
        else {
            window.draw(ip);
            window.draw(port);
            window.draw(ipInput);
            window.draw(portInput);
            window.draw(RCE);
            if(ret.rce)
            window.draw(inner);
            window.draw(outer);
        }
        
        window.display();
    }
    return ret;

}

void networkInterface() {

	showConsole();

    sf::Clock time;

    Type networkType = networkManager();

    Networker network;
    network.setMyPort(networkType.port);
    network.setTargetPort(networkType.port);
    network.setIp(networkType.adress);

    sf::IpAddress myInternIp = sf::IpAddress::getLocalAddress();
    sf::IpAddress myExternIp = sf::IpAddress::getPublicAddress();

    sf::IpAddress partnerInternIp;
    sf::IpAddress partnerExternIp;

    sf::Packet recv;
    sf::Socket::Status result = sf::Socket::NotReady;

    bool isClient = networkType.isClient;
    bool isReceiving = false;
    bool isChat = false;
    bool isConnected = false; 
    bool isRCEon = networkType.rce;

	sf::Font font;
	font.loadFromFile(FONT);

    std::vector<sf::CircleShape> particles;
    std::vector<sf::Vector2f> particlePos;
    int particleCount = 2300;
    srand(GetTickCount64());
    for (int x = 0; x < particleCount; x++) {
        sf::CircleShape temp;
        temp.setPointCount(rand()%2+4);
        temp.setRotation(rand() % 360);
        temp.setFillColor(sf::Color(R(173), R(83), R(83), 3));
        temp.setRadius(rand() % 200 + 50);
        sf::Vector2f tmp(rand() % 5000 - 2500, rand() % 2500 - 1250);
        particlePos.push_back(tmp);
        temp.setPosition(particlePos[x]);
        particles.push_back(temp);
    }

	sf::RenderWindow window(sf::VideoMode(1300, 700), "Network Browser");

    sf::Text chatTitle("Chat:", font, 20);
    chatTitle.setPosition(655, 10);
    chatTitle.setFillColor(visualBlue);

    sf::RectangleShape chatRect;
    chatRect.setPosition(650, 5);
    chatRect.setSize(sf::Vector2f(645, 690));
    chatRect.setOutlineColor(darktheme);
    chatRect.setOutlineThickness(5);
    chatRect.setFillColor(invisible);

    sf::RectangleShape statusRect;
    statusRect.setPosition(5, 5);
    statusRect.setSize(sf::Vector2f(640, 300));
    statusRect.setOutlineColor(darktheme);
    statusRect.setOutlineThickness(5);
    statusRect.setFillColor(invisible);

    sf::RectangleShape actionsRect;
    actionsRect.setPosition(5, 310);
    actionsRect.setSize(sf::Vector2f(640, window.getSize().y - 315));
    actionsRect.setOutlineColor(darktheme);
    actionsRect.setOutlineThickness(5);
    actionsRect.setFillColor(invisible);

    sf::Text disButton("Dis", font, 30);
    disButton.setFillColor(visualRed);
    disButton.setPosition(445, 265);

    sf::Text connectButton("connect", font, 30);
    connectButton.setFillColor(visualGreen);
    connectButton.setPosition(500, 265);

    sf::Text StatusInformation("", font, 20);
    StatusInformation.setPosition(5, 5);
    StatusInformation.setFillColor(visualYellow);

    std::string chatMessage = "";
    sf::Text chatText("Enter Message", font, 20);
    chatText.setPosition(655, window.getSize().y - 30);

    chat c;
    c.text.setFont(font);
    c.text.setPosition(655, 35);
    c.text.setCharacterSize(15);
    c.text.setFillColor(visualRed);
    c.setLineCount(35);

	window.setFramerateLimit(30);

    if (isClient) {
        for (int x = 0; x < particleCount; x++)
            particles[x].setFillColor(sf::Color(R(78), R(201), R(176), 3));
        network.tcpSocket.setBlocking(false);
        while (window.isOpen())
        {
            if (isConnected) {
                sf::Socket::Status st = network.receiveAsClient();
                if (st == sf::Socket::Done) {
                    recv = network.receive;
                    c.addLine(processMessage(recv, networkType.rce));
                } else if (st == sf::Socket::Error) {
                    isConnected = false;
                    c.addLine("Error occured. Connection closed.");
                }
            }
            window.clear(background);
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
                if (event.type == sf::Event::Resized) {
                    sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                    window.setView(sf::View(visibleArea));
                    chatRect.setSize(sf::Vector2f(event.size.width - 655, event.size.height - 10));
                    actionsRect.setSize(sf::Vector2f(640, event.size.height - 315));
                    chatText.setPosition(655, window.getSize().y - 30);
                }
                if (event.type == sf::Event::MouseButtonPressed) {
                    if (chatRect.getGlobalBounds().contains({ (float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y })) {
                        isChat = true;
                    }
                    else isChat = false;
                    if (connectButton.getGlobalBounds().contains({ (float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y })) {
                        c.addLine("Connecting...");
                        network.tcpSocket.setBlocking(true);
                        sf::Socket::Status status = network.connect(sf::seconds(5));
                        if (status < 1) {
                            isConnected = true;
                            c.addLine("Connected!");
                            network.tcpSocket.setBlocking(false);
                        }
                        else {
                            isConnected = false;
                            c.addLine("Connection failed.");
                        }
                    }
                    if (disButton.getGlobalBounds().contains({ (float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y })) {
                        network.disconnect();
                        isConnected = false;
                        c.addLine("Disconnected.");
                    }
                }
                if (event.type == sf::Event::TextEntered) {
                    if (isChat) {
                        if (event.key.code == 8) {
                            if (chatMessage.size() >= 1) {
                                chatMessage.replace(chatMessage.end() - 1, chatMessage.end(), "");
                                chatText.setString(chatMessage);
                            }
                        }
                        else if (event.key.code == 13) {
                            c.width = 200;
                            c.addLine(("[YOU]: " + chatMessage));
                            sf::Packet p;
                            p << chatMessage;
                            network.sendAsClient(p);

                            chatMessage = "";
                            chatText.setString("Enter Message");
                        }
                        else {
                            chatMessage += event.text.unicode;
                            chatText.setString(chatMessage);
                        }
                    }
                }
            }
            std::string status = "My Information:\n\nExternal IP: " + myExternIp.toString() + "\nInternal IP: " + myInternIp.toString() +
                "\nConnection: " + std::to_string(isConnected) + "\n\nServer Information:\n\nExternal IP: " +
                network.getIp().getPublicAddress().toString() + "\nInternal IP: " + network.getIp().getLocalAddress().toString() + "\n" + 
                "Port: " + std::to_string(network.getTargetPort());
            StatusInformation.setString(status);

            for (int x = 0; x < particleCount; x++)
                window.draw(particles[x]);
            window.draw(statusRect);
            window.draw(chatRect);
            window.draw(actionsRect);
            window.draw(chatTitle);
            window.draw(chatText);
            window.draw(c.getText());
            window.draw(StatusInformation);
            window.draw(connectButton);
            window.draw(disButton);
            window.display();
        }
    }
    else {
        c.addLine("Waiting for a client Connecting...");
        network.tcpListener.setBlocking(false);
        network.tcpServer.setBlocking(false);

        network.listen();
        while (window.isOpen()) {

            if (!isConnected && network.accept() == sf::Socket::Done) {
            partnerExternIp = network.tcpServer.getRemoteAddress().getPublicAddress();
            partnerInternIp = network.tcpServer.getRemoteAddress().getLocalAddress();
            c.addLine(("New Client connected: " + partnerExternIp.toString()));
            isConnected = true;
            }
            if (isConnected) {
                sf::Socket::Status st = network.receiveAsServer();
                if (st == sf::Socket::Done) {
                    recv = network.receive;
                    c.addLine(processMessage(recv, networkType.rce));
                }
                else if (st == sf::Socket::Disconnected) {
                    isConnected = false;
                    c.addLine("Client disconnected");
                }
                else if (st == sf::Socket::Error) {
                    isConnected = false;
                    c.addLine("Error occured. Connection closed.");
                }
            }
            window.clear(background);
            sf::Event event;
            while (window.pollEvent(event))
            {
                
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
                if (event.type == sf::Event::Resized) {
                    sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                    window.setView(sf::View(visibleArea));
                    chatRect.setSize(sf::Vector2f(event.size.width - 655, event.size.height - 10));
                    actionsRect.setSize(sf::Vector2f(640, event.size.height - 315));
                    chatText.setPosition(655, window.getSize().y - 30);
                }
                if (event.type == sf::Event::MouseButtonPressed) {
                    if (chatRect.getGlobalBounds().contains({ (float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y })) {
                        isChat = true;
                    }
                    else isChat = false;
                }
                if (event.type == sf::Event::TextEntered) {
                    if (isChat) {
                        if (event.key.code == 8) {
                            if (chatMessage.size() >= 1) {
                                chatMessage.replace(chatMessage.end() - 1, chatMessage.end(), "");
                                chatText.setString(chatMessage);
                            }
                        }
                        else if (event.key.code == 13) {
                            c.width = 200;
                            c.addLine(("[YOU]: " + chatMessage));
                            sf::Packet p;
                            p << chatMessage;
                            network.sendAsServer(p);
                            chatMessage = "";
                            chatText.setString("Enter Message");
                        }
                        else {
                            chatMessage += event.text.unicode;
                            chatText.setString(chatMessage);
                        }
                    }
                }
            }
            std::string status = "External IP: " + myExternIp.toString() + "\nInternal IP: " + myInternIp.toString() +
                  "\nServer Port: " + std::to_string(network.getMyPort()) + "\nConnection: " + std::to_string(isConnected) + 
                    "\n\nClient Information:\n" +
                partnerExternIp.toString() + "\n" + partnerInternIp.toString() + "\n";
            StatusInformation.setString(status);

            for (int x = 0; x < particleCount; x++)
                window.draw(particles[x]);

            window.draw(statusRect);
            window.draw(chatRect);
            window.draw(actionsRect);
            window.draw(chatTitle);
            window.draw(chatText);
            window.draw(c.getText());
            window.draw(StatusInformation);
            window.display();
        }
    }
}