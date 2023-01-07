#pragma once
#include "utility.h"
#include "draw.h"
#include "Physics.h"
#define PLAYER_SPEED 80

#define BALL_SPEED 100
#define BALL_MASS 2
#define DAMPING_FACTOR 0.15
#define WIN_SCORE 11

void main_game();//returns an array {winning_player, player_1 score, player_2 score}
void goal();
void Win();
void Menu();
void NewGame();
void ResumeGame();
void Exit();
void Pause();
void SplashScreen();
void ScoreBoard();