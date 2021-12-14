
#pragma once
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "gameObject.h"
#endif

#include "vec2f.h"

#include "loadFiles.h"
#include "Paddles.h"

// Ball class
class Ball : public gameObjectClass
{
public:
	Ball(Clock gameClock) 
	{ 
		currentBallSpeed = GC::ORIGINAL_BALL_SPEED; 
		whoScored = 2;
		dtClock = gameClock;
	}
	void ballInit(Vec2f);
	void ballUpdate(Paddles, Paddles);
	
	void setBall(Vec2f);
	void setInitBallPos(Vec2f);
	void setBallSpeed();
	void setBallMovementVec();
	// getCurrentPhase();
	void setCurrentPhase(int);
	void resetBallPos(Paddles, Paddles, int);
	void setWhoScored(int);
	int getWhoScored();
	Sprite getSprite();

	void setBallsPos(int, int);

private:
	enum class phaseOptions { stationary, moving };
	phaseOptions currentPhase;

	Texture ballTex;
	Sprite ballSpr;
	Vec2f ballPos;
	sf::SoundBuffer paddleHitBuffer;
	sf::SoundBuffer wallHitBuffer;
	sf::Sound paddleHitSound;
	sf::Sound wallHitSound;

	Vec2f ballMovementVector;
	float currentBallSpeed;
	int whoScored;

	Clock dtClock;
};