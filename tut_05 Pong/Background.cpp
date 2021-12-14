#include "background.h"

void Background::bgndInit()
{
	GF::loadTexture("data/Sprites/background_000.png", bgndTex, false);
	setBackground();
}

void Background::setBackground()
{
	bgndSpr.setTexture(bgndTex);
	IntRect texRect = bgndSpr.getTextureRect();
	bgndSpr.setOrigin(texRect.width / 2.0f, texRect.height / 2.0f);
	bgndSpr.setScale(10.f, 10.f);
	setBackgroundPos();
}

void Background::setBackgroundPos()
{
	bgndPos.setX(GC::SCREEN_RES.x / 2);
	bgndPos.setY(GC::SCREEN_RES.y / 2);
	bgndSpr.setPosition(bgndPos.getX(), bgndPos.getY());
}

Sprite Background::getSprite()
{
	return bgndSpr;
}
