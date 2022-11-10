#include "miblib/miblib.h"

int main()
{
    Window window(SCREEN_WIDTH, SCREEN_HEIGHT, "Mikoshi");
    Renderer r;

    Circle circle(glm::vec2{ 100.0f, 100.0f }, 100.0f, math::Color4<float>{1.0f, 0.2f, 0.1f, 1.0f});
    Rectangle rect(glm::vec2{ 500.0f, 500.0f }, 50.0f, 100.0f, math::Color4<float>{0.1f, 0.2f, 0.3f, 1.0f});

    while (!window.shouldClose()) {
        r.Clear();

        circle.Draw(r);
        rect.Draw(r);

        r.Swap(window);
    }

    return 0;
}