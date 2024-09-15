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
        Dragao* inimigo;
        
        bool vezUsuario;
        Dragao* aliadoAtual;
        int indiceAliado;

        std::atomic<bool> rodando;

    public:

        template<typename T>
        FaseDeBatalha(string name, const T& bkg, const bool& vezUsuario = 
        true) : Fase(name, bkg), vezUsuario(vezUsuario), indiceAliado(2) { }

        ~FaseDeBatalha() { }

        void init() override;
        unsigned run(SpriteBuffer&) override;
        
        void trocaVez() {this->vezUsuario = !this->vezUsuario; }

        void setAliadoAtual();

        void ataque(const Dragao&, Dragao&, Habilidade&);

        void capturarEntrada();

        void pausar(int ms);

        void configurarEntradaNaoBloqueante();

        void configurarModoNaoBloqueante(const bool&);

        int gerarNumeroAleatorio(const int&, const int&);
};

#endif