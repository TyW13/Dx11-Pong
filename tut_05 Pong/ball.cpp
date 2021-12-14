#include "ball.h"

void Ball::ballInit(Vec2f paddlePos)
{
	GF::loadTexture("data/Sprites/ballSprite_000.png", ballTex, true);
	GF::loadAudio("data/Audio/paddle_Hit.wav", paddleHitBuffer);
	GF::loadAudio("data/Audio/wall_Hit.wav", wallHitBuffer);
	paddleHitSound.setBuffer(paddleHitBuffer);
	wallHitSound.setBuffer(wallHitBuffer);
	setBall(paddlePos);
	currentPhase = phaseOptions::stationary;
	ballMovementVector.setX(1.0f);
	ballMovementVector.setY(0.5f);
}

void Ball::ballUpdate(Paddles paddle1, Paddles paddle2)
{
	Time dt = dtClock.restart();
	switch (currentPhase)
	{
	case(phaseOptions::stationary):
		resetBallPos(paddle1, paddle2, whoScored);
		ballMovementVector.setX(0);
		ballMovementVector.setY(0);
		currentPhase = phaseOptions::stationary;
		break;
	case(phaseOptions::moving):
		// Movement
		ballPos.setX(ballSpr.getPosition().x);
		ballPos.setY(ballSpr.getPosition().y);
		ballSpr.setPosition(ballPos.getX() + (ballMovementVector.getX() * (currentBallSpeed * dt.asSeconds())), ballPos.getY() + (ballMovementVector.getY() * (currentBallSpeed * dt.asSeconds())));


		/// Collision with player paddles
		// Player 1 paddle
		if (ballSpr.getGlobalBounds().intersects(paddle1.getSprite().getGlobalBounds()))
		{
			ballMovementVector.setX(1);
			setBallSpeed();
			paddleHitSound.play();
		}

		// Player 2 paddle
		else if (ballSpr.getGlobalBounds().intersects(paddle2.getSprite().getGlobalBounds()))
		{
			ballMovementVector.setX(-1);
			setBallSpeed();
			paddleHitSound.play();
		}

		/// Collision with walls
		// Top wall
		if (ballPos.getY() <= ((ballSpr.getTextureRect().height * GC::BALL_SCALE) / 2) + GC::SIDE_BOUNDRY_SIZE)
		{
			ballMovementVector.setY(0.5);
			wallHitSound.play();
		}

		// Bottom wall
		else if (ballPos.getY() >= GC::SCREEN_RES.y - ((ballSpr.getTextureRect().height * GC::BALL_SCALE) / 2) - GC::SIDE_BOUNDRY_SIZE)
		{
			ballMovementVector.setY(-0.5);
			wallHitSound.play();
		}
		break;
	}
}

void Ball::setBall(Vec2f paddlePos)
{
	ballSpr.setTexture(ballTex);
	IntRect texRect = ballSpr.getTextureRect();
	ballSpr.setScale(GC::BALL_SCALE, GC::BALL_SCALE);
	ballSpr.setOrigin(texRect.width / 2.0f, texRect.height / 2.0f);
	setInitBallPos(paddlePos);
	ballSpr.setPosition(ballPos.getX(), ballPos.getY());
}

void Ball::setInitBallPos(Vec2f paddlePos)
{
	ballPos.setX(paddlePos.getX() + 20);
	ballPos.setY(paddlePos.getY());
}

void Ball::setBallSpeed()
{
	float speedMultiplier = 1.035f;

	if (currentBallSpeed < GC::MAX_BALL_SPEED)
	{
		currentBallSpeed *= speedMultiplier;
	}
}

void Ball::setBallMovementVec()
{
	switch (whoScored)
	{
	case(1):
		ballMovementVector.setX(-1);
		if (ballSpr.getPosition().y > GC::SCREEN_RES.y / 2)
		{
			ballMovementVector.setY(0.5);
		}
		else if (ballSpr.getPosition().y <= GC::SCREEN_RES.y / 2)
		{
			ballMovementVector.setY(-0.5);
		}
		break;
	case(2):
		ballMovementVector.setX(1);
		if (ballSpr.getPosition().y > GC::SCREEN_RES.y / 2)
		{
			ballMovementVector.setY(0.5);
		}
		else if (ballSpr.getPosition().y <= GC::SCREEN_RES.y / 2)
		{
			ballMovementVector.setY(-0.5);
		}
		break;
	}
}

//Ball::phaseOptions Ball::getCurrentPhase()
//{
//	return currentPhase;
//}

void Ball::setCurrentPhase(int phaseNum)
{
	switch (phaseNum)
	{
	case(1):
		currentPhase = phaseOptions::stationary;
		break;
	case(2):
		currentPhase = phaseOptions::moving;
		break;
	}
}

void Ball::resetBallPos(Paddles paddle1, Paddles paddle2, int whoScored)
{
	switch (whoScored)
	{
	case(1):
		ballSpr.setPosition(paddle2.getPaddlePos().getX() - 20, paddle2.getPaddlePos().getY());
		currentPhase = phaseOptions::stationary;
		break;
	case(2):
		ballSpr.setPosition(paddle1.getPaddlePos().getX() + 20, paddle1.getPaddlePos().getY());
		currentPhase = phaseOptions::stationary;
		break;
	default:
		assert(false);
	}
}

void Ball::setWhoScored(int newWhoScored)
{
	whoScored = newWhoScored;
}

int Ball::getWhoScored()
{
	return whoScored;
}

Sprite Ball::getSprite()
{
	return ballSpr;
}

void Ball::setBallsPos(int x, int y)
{
	ballPos.setX(x);
	ballPos.setY(y);
	ballSpr.setPosition(ballPos.getX(), ballPos.getY());
}