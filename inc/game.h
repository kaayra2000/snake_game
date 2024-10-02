#ifndef GAME_H
#define GAME_H

#include <vector>

struct Point {
    int x, y;
};

class Game {
public:
    enum class Direction { STOP, LEFT, RIGHT, UP, DOWN };

    Game(int w, int h);
    bool isGameOver() const;
    void setup();
    void update();
    void setDirection(Direction d);
    void setGameOver(bool value);
    const std::vector<Point>& getTail() const;
    const Point& getSnake() const;
    const Point& getFruit() const;
    int getScore() const;
    int getWidth() const;
    int getHeight() const;

private:
    bool gameOver;
    int width, height;
    Point snake;
    Point fruit;
    std::vector<Point> tail;
    int score;
    Direction dir;  // Burada sadece Direction tipini kullanıyoruz
    Direction lastDir;
};

#endif
