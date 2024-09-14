#ifndef HABILIDADE_HPP
#define HABILIDADE_HPP

#include "../ASCII_Engine/ObjetoDeJogo.hpp"
#include <string>
#include <random>

using std::string;

class Habilidade : public ObjetoDeJogo {

    private:
        string nome;
        std::random_device rd;
        std::mt19937 gen;
        std::uniform_int_distribution<> distrib;

    public:
        Habilidade(const ObjetoDeJogo& obj, const int& danoMinimo, const int& 
        danoMaximo) : ObjetoDeJogo(obj), gen(rd()), 
        distrib(danoMinimo, danoMaximo) { }

        ~Habilidade() { }

        string getNome() const {return this->nome; }

        int getDano() {return this->distrib(gen); }
};

#endif