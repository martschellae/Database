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
    //std::string verschl = "The chain of events that led to the creation of Tyndale's New Testament possibly began in 1522, when Tyndale acquired a copy of the German New Testament. Tyndale began a translation into English using a Greek text compiled by Erasmus from several manuscripts older than the Latin Vulgate of Jerome, the only translation authorized by the Roman Catholic Church.[3][4]        Tyndale made his purpose known to Bishop of London Cuthbert Tunstall but was refused permission to produce this heretical text.Thwarted in England, Tyndale moved to the continent.[5] A partial edition was put into print in 1525 in Cologne of which there is only one fragment left in the British Library.[6] But before the work could be completed, Tyndale was betrayed to the authorities[7] and forced to flee to Worms, where the first complete edition of his New Testament was published in 1526 of which there are only 3 extant copies left.These can be found in the collections of St Paul's Cathedral, London,[8] the British Library,[9] and the Württembergische Landesbibliothek[10] in Stuttgart.[11] Two revised versions were later published in 1534 and 1536, both personally revised by Tyndale. After his death in 1536, Tyndales works were revised and reprinted numerous times[12] and are reflected in more modern versions of the Bible, including, perhaps most famously, the King James Version.        Tyndale's translation of the Pentateuch was published at Antwerp by Merten de Keyser in 1530.[13] His English version of the Book of Jonah was published the following year. This was followed by his revised version of the Book of Genesis in 1534. Tyndale translated additional Old Testament books including Joshua, Judges, First and Second Samuel, First and Second Kings and First and Second Chronicles, but they were not published and have not survived in their original forms.[14] When Tyndale was martyred, these works came to be in the possession of one of his associates, John Rogers. These translations were influential in the creation of the Matthew Bible which was published in 1537.[14]Tyndale used numerous sources when carrying out his translations of both the New and Old Testaments.When translating the New Testament, he referred to the third edition(1522) of Erasmus's Greek New Testament, often referred to as the Received Text. Tyndale also used Erasmus's Latin New Testament, as well as Luther's German version and the Vulgate. Scholars believe that Tyndale stayed away from using Wycliffe's Bible as a source because he did not want his English to reflect that which was used prior to the Renaissance.[15] The sources Tyndale used for his translation of the Pentateuch however are not known for sure.Scholars believe that Tyndale used either the Hebrew Pentateuch or the Polyglot Bible and may have referred to the Septuagint.It is suspected that his other Old Testament works were translated directly from a copy of the Hebrew Bible.He also made use of Greek and Hebrew grammars.[14] ";
    openFileBrowser("password");
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