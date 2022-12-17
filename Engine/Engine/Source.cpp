#include "miblib/miblib.h"
#include <vector>


int main()
{
    Window window(SCREEN_WIDTH, SCREEN_HEIGHT, "Mikoshi");
    Renderer r;

    Circle circle(glm::vec2{ 100.0f, 100.0f }, 50.0f, math::Color4<float>{0.5f, 0.5f, 0.8f, 1.0f});

    while (!window.shouldClose()) {
        r.Clear(); 

        circle.Draw(r);

        r.Swap(window);
    }

    return 0;
}