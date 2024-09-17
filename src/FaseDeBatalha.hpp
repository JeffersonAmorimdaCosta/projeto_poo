#ifndef FASEDEBATALHA_HPP
#define FASEDEBATALHA_HPP

#include "../ASCII_Engine/Fase.hpp"
#include "Dragao.hpp"
#include "Habilidade.hpp"
#include "Vida.hpp"

#include <string>
#include <thread>
#include <atomic>
#include <unistd.h>
#include <termio.h>
#include <fcntl.h>
#include <random>
#include <iostream>
#include <chrono>

using std::string;

class FaseDeBatalha : public Fase {

    private:
        Dragao* aliados[3];
        Vida* vidaAliados[3];

        Dragao* inimigo;
        Vida* vidaInimigo;
        
        bool vezUsuario;
        Dragao* aliadoAtual;
        Vida* vidaAliadoAtual;
        int indiceAliado;

    public:

        template<typename T>
        FaseDeBatalha(string name, const T& bkg, const bool& vezUsuario = 
        true) : Fase(name, bkg), vezUsuario(vezUsuario), indiceAliado(0) { }

        ~FaseDeBatalha() { }

        void init() override;
        void update() override;
        unsigned run(SpriteBuffer&) override;
        
        void trocaVez() {this->vezUsuario = !this->vezUsuario; }

        void setAliadoAtual();

        void ataque(Dragao&, Habilidade&);

        void pausar(int ms);

        void configurarModoNaoBloqueante(const bool&);

        int gerarNumeroAleatorio(const int&, const int&);
};

#endif