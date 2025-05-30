#include "Game.hpp"

Game::Game()
{
}

Game::~Game()
{
} 


int Game::init(Window window, Input input, Render* render){
    this->window = window;
    this->window.init();

    this->input = input;
    this->input.init(this->window);

    this->render = render;
    this->render->init();

    return 1;
}

void Game::loop(){
    while (!this->window.shouldClose())
    {
        // input
        // -----
        this->input.handler();

        // render
        // ------
        this->render->render();

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(this->window.getHandler());
        glfwPollEvents();
    }
}


void Game::stop(){
    this->window.close();
}