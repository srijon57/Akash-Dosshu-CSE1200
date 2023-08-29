#include <string>
#include <cstring>
#include <fstream>
#include <iostream>
#include<algorithm>
#include <functional>
#include<string>
using namespace std;

// to creat file.................
void Enter_Name()
{
	iSetColor(255, 255, 255);
	iText(502, 380, name, GLUT_BITMAP_TIMES_ROMAN_24);
}
bool compareScores(const players a, const players b) {
	if (a.score == b.score)
		return a.bullet < b.bullet;
	else if (a.score > b.score)
		return true;
	else
		return false;
}

void insertHighscore()
{
	
	fstream fp;
	fp.open("SCR.txt");
	for (int i = 0; i < 5; i++) {
		fp>>hs[i].name >> hs[i].score>>hs[i].bullet;
	}
	fp.close();

	// Add current score to the array if it's greater than the last score
	if (nh){
		for (int i = 0; i<5; i++)
		{
			//cout << name << endl;
			if (hs[i].score<score) {
				hs[4].score = score;
				hs[4].bullet = bulletcount;
				copy(name, name + indexNumber, hs[4].name);

				// Sort the scores in descending order
				sort(hs, hs + 5, compareScores);

				// Write the sorted scores back to the file
				fp.open("SCR.txt", ios::out);
				for (int i = 0; i < 5; i++) {
					fp <<hs[i].name<<" "<< hs[i].score <<" "<<hs[i].bullet<< endl;
				}
				fp.close();
				nh = false;
				break;
			}
		}
	}

}

//this function represent menu bar of this game project..

//loading and menu

void loading(){
	load[0] = iLoadImage("Pics\\Menu\\Pre\\1.jpg");
	load[1] = iLoadImage("Pics\\Menu\\Pre\\2.jpg");
	load[2] = iLoadImage("Pics\\Menu\\Pre\\3.jpg");
	load[3] = iLoadImage("Pics\\Menu\\Pre\\4.jpg");
	load[4] = iLoadImage("Pics\\Menu\\Pre\\5.jpg");
	//logo = iLoadImage("Menu\\Pre\\logo2.jpg");
}

void gameState()
{                   //////////////////////FOR LOADING AND LOGO PAGE

	if (loadfinish == true)
	{
		//iShowImage(0, 0, screenWidth, screenHeight, logo);
		iPauseTimer(timer1);
		iPauseTimer(timer2);
		iPauseTimer(timer3);
		iPauseTimer(timer4);
		iPauseTimer(timer5);
		menu = 1;
	}
}

void fuctionForLoad()
{
	loadIndex++;
	if (loadIndex >= 5)
	{
		loadfinish = true;
	}
}
void logo1()
{
	iShowBMP(0, 0, "Pics\\Menu\\Pre\\logo2.bmp");
	if (music == true && music_flag == 1 && menu_flag==-1){
		//PlaySound("Music\\Apex.wav", NULL, SND_ASYNC);
		PlaySound("Music\\Main menu.wav", NULL, SND_ASYNC);
		music = false;
	}
}

//for Menus

void menus()
{
	if (music == true && music_flag == 1 && menu_flag == 0){
		//PlaySound("Music\\Apex.wav", NULL, SND_ASYNC);
		PlaySound("Music\\Main menu.wav", NULL, SND_ASYNC);
		music = false;
	}
	iShowBMP(0, 0, "Pics\\Menu\\Menubg.bmp");
	
}


void inputname(){
	iShowBMP(0, 0, "Pics\\Menu\\nameinput.bmp");
}


void instructions(){
	iShowBMP(0, 0, "Pics\\Menu\\instructions.bmp");
}


void highscore(){
	iShowBMP(0, 0, "Pics\\Menu\\highscore.bmp");


	ifstream fp;
	fp.open("SCR.txt");
	for (int i = 0; i < 5; i++) {
		fp >>hs[i].name>> hs[i].score>>hs[i].bullet;
	}
	fp.close();

	// Display the top 5 scores

	for (int i = 0; i < 5; i++) {
		char scoreStr[10],bulletStr[10];
		iSetColor(204, 255, 255);
		iText(350, 480 - i * 50, hs[i].name , GLUT_BITMAP_TIMES_ROMAN_24);
		_itoa_s(hs[i].score, scoreStr, 10);
		iText(650, 480 - i * 50, scoreStr, GLUT_BITMAP_TIMES_ROMAN_24);
		_itoa_s(hs[i].bullet, bulletStr, 10);
		iText(880, 480 - i * 50, bulletStr, GLUT_BITMAP_TIMES_ROMAN_24);
	}
	
}

void about(){
	iShowBMP(0, 0, "Pics\\Menu\\about.bmp");
}
/*_______________________________________________sound cancel____________________________________________*/
void cancel_sound(){
		if (music_flag == 1){
			PlaySound(0, 0, 0);
			music_flag = 0;
		}
		else
		{
			music = true;
			music_flag = 1;
		}
}
void Highlight1()
{
	iShowBMP(0, 0,"Pics\\Menu\\H1.bmp");
}
void Highlight2()
{
	iShowBMP(0, 0, "Pics\\Menu\\H2.bmp");
}

void Highlight3()
{
	iShowBMP(0, 0, "Pics\\Menu\\H3.bmp");
}

void Highlight4()
{
	iShowBMP(0, 0, "Pics\\Menu\\H4.bmp");
}

void Highlight5()
{
	iShowBMP(0, 0, "Pics\\Menu\\H5.bmp");
}

/*_______________________________________________For Generating everything again____________________________________________*/
void generateagain(){
	insertHighscore();
	health = 300;
	score = 0;
	menu = 1;
	menu_flag = 0;
	chapter = 0;
	storyFinish = false;
	story2Finish = false;
	story3Finish = false;
	nh = true;
	chapterLoad = 0;
	chapter2Load = 0;
	chapter3Load = 0;
	nargis[0].life = 1000;
	nargis[0].alive = true;
	memset(name, 0, sizeof(name));
	//name[20]= ' ';
	indexNumber = 0;
	joshim_x = 595, joshim_y = 30;
	for (int i = 0; i < NUMBEROFENEMY1; i++)
	{
		
			redEnemy[i].enemy_x = 50 + rand() % 1200;
			redEnemy[i].enemy_y = 600 + rand() % 700;
			redEnemy[i].enemy_index = rand() % NUMBEROFENEMY1;
			redEnemy[i].enemyShow = true;
			redEnemy[i].life = 2;

	}

	for (int i = 0; i < NUMBEROFENEMY2; i++)
	{
			redEnemy2[i].enemy_x = 50 + rand() % 1200;
			redEnemy2[i].enemy_y = 600 + rand() % 700;
			redEnemy2[i].enemy_index = rand() % NUMBEROFENEMY2;
			redEnemy2[i].life = 2;
			redEnemy2[i].enemyShow = true;

	}
}



