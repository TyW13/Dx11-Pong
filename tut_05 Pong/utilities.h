#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <string>
#include <assert.h>

using namespace sf;
using namespace std;

//dimensions in 2D that are whole numbers
struct Dim2Di
{
	int x, y;
};

//dimensions in 2D that are floating point numbers
struct Dim2Df
{
	float x, y;
};

/*
A box to put Games Constants in.
These are special numbers with important meanings (screen width,
ascii code for the escape key, number of lives a player starts with,
the name of the title screen music track, etc.
*/
namespace GC
{
	//game play related constants to tweak
	const Dim2Di SCREEN_RES{ 1920,1080 };

	const float SIDE_BOUNDRY_SIZE = 20.0f;

	const char ESCAPE_KEY{ 27 };
	const char ENTER_KEY{ 13 };
	const char RESTART_KEY{ 114 };

	const float PLAYER1_SPEED = 300.0f;
	const float PLAYER2_SPEED = 300.0f;
	const sf::Vector2f PADDLE_SCALE(3.5f, 3.5f);

	const float ORIGINAL_BALL_SPEED = 400.0f;
	const float MAX_BALL_SPEED = 450.0;
	const float BALL_SCALE = 0.3f;

	const int NUM_SCORETYPES = 12;
	const sf::IntRect SCORE_DIMS[NUM_SCORETYPES]
	{
		{0, 0 , 32, 32},
		{32, 0 , 32, 32},
		{64, 0, 32, 32},
		{0, 32, 32, 32},
		{32, 32, 32, 32},
		{64, 32, 32, 32},
		{0, 64, 32, 32},
		{32, 64, 32, 32},
		{64, 64, 32, 32},
		{0, 96, 32, 32},
		{32, 96, 32, 32},
		{64, 96, 32, 32},
	};
}