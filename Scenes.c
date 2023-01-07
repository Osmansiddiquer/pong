#include "Scenes.h"

vector player_1_pos, player_2_pos, prev_player_1_pos, prev_player_2_pos, ball_vel, ball_pos, prev_ball_pos;
FILE *resume_gamep;
char Key[12];
char Player_1[12], Player_2[12];
bool gameOngoing;
double elapsedTime = 0;
void start_round(){
	ball_pos.x = WIDTH/2;
	ball_pos.y = (HEIGHT)/2;
	prev_ball_pos = ball_pos;
	ball_vel.x = random(0, 1*BALL_SPEED/3.0)+2/3.0*BALL_SPEED;
	ball_vel.y = sqrt(pow(BALL_SPEED,2)-pow(ball_vel.x, 2));
	srand(time(0));
	int direction = rand()%4;
	switch(direction){
		case 0:
			break;
		case 1:
			ball_vel.x *= -1;
			break;
		case 2:
			ball_vel.y *= -1;
			ball_vel.x *= -1;
			break;
		case 3:
			ball_vel.y *= -1;
			break;
	}
	
	player_1_pos.x = 2, player_1_pos.y = HEIGHT/2;
	player_2_pos.x = WIDTH-2, player_2_pos.y = HEIGHT/2;
}
void goal(){
	clearGameArea();
	gotoxy(ball_pos.x, ball_pos.y); printf(" ");
	gotoxy(WIDTH/2-3,HEIGHT/2);
	printf("GOAL!!");
	Sleep(1500);
}
void Pause(){
	clearGameArea();
	while(1){
		setColor(WHITE);
		gotoxy(WIDTH/2-3,HEIGHT/2);
		printf("PAUSED");
		gotoxy(WIDTH/2-3,HEIGHT/2+3);
		printf("Menu (M)");
		gotoxy(WIDTH/2-4,HEIGHT/2+5);
		printf("Resume(R)");
		gotoxy(WIDTH/2-3,HEIGHT/2+7);
		printf("Exit (X)");
		if(keydown(0x4D)){ //M
			clearGameArea();
			setColor(YELLOW);
			gotoxy(WIDTH/2-7,HEIGHT/2);
			printf("Abandon Game?");
			gotoxy(WIDTH/2-7,HEIGHT/2 + 3);
			printf("Yes (Y)");
			gotoxy(WIDTH/2-7,HEIGHT/2 + 5);
			printf("No (N)");
			while(1){
				if(keydown(0x59)){ //Y
					openFile(&resume_gamep, "Save Data.txt", "a+");
					fprintf(resume_gamep, "%s %s %s %d %d %g\n", Key, Player_1, Player_2, score_1, score_2, elapsedTime);
					fclose(resume_gamep);
					Menu();
				}
				else if(keydown(0x4E)){ //N
					clearGameArea();
					break;
				}
			}
		}
		else if(keydown(0x52)){ //R
			clearGameArea();
			return;
		}
		else if(keydown(0x58)){ //X
			clearGameArea();
			Exit();
		}
	}
}
void Exit(){
	setColor(RED);
	system("cls");
	hideCursor();
	drawBorders();
	gotoxy(WIDTH/2-5,HEIGHT/2);
	printf("Exit Game?");
	gotoxy(WIDTH/2-3,HEIGHT/2 + 3);
	printf("Yes (Y)");
	gotoxy(WIDTH/2-3,HEIGHT/2 + 5);
	printf("No (N)");
	setColor(WHITE);
	while(1){
		if(keydown(0x59)){ //Y
			if(gameOngoing){
				openFile(&resume_gamep, "Save Data.txt", "a+");
				fprintf(resume_gamep, "%s %s %s %d %d %g\n", Key, Player_1, Player_2, score_1, score_2, elapsedTime);
				fclose(resume_gamep);
			}
			clearGameArea();
			gotoxy(WIDTH/2-11,HEIGHT/2);
			printf("THANK YOU FOR PLAYING!");
			gotoxy(0,HEIGHT-1);
			exit(EXIT_SUCCESS);
		}
		else if(keydown(0x4E)){ //N
			system("cls");
			return;
		}
	}
}
void SplashScreen(){
	system("cls");
	PlaySound("Intro.wav", NULL, SND_FILENAME|SND_LOOP|SND_ASYNC);
	
	openFile(&resume_gamep, "Save Data.txt", "a");
    fclose(resume_gamep);
	
	while(1){
		hideCursor();
		setColor(BLUE-8);
		drawBorders();
		gotoxy(WIDTH/2-40, HEIGHT/5);
		printf(" .----------------.  .----------------.  .-----------------. .----------------. ");
		gotoxy(WIDTH/2-40, HEIGHT/5+1);
		printf("| .--------------. || .--------------. || .--------------. || .--------------. |");
		gotoxy(WIDTH/2-40, HEIGHT/5+2);
		printf("| |   ______     | || |     ____     | || | ____  _____  | || |    ______    | |");
		gotoxy(WIDTH/2-40, HEIGHT/5+3);
		printf("| |  |_   __ \\   | || |   .'    `.   | || ||_   \\|_   _| | || |  .' ___  |   | |");
		gotoxy(WIDTH/2-40, HEIGHT/5+4);
		printf("| |    | |__) |  | || |  /  .--.  \\  | || |  |   \\ | |   | || | / .'   \\_|   | |");
		gotoxy(WIDTH/2-40, HEIGHT/5+5);
		printf("| |    |  ___/   | || |  | |    | |  | || |  | |\\ \\| |   | || | | |    ____  | |");
		gotoxy(WIDTH/2-40, HEIGHT/5+6);
		printf("| |   _| |_      | || |  \\  `--'  /  | || | _| |_\\   |_  | || | \\ `.___]  _| | |");
		gotoxy(WIDTH/2-40, HEIGHT/5+7);
		printf("| |  |_____|     | || |   `.____.'   | || ||_____|\\____| | || |  `._____.'   | |");
		gotoxy(WIDTH/2-40, HEIGHT/5+8);
		printf("| |              | || |              | || |              | || |              | |");
		gotoxy(WIDTH/2-40, HEIGHT/5+9);
		printf("| '--------------' || '--------------' || '--------------' || '--------------' |");
		gotoxy(WIDTH/2-40, HEIGHT/5+10);
		printf(" '----------------'  '----------------'  '----------------'  '----------------' ");
		gotoxy(WIDTH/2-24, 3*HEIGHT/5);
		setColor(WHITE);
		printf("ENTER (E)				EXIT(X)");
		if(keydown(0x45))
			Menu();
		else if(keydown(0x58))
			Exit();	
	}
}
void Menu(){
	system("cls");
	hideCursor();
	while(1){
		setColor(YELLOW);
		drawBorders();
		gotoxy(WIDTH/2-2,HEIGHT/7);
		printf("MENU");
		gotoxy(WIDTH/2-6,3*HEIGHT/7);
		printf("NEW GAME (N)");
		gotoxy(WIDTH/2-8,4*HEIGHT/7);
		printf("RESUME GAME (R)");
		gotoxy(WIDTH/2-7,5*HEIGHT/7);
		printf("SCOREBOARD (S)");
		gotoxy(WIDTH/2-4,6*HEIGHT/7);
		printf("EXIT (X)");
		if(keydown(0x4E)){
			NewGame();
		}
		else if(keydown(0x52)){
			ResumeGame();
		}
		else if(keydown(0x53)){
		//	ScoreBoard();
		}
		else if(keydown(0x58)){
			Exit();
		}
	}
}
void Win(){
	clearGameArea();
	setColor(GREEN);
	gotoxy(ball_pos.x, ball_pos.y); printf(" ");
	gotoxy(WIDTH/2-6,HEIGHT/2);
	printf("%s WON!!", (score_1>score_2)?Player_1:Player_2);
	Sleep(1500);
	SplashScreen();
}
void ResumeGame(){
	char key_to_check[12], key[12];
	struct Data{
		char Player_1[12];
		char Player_2[12];
		int score_1;
		int score_2;
		double elapsedTime;
	};
	struct Data temp;
	temp.elapsedTime = 0;
	
	setColor(GREEN);
	system("cls");
	hideCursor();
	drawBorders();
	gotoxy(WIDTH/2-10,HEIGHT/2);
	
	getch();
	getch();
	
	printf("Enter the Key: ");
	scanf("%s", key_to_check);
	
	openFile(&resume_gamep, "Save Data.txt", "r");
	while (fscanf(resume_gamep, " %s", key) == 1){
	        if(strcmp(key, key_to_check) == 0){
	        strcpy(Key, key_to_check);
			fscanf(resume_gamep, " %s", temp.Player_1);
			fscanf(resume_gamep, " %s", temp.Player_2);
			fscanf(resume_gamep, " %d", &temp.score_1);
			fscanf(resume_gamep, " %d", &temp.score_2);
			fscanf(resume_gamep, " %g", &temp.elapsedTime);
			}
			else
				fscanf(resume_gamep, " %*s %*s %*d %*d %*g");
	}
	
	if(temp.elapsedTime == 0){	
		gotoxy(WIDTH/2-18,HEIGHT/2+3);	
		printf("No save data found matching this key.\n");
		Sleep(1500);
		Menu();
	}
	
	strcpy(Player_1, temp.Player_1);
	strcpy(Player_2, temp.Player_2);
	score_1 = temp.score_1;
	score_2 = temp.score_2;
	elapsedTime = temp.elapsedTime;
	main_game();
}
void NewGame(){
	getch();
	getch();
	setColor(GREEN);
	system("cls");
	hideCursor();
	drawBorders();
	gotoxy(WIDTH/2-10,HEIGHT/2);
	printf("Player 1 Name: ");
	fflush(stdin);
	scanf("%s", Player_1);
	system("cls");
	hideCursor();
	drawBorders();
	gotoxy(WIDTH/2-10,HEIGHT/2);
	fflush(stdin);
	printf("Player 2 Name: ");
	scanf("%s", Player_2);
	system("cls");
	hideCursor();
	drawBorders();
	gotoxy(WIDTH/2-10,HEIGHT/2);
	fflush(stdin);
	printf("Create a Key: ");
	scanf("%s", Key);
	fflush(stdin);
	score_1 = 0;
	score_2 = 0;
	elapsedTime = 0;
	main_game();
}
void main_game(){
	PlaySound("Match.wav", NULL, SND_FILENAME|SND_LOOP|SND_ASYNC);
	gameOngoing = true;
	system("cls");
	hideCursor();
	clock_t start = clock();
	start_round();
	clearGameArea();
	while(score_1 < WIN_SCORE && score_2 < WIN_SCORE){
		hideCursor();
		bool scored = false;
		clock_t t = clock();
		gotoxy(WIDTH/2-5,1);
		
		elapsedTime += deltaTime;

		printTime(elapsedTime);
		
		if(keydown(VK_UP)){
			if(player_2_pos.y > 5)
        		player_2_pos.y-=PLAYER_SPEED*deltaTime;
        }
		if(keydown(VK_DOWN)){
			if(player_2_pos.y < HEIGHT-3)
        		player_2_pos.y+=PLAYER_SPEED*deltaTime;
        }
        if(keydown(VK_LEFT)){
			if(player_2_pos.x > 2)
        		player_2_pos.x-=PLAYER_SPEED*deltaTime;
        }
        if(keydown(VK_RIGHT)){
			if(player_2_pos.x < WIDTH-2)
        		player_2_pos.x+=PLAYER_SPEED*deltaTime;
        }
        if(keydown(0x57)){ //w
			if(player_1_pos.y > 5)
        		player_1_pos.y-=PLAYER_SPEED*deltaTime;
        }
        if(keydown(0x41)){ //a
			if(player_1_pos.x > 2)
        		player_1_pos.x-=PLAYER_SPEED*deltaTime;
        }
        if(keydown(0x53)){//s
        	player_1_pos.y+=PLAYER_SPEED*deltaTime;
        }
        if(keydown(0x44)){//d
        	player_1_pos.x+=PLAYER_SPEED*deltaTime;
        }
		if(keydown(0x50)){//p
        	Pause();
        	t = clock();
        }
		drawLayout();
		
		clamp(&player_1_pos.x, 1, WIDTH-2);
		clamp(&player_1_pos.y, 3+PLAYER_SIZE/2, HEIGHT-2-PLAYER_SIZE/2);
		clamp(&player_2_pos.x, 1, WIDTH-2);
		clamp(&player_2_pos.y, 3+PLAYER_SIZE/2, HEIGHT-2-PLAYER_SIZE/2);
		
		drawBat(player_1_pos, prev_player_1_pos, RED);
		prev_player_1_pos = player_1_pos;
		drawBat(player_2_pos, prev_player_2_pos, BLUE);
		prev_player_2_pos = player_2_pos;
		
		if(sqrt(pow(ball_vel.x, 2) + pow(ball_vel.y, 2)) > BALL_SPEED/2)
			dampen(&ball_vel, DAMPING_FACTOR, BALL_MASS);
		
		ball_pos.x += ball_vel.x*deltaTime;
		ball_pos.y += ball_vel.y*deltaTime;
		
		
		if(ball_pos.y < 3){
			ball_vel.y *= -1;
			ball_pos.y = 3;
		}
		else if(ball_pos.y > HEIGHT-2){
			ball_vel.y *= -1;
			ball_pos.y = HEIGHT-2;
		}
		if(ball_pos.x < 2 && (abs(((HEIGHT-1)/2)-ball_pos.y)>(GOAL_SIZE)/2)){
			ball_vel.x *= -1;
			ball_pos.x = 2;
		}
		else if(ball_pos.x > WIDTH-2 && (abs(((HEIGHT-1)/2)-ball_pos.y)>(GOAL_SIZE)/2)){
			ball_vel.x *= -1;
			ball_pos.x = WIDTH-2;
		}
		
		if(prev_ball_pos.x >= prev_player_1_pos.x && ball_pos.x <= player_1_pos.x){
			if(abs(ball_pos.y - player_1_pos.y)<=PLAYER_SIZE/2+1){
				if(keydown(VK_SPACE))
					ball_vel.x *= -1.5;
        		else
        			ball_vel.x *= -1;
				ball_pos.x = player_1_pos.x+1;
			}
		}
		
		else if(prev_ball_pos.x <= prev_player_1_pos.x && ball_pos.x >= player_1_pos.x){
			if(abs(ball_pos.y - player_1_pos.y)<=PLAYER_SIZE/2){
        		ball_vel.x *= -1;
				ball_pos.x = player_1_pos.x-1;
			}
		}
		
		if(prev_ball_pos.x >= prev_player_2_pos.x && ball_pos.x <= player_2_pos.x){
			if(abs(ball_pos.y - player_2_pos.y)<=PLAYER_SIZE/2){
        		ball_vel.x *= -1;
				ball_pos.x = player_2_pos.x+1;
			}
		}
		else if(prev_ball_pos.x <= prev_player_2_pos.x && ball_pos.x >= player_2_pos.x){
			if(abs(ball_pos.y - player_2_pos.y)<=PLAYER_SIZE/2){
				if(keydown(VK_RETURN))
					ball_vel.x *= -1.5;
        		else
        			ball_vel.x *= -1;
				ball_pos.x = player_2_pos.x-1;
			}
		}
		
		if(ball_pos.x > WIDTH-2 && !(abs(((HEIGHT-1)/2)-ball_pos.y)>(GOAL_SIZE)/2)){
			score_1++;
			scored = true;
		}
		if(ball_pos.x < 2 && !(abs(((HEIGHT-1)/2)-ball_pos.y)>(GOAL_SIZE)/2)){
			score_2++;
			scored = true;
		}
		
		
		
		drawBall(ball_pos, prev_ball_pos);
		prev_ball_pos = ball_pos;
		
		printScore();
		t = clock() - t;
		hideCursor();
		
		deltaTime = ((double)t)/CLOCKS_PER_SEC;

		if(scored){
			goal();
			clearGameArea();
			start_round();
		}
	}
	gameOngoing = false;
	gotoxy(0,HEIGHT-1);
	(score_1>score_2)?Win(1):Win(2);
}