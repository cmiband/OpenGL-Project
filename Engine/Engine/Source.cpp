#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "Application.h"

int main(void)
{
    Application *app = new Application(640, 480, "window");
    delete app;

    return 0;
}