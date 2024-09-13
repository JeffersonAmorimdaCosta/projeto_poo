#include "Vida.hpp"

void Vida::perderVida(const int& dano) {
    this->tamAtual = (dano <= this->tamAtual) ? this->tamAtual - dano : 0;

    if (this->tamAtual <= this->tam * 0.9 && !this->s1) {
        this->update();
        this->s1 = true;
    }

    if (this->tamAtual <= this->tam * 0.8 && !this->s2) {
        this->update();
        this->s2 = true;
    }

    if (this->tamAtual <= this->tam * 0.7 && !this->s3) {
        this->update();
        this->s3 = true;
    }
    
    if (this->tamAtual <= this->tam * 0.6 && !this->s4) {
        this->update();
        this->s4 = true;
    }

    if (this->tamAtual <= this->tam * 0.5 && !this->s5) {
        this->update();
        this->s5 = true;
    }

    if (this->tamAtual <= this->tam * 0.4 && !this->s6) {
        this->update();
        this->s6 = true;
    }

    if (this->tamAtual <= this->tam * 0.3 && !this->s7) {
        this->update();
        this->s7 = true;
    }
    
    if (this->tamAtual <= this->tam * 0.2 && !this->s8) {
        this->update();
        this->s8 = true;
    }

    if (this->tamAtual <= this->tam * 0.1 && !this->s9) {
        this->update();
        this->s9 = true;
    }

    if (!this->tamAtual)
        this->desativarObj();
}