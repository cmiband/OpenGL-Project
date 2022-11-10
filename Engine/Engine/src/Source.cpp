#include "Application.h"
#include "Window.h"
#include "MEngine.h"

int main()
{
    Window window(680, 680, "Mikoshi");
    Renderer r;

    while (!window.shouldClose()) {
        r.Clear();

        r.Swap(window);
    }

    return 0;
}