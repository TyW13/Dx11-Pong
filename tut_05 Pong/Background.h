#pragma once

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "gameObject.h"
#endif

#include "loadFiles.h"

#include "vec2f.h"

//Background image class
class Background : public gameObjectClass
{
public:
	void bgndInit();

	void setBackground();
	void setBackgroundPos();
	Sprite getSprite();
private:
	Texture bgndTex;
	Sprite bgndSpr;
	Vec2f bgndPos;
};