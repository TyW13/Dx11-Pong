#pragma once

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "gameObject.h"
#endif

#include "loadFiles.h"

#include "vec2f.h"

// Win text class
class winText : public gameObjectClass
{
public:
	winText() {}
	winText(bool p1DidWin) {
		p1Win = p1DidWin;
	}

	void winTextInit();

	void setWinText();
	void setWinTextPos();
	Sprite getSprite();
private:
	Texture p1WinTextTex;
	Texture p2WinTextTex;
	Sprite p1WinTextSpr;
	Sprite p2WinTextSpr;
	bool p1Win;
	Vec2f p1WinTextPos;
	Vec2f p2WinTextPos;
};