// Doodle Jump.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "hash.h"
#include "stdlib.h"
#include "time.h"
#include <iostream>
#include <string>
//#include "SDL2_rotozoom.h"
//#include <fstream>

#undef main

using namespace std;

/*****************************************************************************/

SDL_Surface* screen;
SDL_Surface* back_ground;
SDL_Surface* name;
SDL_Surface* gameover;
SDL_Surface* play;
SDL_Surface* playon;
SDL_Surface* toys;
SDL_Surface* toyson;
SDL_Surface* options;
SDL_Surface* optionson;
SDL_Surface* scores;
SDL_Surface* scoreson;
SDL_Surface* store;
SDL_Surface* storeiconon;
SDL_Surface* resume;
SDL_Surface* resumeon;
SDL_Surface* removeads;
SDL_Surface* removeadson;
SDL_Surface* playagain;
SDL_Surface* playagainon;
SDL_Surface* playagaindisabled;
SDL_Surface* hole;
SDL_Surface* topscore;
SDL_Surface* bottombugtiles1;
SDL_Surface* bottombugtiles2;
SDL_Surface* bottombugtiles3;
SDL_Surface* bottombugtiles4;
SDL_Surface* bottombugtiles5;
SDL_Surface* bottombugtiles6;
SDL_Surface* ufo_f1;
SDL_Surface* ufo_f2;
SDL_Surface* doodler;
SDL_Surface* doodle_left;
SDL_Surface* doodle_right;
SDL_Surface* likrightodskok;
SDL_Surface* likleftodskok;
SDL_Surface* doodle_no_nose;
SDL_Surface* nose;
SDL_Surface* cap_f1;
SDL_Surface* cap_f2;
SDL_Surface* cap_f3;
SDL_Surface* cap_f4;
SDL_Surface* themes1;
SDL_Surface* normal_platform;
SDL_Surface* fake_platform_f1;
SDL_Surface* fake_platform_f2;
SDL_Surface* fake_platform_f3;
SDL_Surface* fake_platform_f4;
SDL_Surface* right_left_moving_paltform;
SDL_Surface* up_down_moving_platform;
SDL_Surface* loading;
SDL_Surface* monster_five_f1;
SDL_Surface* monster_five_f2;
SDL_Surface* monster_five_f3;
SDL_Surface* monster_five_f4;
SDL_Surface* monster_five_f5;
SDL_Surface* monster_four;
SDL_Surface* monster_one_f1;
SDL_Surface* monster_one_f2;
SDL_Surface* monster_one_f3;
SDL_Surface* monster_six;
SDL_Surface* monster_three;
SDL_Surface* monster_two_f1;
SDL_Surface* monster_two_f2;
SDL_Surface* Shield;
SDL_Surface* shield_f1;
SDL_Surface* shield_f2;
SDL_Surface* shield_f3;
SDL_Surface* spring_f1;
SDL_Surface* spring_f2;
SDL_Surface* trampolin_f1;
SDL_Surface* trampolin_f2;
SDL_Surface* trampolin_f3;
SDL_Surface* stars1;
SDL_Surface* stars2;
SDL_Surface* stars3;
SDL_Surface* share;
SDL_Surface* menu;
SDL_Surface* menuon;
SDL_Surface* pause;
SDL_Surface* optionstitle;
SDL_Surface* optionssounds;
SDL_Surface* offbutton;
SDL_Surface* offbuttonon;
SDL_Surface* onbutton;
SDL_Surface* onbuttonon;
SDL_Surface* tir;
SDL_Surface* rotated;

/***************************************************************************************/

Music* jump;
Music* basic_throw;
Music* feder;
Music* jumponmonster;
Music* monsterblizu;
Music* propeller5;
Music* springshoes;
Music* trampoline;
Music* ufo;
Music* lomiz;
Music* pada;

/***************************************************************************************/

enum GameScreen
{
	MainMenu,
	Playing,
	GameOver,
	Scores,
	Pause,
	Options,
	PlayAgain,
	BeforeGameOver
};

/***************************************************************************************/

struct Platform 
{
	int x;
	int y;
};

/***************************************************************************************/

