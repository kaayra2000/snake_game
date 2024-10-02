#include "game.h"
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <cstdio>

int kbhit() {
    struct termios oldt, newt;
    int ch;
    int oldf;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);
    if(ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }
    return 0;
}

void handleInput(Game& game) {
    if (kbhit()) {
        switch (getchar()) {
            case 'a': game.setDirection(Game::Direction::LEFT); break;
            case 'd': game.setDirection(Game::Direction::RIGHT); break;
            case 'w': game.setDirection(Game::Direction::UP); break;
            case 's': game.setDirection(Game::Direction::DOWN); break;
            case 'x': game.setGameOver(true); break;
        }
    }
}
