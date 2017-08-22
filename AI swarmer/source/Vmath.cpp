#include "Vmath.h"

#define _USE_MATH_DEFINES
#include <math.h>

float magnitude(sf::Vector2f vector)
{

    return sqrt((vector.x * vector.x) + (vector.y * vector.y));
}

float angleOfVect(sf::Vector2f vector)
{

    float angle = std::atan2f(vector.y, vector.x) / (float)M_PI * 180.0f;
    return angle < 0.0f ? angle + 360.0f : angle;
}

sf::Vector2f normalise(sf::Vector2f vector)
{
    float mag = magnitude(vector);
    sf::Vector2f newVect;
    if (mag > 0)
    {
        newVect = vector / mag;
        return newVect;
    }
    //error here somehow vector magnitude is already zero
}