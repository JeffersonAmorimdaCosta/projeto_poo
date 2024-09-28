#ifndef FASEDEBATALHA_HPP
#define FASEDEBATALHA_HPP

#include "../ASCII_Engine/Fase.hpp"
#include "Dragao.hpp"
#include "Habilidade.hpp"
#include "Vida.hpp"

#include <string>
#include <thread>
#include <unistd.h>
#include <termio.h>
#include <random>
#include <iostream>
#include <chrono>
#include <cctype>

using std::string;

class FaseDeBatalha : public Fase {

    private:
        Dragao* aliados[3];
        Vida* vidaAliados[3];
        Habilidade* habilidadesAliados[9];
        Habilidade* habilidadesInimigo[3];
        ObjetoDeJogo* nomesHabilidades[9];

        Dragao* inimigo;
        Vida* vidaInimigo;
        
        Dragao* aliadoAtual;
        Vida* vidaAliadoAtual;
        bool vezUsuario;
        int indiceAliado, indiceVida, indicePrimeiraHabilidade, qntHabilidades;

        ObjetoDeJogo *molduraVidaAliado, *molduraVidaInimigo, *caixaHabilidade1,
        *caixaHabilidade2, *caixaHabilidade3, *suaVez, *vezOponente;

    public:

        template<typename T>
        FaseDeBatalha(string name, const T& bkg, const bool& vezUsuario = 
        true) : Fase(name, bkg), vezUsuario(vezUsuario), indiceAliado(0), 
        indiceVida(0), indicePrimeiraHabilidade(0), qntHabilidades(3) { }

        ~FaseDeBatalha() { }

        void init() override;
        void update() override;
        unsigned run(SpriteBuffer&) override;
        
        void trocaVez() {this->vezUsuario = !this->vezUsuario; }

        void setAliadoAtual();

        void ataque(Habilidade&, Vida&);

        void pausar(int ms);

        void configurarModoNaoBloqueante(const bool&);

        int gerarNumeroAleatorio(const int&, const int&);

        void ativarCaixasHabilidade();

        void indicarTurno();

        void atualizaTerminal(SpriteBuffer&);

        void animacaoHabilidade(SpriteBuffer&);

        void selecionarNomesHabilidades();

        void ativarNomesHabildades();
};

#endif