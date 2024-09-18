// #include "src/Vida.hpp"
// #include "ASCII_Engine/ObjetoDeJogo.hpp"
// #include "ASCII_Engine/SpriteAnimado.hpp"
// #include "ASCII_Engine/Core/Cores_base.hpp"
// #include "ASCII_Engine/SpriteBuffer.hpp"
// #include <iostream>
// #include <string>

// using namespace std;

// int main(void) {

//     SpriteBuffer screen(300, 84);

//     Sprite health_bar("rsc/details/health_bar.img", COR::MARROM);
//     Vida vida(ObjetoDeJogo("vida", SpriteAnimado("rsc/details/health.anm", 1, COR::VERDE), 8, 35), 100);


//     int dano;
//     while (true) {
//         system("clear");

//         health_bar.draw(screen, 7, 30);
//         vida.draw(screen, vida.getPosL(), vida.getPosC());

//         cout << screen << endl;

//         cin >> dano;
//         vida.perderVida(dano);
//     }

//     return 0;
// }