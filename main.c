#include <stdio.h>
#include <stdlib.h>
#include "utility.h"
#include "Scenes.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
HANDLE output;
int score_1;
int score_2;
double deltaTime;

void setup(){
	output = GetStdHandle(STD_OUTPUT_HANDLE);
	fullscreen();
	hideCursor();
}

int main(int argc, char *argv[]) {
	setup();
	SplashScreen();
	return 0;
}