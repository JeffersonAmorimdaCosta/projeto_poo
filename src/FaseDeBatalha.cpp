#include "FaseDeBatalha.hpp"

void FaseDeBatalha::init() {
    Habilidade blazeSkill(ObjetoDeJogo("blaze", SpriteAnimado("rsc/skills/allies/blaze.anm", 1, COR::VERMELHA), 47, 190), "blaze", 300, 500);

    Habilidade flameSkill(ObjetoDeJogo("flame", SpriteAnimado("rsc/skills/allies/flame.anm", 1, COR::VERMELHA), 47, 105), "flame", 250, 400);

    // Habilidade raySkill(ObjetoDeJogo("ray", SpriteAnimado("../rsc/skills/allies/ray.img", 1, COR::VERMELHA), 15, 190), "ray", 150, 300);

    Habilidade earthquakeSkill(ObjetoDeJogo("earthquake", SpriteAnimado("rsc/skills/enemies/earthquake.anm", 1, COR::MARROM), 38, 190), "earthquake", 150, 300); 

    Vida vidaInimigo(ObjetoDeJogo("vida inimigo", SpriteAnimado("rsc/details/health.anm", 1, COR::VERDE), 8, 205), 2000);

    this->inimigo = new Dragao(ObjetoDeJogo("inimigo", Sprite("rsc/enemies/villain_dragon.img",
    COR::MARROM_ESCURA), 14, 180), vidaInimigo, blazeSkill, flameSkill, blazeSkill);
    objs.push_back(this->inimigo);

    this->aliados[0] = new Dragao(ObjetoDeJogo("flame dragon", Sprite("rsc/allies/flame_dragon.img", COR::VERMELHA), 25, 8), vidaInimigo, blazeSkill, flameSkill, blazeSkill);
    this->aliados[0]->desativarObj();
    objs.push_back(this->aliados[0]);

    this->aliados[1] = new Dragao(ObjetoDeJogo("eletric dragon", Sprite("rsc/allies/eletric_dragon.img", COR::AMARELA), 23, 8), vidaInimigo, blazeSkill, flameSkill, blazeSkill);
    this->aliados[1]->desativarObj();
    objs.push_back(this->aliados[1]);

    this->aliadoAtual = this->aliados[2] = new Dragao(ObjetoDeJogo("metal dragon", Sprite("rsc/allies/metal_dragon.img", COR::CINZA_ESCURA), 25, 8), vidaInimigo, blazeSkill, flameSkill, blazeSkill);
    objs.push_back(this->aliados[2]);
}

int FaseDeBatalha::gerarNumeroAleatorio(const int& min, const int& max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(min, max);

    return distrib(gen);
}

void FaseDeBatalha::configurarModoNaoBloqueante(const bool& ativar) {
    struct termios terminalEstado;
    tcgetattr(STDIN_FILENO, &terminalEstado);

    if (ativar) {
        terminalEstado.c_lflag &= ~ICANON; // Flag que configura o modo canônico (padrão) no terminal
        terminalEstado.c_lflag &= ~ECHO; // Flag de Exibição de entrada no terminal
        terminalEstado.c_cc[VMIN] = 1;

    } else {
        terminalEstado.c_lflag |= ICANON;
        terminalEstado.c_lflag |= ECHO;
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &terminalEstado); // Atualiza o terminal com as novas configs
}

void FaseDeBatalha::configurarEntradaNaoBloqueante() {
    int flags = fcntl(STDIN_FILENO, F_GETFL, 0); // Captura as flags do terminal
    fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK); // Seta como entrada não bloqueante
}

void FaseDeBatalha::pausar(int ms) {
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

void FaseDeBatalha::capturarEntrada() {
    if (!this->vezUsuario)
        return;

    while(rodando) {
        char ent;
        int n = read(STDIN_FILENO, &ent, 1);

        if (n > 0) {
            if (ent == 'q')
                rodando = false;

            else if (ent == '1') {
                Habilidade hab1 = this->aliadoAtual->getHabilidade1();
                this->ataque(*this->aliadoAtual, *this->inimigo, hab1);
            }

            else if (ent == '2') {
                Habilidade hab2 = this->aliadoAtual->getHabilidade2();
                this->ataque(*this->aliadoAtual, *this->inimigo, hab2);
            }

            else if (ent == '3') {
                Habilidade hab3 = this->aliadoAtual->getHabilidade3();
                this->ataque(*this->aliadoAtual, *this->inimigo, hab3);
            }
        }

        this->pausar(100);
    }
}

unsigned FaseDeBatalha::run(SpriteBuffer& screen) {
    this->rodando = true;
    this->configurarModoNaoBloqueante(true);
    this->configurarEntradaNaoBloqueante();

    screen.clear();
    this->draw(screen);
    system("clear");
    show(screen);

    std::thread entrada(&FaseDeBatalha::capturarEntrada, this);
    unsigned resultado;

    while (rodando) {

        if (!this->aliadoAtual->estaVivo()) {
            if (!this->indiceAliado) {
                this->rodando = false;
                resultado = Fase::GAME_OVER;
                break;
            } else {
                this->setAliadoAtual();
            }
        }

        if (!this->inimigo->estaVivo()) {
            this->rodando = false;
            resultado = Fase::END_GAME;
            break;
        }

        if (!this->vezUsuario) {
            // Mecânica do inimigo
            int hab = this->gerarNumeroAleatorio(1, 3); // Sortando qual vai ser a habilidade do inimigo

            if (hab == 1) {
                Habilidade hab1 = this->inimigo->getHabilidade1();
                this->ataque(*this->inimigo, *this->aliadoAtual, hab1);
            }

            else if (hab == 2) {
                Habilidade hab2 = this->inimigo->getHabilidade1();
                this->ataque(*this->inimigo, *this->aliadoAtual, hab2);
            }

            else if (hab == 3) {
                Habilidade hab3 = this->inimigo->getHabilidade1();
                this->ataque(*this->inimigo, *this->aliadoAtual, hab3);
            }
        }

        this->pausar(300);
        this->trocaVez();
    }

    entrada.join();
    this->configurarModoNaoBloqueante(false);

    return resultado;
}

void FaseDeBatalha::setAliadoAtual() {
    this->aliadoAtual->desativarObj();
    this->indiceAliado--;
    this->aliadoAtual = this->aliados[this->indiceAliado];
    this->aliadoAtual->ativarObj();
}

void FaseDeBatalha::ataque(const Dragao& atacante, Dragao& defensor, Habilidade& habilidade) {
    // Animação da habilidade...

    defensor.sofrerDano(habilidade.getDano());

    // Animação da barra de vida...
}