void Loadimages();
void Loadmusic();
void LoadFonts();
void MenuPhotoes();
void PlayingPhotos();
void GameOverPhotos();
void PausePhotos();
void OptionsPhotos();
void ScoresPhotos();
void random();
inline SDL_Surface* MakeScore(int& length);

/***************************************************************************************/

int doodle_y = 520;
int doodle_x = 200;
int height;
int score;

int ufo_x = 330;
int ufo_y = 30;
int ufo_animation;

int bottombugtiles2_x = 63;
int bottombugtiles2_y = 30;

int bottombugtiles3_x = 340;
int bottombugtiles3_y = 550;

int bottombugtiles4_x = 55;

int bottombugtiles6_x = 240;
int bottombugtiles5_y = 250;
//int tir_x;
//int tir_y;
int cx = 480 / 2;
int cy = 890 / 2;

float doodle_v_y;
float doodle_v_x;
//float v_y_tir;
//float v_x_tir;
float rad;
float deg;

bool music_check = false;

TTF_Font* doodlejumpbold;

GameScreen currscreen;

Platform normalPlatform[12];
//Platform fakeplatform[4];

//SDL_Surface* file[10];
//int scoreFile[10];


int main()
{
	srand(time(NULL));

	InitEngine(screen, "Doodle_Jump", 480, 890);

	Loadimages();
	Loadmusic();
	LoadFonts();

	//fstream scorefile("assets/files/file.txt");

	currscreen = MainMenu;

	while (!ExitRequested)
	{
		Update();

		int scoreLength = 0;
		SDL_Surface* scoreSurface = MakeScore(scoreLength);

		rad = atan2(cx - Mouse.x, cy - Mouse.y);
		deg = 180 * rad / M_PI;

/***************************************************************************************/

		if (currscreen == MainMenu)
		{
			MenuPhotoes();

			ufo_animation += 1;
			ufo_x -= 2;
			ufo_y += 2;
			if (ufo_animation % 3 == 1)
			{
				SDL_BlitSurface(ufo_f1, screen, ufo_x, ufo_y);
			}
			if (ufo_animation % 3 == 0)
			{
				SDL_BlitSurface(ufo_f2, screen, ufo_x, ufo_y);
			}
			if (ufo_x < 326)
			{
				ufo_x = 315;
			}
			if (ufo_y > 34)
			{
				ufo_y = 0;
			}

			bottombugtiles2_x += 2;
			bottombugtiles2_y -= 2;

			if (bottombugtiles2_x > 65)
			{
				bottombugtiles2_x = 63;
			}
			if (bottombugtiles2_y < 24)
			{
				bottombugtiles2_y = 30;
			}

			bottombugtiles3_x += 2;
			bottombugtiles3_y -= 2;

			if (bottombugtiles3_x > 347)
			{
				bottombugtiles3_x = 340;
			}
			if (bottombugtiles3_y < 530)
			{
				bottombugtiles3_y = 550;
			}

			bottombugtiles4_x += 2;

			if (bottombugtiles4_x > 120)
			{
				bottombugtiles4_x = 55;
			}

			bottombugtiles6_x -= 2;

			if (bottombugtiles6_x < 180)
			{
				bottombugtiles6_x = 240;
			}

			bottombugtiles5_y += 2;

			if (bottombugtiles5_y > 310)
			{
				bottombugtiles5_y = 250;
			}

			SDL_BlitSurface(doodler, screen, 48, doodle_y);

			doodle_v_y += 0.3;
			doodle_y += doodle_v_y;

			if (doodle_y > 580 )
			{
				doodle_v_y = -11;

				if (music_check == false)
				{
					PlayMusic(jump, 0);
				}
			}

			if (MouseX > 70 && MouseX < 230 && MouseY < 260 && MouseY > 200)
			{
				SDL_BlitSurface(playon, screen, 70, 200);

				if (MouseLB)
				{
					currscreen = Playing;
					
					random();
				}
			}

			if (MouseX > 420 && MouseX < 460 && MouseY < 730 && MouseY > 660)
			{
				SDL_BlitSurface(optionson, screen, 390, 660);

				if (MouseLB)
				{
					currscreen = Options;
				}
			}

			if (MouseX > 315 && MouseX < 380 && MouseY < 730 && MouseY > 660)
			{
				SDL_BlitSurface(scoreson, screen, 310, 660);

				if (MouseLB)
				{
					currscreen = Scores;
				}
			}
		}

/***************************************************************************************/

		else if (currscreen == Playing)
		{
			PlayingPhotos();

			/*v_y_tir += 0.2;
			tir_y += v_y_tir;*/
				
			if (MouseX > 420 && MouseX<460 && MouseY>-1 && MouseY < 50)
			{
				if (MouseLB)
				{
					currscreen = Pause;
				}

			}
			
		/*	if (MouseLB)
			{
				tir = rotozoomSurfaceXY(tir, 30, 1, 1, 0);
				SDL_BlitSurface(tir, screen, tir_x, tir_y);
			}*/

			if (event.key.keysym.sym == SDLK_LEFT)
			{
				doodler = doodle_left;
				doodle_x -= 10;
			}

			if (event.key.keysym.sym == SDLK_RIGHT)
			{
				doodler = doodle_right;
				doodle_x += 10;
			}

			if (doodle_x < -14)
			{
				doodle_x = 410;
			}

			if (doodle_x > 460)
			{
				doodle_x = -12;
			}
			
		/*	if (MouseLB)
			{
				rotated = rotozoomSurface(nose, deg, 1, 1);
				SDL_BlitSurface(doodle_no_nose, screen, cx - (doodle_no_nose->w) / 2, cy - (doodle_no_nose->h) / 2 - 10);
				SDL_BlitSurface(rotated, screen, cx - (rotated->w) / 2, cy - (rotated->h) / 2);
			}*/

			doodle_v_y += 0.3;
			doodle_y += doodle_v_y;

			if (doodle_y < height)
			{
				score++;
			}

			if (doodle_y < height)
			{
				for (int i = 0; i < 12; i++)
				{
					doodle_y = height;
					normalPlatform[i].y -= doodle_v_y;

					if (normalPlatform[i].y > 800)
					{
						normalPlatform[i].y = 0;
						normalPlatform[i].x = rand() % 70 + (i % 3) * 150;
					}
				}
			/*	for (int i = 1; i < 5; i++)
				{
					doodle_y = height;
					fakeplatform[i].y -= doodle_v_y;

					if (fakeplatform[i].y > 800)
					{
						fakeplatform[i].y = 0;
						fakeplatform[i].x = (rand() % 10 )*(i*20);
					}

				}*/
			}


			for (int i = 0; i < 12; i++)
			{
					if (doodle_x > normalPlatform[i].x - 40 && doodle_x < normalPlatform[i].x + 45 &&
						doodle_y + 100 > normalPlatform[i].y && doodle_y < normalPlatform[i].y - 80 )
					{
						doodle_y = normalPlatform[i].y - 100;
						doodle_v_y = -11;
						if (doodler == doodle_right)
						{
							doodler = likrightodskok;
						}

						if (doodler == doodle_left)
						{
							doodler = likleftodskok;
						}

						if (music_check == false)
						{
							PlayMusic(jump, 0);
						}
					}
			}

			SDL_BlitSurface(scoreSurface, screen, 20, 0);
			SDL_FreeSurface(scoreSurface);

			SDL_BlitSurface(doodler, screen, doodle_x, doodle_y);

			if (doodle_y > 815)
			{
				currscreen = BeforeGameOver;
				doodle_y = 0;
				doodle_v_y = 0;

				if (music_check == false)
				{
					PlayMusic(pada, 0);
				}
			}

		}

/***************************************************************************************/

		else if (currscreen == GameOver)
		{
			GameOverPhotos();
			
			SDL_BlitSurface(scoreSurface, screen, 20, 0);
			SDL_FreeSurface(scoreSurface);

			if (MouseX > 150 && MouseX < 330 && MouseY > 390 && MouseY < 470)
			{
				SDL_BlitSurface(playagainon, screen, 155, 400);

				if (MouseLB)
				{
					currscreen = Playing;
					random();
					doodle_y = 420;
					doodle_x = 200;
					height = 0;
					doodle_v_y = 0;
					doodle_v_x = 0;
					score = 0;
				}

			}

			if (MouseX > 150 && MouseX < 320 && MouseY > 590 && MouseY < 670)
			{
				SDL_BlitSurface(menuon, screen, 160, 600);

				if (MouseLB)
				{
					currscreen = MainMenu;
					doodle_y = 520;
					doodle_x = 200;
					doodler = doodle_right;
					score = 0;
					random();
				}
			}
			SDL_BlitSurface(doodler, screen, doodle_x, doodle_y);
		}
		
/***************************************************************************************/

		else if (currscreen == Scores)
		{
			ScoresPhotos();

			if (MouseX > 290 && MouseX < 470 && MouseY < 765 && MouseY > 700)
			{
				SDL_BlitSurface(menuon, screen, 300, 700);

				if (MouseLB)
				{
					currscreen = MainMenu;
				}
			}
		}

/***************************************************************************************/

		else if (currscreen == Options)
		{
			OptionsPhotos();

			if (MouseX > 290 && MouseX < 470 && MouseY < 765 && MouseY > 700)
			{
				SDL_BlitSurface(menuon, screen, 300, 700);

				if (MouseLB)
				{
					currscreen = MainMenu;
				}
			}

			if (MouseX > 150 && MouseX < 210 && MouseY > 350 && MouseY < 385)
			{
				SDL_BlitSurface(offbuttonon, screen, 150, 350);

				if (MouseLB)
				{
					music_check = true;
				}
			}

			if (MouseX > 150 && MouseX < 210 && MouseY > 430 && MouseY < 465)
			{
				SDL_BlitSurface(onbuttonon, screen, 150, 430);

				if (MouseLB)
				{
					music_check = false;
				}
			}
		}

/***************************************************************************************/

		else if (currscreen == Pause)
		{
			PausePhotos();
			
			if (MouseX > 150 && MouseX < 320 && MouseY > 400 && MouseY < 500)
			{
				SDL_BlitSurface(resumeon, screen, 160, 400);

				if (MouseLB)
				{
					currscreen = Playing;
				}
			}
		}

/***************************************************************************************/
		
		else if (currscreen == BeforeGameOver)
		{
			SDL_BlitSurface(back_ground, screen, 0, 0);

			doodle_v_y += 0.3;
			doodle_y += doodle_v_y;

			if (event.key.keysym.sym == SDLK_LEFT)
			{
				doodler = doodle_left;
				doodle_x -= 10;
			}

			if (event.key.keysym.sym == SDLK_RIGHT)
			{
				doodler = doodle_right;
				doodle_x += 10;
			}

			if (doodle_x < -14)
			{
				doodle_x = 410;
			}

			if (doodle_x > 460)
			{
				doodle_x = -12;
			}

			if (doodle_y > 800)
			{
				currscreen = GameOver;
			}

			SDL_BlitSurface(doodler, screen, doodle_x, doodle_y);
		}

/***************************************************************************************/

			SDL_UpdateScreen();
			SDL_Delay(5);
		}
			return 0;
	}


