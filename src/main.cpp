#include "game.h"
#include <unistd.h>

void handleInput(Game& game);
void render(const Game& game);

int main() {
    Game game(20, 20);
    game.setup();

    while (!game.isGameOver()) {
        render(game);
        handleInput(game);
        game.update();
        usleep(100000);
    }

    return 0;
}
