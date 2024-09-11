#ifndef FASEDEBATALHA_HPP
#define FASEDEBATALHA_HPP

#include "../ASCII_Engine/Fase.hpp"
#include "Dragao.hpp"
#include "Habilidade.hpp"

#include <string>

using std::string;

class FaseDeBatalha : public Fase {

    private:
        Dragao* allies[3];
        Dragao* enemy;
        
        bool vezUsuario;
        Dragao* aliadoAtual;

    public:

        FaseDeBatalha(string name, const Sprite& bkg, const bool& vezUsuario = 
        true) : Fase(name, bkg), vezUsuario(vezUsuario) {
            this->setAliadoAtual();
        }

        FaseDeBatalha(string name, const SpriteAnimado& bkg, const bool& vezUsuario = true) : Fase(name, bkg), vezUsuario(vezUsuario) {
            this->setAliadoAtual();
        }

        ~FaseDeBatalha() { }

        void init() override;
        unsigned run(SpriteBuffer&) override;
        
        void trocaVez() {this->vezUsuario = !this->vezUsuario; }

        void setAliadoAtual();

        void ataque(const Dragao&, Dragao&, const Habilidade&);
};

#endif