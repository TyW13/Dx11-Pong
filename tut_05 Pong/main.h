#pragma once

#ifndef UTILITIES_H
#define UTILITIES_H
#include "utilities.h"
#endif

#include "Background.h"
#include "Paddles.h"
#include "main.h"
#ifndef BALL_H
#define BALL_H
#include "ball.h"
#endif
#include "winText.h"
#include "score.h"

class pongGameClass
{
public:
	pongGameClass() {}

	void init(Background&, Paddles&, Paddles&, Ball&, winText&, winText&, Score&, Score&);
	void update(Paddles&, Paddles&, Ball&, Score&, Score&);
	void render(Background&, Paddles&, Paddles&, Ball&, winText&, winText&, Score&, Score&);

	Sound getWinSound();
	void setCanPlayWinSound(bool);
	
	RenderWindow pWindow;
private:
	Time dt;
	bool canPlayWinSound = true;

	SoundBuffer winSoundBuffer;
	Sound winSound;
};

inline Sound pongGameClass::getWinSound()
{
	return winSound;
}

inline void pongGameClass::setCanPlayWinSound(bool canPlay)
{
	canPlayWinSound = canPlay;
}