#include "FaseDeBatalha.hpp"

void FaseDeBatalha::init() {

    this->suaVez = new ObjetoDeJogo("sua vez", Sprite("rsc/details/sua_vez.img", COR::VERDE), 4, 130);
    objs.push_back(this->suaVez);

    this->vezOponente = new ObjetoDeJogo("vez oponente", Sprite("rsc/details/vez_oponente.img", COR::VERMELHA), 3, 118);
    objs.push_back(this->vezOponente);

    if (this->vezUsuario)
        this->vezOponente->desativarObj();
    else
        this->suaVez->desativarObj();

    this->molduraVidaInimigo = new ObjetoDeJogo("moldura vida inimigo", Sprite("rsc/details/health_bar.img", COR::CINZA), 7, 200);
    objs.push_back(this->molduraVidaInimigo);

    this->molduraVidaAliado = new ObjetoDeJogo("moldura vida aliado", Sprite("rsc/details/health_bar.img", COR::CINZA), 7, 30);
    objs.push_back(this->molduraVidaAliado);

    this->caixaHabilidade1 = new ObjetoDeJogo("caixa habilidade 1", Sprite("rsc/details/skill_box1.img", COR::CIANO), 73, 10);
    objs.push_back(this->caixaHabilidade1);
    
    this->caixaHabilidade2 = new ObjetoDeJogo("caixa habilidade 2", Sprite("rsc/details/skill_box2.img", COR::CIANO), 73, 95);
    objs.push_back(this->caixaHabilidade2);

    this->caixaHabilidade3 = new ObjetoDeJogo("caixa habilidade 3", Sprite("rsc/details/skill_box3.img", COR::CIANO), 73, 180);
    objs.push_back(this->caixaHabilidade3);

    this->nomesHabilidades[0] = new ObjetoDeJogo("nome soco", Sprite("rsc/details/soco.img", COR::MAGENTA), 75, 39);

    this->nomesHabilidades[1] = new ObjetoDeJogo("nome labareda", Sprite("rsc/details/labareda.img", COR::MAGENTA), 74, 110);

    this->nomesHabilidades[2] = new ObjetoDeJogo("nome chamas", Sprite("rsc/details/chamas.img", COR::MAGENTA), 74, 195);

    this->nomesHabilidades[3] = new ObjetoDeJogo("nome soco", Sprite("rsc/details/soco.img", COR::MAGENTA), 75, 39);

    this->nomesHabilidades[4] = new ObjetoDeJogo("nome laser", Sprite("rsc/details/laser.img", COR::MAGENTA), 74, 120);

    this->nomesHabilidades[5] = new ObjetoDeJogo("nome raio", Sprite("rsc/details/raio.img", COR::MAGENTA), 74, 200);

    this->nomesHabilidades[6] = new ObjetoDeJogo("nome soco", Sprite("rsc/details/soco.img", COR::MAGENTA), 75, 39);

    this->nomesHabilidades[7] = new ObjetoDeJogo("nome sabre", Sprite("rsc/details/sabre.img", COR::MAGENTA), 74, 112);

    this->nomesHabilidades[8] = new ObjetoDeJogo("nome bigorna", Sprite("rsc/details/impacto.img", COR::MAGENTA), 74, 194);

    for (int i = 0; i < this->qntHabilidades * 3; i++) {
        objs.push_back(this->nomesHabilidades[i]);
        if (i < 3)
            continue;
        this->nomesHabilidades[i]->desativarObj();
    }

    this->vidaInimigo = new Vida(ObjetoDeJogo("vida inimigo", SpriteAnimado("rsc/details/health.anm", 1, COR::VERDE), 8, 205), 3900);
    objs.push_back(this->vidaInimigo);
 
    this->vidaAliadoAtual = this->vidaAliados[0] = new Vida(ObjetoDeJogo("vida aliado 1", SpriteAnimado("rsc/details/health.anm", 1, COR::VERDE), 8, 35), 1000);

    this->vidaAliados[1] = new Vida(ObjetoDeJogo("vida aliado 2", SpriteAnimado("rsc/details/health.anm", 1, COR::VERDE), 8, 35), 1000);

    this->vidaAliados[2] = new Vida(ObjetoDeJogo("vida aliado 3", SpriteAnimado("rsc/details/health.anm", 1, COR::VERDE), 8, 35), 1000);

    this->inimigo = new Dragao(ObjetoDeJogo("inimigo", Sprite("rsc/enemies/villain_dragon.img", COR::MARROM_ESCURA), 14, 180));
    objs.push_back(this->inimigo);

    this->aliadoAtual = this->aliados[0] = new Dragao(ObjetoDeJogo("flame dragon", Sprite("rsc/allies/flame_dragon.img", COR::VERMELHA), 25, 8));

    this->aliados[1] = new Dragao(ObjetoDeJogo("eletric dragon", Sprite("rsc/allies/eletric_dragon.img", COR::AMARELA), 23, 8));

    this->aliados[2] = new Dragao(ObjetoDeJogo("metal dragon", Sprite("rsc/allies/metal_dragon.img", COR::CINZA_ESCURA), 25, 8));

    for (int i = 0; i < 3; i++) {
        objs.push_back(this->vidaAliados[i]);
        objs.push_back(this->aliados[i]);

        if (!i)
            continue;

        this->vidaAliados[i]->desativarObj();
        this->aliados[i]->desativarObj();
    }

    this->habilidadesInimigo[0] = new Habilidade(ObjetoDeJogo("hit", SpriteAnimado("rsc/skills/enemies/hit1.anm", 1, COR::VERDE), 40, 35), "hit", 300, 500);

    this->habilidadesInimigo[1] = new Habilidade(ObjetoDeJogo("earthquake", SpriteAnimado("rsc/skills/enemies/earthquake.anm", 1, COR::MARROM_ESCURA), 38, 25), "earthquake", 300, 500);

    this->habilidadesInimigo[2] = new Habilidade(ObjetoDeJogo("meteor", SpriteAnimado("rsc/skills/enemies/meteors.anm", 1, COR::AMARELA), 15, 60), "meteor", 250, 400);

    for (auto hab : this->habilidadesInimigo) {
        hab->desativarObj();
        objs.push_back(hab);
    }

    this->habilidadesAliados[0] = new Habilidade(ObjetoDeJogo("hit", SpriteAnimado("rsc/skills/allies/hit.anm", 1, COR::AZUL), 30, 110), "hit", 300, 500);
    
    this->habilidadesAliados[1] = new Habilidade(ObjetoDeJogo("blaze", SpriteAnimado("rsc/skills/allies/blaze.anm", 1, COR::VERMELHA), 48, 190), "blaze", 300, 500);

    this->habilidadesAliados[2] = new Habilidade(ObjetoDeJogo("flame", SpriteAnimado("rsc/skills/allies/flame.anm", 1, COR::VERMELHA), 47, 105), "flame", 250, 400);

    this->habilidadesAliados[3] = new Habilidade(ObjetoDeJogo("hit", SpriteAnimado("rsc/skills/allies/hit.anm", 1, COR::AZUL), 30, 110), "hit", 300, 500);

    this->habilidadesAliados[4] = new Habilidade(ObjetoDeJogo("laser", SpriteAnimado("rsc/skills/allies/laser.anm", 1, COR::CIANO), 40, 105), "laser", 300, 500);
    
    this->habilidadesAliados[5] = new Habilidade(ObjetoDeJogo("ray", SpriteAnimado("rsc/skills/allies/ray.anm", 1, COR::CIANO), 20, 190), "ray", 300, 500);

    this->habilidadesAliados[6] = new Habilidade(ObjetoDeJogo("hit", SpriteAnimado("rsc/skills/allies/hit.anm", 1, COR::AZUL), 30, 110), "hit", 300, 500);

    this->habilidadesAliados[7] = new Habilidade(ObjetoDeJogo("sword", SpriteAnimado("rsc/skills/allies/sword.anm", 1, COR::CINZA_ESCURA), 20, 150), "sword", 300, 500);
    
    this->habilidadesAliados[8] = new Habilidade(ObjetoDeJogo("anvil", SpriteAnimado("rsc/skills/allies/anvil.anm", 1, COR::CINZA_ESCURA), 18, 205), "anvil", 300, 500);

    for (auto hab : this->habilidadesAliados) {
        hab->desativarObj();
        objs.push_back(hab);
    }
}

