#include <iostream>
#include <string>
#include "ASCII_Engine/Sprite.hpp"
#include "ASCII_Engine/SpriteBuffer.hpp"
#include "ASCII_Engine/TextSprite.hpp"
#include "ASCII_Engine/SpriteAnimado.hpp"

using namespace std;

int main(void) {

    system("clear");

    Sprite flame_dragon("rsc/allies/flame_dragon.img");
    Sprite metal_dragon("rsc/allies/metal_dragon.img");
    Sprite eletric_dragon("rsc/allies/eletric_dragon.img");
    Sprite villain_dragon("rsc/enemies/villain_dragon.img");
    Sprite background1("rsc/background/background1.img");
    Sprite background2("rsc/background/background2.img");
    Sprite background3("rsc/background/background3.img");
    Sprite skill_box1("rsc/details/skill_box1.img");
    Sprite skill_box2("rsc/details/skill_box2.img");
    Sprite skill_box3("rsc/details/skill_box3.img");
    // Sprite hit1("rsc/skills/hit1.img");
    // Sprite hit2("rsc/skills/hit2.img");
    // Sprite hit3("rsc/skills/hit3.img");
    // Sprite hit4("rsc/skills/hit4.img");
    Sprite health_bar("rsc/details/health_bar.img");
    // Sprite earthquake("rsc/skills/earthquake.anm");
    // Sprite meteors("rsc/skills/meteors.img");
    SpriteAnimado flame("rsc/skills/allies/flame.anm");
    SpriteAnimado blaze("rsc/skills/allies/blaze.anm");
    Sprite laser("rsc/skills/allies/laser2.img");
    Sprite ray("rsc/skills/allies/ray.img");
    Sprite anvil("rsc/skills/allies/anvil.img");
    TextSprite name1("Dragao Aliado");

    SpriteBuffer screen(300, 102);

    // background1.draw(screen, 0, 0);
    // background2.draw(screen, 0, 0);

    string str;

    while (1) {
        getline(cin, str);
        system("clear");

        // blaze.update();
        // flame.update();

        background1.draw(screen, 0, 0);
        // background3.draw(screen, 0, 0);
        health_bar.draw(screen, 7, 30);
        health_bar.draw(screen, 7, 200);

        // flame_dragon.draw(screen, 25, 8);
        // metal_dragon.draw(screen, 25, 8);
        eletric_dragon.draw(screen, 23, 8);
        villain_dragon.draw(screen, 14, 180);
        // name1.draw(screen, 22, 20);
        skill_box1.draw(screen, 73, 10);
        skill_box2.draw(screen, 73, 75);
        skill_box3.draw(screen, 73, 140);
        // hit1.draw(screen, 45, 210);
        // hit2.draw(screen, 45, 210);
        // hit3.draw(screen, 45, 210);
        // earthquake.draw(screen, 38, 190);
        // meteors.draw(screen, 20, 40);
        // hit4.draw(screen, 36, 29);
        // flame.draw(screen, 47, 105);
        // blaze.draw(screen, 47, 190);
        // ray.draw(screen, 15, 190);
        // laser.draw(screen, 40, 105);
        // anvil.draw(screen, 38, 162);


        cout << screen << endl;
    }

    return 0;
}