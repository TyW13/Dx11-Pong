#include "winText.h"

void winText::winTextInit()
{
	GF::loadTexture("data/Sprites/winText_001.png", p1WinTextTex, true);
	GF::loadTexture("data/Sprites/winText_002.png", p2WinTextTex, true);

	setWinText();
}

void winText::setWinText()
{
	p1WinTextSpr.setTexture(p1WinTextTex);
	IntRect p1TexRect = p1WinTextSpr.getTextureRect();
	p1WinTextSpr.setOrigin(p1TexRect.width / 2.0f, p1TexRect.height / 2.0f);

	p2WinTextSpr.setTexture(p2WinTextTex);
	IntRect p2TexRect = p2WinTextSpr.getTextureRect();
	p2WinTextSpr.setOrigin(p2TexRect.width / 2.0f, p2TexRect.height / 2.0f);

	setWinTextPos();
}

void winText::setWinTextPos()
{
	switch (p1Win)
	{
	case(true):
		p1WinTextPos.setX(GC::SCREEN_RES.x / 2);
		p1WinTextPos.setY(GC::SCREEN_RES.y / 2);
		p1WinTextSpr.setPosition(p1WinTextPos.getX(), p1WinTextPos.getY());
		break;
	case(false):
		p2WinTextPos.setX(GC::SCREEN_RES.x / 2);
		p2WinTextPos.setY(GC::SCREEN_RES.y / 2);
		p2WinTextSpr.setPosition(p2WinTextPos.getX(), p2WinTextPos.getY());
		break;
	}
}

Sprite winText::getSprite()
{
	switch (p1Win)
	{
	case(true):
		return p1WinTextSpr;
		break;
	case(false):
		return p2WinTextSpr;
		break;
	}
}