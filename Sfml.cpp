#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>

#include <iostream>

#include "startup.h"
#include "mainGui.h"
#include "data.h"
#include "keygen.h"
#include "sfml-extension/gui.h"
#include "templates.h"
#include "captcha.h"
#include "networking.h"

int main()
{
    /*
    if (captcha() == 1) {
        if (login() == 1)openFileBrowser();
        else {
            return -1;
        }
    }
    */
    //else return -1;
    //networkInterface();
    //showConsole();
    dictionary d;

    std::string entschl = "hilfe_wAruM_GEHT_eS";
    //std::string verschl = d.encrypt("abcd", entschl);
    //std::cout << verschl << "\n";
    //std::cout << d.decrypt("abcd", verschl);
    
    /*
    std::string str = "WZLQMOPGSVPDMQRXLFPIXZBZXFPCZESXYDLPWTTEDVYDQJEMQMOPLRVBFOZHTPCZIOKQQMLTHPISYXMWCFYNGIPHTMFDMTEFYMQPVYXPETXUQHDSYZKSPNQPFCBMXUPQQRJRTGFFTMEIOFHPDVMLQGIPHGREPCZQBWUXWHCIEWFEYGISFHSMODFMREVUYOPYHFIFCXMWULYSPJNBQFSZNZMDSNYIICMOLBQZQR";
    
    for (int z = 0; z < str.size(); z++) {
        for (int p = 0; p < 6; p++) {

        }
    }
*/
    return 0;
}
/*    
sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    
    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.display();
        
    }
    return EXIT_SUCCESS;
*/