void FaseDeBatalha::atualizaTerminal(SpriteBuffer& screen) {
    screen.clear();
    this->update();
    system("clear");
    this->draw(screen);
    this->show(screen);
}

void FaseDeBatalha::ativarCaixasHabilidade() {
    if (!this->vezUsuario) { // Ativa as caixas de habilidade
        this->caixaHabilidade1->ativarObj();
        this->caixaHabilidade2->ativarObj();
        this->caixaHabilidade3->ativarObj();
    } else {                                // desativa as caixas de habilidade
        this->caixaHabilidade1->desativarObj();
        this->caixaHabilidade2->desativarObj();
        this->caixaHabilidade3->desativarObj();
    }
}

void FaseDeBatalha::ativarNomesHabildades() {
    for (int i = 0; i < this->qntHabilidades; i++) {
        if (!this->vezUsuario)
            this->nomesHabilidades[this->indiceAliado * this->qntHabilidades + i]->ativarObj();
        else
            this->nomesHabilidades[this->indiceAliado * this->qntHabilidades + i]->desativarObj();
    }
}

void FaseDeBatalha::indicarTurno() {
    if (!this->vezUsuario) { // Indica que o turno é do usúário
        this->suaVez->ativarObj();
        this->vezOponente->desativarObj();
    } else {                           // Indica que o turno é do oponente
        this->suaVez->desativarObj(); 
        this->vezOponente->ativarObj();
    }
}

