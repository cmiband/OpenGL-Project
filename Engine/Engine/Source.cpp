#include "miblib/miblib.h"
#include <vector>


int main()
{
    Window window(SCREEN_WIDTH, SCREEN_HEIGHT, "Mikoshi");
    Renderer r;

    Rectangle rect(glm::vec2{ 500.0f, 500.0f }, 50.0f, 100.0f, math::Color4<float>{0.1f, 0.2f, 0.3f, 1.0f});
    Rectangle rect2(glm::vec2{ 100.0f, 410.0f }, 50.0f, 100.0f, math::Color4<float>{0.5f, 0.3f, 0.1f, 1.0f});

    float posX = rect.getPosition().x;
    float diff = 2.0f;
    bool dir = true;

    while (!window.shouldClose()) {
        r.Clear(); 

        if (Keyboard::keyPressed(window, GLFW_KEY_W)) {
            rect2.Move(glm::vec2{ 0.0f, 5.0f });
        }
        if (Keyboard::keyPressed(window, GLFW_KEY_A)) {
            rect2.Move(glm::vec2{ -5.0f, 0.0f });
        }
        if (Keyboard::keyPressed(window, GLFW_KEY_S)) {
            rect2.Move(glm::vec2{ 0.0f, -5.0f });
        }
        if (Keyboard::keyPressed(window, GLFW_KEY_D)) {
            rect2.Move(glm::vec2{ 5.0f, 0.0f });
        }       

        rect.Draw(r);
        rect2.Draw(r);

        std::cout << rect.collidesWith(rect2) << std::endl;

        r.Swap(window);
    }

    return 0;
}