void random()
{
	for (int i = 0; i < 12; i++)
	{
		normalPlatform[i].x = rand() % 70 + (i % 3) * 150;
		/* x = 480 */
		normalPlatform[i].y = rand() % 90 + i * 60;
		/* y = 890 */
	}
	//for (int i = 1; i < 5; i++)
	//{
	//	fakeplatform[i].x = (rand() % 10)*(i*20);
	//	fakeplatform[i].y = rand() % 100 + i * 195;
	//}
}

void GameOverPhotos()
{
	SDL_BlitSurface(back_ground, screen, 0, 0);
	SDL_BlitSurface(topscore, screen, 0, 0);
	SDL_BlitSurface(gameover, screen, 80, 90);
	SDL_BlitSurface(playagain, screen, 155, 400);
	SDL_BlitSurface(removeads, screen, 50, 500);
	SDL_BlitSurface(share, screen, 280, 500);
	SDL_BlitSurface(menu, screen, 160, 600);
}

void MenuPhotoes()
{

	SDL_BlitSurface(back_ground, screen, 0, 0);
	SDL_BlitSurface(name, screen, 20, 60);
	SDL_BlitSurface(play, screen, 70, 200);
	SDL_BlitSurface(hole, screen, 320, 360);
	SDL_BlitSurface(toys, screen, 130, 320);
	SDL_BlitSurface(options, screen, 390, 660);
	SDL_BlitSurface(scores, screen, 310, 660);
	SDL_BlitSurface(store, screen, 220, 648);
	SDL_BlitSurface(themes1, screen, 0, 760);
	SDL_BlitSurface(bottombugtiles1, screen, -2, 735);
	SDL_BlitSurface(bottombugtiles2, screen, bottombugtiles2_x, bottombugtiles2_y);
	SDL_BlitSurface(bottombugtiles3, screen, bottombugtiles3_x, bottombugtiles3_y);
	SDL_BlitSurface(bottombugtiles4, screen, bottombugtiles4_x, 300);
	SDL_BlitSurface(bottombugtiles5, screen, 320, bottombugtiles5_y);
	SDL_BlitSurface(bottombugtiles6, screen, bottombugtiles6_x, 470);
	SDL_BlitSurface(normal_platform, screen, 55, 690);
	SDL_BlitSurface(ufo_f1, screen, ufo_x, ufo_y);

}

