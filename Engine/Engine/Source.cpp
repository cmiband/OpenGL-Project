#include "miblib/miblib.h"
#include <stdlib.h>
#include <time.h>
#include <vector>

int main()
{
    Window window(SCREEN_WIDTH, SCREEN_HEIGHT, "Mikoshi");
    Renderer r;

    srand(time(NULL));

    float ballWidth = 20.0f;
    float racketWidth = 160.0f;
    Rectangle ball(glm::vec2{ 400.0f, 10.0f }, ballWidth, ballWidth, math::Color4<float>{0.1f, 0.1f, 0.9f, 1.0f});
    Rectangle racket(glm::vec2{ SCREEN_WIDTH / 2, 30.0f }, racketWidth, 10.0f, math::Color4<float>{0.5f, 0.9f, 0.1f, 1.0f});

    const int numberOfRectsInARow = 16;
    const float space = 6.25f;
    const float bigRectWidth = 100.0f;
    const float middleRectWidth = 50.0f;
    const float smallRectWidth = 40.0f;
    const float rectHeight = 50.0f;
    float possibilities[] = {300.0f, 400.0f, 200.0f};
    float offsetX = 0;
    std::vector<Rectangle*> blocks;
    float offsetTest = 0.0f;
    
    bool canAddNewRect = true;
    for (int i = 0; i < numberOfRectsInARow; i++) {
        int randomNumber = rand() % 2 + 0;

        if(possibilities[randomNumber] <= 0) {
            int spaceLeftFirst = possibilities[0];
            int spaceLeftSecond = possibilities[1];
            int spaceLeftThird = possibilities[2];

            if (spaceLeftFirst > 0) {
                randomNumber = 0;
            }
            else if (spaceLeftSecond > 0) {
                randomNumber = 1;
            }
            else if (spaceLeftThird > 0) {
                randomNumber = 2;
            }
            else break;
        }
        
        if(randomNumber == 0){
            Rectangle *rect = new Rectangle(glm::vec2{ offsetX,400.0f }, bigRectWidth, rectHeight, math::Color4<float>{1.0f, 0.0f, 0.0f, 1.0f});
            blocks.push_back(rect);
            offsetX += bigRectWidth + space;
            possibilities[randomNumber] -= bigRectWidth;
        }
        else if(randomNumber == 1) {
            Rectangle *rect = new Rectangle(glm::vec2{ offsetX,400.0f }, middleRectWidth, rectHeight, math::Color4<float>{1.0f, 0.0f, 0.0f, 1.0f});
            blocks.push_back(rect);
            offsetX += middleRectWidth + space;
            possibilities[randomNumber] -= middleRectWidth;
        }
        else if(randomNumber == 2) {
            Rectangle *rect = new Rectangle(glm::vec2{ offsetX,400.0f }, smallRectWidth, rectHeight, math::Color4<float>{1.0f, 0.0f, 0.0f, 1.0f});
            blocks.push_back(rect);
            offsetX += smallRectWidth + space;
            possibilities[randomNumber] -= smallRectWidth;
        }
    }

    float ballSpeedX = 8.0f;
    float ballSpeedY = 8.0f;
    float racketSpeed = 12.0f;
    bool moveUp = true;
    bool moveRight = true;

    while (!window.shouldClose()) {
        r.Clear();

        if (ball.GetPosition().y >= SCREEN_HEIGHT - ballWidth) {
            moveUp = false;
        }
        if (ball.GetPosition().y <= 0) {
            moveUp = true;
        }
        if (ball.GetPosition().x >= SCREEN_WIDTH - ballWidth) {
            moveRight = false;
        }
        if (ball.GetPosition().x <= 0) {
            moveRight = true;
        }

        if (racket.CollidesWith(ball)) {
            moveUp = true;
            glm::vec2 ballPosition = ball.GetPosition();
            if (ballPosition.x < racket.GetPosition().x + racketWidth/2) {
                moveRight = false;
            }
            else{
                moveRight = true;
            }
            std::cout << "Collision" << std::endl;
        }
        
        if (moveRight) {
            ballSpeedX = 5.0f;
        }
        else {
            ballSpeedX = -5.0f;
        }
        if (moveUp) {
            ballSpeedY = 5.0f;
        }
        else {
            ballSpeedY = -5.0f;
        }

        if (Keyboard::KeyPressed(window, GLFW_KEY_A) && racket.GetPosition().x >= 0) {
            racket.Move(glm::vec2{ -racketSpeed,0 });
        }
        if (Keyboard::KeyPressed(window, GLFW_KEY_D) && racket.GetPosition().x <= SCREEN_WIDTH-racketWidth) {
            racket.Move(glm::vec2{ racketSpeed,0 });
        }

        ball.Move(glm::vec2{ ballSpeedX,ballSpeedY });

        ball.Draw(r);
        racket.Draw(r);
        for (int i = 0; i < blocks.size(); i++) {
            blocks[i]->Draw(r);
        }

        r.Swap(window);
    }
    return 0;
}