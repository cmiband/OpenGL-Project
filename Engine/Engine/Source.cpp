#include "miblib/miblib.h"
#include <vector>


int main()
{
    Window window(SCREEN_WIDTH, SCREEN_HEIGHT, "Mikoshi");
    Renderer r;

    float ballWidth = 10.0f;
    float racketWidth = 80.0f;
    Rectangle ball(glm::vec2{ 400.0f, 10.0f }, ballWidth, ballWidth, math::Color4<float>{0.1f, 0.1f, 0.9f, 1.0f});
    Rectangle racket(glm::vec2{ SCREEN_WIDTH / 2, 30.0f }, racketWidth, 10.0f, math::Color4<float>{0.5f, 0.9f, 0.1f, 1.0f});

    const float space = 6.6f;
    const float bigSquareWidth = 50.0f;
    const float middleSquareWidth = 35.0f;
    const float smallSquareWidth = 20.0f;

    float ballSpeedX = 5.0f;
    float ballSpeedY = 5.0f;
    float racketSpeed = 5.0f;
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

        r.Swap(window);
    }

    return 0;
}