void PlayingPhotos()
{
	SDL_BlitSurface(back_ground, screen, 0, 0);

	for (int i = 0; i < 12; i++)
	{
		SDL_BlitSurface(normal_platform, screen, normalPlatform[i].x, normalPlatform[i].y);
	}
	/*for (int i = 1; i < 5; i++)
	{
		SDL_BlitSurface(fake_platform_f1, screen, fakeplatform[i].x, fakeplatform[i].y);
	}*/

	SDL_BlitSurface(topscore, screen, 0, 0);
	SDL_BlitSurface(pause, screen, 420, 0);
}

void PausePhotos()
{
	SDL_BlitSurface(back_ground, screen, 0, 0);
	SDL_BlitSurface(name, screen, 20, 30);
	SDL_BlitSurface(resume, screen, 160, 400); 
	SDL_BlitSurface(bottombugtiles2, screen, 63, 30);
	SDL_BlitSurface(bottombugtiles3, screen, 340, 550);
	SDL_BlitSurface(bottombugtiles4, screen, 55, 300);
	SDL_BlitSurface(bottombugtiles5, screen, 320, 250);
	SDL_BlitSurface(bottombugtiles6, screen, 240, 470);
}

void LoadFonts()
{
	doodlejumpbold = TTF_OpenFont("assets/fonts/doodlejumpbold_v2.ttf", 70);
}	

