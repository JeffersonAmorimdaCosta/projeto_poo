#ifndef DRAGAO_HPP
#define DRAGAO_HPP

#include "../ASCII_Engine/ObjetoDeJogo.hpp"

#include "Vida.hpp"
#include "Habilidade.hpp"

class Dragao : public ObjetoDeJogo {

    public:
        Dragao(const ObjetoDeJogo& obj, const Habilidade& hab1, 
        const Habilidade& hab2, const Habilidade& hab3) : ObjetoDeJogo(obj) { }
};

#endif