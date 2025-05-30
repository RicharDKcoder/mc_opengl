#pragma once
#include "Render.hpp"
#include "Window.hpp"
#include "Input.hpp"


class Game
{
public:
    Game();
    Game(Game &&) = default;
    Game(const Game &) = default;
    Game &operator=(Game &&) = default;
    Game &operator=(const Game &) = default;
    ~Game();

    int init(Window window, Input input, Render* render);

    void loop();

    void stop();

private:
    Window window;
    Input input;
    Render* render;
};