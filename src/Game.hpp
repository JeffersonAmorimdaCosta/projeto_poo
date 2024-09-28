#ifndef GAME_HPP
#define GAME_HPP

#include "../ASCII_Engine/Sprite.hpp"
#include "FaseDeBatalha.hpp"
#include "FaseVitoria.hpp"
#include "FaseDerrota.hpp"

#include <iostream>
#include <string>

using std::cout, std::endl;

class Game {

    public:
        Game() { }
        ~Game() { }

        static void run() {
            SpriteBuffer screen(300, 83);

            FaseDeBatalha fase1("fase1", Sprite("rsc/background/background1.img", COR::MARROM));
            FaseVitoria faseVitoria("fase vitoria", Sprite("rsc/background/vazio.img"));
            FaseDerrota faseDerrota("fase derrota", Sprite("rsc/background/vazio.img"));

            screen.clear();
            fase1.init();


            int ret1 = fase1.run(screen);
            system("clear");

            if (ret1 == Fase::LEVEL_COMPLETE) {
                screen.clear();
                faseVitoria.init();
                faseVitoria.run(screen);
            }

            else if (ret1 == Fase::END_GAME || ret1 == Fase::GAME_OVER) {
                screen.clear();
                faseDerrota.init();
                faseDerrota.run(screen);
            }
        }
};

#endif