#ifndef FASEDERROTA_HPP
#define FASEDERROTA_HPP

#include "../ASCII_Engine/Fase.hpp"
#include "../ASCII_Engine/ObjetoDeJogo.hpp"

#include <string>
#include <iostream>

using std::string;

class FaseDerrota : public Fase {

    public:

        template<typename T>
        FaseDerrota(string name, const T& bkg) : Fase(name, bkg) { }

        ~FaseDerrota() { }

        void init() override {
            objs.push_back(new ObjetoDeJogo("derrota", Sprite("rsc/details/derrota.img"), 30, 130));
        }
        unsigned run(SpriteBuffer& screen) override {
            screen.clear();
            this->update();
            system("clear");
            this->draw(screen);
            this->show(screen);

            return Fase::END_GAME;
        }
};

#endif