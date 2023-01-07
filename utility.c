#include "utility.h"

void clamp(double* value_to_clamp, float min, float max){//min and max are inclusive
	if(*value_to_clamp < min)
		*value_to_clamp = min;
	else if(*value_to_clamp > max)
		*value_to_clamp = max;
}

void fullscreen()
{
	keybd_event(VK_MENU,0x38,0,0);
	keybd_event(VK_RETURN,0x1c,0,0);
	keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
	keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
}

double random(double min,double max){
	srand(time(0));
	rand();
	double random = ((double)rand()/(RAND_MAX));
    double range =((double) random)*max;
    double num = range + min;
    return num;
}

bool keydown(int key)
{
    return (GetAsyncKeyState(key) & 0x8000) != 0;
}

void setColor(int c)
{
	SetConsoleTextAttribute(output, c);
}

void gotoxy(int x, int y) { 
	if(x>=0 && y>=0 && x<WIDTH && y<HEIGHT){
	    COORD pos = {x, y};
	    SetConsoleCursorPosition(output, pos);
	}
}
void setScreenSize(int length, int height)
{
	COORD c;
	c.X = length;
	c.Y= height;
	
	SMALL_RECT s;
	s.Left = 0;
	s.Top = 0;
	s.Right = length;
	s.Bottom = height;
	
	SetConsoleWindowInfo(output, TRUE, &s);
	SetConsoleScreenBufferSize(output, c);
}
void hideCursor()
{
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(output, &info);
}
void openFile(FILE** fp, char* filename, char* Mode){
	*fp = fopen(filename, Mode);
	if(fp == NULL){
		printf("Failed to open the file. Closing");
		exit(EXIT_FAILURE);
	}
}