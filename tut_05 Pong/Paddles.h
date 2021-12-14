#pragma once

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "gameObject.h"
#endif

#include "loadFiles.h"

#include "vec2f.h"

// Paddle Class
class Paddles : public gameObjectClass
{
public:
	Paddles() {}
	Paddles(bool isLeftHand, Clock gameClock) 
	{ 
		leftHand = isLeftHand;
		dtClock = gameClock;
	}

	void paddleInit();
	void paddleUpdate();

	void setPaddles();
	void setPaddlePos();
	Vec2f getPaddlePos();
	void setPaddleSize();
	Sprite getSprite();
	void isLeftHand(bool);
private:
	Texture paddleTex;
	Sprite player1Spr;
	Sprite player2Spr;
	bool leftHand;
	Vec2f player1Pos;
	Vec2f player2Pos;
	Clock dtClock;
};