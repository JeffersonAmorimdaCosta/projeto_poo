#include "Vida.hpp"

void Vida::perderVida(const int& dano) {
    this->tamAtual = (dano <= this->tamAtual) ? this->tamAtual - dano : 0;

    if (this->tamAtual <= this->tam * 0.9 && !this->condicoes.test(0)) {
        this->update();
        this->condicoes.set(0, true);
    }

    if (this->tamAtual <= this->tam * 0.8 &&!this->condicoes.test(1)) {
        this->update();
        this->condicoes.set(1, true);
    }

    if (this->tamAtual <= this->tam * 0.7 && !this->condicoes.test(2)) {
        this->update();
        this->condicoes.set(2, true);
    }
    
    if (this->tamAtual <= this->tam * 0.6 && !this->condicoes.test(3)) {
        this->update();
        this->condicoes.set(3, true);
    }

    if (this->tamAtual <= this->tam * 0.5 && !this->condicoes.test(4)) {
        this->update();
        this->condicoes.set(4, true);
    }

    if (this->tamAtual <= this->tam * 0.4 && !this->condicoes.test(5)) {
        this->update();
        this->condicoes.set(5, true);
    }

    if (this->tamAtual <= this->tam * 0.3 && !this->condicoes.test(6)) {
        this->update();
        this->condicoes.set(6, true);
    }
    
    if (this->tamAtual <= this->tam * 0.2 && !this->condicoes.test(7)) {
        this->update();
        this->condicoes.set(7, true);
    }

    if (this->tamAtual <= this->tam * 0.1 && !this->condicoes.test(8)) {
        this->update();
        this->condicoes.set(8, true);
    }

    if (!this->tamAtual)
        this->desativarObj();
}