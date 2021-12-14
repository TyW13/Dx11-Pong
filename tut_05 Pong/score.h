#pragma once

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "gameObject.h"
#endif

#include "loadFiles.h"
#include "vec2f.h"
#ifndef BALL_H
#define BALL_H
#include "ball.h"
#endif

// Score class
class Score : gameObjectClass
{
public:
	Score() {}
	Score(bool scoreIsP1)
	{
		isP1 = scoreIsP1;
		p1Score = 0;
		p2Score = 0;
	}

	void scoreInit();
	void scoreUpdate(Paddles, Paddles, Ball&);

	void setScoreDisplay();
	void setScorePos();
	int getScore();
	Sprite getSprite();
private:
	Texture scoreTex;
	Sprite scoreSpr;
	Vec2f scorePos;
	SoundBuffer scoreSoundBuffer;
	Sound scoreSound;

	bool isP1;
	int p1Score;
	int p2Score;
};