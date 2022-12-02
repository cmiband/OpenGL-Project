#include "collSystem.h"

bool collSystem::containsOnYAxis(std::vector<glm::vec2>& objectOneCorners, std::vector<glm::vec2>& objectTwoCorners)
{
    if (objectOneCorners[1].x >= objectTwoCorners[0].x && objectTwoCorners[1].x >= objectOneCorners[1].x) {
        return true;
    }
    else if(objectTwoCorners[1].x >= objectOneCorners[0].x && objectOneCorners[1].x >= objectOneCorners[1].x) {
        return true;
    }
    return false;
}

bool collSystem::containsOnXAxis(std::vector<glm::vec2>& objectOneCorners, std::vector<glm::vec2>& objectTwoCorners)
{
    if (objectTwoCorners[0].y >= objectOneCorners[0].y && objectOneCorners[2].y >= objectTwoCorners[0].y) {
        return true;
    }
    else if (objectOneCorners[0].y >= objectTwoCorners[0].y && objectTwoCorners[2].y >= objectOneCorners[0].y) {
        return true;
    }
    return false;
}
