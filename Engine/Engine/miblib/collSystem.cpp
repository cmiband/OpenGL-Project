#include "collSystem.h"

bool collSystem::containsOnXAxis(std::vector<glm::vec2>& objectOneCorners, std::vector<glm::vec2>& objectTwoCorners)
{
    int objectOneXPos0 = objectOneCorners[0].x;
    int objectOneXPos1 = objectOneCorners[1].x;
    int objectOneXPos2 = objectOneCorners[2].x;
    int objectOneXPos3 = objectOneCorners[3].x;

    int objectTwoXPos0 = objectTwoCorners[0].x;
    int objectTwoXPos1 = objectTwoCorners[1].x;
    int objectTwoXPos2 = objectTwoCorners[2].x;
    int objectTwoXPos3 = objectTwoCorners[3].x;


    if (objectTwoXPos0 > objectOneXPos0) {
        if (objectOneXPos1 >= objectTwoXPos0 && objectTwoXPos1 >= objectOneXPos1) {
            return true;
        }
    }
    else if (objectOneXPos0 > objectTwoXPos0) {
        if (objectTwoXPos1 >= objectOneXPos0 && objectOneXPos1 >= objectTwoXPos1) {
            return true;
        }
    }
    
    if (objectOneXPos0 == objectTwoXPos0 && objectOneXPos1 == objectTwoXPos1) {
        return true;
    }

    return false;
}

bool collSystem::containsOnYAxis(std::vector<glm::vec2>& objectOneCorners, std::vector<glm::vec2>& objectTwoCorners)
{
    int objectOneYPos0 = objectOneCorners[0].y;
    int objectOneYPos1 = objectOneCorners[1].y;
    int objectOneYPos2 = objectOneCorners[2].y;
    int objectOneYPos3 = objectOneCorners[3].y;
                                             
    int objectTwoYPos0 = objectTwoCorners[0].y;
    int objectTwoYPos1 = objectTwoCorners[1].y;
    int objectTwoYPos2 = objectTwoCorners[2].y;
    int objectTwoYPos3 = objectTwoCorners[3].y;


    if (objectTwoYPos0 > objectOneYPos0)
    {
        if (objectTwoYPos0 >= objectOneYPos0 && objectOneYPos2 >= objectTwoYPos0) {
            return true;
        }
    }
    else if (objectOneYPos0 > objectTwoYPos0) {
        if (objectOneYPos0 >= objectTwoYPos0 && objectTwoYPos2 >= objectOneYPos0) {
            return true;
        }
    }
    
    if (objectOneYPos0 == objectTwoYPos0 && objectOneYPos2 == objectTwoYPos2) {
        return true;
    }

    return false;
}
