#include "FaseDeBatalha.hpp"

void FaseDeBatalha::init() {

    this->suaVez = new ObjetoDeJogo("sua vez", Sprite("rsc/details/your_turn.img", COR::VERDE), 4, 130);
    objs.push_back(this->suaVez);

    this->vezOponente = new ObjetoDeJogo("vez oponente", Sprite("rsc/details/enemy_turn.img", COR::VERMELHA), 3, 118);
    objs.push_back(this->vezOponente);

    if (this->vezUsuario)
        this->vezOponente->desativarObj();
    else
        this->suaVez->desativarObj();

    this->molduraVidaInimigo = new ObjetoDeJogo("moldura vida inimigo", Sprite("rsc/details/health_bar.img", COR::MARROM), 7, 200);
    objs.push_back(this->molduraVidaInimigo);

    this->molduraVidaAliado = new ObjetoDeJogo("moldura vida aliado", Sprite("rsc/details/health_bar.img", COR::MARROM), 7, 30);
    objs.push_back(this->molduraVidaAliado);

    this->caixaHabilidade1 = new ObjetoDeJogo("caixa habilidade 1", Sprite("rsc/details/skill_box1.img", COR::CIANO), 73, 10);
    objs.push_back(this->caixaHabilidade1);
    
    this->caixaHabilidade2 = new ObjetoDeJogo("caixa habilidade 2", Sprite("rsc/details/skill_box2.img", COR::CIANO), 73, 85);
    objs.push_back(this->caixaHabilidade2);

    this->caixaHabilidade3 = new ObjetoDeJogo("caixa habilidade 3", Sprite("rsc/details/skill_box3.img", COR::CIANO), 73, 160);
    objs.push_back(this->caixaHabilidade3);


    Habilidade blazeSkill(ObjetoDeJogo("blaze", SpriteAnimado("rsc/skills/allies/blaze.anm", 1, COR::VERMELHA), 47, 190), "blaze", 300, 500);

    Habilidade flameSkill(ObjetoDeJogo("flame", SpriteAnimado("rsc/skills/allies/flame.anm", 1, COR::VERMELHA), 47, 105), "flame", 250, 400);

    // Habilidade raySkill(ObjetoDeJogo("ray", SpriteAnimado("../rsc/skills/allies/ray.img", 1, COR::VERMELHA), 15, 190), "ray", 150, 300);

    Habilidade earthquakeSkill(ObjetoDeJogo("earthquake", SpriteAnimado("rsc/skills/enemies/earthquake.anm", 1, COR::MARROM), 38, 190), "earthquake", 150, 300); 

    this->vidaInimigo = new Vida(ObjetoDeJogo("vida inimigo", SpriteAnimado("rsc/details/health.anm", 1, COR::VERDE), 8, 205), 3400);
    objs.push_back(this->vidaInimigo);

    this->vidaAliadoAtual = this->vidaAliados[0] = new Vida(ObjetoDeJogo("vida aliado 1", SpriteAnimado("rsc/details/health.anm", 1, COR::VERDE), 8, 35), 1000);
    objs.push_back(this->vidaAliados[0]);

    this->vidaAliados[1] = new Vida(ObjetoDeJogo("vida aliado 2", SpriteAnimado("rsc/details/health.anm", 1, COR::VERDE), 8, 35), 1000);
    this->vidaAliados[1]->desativarObj();
    objs.push_back(this->vidaAliados[1]);

    this->vidaAliados[2] = new Vida(ObjetoDeJogo("vida aliado 3", SpriteAnimado("rsc/details/health.anm", 1, COR::VERDE), 8, 35), 1000);
    this->vidaAliados[2]->desativarObj();
    objs.push_back(this->vidaAliados[2]);   

    this->inimigo = new Dragao(ObjetoDeJogo("inimigo", Sprite("rsc/enemies/villain_dragon.img", COR::MARROM_ESCURA), 14, 180), blazeSkill, flameSkill, blazeSkill);
    objs.push_back(this->inimigo);

    this->aliadoAtual = this->aliados[0] = new Dragao(ObjetoDeJogo("flame dragon", Sprite("rsc/allies/flame_dragon.img", COR::VERMELHA), 25, 8), blazeSkill, flameSkill, blazeSkill);
    objs.push_back(this->aliadoAtual);

    this->aliados[1] = new Dragao(ObjetoDeJogo("eletric dragon", Sprite("rsc/allies/eletric_dragon.img", COR::AMARELA), 23, 8), blazeSkill, flameSkill, blazeSkill);
    this->aliados[1]->desativarObj();
    objs.push_back(this->aliados[1]);

    this->aliados[2] = new Dragao(ObjetoDeJogo("metal dragon", Sprite("rsc/allies/metal_dragon.img", COR::CINZA_ESCURA), 25, 8), blazeSkill, flameSkill, blazeSkill);
    objs.push_back(this->aliados[2]);
    this->aliados[2]->desativarObj();
}