void Loadmusic()
{
	jump = LoadMusic("assets/sounds/jump.ogg");
	basic_throw = LoadMusic("assets/sounds/basic_throw.ogg");
	feder = LoadMusic("assets/sounds/feder.ogg");
	jumponmonster = LoadMusic("assets/sounds/jumponmonster.ogg");
	monsterblizu = LoadMusic("assets/sounds/monsterblizu.ogg");
	propeller5 = LoadMusic("assets/sounds/propeller5.ogg");
	springshoes = LoadMusic("assets/sounds/springshoes.ogg");
	trampoline = LoadMusic("assets/sounds/trampoline.ogg");
	ufo = LoadMusic("assets/sounds/ufo.ogg");
	lomiz = LoadMusic("assets/sounds/lomise.ogg");
	pada = LoadMusic("assets/sounds/pada.ogg");
}

void Loadimages()
{
	back_ground = ImgLoader("assets/images/bck_X.png", 255, 255, 255);
	name = ImgLoader("assets/images/doodlejump_L.png", 255, 255, 255);
	gameover = ImgLoader("assets/images/startendtiles_L.png", 255, 255, 255);
	play = ImgLoader("assets/images/play_L.png", 255, 255, 255);
	playon = ImgLoader("assets/images/playon_L.png", 255, 255, 255);
	resume = ImgLoader("assets/images/resume_L.png", 255, 255, 255);
	resumeon = ImgLoader("assets/images/resumeon_L.png", 255, 255, 255);
	removeads = ImgLoader("assets/images/removeads_L.png", 255, 255, 255);
	removeadson = ImgLoader("assets/images/removeadson_L.png", 255, 255, 255);
	playagain = ImgLoader("assets/images/playagain_L.png", 255, 255, 255);
	playagainon = ImgLoader("assets/images/playagainon_L.png", 255, 255, 255);
	playagaindisabled = ImgLoader("assets/images/playagaindisabled_L.png", 255, 255, 255);
	hole = ImgLoader("assets/images/hole_X.png", 255, 255, 255);
	topscore = ImgLoader("assets/images/topscore_L.png", 255, 255, 255);
	toys = ImgLoader("assets/images/toys_L.png", 255, 255, 255);
	toyson = ImgLoader("assets/images/toyson_L.png", 255, 255, 255);
	options = ImgLoader("assets/images/options_L.png", 255, 255, 255);
	optionson = ImgLoader("assets/images/optionson_L.png", 255, 255, 255);
	scores = ImgLoader("assets/images/scores_L.png", 255, 255, 255);
	scoreson = ImgLoader("assets/images/scoreson_L.png", 255, 255, 255);
	store = ImgLoader("assets/images/storeicon_L.png", 255, 255, 255);
	storeiconon = ImgLoader("assets/images/storeiconon_L.png", 255, 255, 255);
	bottombugtiles1 = ImgLoader("assets/images/bottombugtiles1_X.png", 255, 255, 255);
	bottombugtiles2 = ImgLoader("assets/images/bottombugtiles2_X.png", 255, 255, 255);
	bottombugtiles3 = ImgLoader("assets/images/bottombugtiles3_X.png", 255, 255, 255);
	bottombugtiles4 = ImgLoader("assets/images/bottombugtiles4_X.png", 255, 255, 255);
	bottombugtiles5 = ImgLoader("assets/images/bottombugtiles5_X.png", 255, 255, 255);
	bottombugtiles6 = ImgLoader("assets/images/bottombugtiles6_X.png", 255, 255, 255);
	ufo_f1 = ImgLoader("assets/images/ufo_f1.png", 255, 255, 255);
	ufo_f2 = ImgLoader("assets/images/ufo f2.png", 255, 255, 255);
	doodler = ImgLoader("assets/images/likright_X.png", 255, 255, 255);
	doodle_left = ImgLoader("assets/images/likleft_X.png", 255, 255, 255);
	doodle_right = ImgLoader("assets/images/likright_X.png", 255, 255, 255);
	likrightodskok = ImgLoader("assets/images/likrightodskok_X.png", 255, 255, 255);
	likleftodskok = ImgLoader("assets/images/likleftodskok_X.png", 255, 255, 255);
	doodle_no_nose = ImgLoader("assets/images/likpucaodskok_X.png", 255, 255, 255);
	nose = ImgLoader("assets/images/liknjuska_X.png", 255, 255, 255);
	cap_f1 = ImgLoader("assets/images/cap f1.png", 255, 255, 255);
	cap_f2 = ImgLoader("assets/images/cap f2.png", 255, 255, 255);
	cap_f3 = ImgLoader("assets/images/cap f3.png", 255, 255, 255);
	cap_f4 = ImgLoader("assets/images/cap f4.png", 255, 255, 255);
	themes1 = ImgLoader("assets/images/themes1_X.png", 255, 255, 255);
	normal_platform = ImgLoader("assets/images/normal platform.png", 255, 255, 255);
	fake_platform_f1 = ImgLoader("assets/images/fake platform f1.png", 255, 255, 255);
	fake_platform_f2 = ImgLoader("assets/images/fake platform f2.png", 255, 255, 255);
	fake_platform_f3 = ImgLoader("assets/images/fake platform f3.png", 255, 255, 255);
	fake_platform_f4 = ImgLoader("assets/images/fake platform f4.png", 255, 255, 255);
	right_left_moving_paltform = ImgLoader("assets/images/right left moving paltform.png", 255, 255, 255);
	up_down_moving_platform = ImgLoader("assets/images/up down moving platform.png", 255, 255, 255);
	loading = ImgLoader("assets/images/loading_X.png", 255, 255, 255);
	monster_five_f1 = ImgLoader("assets/images/monster five f1.png", 255, 255, 255);
	monster_five_f2 = ImgLoader("assets/images/monster five f2.png", 255, 255, 255);
	monster_five_f3 = ImgLoader("assets/images/monster five f3.png", 255, 255, 255);
	monster_five_f4 = ImgLoader("assets/images/monster five f4.png", 255, 255, 255);
	monster_five_f5 = ImgLoader("assets/images/monster five f5.png", 255, 255, 255);
	monster_four = ImgLoader("assets/images/monster four.png", 255, 255, 255);
	monster_one_f1 = ImgLoader("assets/images/monster one f1.png", 255, 255, 255);
	monster_one_f2 = ImgLoader("assets/images/monster one f2.png", 255, 255, 255);
	monster_one_f3 = ImgLoader("assets/images/monster one f3.png", 255, 255, 255);
	monster_six = ImgLoader("assets/images/monster six.png", 255, 255, 255);
	monster_three = ImgLoader("assets/images/monster three.png", 255, 255, 255);
	monster_two_f1 = ImgLoader("assets/images/monster two f1.png", 255, 255, 255);
	monster_two_f2 = ImgLoader("assets/images/monster two f2.png", 255, 255, 255);
	Shield = ImgLoader("assets/images/Shield.png", 255, 255, 255);
	shield_f1 = ImgLoader("assets/images/shield f1.png", 255, 255, 255);
	shield_f2 = ImgLoader("assets/images/shield f2.png", 255, 255, 255);
	shield_f3 = ImgLoader("assets/images/shield f3.png", 255, 255, 255);
	spring_f1 = ImgLoader("assets/images/spring f1.png", 255, 255, 255);
	spring_f2 = ImgLoader("assets/images/spring f2.png", 255, 255, 255);
	trampolin_f1 = ImgLoader("assets/images/trampolin f1.png", 255, 255, 255);
	trampolin_f2 = ImgLoader("assets/images/trampolin f2.png", 255, 255, 255);
	trampolin_f3 = ImgLoader("assets/images/trampolin f3.png", 255, 255, 255);
	stars1 = ImgLoader("assets/images/stars1_L.png", 255, 255, 255);
	stars2 = ImgLoader("assets/images/stars2_L.png", 255, 255, 255);
	stars3 = ImgLoader("assets/images/stars3_L.png", 255, 255, 255);
	share = ImgLoader("assets/images/share_L.png", 255, 255, 255);
	menu = ImgLoader("assets/images/menu_L.png", 255, 255, 255);
	menuon = ImgLoader("assets/images/menuon_L.png", 255, 255, 255);
	pause = ImgLoader("assets/images/topscore_X.png", 255, 255, 255);
	optionstitle = ImgLoader("assets/images/optionstitle_L.png", 255, 255, 255);
	optionssounds = ImgLoader("assets/images/optionssounds_L.png" ,255, 255, 255);
	offbutton = ImgLoader("assets/images/offbutton_L.png", 255, 255, 255);
	offbuttonon = ImgLoader("assets/images/offbuttonon_L.png", 255, 255, 255);
	onbutton = ImgLoader("assets/images/onbutton_L.png", 255, 255, 255);
	onbuttonon = ImgLoader("assets/images/onbuttonon_L.png", 255, 255, 255);
	tir = ImgLoader("assets/images/projectiletiles_L.png", 255, 255, 255);
}

