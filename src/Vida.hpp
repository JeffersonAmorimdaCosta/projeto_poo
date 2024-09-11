#ifndef VIDA_HPP
#define VIDA_HPP

#include "../ASCII_Engine/ObjetoDeJogo.hpp"

class Vida : public ObjetoDeJogo {

    private:
        int tam, tamAtual;
        bool s1, s2, s3, s4;

    public:
        Vida(const ObjetoDeJogo& obj, const int& tam) : ObjetoDeJogo(obj),
        s1(false), s2(false), s3(false), s4(false) {
            this->tam = this->tamAtual = (tam >= 100) ? tam : 100;
        }

        int getVida() const {return this->tamAtual; }
        void perderVida(const int&);
};

#endif