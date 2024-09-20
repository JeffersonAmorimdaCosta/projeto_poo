#ifndef GAME_HPP
#define GAME_HPP

#include "../ASCII_Engine/Sprite.hpp"
#include "FaseDeBatalha.hpp"

#include <iostream>
#include <string>

using std::cout, std::endl;

class Game {

    public:
        Game() { }
        ~Game() { }

        static void run() {
            SpriteBuffer screen(300, 83);

            FaseDeBatalha fase1("fase1", Sprite("rsc/background/background1.img", COR::CINZA));

            screen.clear();
            fase1.init();


            int ret1 = fase1.run(screen);
            system("clear");

            if (ret1 == Fase::LEVEL_COMPLETE)
                cout << "Vitoria!" << endl;

            else if (ret1 == Fase::END_GAME)
                cout << "Voce saiu do jogo." << endl;
            
            else
                cout << "Derrota!" << endl;
        }
};

#endif