#include "miblib/miblib.h"
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <chrono>
#include <thread>

void BuildGame(std::vector<Rectangle*> &arrayOfBlocks, float rectHeight) {
    arrayOfBlocks.clear();
    const int numberOfRectsInARow = 12;
    const int numberOfRows = 5;
    const float space = 6.25f;
    const float bigRectWidth = 100.0f;
    const float middleRectWidth = 80.0f;
    const float smallRectWidth = 60.0f;
    float possibilities[] = { 400.0f, 480.0f, 120.0f };
    float offsetX = 0;
    float offsetY = 350.0f;

    bool canAddNewRect = true;
    for (int j = 0; j < numberOfRows; j++) {
        for (int i = 0; i < numberOfRectsInARow; i++) {
            int randomNumber = rand() % 2 + 0;
            float colour = 0.01f;
            int randomizerOne = rand() % 99 + 0;
            int randomizerTwo = rand() % 99 + 0;
            int randomizerThree = rand() % 99 + 0;

            if (possibilities[randomNumber] <= 0) {
                float spaceLeftFirst = possibilities[0];
                float spaceLeftSecond = possibilities[1];
                float spaceLeftThird = possibilities[2];

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

            if (randomNumber == 0) {
                Rectangle* rect = new Rectangle(glm::vec2{ offsetX,offsetY }, bigRectWidth, rectHeight, math::Color4<float>{(float)(colour* randomizerOne), (float)(colour* randomizerTwo), (float)(colour* randomizerThree), 1.0f});
                arrayOfBlocks.push_back(rect);
                offsetX += bigRectWidth + space;
                possibilities[randomNumber] -= bigRectWidth;
            }
            else if (randomNumber == 1) {
                Rectangle* rect = new Rectangle(glm::vec2{ offsetX,offsetY }, middleRectWidth, rectHeight, math::Color4<float>{(float)(colour* randomizerOne), (float)(colour* randomizerTwo), (float)(colour* randomizerThree), 1.0f});
                arrayOfBlocks.push_back(rect);
                offsetX += middleRectWidth + space;
                possibilities[randomNumber] -= middleRectWidth;
            }
            else if (randomNumber == 2) {
                Rectangle* rect = new Rectangle(glm::vec2{ offsetX,offsetY }, smallRectWidth, rectHeight, math::Color4<float>{(float)(colour* randomizerOne), (float)(colour* randomizerTwo), (float)(colour* randomizerThree), 1.0f});
                arrayOfBlocks.push_back(rect);
                offsetX += smallRectWidth + space;
                possibilities[randomNumber] -= smallRectWidth;
            }

            if (i == numberOfRectsInARow - 1) {
                offsetY += rectHeight + space;
                offsetX = 0;
                possibilities[0] = 400.0f;
                possibilities[1] = 480.0f;
                possibilities[2] = 120.0f;
            }
        }
    }
};

void setBallSpeedX(float& speed, float value) { speed = value; }
void setBallSpeedY(float& speed, float value) { speed = value; }

int main()
{
    Window window(SCREEN_WIDTH, SCREEN_HEIGHT, "Atari Breakout");
    Renderer r;

    srand(time(NULL));

    float ballWidth = 20.0f;
    const float racketWidth = 160.0f;
    const float racketHeight = 10.0f;
    Rectangle ball(glm::vec2{ 400.0f, 10.0f }, ballWidth, ballWidth, math::Color4<float>{0.1f, 0.1f, 0.9f, 1.0f});
    Rectangle racket(glm::vec2{ SCREEN_WIDTH / 2, 30.0f }, racketWidth, racketHeight, math::Color4<float>{0.5f, 0.9f, 0.1f, 1.0f});
    const float rectHeight = 50.0f;

    std::vector<Rectangle*> blocks;
    BuildGame(blocks, rectHeight);

    const float defaultSpeed = 4.0f;
    int amountOfLives = 3;
    float ballSpeedX = defaultSpeed;
    float ballSpeedY = defaultSpeed;
    float racketSpeed = 12.0f;
    bool moveUp = true;
    bool moveRight = true;

    while (!window.shouldClose()) {
        r.Clear();

        if (blocks.size() == 0) {
            amountOfLives = 3;
            BuildGame(blocks, rectHeight);
            ball.SetPosition(glm::vec2{ SCREEN_WIDTH / 2, 150.0f });
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            setBallSpeedY(ballSpeedY, defaultSpeed);
        }

        if (ball.GetPosition().y >= SCREEN_HEIGHT - ballWidth) {
            setBallSpeedY(ballSpeedY, -defaultSpeed);
        }
        if (ball.GetPosition().y <= 0) {
            amountOfLives--;
            if (amountOfLives == 0) {
                BuildGame(blocks,rectHeight);
                amountOfLives = 3;
            }
            ball.SetPosition(glm::vec2{ SCREEN_WIDTH / 2, 150.0f });
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            setBallSpeedY(ballSpeedY, defaultSpeed);
        }
        if (ball.GetPosition().x >= SCREEN_WIDTH - ballWidth) {
            setBallSpeedX(ballSpeedX, -defaultSpeed);
        }
        if (ball.GetPosition().x <= 0) {
            setBallSpeedX(ballSpeedX, defaultSpeed);
        }

        if (racket.CollidesWith(ball)) {
            setBallSpeedY(ballSpeedY, defaultSpeed);
            glm::vec2 ballPosition = ball.GetPosition();
            if (ballPosition.x < racket.GetPosition().x + racketWidth/2) {
                setBallSpeedX(ballSpeedX, -defaultSpeed);
            }
            else{
                setBallSpeedX(ballSpeedX, defaultSpeed);
            }
            std::cout << "Collision" << std::endl;
        }

        if (Keyboard::KeyPressed(window, GLFW_KEY_A) && racket.GetPosition().x >= 0) {
            racket.Move(glm::vec2{ -racketSpeed,0 });
        }
        if (Keyboard::KeyPressed(window, GLFW_KEY_D) && racket.GetPosition().x <= SCREEN_WIDTH-racketWidth) {
            racket.Move(glm::vec2{ racketSpeed,0 });
        }

        ball.Move(glm::vec2{ ballSpeedX,ballSpeedY });

        racket.Draw(r);
        for (int i = 0; i < blocks.size(); i++) {
            blocks[i]->Draw(r);

            if (ball.CollidesWith(*blocks[i])) {
                glm::vec2 blockPos = blocks[i]->GetPosition();
                glm::vec2 ballPos = ball.GetPosition();
                if (blockPos.y >= ballPos.y) {
                    setBallSpeedY(ballSpeedY, -defaultSpeed);
                }
                else if(ballPos.y >= blockPos.y+rectHeight) {
                    setBallSpeedY(ballSpeedY, defaultSpeed);
                }

                if (blockPos.x >= ballPos.x) {
                    setBallSpeedX(ballSpeedX, -defaultSpeed);
                }
                else if(ballPos.x >= blockPos.x + blocks[i]->GetWidth()) {
                    setBallSpeedX(ballSpeedX, defaultSpeed);
                }
                blocks.erase(blocks.begin()+i, blocks.begin()+i+1);
            }
        }
        ball.Draw(r);

        r.Swap(window);
    }
    return 0;
}