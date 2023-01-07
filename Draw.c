#include "draw.h"

void printTime(double seconds){
	printf("%.2d:%.2d:%.2d",((int)(seconds)%3600)/60, (int)seconds%60, ((int)(seconds*100))%100);
}

void drawBall(vector pos, vector prev_pos){
	
	if(pos.x != prev_pos.x || pos.y != prev_pos.y){
		gotoxy(prev_pos.x, prev_pos.y);
		printf(" ");
	}
	gotoxy(pos.x, pos.y);
	printf("o");
}

void drawBat(vector position, vector prev_position, int Color){
	setColor(WHITE);
	if(prev_position.x != position.x || prev_position.y != position.y){
		for(int i = -PLAYER_SIZE/2; i<=PLAYER_SIZE/2; i++){
			gotoxy(prev_position.x,prev_position.y+i);
			printf(" ");
		}
	}
	setColor(Color);
	for(int i = -PLAYER_SIZE/2; i<=PLAYER_SIZE/2; i++){
		gotoxy(position.x,position.y+i);
		printf("%c", 178);
	}
	setColor(WHITE);
}

void printScore(){
	gotoxy(2,1);
	printf("%s score: %d", Player_1, score_1);
	gotoxy(WIDTH-21,1);
	printf("%s score: %d", Player_2, score_2);
}

void clearGameArea()
{
	gotoxy(1,3);
	for(int j = 3; j<HEIGHT; j++){
		for(int i = 2; i<WIDTH; i++)
			printf(" ");
		gotoxy(1,j);
	}
}

void drawBorders(){
	gotoxy(0,0);
	for(int i=0;i<WIDTH; i++){printf("%c", 178);}
	for(int i=1;i<HEIGHT; i++){gotoxy(0,i);printf("%c", 178);}
	for(int i=1;i<HEIGHT; i++){gotoxy(WIDTH-1,i);printf("%c", 178);}
	gotoxy(0, HEIGHT-1);
	for(int i=1;i<WIDTH; i++){printf("%c", 178);}
}

void drawLayout(){
	gotoxy(0,0);
	for(int i=0;i<WIDTH; i++){printf("%c", 178);}
	for(int i=1;i<HEIGHT; i++){gotoxy(0,i);if(abs(((HEIGHT-1)/2)-i)>(GOAL_SIZE)/2)printf("%c", 178);}
	for(int i=1;i<HEIGHT; i++){gotoxy(WIDTH-1,i);if(abs(((HEIGHT-1)/2)-i)>(GOAL_SIZE)/2)printf("%c", 178);}
	gotoxy(0, HEIGHT-1);
	for(int i=1;i<WIDTH; i++){printf("%c", 178);}
	gotoxy(1,2);
	for(int i=0;i<WIDTH-2; i++){printf("%c", 178);}
	for(int i=3;i<HEIGHT-1; i++){gotoxy(WIDTH/2,i);if(i%2)printf("%c", 179);}
}