void ScoresPhotos()
{
	SDL_BlitSurface(back_ground, screen, 0, 0);
	SDL_BlitSurface(name, screen, 20, 30);
	SDL_BlitSurface(menu, screen, 300, 700);
	SDL_BlitSurface(doodler, screen, 40, 575);
	SDL_BlitSurface(normal_platform, screen,50, 700);
	SDL_BlitSurface(bottombugtiles2, screen, 63, 30);
	SDL_BlitSurface(bottombugtiles3, screen, 340, 550);
	SDL_BlitSurface(bottombugtiles4, screen, 55, 300);
	SDL_BlitSurface(bottombugtiles5, screen, 320, 250);
	SDL_BlitSurface(bottombugtiles6, screen, 240, 470);
}

void OptionsPhotos()
{
	SDL_BlitSurface(back_ground, screen, 0, 0);
	SDL_BlitSurface(name, screen, 20, 30);
	SDL_BlitSurface(menu, screen, 300, 700);
	SDL_BlitSurface(optionstitle,screen, 20, 100);
	SDL_BlitSurface(optionssounds, screen, 100, 250);
	SDL_BlitSurface(offbutton, screen, 150, 350);
	SDL_BlitSurface(onbutton, screen, 150, 430);
	

}

inline SDL_Surface* MakeScore(int& length)
{
	char ary[100];
	 sprintf_s(ary, "%d", score);
return TTF_RenderText_Solid(doodlejumpbold, ary, 0, 0, 0);
}

