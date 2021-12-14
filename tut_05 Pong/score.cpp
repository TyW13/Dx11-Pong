#include "score.h"

void Score::scoreInit()
{
	GF::loadTexture("data/Sprites/scores.png", scoreTex, false);
	GF::loadAudio("data/Audio/score_Cheer.wav", scoreSoundBuffer);

	scoreSound.setBuffer(scoreSoundBuffer);
	setScoreDisplay();
}

void Score::scoreUpdate(Paddles paddle1, Paddles paddle2, Ball& ball)
{
	switch (isP1)
	{
	// Player 1 scores
	case(true):
		if (ball.getSprite().getPosition().x >= GC::SCREEN_RES.x)
		{
			if (p1Score < 11)
			{
				ball.setWhoScored(1);
				ball.resetBallPos(paddle1, paddle2, 1);
				ball.setCurrentPhase(1);
				++p1Score;
				scoreSpr.setTextureRect(GC::SCORE_DIMS[p1Score]);

				if (p1Score < 11)
				{
					scoreSound.play();
				}
			}
		}
		break;

	// Player 2 scores
	case(false):
		if (ball.getSprite().getPosition().x <= 0)
		{
			if (p2Score < 11)
			{
				ball.setWhoScored(2);
				ball.setCurrentPhase(1);
				++p2Score;
				scoreSpr.setTextureRect(GC::SCORE_DIMS[p2Score]);

				if (p2Score < 11)
				{
					scoreSound.play();
				}
			}
		}
		break;
	}
}

void Score::setScoreDisplay()
{
	scoreSpr.setTexture(scoreTex);
	scoreSpr.setTextureRect(GC::SCORE_DIMS[0]);
	scoreSpr.setOrigin(scoreSpr.getTextureRect().width / 2, scoreSpr.getTextureRect().height / 2);
	scoreSpr.setScale(9.0f, 9.0f);
	setScorePos();
	p1Score = 0;
	p2Score = 0;
}

void Score::setScorePos()
{
	switch (isP1)
	{
	case(true):
		scorePos.setX(770.0f);
		scorePos.setY(150.0f);
		scoreSpr.setPosition(scorePos.getX(), scorePos.getY());
		break;
	case(false):
		scorePos.setX(1130.0f);
		scorePos.setY(150.0f);
		scoreSpr.setPosition(scorePos.getX(), scorePos.getY());
		break;
	}
}

int Score::getScore()
{
	switch (isP1)
	{
	case(true):
		return p1Score;
		break;
	case(false):
		return p2Score;
		break;
	}
}

Sprite Score::getSprite()
{
	return scoreSpr;
}