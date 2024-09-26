#ifndef DRAGAO_HPP
#define DRAGAO_HPP

#include "../ASCII_Engine/ObjetoDeJogo.hpp"

class Dragao : public ObjetoDeJogo {

    public:
        Dragao(const ObjetoDeJogo& obj) : ObjetoDeJogo(obj) { }
};

#endif