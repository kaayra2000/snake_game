#include "game.h"
#include <cstdlib>
#include <ctime>

Game::Game(int w, int h) : width(w), height(h), gameOver(false), score(0), dir(Direction::STOP) {
    srand(time(0));
}

bool Game::isGameOver() const {
    return gameOver;
}

void Game::setup() {
    snake = {width / 2, height / 2};
    fruit = {rand() % width, rand() % height};
    tail.clear();
    score = 0;
    dir = Direction::STOP;
}

void Game::update() {
    if (dir == Direction::STOP) return;

    Point newHead = snake;
    switch (dir) {
        case Direction::LEFT:  newHead.x--; break;
        case Direction::RIGHT: newHead.x++; break;
        case Direction::UP:    newHead.y--; break;
        case Direction::DOWN:  newHead.y++; break;
    }

    if (newHead.x >= width) newHead.x = 0;
    else if (newHead.x < 0) newHead.x = width - 1;
    if (newHead.y >= height) newHead.y = 0;
    else if (newHead.y < 0) newHead.y = height - 1;

    for (const auto& segment : tail) {
        if (newHead.x == segment.x && newHead.y == segment.y) {
            gameOver = true;
            return;
        }
    }

    if (newHead.x == fruit.x && newHead.y == fruit.y) {
        score += 10;
        fruit = {rand() % width, rand() % height};
        tail.push_back(snake);
    } else if (!tail.empty()) {
        tail.push_back(snake);
        tail.erase(tail.begin());
    }

    snake = newHead;
}

void Game::setDirection(Direction d) {
    dir = d;
}

void Game::setGameOver(bool value) {
    gameOver = value;
}

const std::vector<Point>& Game::getTail() const {
    return tail;
}

const Point& Game::getSnake() const {
    return snake;
}

const Point& Game::getFruit() const {
    return fruit;
}

int Game::getScore() const {
    return score;
}

int Game::getWidth() const {
    return width;
}

int Game::getHeight() const {
    return height;
}
