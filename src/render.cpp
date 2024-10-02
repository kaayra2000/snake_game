#include "game.h"
#include <iostream>

void render(const Game& game) {
    system("clear");
    for (int i = 0; i < game.getWidth() + 2; i++)
        std::cout << "#";
    std::cout << std::endl;

    for (int y = 0; y < game.getHeight(); y++) {
        for (int x = 0; x < game.getWidth(); x++) {
            if (x == 0) std::cout << "#";
            
            if (x == game.getSnake().x && y == game.getSnake().y)
                std::cout << "O";
            else if (x == game.getFruit().x && y == game.getFruit().y)
                std::cout << "F";
            else {
                bool printTail = false;
                for (const auto& segment : game.getTail()) {
                    if (segment.x == x && segment.y == y) {
                        std::cout << "o";
                        printTail = true;
                        break;
                    }
                }
                if (!printTail) std::cout << " ";
            }

            if (x == game.getWidth() - 1) std::cout << "#";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < game.getWidth() + 2; i++)
        std::cout << "#";
    std::cout << std::endl;
    std::cout << "Skor: " << game.getScore() << std::endl;
}
