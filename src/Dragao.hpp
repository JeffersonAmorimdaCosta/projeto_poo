#ifndef DRAGAO_HPP
#define DRAGAO_HPP

#include "../ASCII_Engine/ObjetoDeJogo.hpp"

#include "Vida.hpp"
#include "Habilidade.hpp"

class Dragao : public ObjetoDeJogo {

    private:
        Habilidade hab1;
        Habilidade hab2;
        Habilidade hab3;

    public:
        Dragao(const ObjetoDeJogo& obj, const Habilidade& hab1, 
        const Habilidade& hab2, const Habilidade& hab3) : ObjetoDeJogo(obj), 
        hab1(hab1), hab2(hab2), hab3(hab3) { }

        Habilidade getHabilidade1() const {return this->hab1; }
        Habilidade getHabilidade2() const {return this->hab2; }
        Habilidade getHabilidade3() const {return this->hab3; }
};

#endif