#include "Chunk.hpp"
#include "Game.hpp"
#include "Input.hpp"

int main()
{
    Window window;
    Input input;
    Chunk chunk;

    Game game;

    game.init(window, input, &chunk);
    game.loop();
    game.stop();
    return 0;
}
