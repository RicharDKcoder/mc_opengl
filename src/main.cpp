#include "shader.hpp"
#include "grip.hpp"
#include "window.hpp"
#include <glm/fwd.hpp>
#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "ui.hpp"

int main()
{
    Window window;
    window.init();

    // ui
    UI ui;
    ui.init(window.getId());

    Shader shader;
    shader.build("../resources/shader/default.vert", "../resources/shader/default.frag");


    // texture
    GLuint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    // 为当前绑定的纹理对象设置环绕、过滤方式
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // 加载并生成纹理
    int width, height, nrChannels;
    unsigned char* data = stbi_load("../resources/texture/wall.jpg", &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);

    int gripWidth = 50;
    int gripHeight = 50;
    Grip vao(gripWidth,gripHeight);
    
    //vao.build(vertices, sizeof(vertices), indices, sizeof(indices));
    vao.build();

    glUseProgram(shader.getId());
    glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
    unsigned int projectionLoc = glGetUniformLocation(shader.getId(), "projection");
    glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));


    // render loop
    // -----------
    while (!window.shouldClose())
    {
        glfwPollEvents();
        ui.loop_start();
        // render
        // ------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        //glClear(GL_COLOR_BUFFER_BIT);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // bind Texture
        glBindTexture(GL_TEXTURE_2D, texture);

        // draw our first triangle
        glUseProgram(shader.getId());

        // color uniform
        float timeValue = glfwGetTime();
        float greenValue = (sin(timeValue) / 2.0f) + 0.5f;
        int vertexColorLocation = glGetUniformLocation(shader.getId(), "ourColor");
        glUniform4f(vertexColorLocation, 0.5f, greenValue, 0.5f, 1.0f);

        // // instance offset
        // int offsetLocation = glGetUniformLocation(shader.getId(), "offset");
        // glUniform3f(offsetLocation, 10.0f,1.0f,1.0f);

        // create model transformations
        float angle = 20.0f;
        glm::mat4 model = glm::mat4(1.0f);
        // model = glm::translate(model, glm::vec3(1.0f, 1.0f, -1.0f));
        // model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
        unsigned int modelLoc = glGetUniformLocation(shader.getId(), "model");
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

        // create view transformations
        float radius = 100.0f;
        float camX = sin(glfwGetTime()) * radius;
        float camZ = cos(glfwGetTime()) * radius;
        glm::mat4 view = glm::lookAt(glm::vec3(camX, 50.0,camZ), glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 1.0, 0.0));
        unsigned int viewLoc = glGetUniformLocation(shader.getId(), "view");
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
        
        // draw
        glBindVertexArray(vao.getId()); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
        // glDrawArrays(GL_TRIANGLES, 0, 36);
        glDrawArraysInstanced(GL_TRIANGLES, 0, 36, gripWidth * gripHeight);
        //glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        // glBindVertexArray(0); // no need to unbind it every time 

        ui.loop_end();
        window.swapBuffers();
    }

    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    /*glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    glDeleteProgram(shaderProgram);*/
    ui.close();
    window.close();
    return 0;
}