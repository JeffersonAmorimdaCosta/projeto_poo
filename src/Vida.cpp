#include "Vida.hpp"

void Vida::perderVida(const int& dano) {
    this->tamAtual = (dano <= this->tamAtual) ? this->tamAtual - dano : 0;

    if (this->tamAtual <= this->tam * 0.8 && !this->s1) {
        this->update();
        this->s1 = true;
    }
    
    if (this->tamAtual <= this->tam * 0.6 && !this->s2) {
        this->update();
        this->s2 = true;
    }

    if (this->tamAtual <= this->tam * 0.4 && !this->s3) {
        this->update();
        this->s3 = true;
    }
    
    if (this->tamAtual <= this->tam * 0.2 && !this->s4) {
        this->update();
        this->s4 = true;
    }

    if (!this->tamAtual)
        this->desativarObj();
}