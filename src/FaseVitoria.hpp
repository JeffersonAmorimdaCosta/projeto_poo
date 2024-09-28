#ifndef FASEVITORIA_HPP
#define FASEVITORIA_HPP

#include "../ASCII_Engine/Fase.hpp"
#include "../ASCII_Engine/ObjetoDeJogo.hpp"

#include <string>
#include <iostream>

using std::string;

class FaseVitoria : public Fase {

    public:

        template<typename T>
        FaseVitoria(string name, const T& bkg) : Fase(name, bkg) { }

        ~FaseVitoria() { }

        void init() override {
            objs.push_back(new ObjetoDeJogo("vitoria", Sprite("rsc/details/vitoria.img"), 30, 130));
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