#pragma once
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <conio.h>

#define WIDTH 210
#define HEIGHT 54

#define GOAL_SIZE 30
#define PLAYER_SIZE 7

#define BLACK 0
#define BLUE 9
#define GREEN 10
#define AQUA 11
#define RED 12
#define PINK 13
#define YELLOW 14
#define WHITE 15

extern HANDLE output;
extern char Player_1[12], Player_2[12];
extern int score_1, score_2;
extern double deltaTime;
extern FILE *resume_gamep;

typedef struct vector{
	double x;
	double y;
} vector;

void clamp(double* value_to_clamp, float min, float max);
void fullscreen();
double random(double min,double max);
bool keydown(int key);
void setColor(int c);
void gotoxy(int x, int y);
void setScreenSize(int length, int height);
void hideCursor();
void arrayCopy();
void openFile(FILE** fp, char* filename, char* Mode);