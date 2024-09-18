#ifndef DRAGAO_HPP
#define DRAGAO_HPP

#include "../ASCII_Engine/ObjetoDeJogo.hpp"

#include "Vida.hpp"
#include "Habilidade.hpp"

class Dragao : public ObjetoDeJogo {

    private:
        Vida &vida;
        Habilidade hab1;
        Habilidade hab2;
        Habilidade hab3;

    public:
        Dragao(const ObjetoDeJogo& obj, Vida& vida, const Habilidade& hab1, 
        const Habilidade& hab2, const Habilidade& hab3) : ObjetoDeJogo(obj),
        vida(vida), hab1(hab1), hab2(hab2), hab3(hab3) { }

        bool estaVivo() const {return this->vida.getVida() > 0; }
        void sofrerDano(const int& dano) {this->vida.perderVida(dano); }

        Habilidade getHabilidade1() const {return this->hab1; }
        Habilidade getHabilidade2() const {return this->hab2; }
        Habilidade getHabilidade3() const {return this->hab3; }
};

#endif