void FaseDeBatalha::atualizaTerminal(SpriteBuffer& screen) {
    screen.clear();
    this->update();
    system("clear");
    this->draw(screen);
    this->show(screen);
}

void FaseDeBatalha::ativarCaixasHabilidade() {
    if (!this->vezUsuario) {
        this->caixaHabilidade1->ativarObj();
        this->caixaHabilidade2->ativarObj();
        this->caixaHabilidade3->ativarObj();
    } else {
        this->caixaHabilidade1->desativarObj();
        this->caixaHabilidade2->desativarObj();
        this->caixaHabilidade3->desativarObj();
    }
}

void FaseDeBatalha::indicarTurno() {
    if (!this->vezUsuario) {
        this->suaVez->ativarObj();
        this->vezOponente->desativarObj();
    } else {
        this->suaVez->desativarObj();
        this->vezOponente->ativarObj();
    }
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
    this->atualizaTerminal(screen);

    unsigned resultado;

     while (true) {

        if (this->vezUsuario) {

            char ent;
            std::cin >> ent;

            // this->pausar(1000);

            if (ent == 'q') {
                return Fase::END_GAME;
            }
                
            else if (ent == '1') {
                Habilidade hab1 = this->aliadoAtual->getHabilidade1();
                this->ataque(hab1, *this->vidaInimigo);
            }

            else if (ent == '2') {
                Habilidade hab2 = this->aliadoAtual->getHabilidade2();
                this->ataque(hab2, *this->vidaInimigo);
            }

            else if (ent == '3') {
                Habilidade hab3 = this->aliadoAtual->getHabilidade3();
                this->ataque(hab3, *this->vidaInimigo);
            }
        }

        else {
            // this->pausar(1000);
            // Mecânica do inimigo

            int hab = this->gerarNumeroAleatorio(1, 3); // Sortando qual vai ser a habilidade do inimigo

            if (hab == 1) {
                Habilidade hab1 = this->inimigo->getHabilidade1();
                this->ataque(hab1, *this->vidaAliadoAtual);
            }

            else if (hab == 2) {
                Habilidade hab2 = this->inimigo->getHabilidade2();
                this->ataque(hab2, *this->vidaAliadoAtual);
            }

            else if (hab == 3) {
                Habilidade hab3 = this->inimigo->getHabilidade3();
                this->ataque(hab3, *this->vidaAliadoAtual);
            }
        }

        if (!this->vidaAliadoAtual->getVida()) {
            if (this->indiceAliado == 2) {
                resultado = Fase::GAME_OVER;
                break;
            } else {
                this->setAliadoAtual();
                this->update();
            }
        }

        if (!this->vidaInimigo->getVida()) {
            resultado = Fase::LEVEL_COMPLETE;
            break;
        }

        this->ativarCaixasHabilidade();
        this->indicarTurno();

        this->pausar(1000);
        this->trocaVez();
        this->atualizaTerminal(screen);
    }

    this->pausar(1000);
    this->atualizaTerminal(screen);
    this->pausar(1000);

    this->configurarModoNaoBloqueante(false);
    return resultado;
}

void FaseDeBatalha::setAliadoAtual() {
    this->aliadoAtual->desativarObj();
    this->aliadoAtual = this->aliados[++indiceAliado];
    this->vidaAliadoAtual = this->vidaAliados[++this->indiceVida];
    this->aliadoAtual->ativarObj();
    this->vidaAliadoAtual->ativarObj();
}

void FaseDeBatalha::ataque(Habilidade& habilidade, Vida& vidaDefensor) {
    // Animação da habilidade...

    vidaDefensor.perderVida(habilidade.getDano());
}