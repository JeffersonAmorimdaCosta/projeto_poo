#ifndef DRAGAO_HPP
#define DRAGAO_HPP

#include "../ASCII_Engine/ObjetoDeJogo.hpp"

#include "Vida.hpp"
#include "Habilidade.hpp"

class Dragao : public ObjetoDeJogo {

    public:
        Dragao(const ObjetoDeJogo& obj) : ObjetoDeJogo(obj) { }
};

#endif