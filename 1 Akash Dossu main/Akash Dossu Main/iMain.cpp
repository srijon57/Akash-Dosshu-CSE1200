# include "iGraphics.h"
#include "Variables.h"
#include"Menu.h"
#include"chapter1.h"
#include"chapter2.h"
#include"chapter3.h"
#include"score.h"
# include <iostream>
using namespace std;

#define screenWidth 1280
#define screenHeight 800



void iDraw()
{
	//place your drawing codes here
	iClear();
	if (menu == 0){                   //idraw for loading
		iShowImage(0, 0, screenWidth, screenHeight, load[loadIndex]);///////LOADING
		gameState();//menu.h
	}

	else if (menu == 1){         //idraw for logo and menu
		if (menu_flag == -1){
			logo1();//menu.h
		}
		else if (menu_flag == 0){

			menus();
		}
		else if (menu_flag == 1){
			menu = 3;
			chapter = 1;
		}
		else if (menu_flag == 2){
			instructions();//menu.h
		}
		else if (menu_flag == 3){
			highscore();//menu.h
		}
		else if (menu_flag == 4){
			about();//menu.h
		}
		if (highlight_flag == 1)
			Highlight1();//menu.h
		else if (highlight_flag == 2)
			Highlight2();//menu.h
		else if (highlight_flag == 3)
			Highlight3();//menu.h
		else if (highlight_flag == 4)
			Highlight4();//menu.h
		else if (highlight_flag == 5)
			Highlight5();//menu.h
	}
	else if (menu == 3){            //idraw for chapter
		if (chapter == 1){
			chap1();//chapter1.h
		}
		else if (chapter == 2){
			chap2();//chapter2.h
		}
		else if (chapter == 3)
			chap3();//chapter3.h
	}
	else if (menu == 4){
		iShowBMP(0, 0, "Pics\\input.bmp");
		Enter_Name();//menu.h
	}
	else if (menu == 5){
		iShowBMP(0, 0, "Pics\\GameOver\\win.bmp");
	}
	else if (menu == 6){
		iShowBMP(0, 0, "Pics\\GameOver\\oops.bmp");
	}
}

void iPassiveMouse(int mx, int my)
{
	//cout << mx << " " << my << endl;
	//for highlighting menu bars.
	if (menu_flag == 0){
		if (((mx >= 515 && mx <= 814) && (my >= 505 && my <= 593))){
			highlight_flag = 1;
		}
		else if ((mx >= 515 && mx <= 814) && (my >= 387 && my <= 476))
			highlight_flag = 2;
		else if ((mx >= 515 && mx <= 814) && (my >= 277 && my <= 365))
			highlight_flag = 3;
		else if ((mx >= 515 && mx <= 814) && (my >= 161 && my <= 251))
			highlight_flag = 4;
		else if ((mx >= 515 && mx <= 814) && (my >= 37 && my <= 125))
			highlight_flag=5;
		else
			highlight_flag = 0;
	}
}

void iMouseMove(int mx, int my)
{
		//place your codes here
}

void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//cout << "x= " << mx << " y= " << my << endl;
		//place your codes here
		if (menu_flag ==0 )
		{
			if ((mx >= 1189 && mx <= 1261) && (my >= 725 && my <= 785))
				cancel_sound();//sound on off

			//click any menu bar 
			if (((mx >= 515 && mx <= 814) && (my >= 505 && my <= 593))){
				menu_flag = 1;
				highlight_flag = 0;
			}
			else if ((mx >= 515 && mx <= 814) && (my >= 387 && my <= 476)){
				menu_flag = 2;
				highlight_flag = 0;
			}
			else if ((mx >= 515 && mx <= 814) && (my >= 277 && my <= 365)){
				menu_flag = 3;
				highlight_flag = 0;
			}
			else if ((mx >= 515 && mx <= 814) && (my >= 161 && my <= 251)){
				menu_flag = 4;
				highlight_flag = 0;
			}
			else if ((mx >= 515 && mx <= 814) && (my >= 37 && my <= 125)){
				highlight_flag = 0;
				exit(0);
			}
			
		}
		//going back from any interface
		else if ((menu_flag == 1|| menu_flag == 2 || menu_flag == 3 || menu_flag == 4))
		{
			if ((mx >= 30 && mx <= 153) && (my >= 703 && my <= 753))
				menu_flag = 0;
		}

	}

	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/