void FaseDeBatalha::update() {
    background->update();
	
	for (auto it = objs.begin() ; it != objs.end() ; ++it) {
        Vida* vidaObj = dynamic_cast<Vida*>(*it);
        
        if (vidaObj) // Ignora os objetos Vida
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

void FaseDeBatalha::animacaoHabilidade(SpriteBuffer& screen) {
    for (int i = 0; i < 7; i++) {
        this->atualizaTerminal(screen);
        this->pausar(240);

    }
}

unsigned FaseDeBatalha::run(SpriteBuffer& screen) {

    this->configurarModoNaoBloqueante(true);    
    this->atualizaTerminal(screen);

    unsigned resultado;

     while (true) {

        if (this->vezUsuario) {

            while (true) {
                char ent;
                std::cin >> ent; // Pegando a entrada do usuário

                int indiceHabilidade = this->indiceAliado * this->qntHabilidades; // Pegando o índice da primeira habilidade do dragão atual

                if (tolower(ent) == 'q') { // Encerra o jogo
                    return Fase::END_GAME;
                }
                
                else if (ent >= '1' && ent <= '3') { // Selecionando a habilidade
                    int entInt = (ent - '0') - 1;
                    Habilidade& habEscolhida = *this->habilidadesAliados[indiceHabilidade + entInt];
                    habEscolhida.ativarObj();
                    this->animacaoHabilidade(screen);
                    habEscolhida.desativarObj();
                    this->atualizaTerminal(screen);
                    this->ataque(habEscolhida, *this->vidaInimigo);
                    this->atualizaTerminal(screen);
                    break;
                }
            }
        }

        else {
            // Mecânica do inimigo

            int hab = this->gerarNumeroAleatorio(1, 3); // Sortando qual vai ser a habilidade do inimigo

            if (hab >= 1 && hab <= 3) { 
                Habilidade& habEscolhida = *this->habilidadesInimigo[hab - 1];
                habEscolhida.ativarObj();
                this->animacaoHabilidade(screen);
                habEscolhida.desativarObj();
                this->atualizaTerminal(screen);
                this->ataque(habEscolhida, *this->vidaAliadoAtual);
                this->atualizaTerminal(screen);
            }
        }

        if (!this->vidaAliadoAtual->getVida()) {
            if (this->indiceAliado == 2) { // Verifica se o aliado morreu e não tem mais dragões
                resultado = Fase::GAME_OVER;
                break;
            } else { // O aliado morreu, mas ainda tem dragões
                this->setAliadoAtual();
            }
        }

        if (!this->vidaInimigo->getVida()) { // Verifica se o inimigo morreu
            resultado = Fase::LEVEL_COMPLETE;
            break;
        }

        this->ativarCaixasHabilidade();
        this->ativarNomesHabildades();
        this->indicarTurno();

        this->pausar(1000);
        this->trocaVez();
        this->atualizaTerminal(screen);
    }

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

void FaseDeBatalha::selecionarNomesHabilidades() {
    for (int i = 0; i < qntHabilidades; i ++) {
        this->nomesHabilidades[this->indiceAliado * this->qntHabilidades + i]->desativarObj();
        this->nomesHabilidades[(this->indiceAliado + 1) * this->qntHabilidades + i]->ativarObj();
    }
}