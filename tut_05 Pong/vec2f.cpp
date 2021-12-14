#include "vec2f.h"

float Vec2f::getX()
{
	return x;
}
float Vec2f::getY()
{
	return y;
}
void Vec2f::setX(float newX)
{
	x = newX;
}
void Vec2f::setY(float newY)
{
	y = newY;
}


sf::Vector2f operator+(Vec2f& vec1, Vec2f& vec2)
{
	return sf::Vector2f(vec1.getX() + vec2.getX(), vec1.getY() + vec2.getY());
}

sf::Vector2f operator-(Vec2f& vec1, Vec2f& vec2)
{
	return sf::Vector2f(vec1.getX() - vec2.getX(), vec1.getY() - vec2.getY());
}