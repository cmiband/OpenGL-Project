#include "miblib/miblib.h"

int main()
{
    Window window(SCREEN_WIDTH, SCREEN_HEIGHT, "Mikoshi");
    Renderer r;

    Circle circle(glm::vec2{ 100.0f, 100.0f }, 100.0f, math::Color4<float>{1.0f, 0.2f, 0.1f, 1.0f});
    Rectangle rect(glm::vec2{ 500.0f, 500.0f }, 50.0f, 100.0f, math::Color4<float>{0.1f, 0.2f, 0.3f, 1.0f});

    float posX = rect.getPosition().x;
    float diff = 2.0f;
    bool dir = true;

    while (!window.shouldClose()) {
        r.Clear(); 

        if (Keyboard::keyPressed(window, GLFW_KEY_A)) {
            circle.Move(glm::vec2{ -10.0f, 0.0f });
        }
        if (Keyboard::keyPressed(window, GLFW_KEY_D)) {
            circle.Move(glm::vec2{ 10.0f, 0.0f });
        }
        if (Keyboard::keyPressed(window, GLFW_KEY_W)) {
            circle.Move(glm::vec2{ 0.0f, 10.0f });
        }
        if (Keyboard::keyPressed(window, GLFW_KEY_S)) {
            circle.Move(glm::vec2{ 0.0f, -10.0f });
        }

        if (posX > 590.0f) {
            dir = false;
        }
        if (posX < 0.0f) {
            dir = true;
        }

        if (dir)
            posX += diff;
        else
            posX -= diff;

        rect.SetPosition(glm::vec2{posX,500.0f});

        circle.Draw(r);
        rect.Draw(r);

        r.Swap(window);
    }

    return 0;
}