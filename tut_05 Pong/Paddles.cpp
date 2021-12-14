#include "Paddles.h"

void Paddles::paddleInit()
{
	GF::loadTexture("data/Sprites/characterSprite_000.png", paddleTex, true);
	setPaddles();
	setPaddleSize();
}

void Paddles::paddleUpdate()
{
	Time dt = dtClock.restart();
	// PLAYER 1 PADDLE
	if (leftHand == true)
	{
		//player1Spr.setPosition(player1Pos.getX(), player1Pos.getY());
		if (Keyboard::isKeyPressed(Keyboard::W))
		{
			if (player1Pos.getY() > (((player1Spr.getTextureRect().height / 2) * GC::PADDLE_SCALE.y) + GC::SIDE_BOUNDRY_SIZE))
			{
				player1Pos.setY(player1Pos.getY() + -GC::PLAYER1_SPEED * dt.asSeconds());
				player1Spr.setPosition(player1Pos.getX(), player1Pos.getY());
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::S))
		{
			if (player1Pos.getY() < (GC::SCREEN_RES.y - ((player1Spr.getTextureRect().height / 2) * GC::PADDLE_SCALE.y) - GC::SIDE_BOUNDRY_SIZE))
			{
				player1Pos.setY(player1Pos.getY() + GC::PLAYER1_SPEED * dt.asSeconds());
				player1Spr.setPosition(player1Pos.getX(), player1Pos.getY());
			}
		}
	}

	// PLAYER 2 PADDLE
	if (leftHand == false)
	{
		//player1Spr.setPosition(player1Pos.getX(), player1Pos.getY());
		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			if (player2Pos.getY() > (((player2Spr.getTextureRect().height / 2) * GC::PADDLE_SCALE.y) + GC::SIDE_BOUNDRY_SIZE))
			{
				player2Pos.setY(player2Pos.getY() + (-GC::PLAYER1_SPEED * dt.asSeconds()));
				player2Spr.setPosition(player2Pos.getX(), player2Pos.getY());
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			if (player2Pos.getY() < (GC::SCREEN_RES.y - ((player2Spr.getTextureRect().height / 2) * GC::PADDLE_SCALE.y) - GC::SIDE_BOUNDRY_SIZE))
			{
				player2Pos.setY(player2Pos.getY() + (GC::PLAYER1_SPEED * dt.asSeconds()));
				player2Spr.setPosition(player2Pos.getX(), player2Pos.getY());
			}
		}
	}
}

void Paddles::setPaddles()
{
	player1Spr.setTexture(paddleTex);
	IntRect texRect = player1Spr.getTextureRect();
	player1Spr.setOrigin(texRect.width / 2.0f, texRect.height / 2.0f);

	player2Spr.setTexture(paddleTex);
	player2Spr.setOrigin(texRect.width / 2.0f, texRect.height / 2.0f);

	setPaddlePos();
	getPaddlePos();
}

void Paddles::setPaddlePos()
{
	if (leftHand == true)
	{
		player1Pos.setX(20);
		player1Pos.setY(540);
		player1Spr.setPosition(player1Pos.getX(), player1Pos.getY());
	}

	else if (leftHand == false)
	{
		player2Pos.setX(1900);
		player2Pos.setY(540);

		player2Spr.setPosition(player2Pos.getX(), player2Pos.getY());
	}
}

Vec2f Paddles::getPaddlePos()
{
	switch (leftHand)
	{
	case(true):
		return player1Pos;
		break;
	case(false):
		return player2Pos;
		break;
	}
}

void Paddles::setPaddleSize()
{
	player1Spr.setScale(GC::PADDLE_SCALE);
	player2Spr.setScale(GC::PADDLE_SCALE);
}

Sprite Paddles::getSprite()
{
	switch (leftHand)
	{
	case(true):
		return player1Spr;
		break;
	case(false):
		return player2Spr;
		break;
	}
}

void Paddles::isLeftHand(bool newLeftHand)
{
	leftHand = newLeftHand;
}