#include "main.h"

int main()
{
	Clock clock;

	pongGameClass pGame;
	Background background;
	Paddles player1Paddle(true, clock);
	Paddles player2Paddle(false, clock);
	Ball ball(clock);
	Score p1ScoreText(true);
	Score p2ScoreText(false);
	winText p1WinText(true);
	winText p2WinText(false);

	// Create the main window
	pGame.pWindow.create(VideoMode(GC::SCREEN_RES.x, GC::SCREEN_RES.y), "Pong");
	pGame.init(background, player1Paddle, player2Paddle, ball, p1WinText, p2WinText, p1ScoreText, p2ScoreText);

	srand(time(NULL));

	// Start the game loop 
	while (pGame.pWindow.isOpen())
	{
		float elapsed = clock.getElapsedTime().asSeconds();
		clock.restart();



		// Process events
		Event event;
		while (pGame.pWindow.pollEvent(event))
		{
			// Close window: exit
			if (event.type == Event::Closed)
				pGame.pWindow.close();

			if (event.type == Event::TextEntered)
			{
				// Exit the game
				if (event.text.unicode == GC::ESCAPE_KEY)
					pGame.pWindow.close();

				else if (event.text.unicode == GC::ENTER_KEY)
				{
					// Shoot ball
					ball.setBallMovementVec();
					ball.setCurrentPhase(2);
				}
				else if (event.text.unicode == GC::RESTART_KEY)
				{
					// Reset the game
					pGame.getWinSound().stop();
					pGame.setCanPlayWinSound(true);
					p1ScoreText.setScoreDisplay();
					p2ScoreText.setScoreDisplay();
					player1Paddle.setPaddlePos();
					player2Paddle.setPaddlePos();

					switch (ball.getWhoScored())
					{
					case(1):
						ball.resetBallPos(player1Paddle, player2Paddle, 1);
						break;
					case(2):
						ball.resetBallPos(player1Paddle, player2Paddle, 2);
						break;
					}
					
				}
			}
		}


		// Clear screen
		pGame.pWindow.clear();

		pGame.render(background, player1Paddle, player2Paddle, ball, p1WinText, p2WinText, p1ScoreText, p2ScoreText);

		pGame.update(player1Paddle, player2Paddle, ball, p1ScoreText, p2ScoreText);

		// Update the window
		pGame.pWindow.display();
	}

	return EXIT_SUCCESS;
}


void pongGameClass::init(Background& bgnd, Paddles& p1Paddle, Paddles& p2Paddle, Ball& ball, winText& p1WinText, winText& p2WinText, Score& p1ScoreText, Score& p2ScoreText)
{
	GF::loadAudio("data/Audio/score_Cheer.wav", winSoundBuffer);

	winSound.setBuffer(winSoundBuffer);

	bgnd.bgndInit();
	p1Paddle.paddleInit();
	p2Paddle.paddleInit();
	ball.ballInit(p1Paddle.getPaddlePos());
	p1ScoreText.scoreInit();
	p2ScoreText.scoreInit();
	p1WinText.winTextInit();
	p2WinText.winTextInit();
}

void pongGameClass::update(Paddles& p1Paddle, Paddles& p2Paddle, Ball& ball, Score& p1ScoreText, Score& p2ScoreText)
{
	p1Paddle.paddleUpdate();
	p2Paddle.paddleUpdate();
	ball.ballUpdate(p1Paddle, p2Paddle);
	p1ScoreText.scoreUpdate(p1Paddle, p2Paddle, ball);
	p2ScoreText.scoreUpdate(p1Paddle, p2Paddle, ball);
}

void pongGameClass::render(Background& bgnd, Paddles& p1Paddle, Paddles& p2Paddle, Ball& ball, winText& p1WinText, winText& p2WinText, Score& p1ScoreText, Score& p2ScoreText)
{
	if (p1ScoreText.getScore() >= 11)
	{
		pWindow.draw(p1WinText.getSprite());

		if (canPlayWinSound == true)
		{
			winSound.play();
			canPlayWinSound = false;
		}
	}

	else if (p2ScoreText.getScore() >= 11)
	{
		pWindow.draw(p2WinText.getSprite());

		if (canPlayWinSound == true)
		{
			winSound.play();
			canPlayWinSound = false;
		}
	}

	else
	{
		pWindow.draw(bgnd.getSprite());
		pWindow.draw(p1Paddle.getSprite());
		pWindow.draw(p2Paddle.getSprite());
		pWindow.draw(ball.getSprite());
	}

	pWindow.draw(p1ScoreText.getSprite());
	pWindow.draw(p2ScoreText.getSprite());
}