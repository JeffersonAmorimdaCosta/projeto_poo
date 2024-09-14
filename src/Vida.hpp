#ifndef VIDA_HPP
#define VIDA_HPP

#include "../ASCII_Engine/ObjetoDeJogo.hpp"

class Vida : public ObjetoDeJogo {

    private:
        int tam, tamAtual;
        bool s1, s2, s3, s4, s5, s6, s7, s8, s9;

    public:
        Vida(const ObjetoDeJogo& obj, const int& tam) : ObjetoDeJogo(obj) {
            this->tam = this->tamAtual = (tam >= 100) ? tam : 100;
            s1 = s2 = s3 = s4 = s5 = s6 = s7 = s8 = s9 = false;
        }

        int getVida() const {return this->tamAtual; }
        void perderVida(const int&);
};

#endif