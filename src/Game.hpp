#ifndef GAME_HPP
#define GAME_HPP

#include "../ASCII_Engine/Sprite.hpp"
#include "FaseDeBatalha.hpp"

#include <iostream>
#include <string>

class Game {

    public:
        Game() { }
        ~Game() { }

        static void run() {
            SpriteBuffer screen(300, 84);

            FaseDeBatalha fase1("fase1", Sprite("rsc/background/background1.img", COR::CINZA));

            screen.clear();
            fase1.init();


            int ret1 = fase1.run(screen);
            system("clear");

            if (ret1 != Fase::GAME_OVER && ret1 != Fase::END_GAME)
                std::cout << "Vitoria!" << std::endl;

            else
                std::cout << "Derrota!" << std::endl;
        }
};

#endif