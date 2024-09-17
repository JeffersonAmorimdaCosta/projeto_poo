#include "FaseDeBatalha.hpp"

void FaseDeBatalha::init() {

    objs.push_back(new ObjetoDeJogo("barra vida inimigo", Sprite("rsc/details/health_bar.img", COR::MARROM), 7, 200));
    objs.push_back(new ObjetoDeJogo("barra vida aliado", Sprite("rsc/details/health_bar.img", COR::MARROM), 7, 30));

    Habilidade blazeSkill(ObjetoDeJogo("blaze", SpriteAnimado("rsc/skills/allies/blaze.anm", 1, COR::VERMELHA), 47, 190), "blaze", 300, 500);

    Habilidade flameSkill(ObjetoDeJogo("flame", SpriteAnimado("rsc/skills/allies/flame.anm", 1, COR::VERMELHA), 47, 105), "flame", 250, 400);

    // Habilidade raySkill(ObjetoDeJogo("ray", SpriteAnimado("../rsc/skills/allies/ray.img", 1, COR::VERMELHA), 15, 190), "ray", 150, 300);

    Habilidade earthquakeSkill(ObjetoDeJogo("earthquake", SpriteAnimado("rsc/skills/enemies/earthquake.anm", 1, COR::MARROM), 38, 190), "earthquake", 150, 300); 

    this->vidaInimigo = new Vida(ObjetoDeJogo("vida inimigo", SpriteAnimado("rsc/details/health.anm", 1, COR::VERDE), 8, 205), 2000);
    objs.push_back(this->vidaInimigo);

    this->vidaAliadoAtual = this->vidaAliados[0] = new Vida(ObjetoDeJogo("vida aliado 1", SpriteAnimado("rsc/details/health.anm", 1, COR::VERDE), 8, 35), 2000);
    objs.push_back(this->vidaAliados[0]);

    this->vidaAliados[1] = new Vida(ObjetoDeJogo("vida aliado 2", SpriteAnimado("rsc/details/health.anm", 1, COR::VERDE), 8, 35), 2000);
    this->vidaAliados[1]->desativarObj();
    objs.push_back(this->vidaAliados[1]);

    this->vidaAliados[2] = new Vida(ObjetoDeJogo("vida aliado 3", SpriteAnimado("rsc/details/health.anm", 1, COR::VERDE), 8, 35), 2000);
    this->vidaAliados[2]->desativarObj();
    objs.push_back(this->vidaAliados[2]);   

    this->inimigo = new Dragao(ObjetoDeJogo("inimigo", Sprite("rsc/enemies/villain_dragon.img", COR::MARROM_ESCURA), 14, 180), *this->vidaInimigo, blazeSkill, flameSkill, blazeSkill);
    objs.push_back(this->inimigo);

    this->aliadoAtual = this->aliados[0] = new Dragao(ObjetoDeJogo("flame dragon", Sprite("rsc/allies/flame_dragon.img", COR::VERMELHA), 25, 8), *this->vidaAliados[0], blazeSkill, flameSkill, blazeSkill);
    objs.push_back(this->aliadoAtual);

    this->aliados[1] = new Dragao(ObjetoDeJogo("eletric dragon", Sprite("rsc/allies/eletric_dragon.img", COR::AMARELA), 23, 8), *this->vidaAliados[1], blazeSkill, flameSkill, blazeSkill);
    this->aliados[1]->desativarObj();
    objs.push_back(this->aliados[1]);

    this->aliados[2] = new Dragao(ObjetoDeJogo("metal dragon", Sprite("rsc/allies/metal_dragon.img", COR::CINZA_ESCURA), 25, 8), *this->vidaAliados[2], blazeSkill, flameSkill, blazeSkill);
    objs.push_back(this->aliados[2]);
    this->aliados[2]->desativarObj();
}

void FaseDeBatalha::update() {
    background->update();
	
	for (auto it = objs.begin() ; it != objs.end() ; ++it) {
        Vida* vidaObj = dynamic_cast<Vida*>(*it);
        
        if (vidaObj)
            continue;

		(*it)->update();
    }
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
        terminalEstado.c_cc[VMIN] = 1; // Tamanho mínimo da entrada

    } else {
        terminalEstado.c_lflag |= ICANON;
        terminalEstado.c_lflag |= ECHO;
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &terminalEstado); // Atualiza o terminal com as novas configs
}

void FaseDeBatalha::pausar(int ms) {
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

unsigned FaseDeBatalha::run(SpriteBuffer& screen) {
    this->configurarModoNaoBloqueante(true);

    screen.clear();
    system("clear");
    this->draw(screen);
    this->show(screen);

    unsigned resultado;

     while (true) {
        

        if (!this->aliadoAtual->estaVivo()) {
            if (!this->indiceAliado) {
                resultado = Fase::GAME_OVER;
                break;
            } else {
                this->setAliadoAtual();
            }
        }

        if (!this->inimigo->estaVivo()) {
            resultado = Fase::END_GAME;
            break;
        }

        if (this->vezUsuario) {
            char ent;
            std::cin >> ent;

            if (ent == 'q') {
                resultado = Fase::END_GAME;
                break;
            }
                
            else if (ent == '1') {
                Habilidade hab1 = this->aliadoAtual->getHabilidade1();
                this->ataque(*this->inimigo, hab1);
            }

            else if (ent == '2') {
                Habilidade hab2 = this->aliadoAtual->getHabilidade2();
                this->ataque(*this->inimigo, hab2);
            }

            else if (ent == '3') {
                Habilidade hab3 = this->aliadoAtual->getHabilidade3();
                this->ataque(*this->inimigo, hab3);
            }
        }

        if (!this->vezUsuario) {
            this->pausar(1000);
            // Mecânica do inimigo

            int hab = this->gerarNumeroAleatorio(1, 3); // Sortando qual vai ser a habilidade do inimigo

            if (hab == 1) {
                Habilidade hab1 = this->inimigo->getHabilidade1();
                this->ataque(*this->aliadoAtual, hab1);
            }

            else if (hab == 2) {
                Habilidade hab2 = this->inimigo->getHabilidade1();
                this->ataque(*this->aliadoAtual, hab2);
            }

            else if (hab == 3) {
                Habilidade hab3 = this->inimigo->getHabilidade1();
                this->ataque(*this->aliadoAtual, hab3);
            }
        }

        this->trocaVez();
        screen.clear();
        this->update();
        system("clear");
        this->draw(screen);
        this->show(screen);
    }

    this->configurarModoNaoBloqueante(false);
    return resultado;
}

void FaseDeBatalha::setAliadoAtual() {
    (this->aliadoAtual)++->desativarObj();
    // (this->vidaAliadoAtual)++->desativarObj();
    this->aliadoAtual->ativarObj();
    this->vidaAliadoAtual->ativarObj();
}

void FaseDeBatalha::ataque(Dragao& defensor, Habilidade& habilidade) {
    // Animação da habilidade...

    defensor.sofrerDano(habilidade.getDano());

    // Animação da barra de vida...
}