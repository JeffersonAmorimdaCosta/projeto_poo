#ifndef VIDA_HPP
#define VIDA_HPP

#include "../ASCII_Engine/ObjetoDeJogo.hpp"
#include <bitset>

class Vida : public ObjetoDeJogo {

    private:
        int tam, tamAtual;
        std::bitset<9> condicoes;

    public:
        Vida(const ObjetoDeJogo& obj, const int& tam) : ObjetoDeJogo(obj), 
        condicoes(0) {
            this->tam = this->tamAtual = (tam >= 100) ? tam : 100;
        }

        int getVida() const {return this->tamAtual; }
        void perderVida(const int&);
};

#endif