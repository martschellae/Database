#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>

#include <iostream>
#include <string>

class TCPclient {
public:
    sf::IpAddress server;
    sf::TcpSocket socket;

    bool connecttoadress(sf::IpAddress ip, int port) {
        server = ip;
        if (socket.connect(server, port) != sf::Socket::Done)
            return -1;
        std::cout << "Connected to server " << server << std::endl;
    }

    bool send(std::string msg) {
        if (socket.send(msg.c_str(), msg.size()) != sf::Socket::Done)
            return -1;
        std::cout << "Message sent to the server: \"" << msg << "\"" << std::endl;
    }

    bool receive(char recv[128]) {
        char in[128];
        std::size_t received;
        if (socket.receive(in, sizeof(in), received) != sf::Socket::Done)
            return -1;
        std::cout << "Message received from the server: \"" << in << "\"" << std::endl;
        recv = in;
    }

};