void iKeyboard(unsigned char key)
{
	if (menu == 1){
			if (key=='\r')//enter key press logo to menu
				menu_flag = 0;
	}
	else if (menu == 4){
		/////////////////TO ENTER NAME1/////////////////
		if (key == '\r')
		{
			//cout << name << endl;
			generateagain();//menu.h

		}
		else if (key == '\b')//remove charecter if we hit backspace
		{
			if (indexNumber <= 0)
				indexNumber = 0;
			else
				indexNumber--;

			name[indexNumber] = '\0';//the charecter we removed we placed NULL character at last
		}
		else{
			name[indexNumber] = key;
			indexNumber++;

			if (indexNumber > 15) //can't give more than 15 characters in name input
			indexNumber = 15;

			name[indexNumber] = '\0';//put a NULL character at last.
		}
	}
	else if (menu == 3){
		if (chapter == 1)//chapter 1 story one by one show if we hit enter
		{
			if (key == '\r')
				chapterLoad++;
		}
		else if (chapter ==2)//chapter 2 story one by one show if we hit enter
		{
			if (key == '\r')
				chapter2Load++;
		}
		else if (chapter == 3)//chapter 3 story one by one show if we hit enter
		{
			if (key == '\r')
				chapter3Load++;
		}
	}
	else if (menu == 6||menu==5){
		if (key == '\r'){
			menu = 4;
		}
	}
	
	if (menu == 3 && (chapter == 1 || chapter == 2 || chapter == 3)){
		if (key == 'z' || key == ' '){
			bulletcount++;//needed for scoring system
			//cout << "Bullet= " << bulletcount << endl;
			if (fireIndex == 30)
				fireIndex = 0;

			fireBall[fireIndex].fire_OnOff = true;
			fireBall[fireIndex].fire_x = joshim_x+40;
			fireBall[fireIndex].fire_y = joshim_y + 60;
			++fireIndex;
		}
		if (key == 'p')//for pausing the game
		{

			if (!pause) {
				pause = true;
				for (int i = 0; i < 8; ++i) {
					iPauseTimer(i);
				}
				// ... pause other timers ...
			}
			else {
				for (int i = 0; i < 8; ++i) {
					iResumeTimer(i);
					pause = false;
				}
			}
		}
		else if (key == 'q' && music_flag==1){//pause music
			cancel_sound();
		}
		else if (key == 'q' && music_flag == 0){//resume music
			music_flag=1;
			PlaySound("Music\\Main menu.wav", NULL, SND_ASYNC);
			music = false;
		}
	}
}

/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_END)
	{
		exit(0);
	}
		if (key == GLUT_KEY_UP)
		{
			if (joshim_y >= 1 && joshim_y <= 750){
				joshim_y += 20;
			}
			else if (joshim_y > 750)
				joshim_y = 750;

		}
		else if (key == GLUT_KEY_DOWN)
		{
			if (joshim_y >= 15 && joshim_y <= 770){
				joshim_y -= 20;
			}
			else if (joshim_y < 2){
				joshim_y = 2;
			}

		}
		else if (key == GLUT_KEY_RIGHT)
		{
			if (joshim_x >= 00 && joshim_x <= 1200){
				joshim_x += 25;
			}
			else if (joshim_x>1200)
			{
				joshim_x = 1200;
			}
		}
		else if (key == GLUT_KEY_LEFT)
		{
			if (joshim_x >= 25 && joshim_x <= 1260){
				joshim_x -= 25;
			}
			else if (joshim_x<25)
			{
				joshim_x = 25;
			}
		}

}


int main()
{
	//place your own initialization codes here.
	iSetTimer(1000, imagePositionf);//slice show speed up down
	iSetTimer(40, renderslow);//speed up down render
	
	//bilkis enenmy placement
	iSetTimer(500, regenerateenemy);
	iSetTimer(500, changeEnemy);

	//kuddus enenmy placement
	iSetTimer(500, regenerateenemy2);
	iSetTimer(500, changeEnemy2);
	iSetTimer(800, blasting);

	iInitialize(screenWidth, screenHeight, "Akash Dosshu");
	iSetTimer(30, fireMove);
	
	loading();//loading screen image show before menu
	iSetTimer(200, NargisMovement);
	iSetTimer(80, Nargisfire);

	iStart(); // it will start drawing
	return 0;
}



