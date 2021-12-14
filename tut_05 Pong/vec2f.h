#pragma once

#include "SFML/Graphics.hpp"

class Vec2f
{
public:
	float getX();
	float getY();
	void setX(float);
	void setY(float);
private:
	float x;
	float y;
};