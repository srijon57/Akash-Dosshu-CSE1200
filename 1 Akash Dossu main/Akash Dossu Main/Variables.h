# define NUMBEROFENEMY1 10
# define NUMBEROFENEMY2 6
# define NUMBEROFHEALTH 1
# define slice 32

int menu = 0, menu_flag = -1, music_flag = 1,highlight_flag=0;//menu flag ,menu highlight bar flag
bool music = true; //music flag
bool loadfinish = false;
int timer1, timer2, timer3, timer4, timer5, timer6;
int load[5], chapter = 0;
int logo = iLoadImage("Menu\\Pre\\logo2.jpg");
int loadIndex = 0;
int blastFrame = 0; // Initialize blast frame counter

/*_______________________________________________For story____________________________________________*/
int chapterLoad = 0, chapter2Load = 0, chapter3Load = 0;
bool storyFinish = false, story2Finish = false, story3Finish = false; //lvl1, lvl2 and lvl3 story
/*_______________________________________________For blasts____________________________________________*/
bool blasts = false,blasts2=false;
char highScore[100];
/*_______________________________________________For game pause____________________________________________*/
bool pause = false;

/*_______________________________________________For render____________________________________________*/
int  width = 800 / slice;//width of per image
int imagePosition[32];
/*_______________________________________________For picture input____________________________________________*/
//image renders pictures
char imgName[32][50] = { "Pics\\Level\\back\\1.bmp", "Pics\\Level\\back\\2.bmp", "Pics\\Level\\back\\3.bmp", "Pics\\Level\\back\\4.bmp", "Pics\\Level\\back\\5.bmp", "Pics\\Level\\back\\6.bmp", "Pics\\Level\\back\\7.bmp", "Pics\\Level\\back\\8.bmp", "Pics\\Level\\back\\9.bmp", "Pics\\Level\\back\\10.bmp", "Pics\\Level\\back\\11.bmp", "Pics\\Level\\back\\12.bmp", "Pics\\Level\\back\\13.bmp", "Pics\\Level\\back\\14.bmp", "Pics\\Level\\back\\15.bmp", "Pics\\Level\\back\\16.bmp", "Pics\\Level\\back\\17.bmp", "Pics\\Level\\back\\18.bmp", "Pics\\Level\\back\\19.bmp", "Pics\\Level\\back\\20.bmp", "Pics\\Level\\back\\21.bmp", "Pics\\Level\\back\\22.bmp", "Pics\\Level\\back\\23.bmp", "Pics\\Level\\back\\24.bmp", "Pics\\Level\\back\\25.bmp", "Pics\\Level\\back\\26.bmp", "Pics\\Level\\back\\27.bmp", "Pics\\Level\\back\\28.bmp", "Pics\\Level\\back\\29.bmp", "Pics\\Level\\back\\30.bmp", "Pics\\Level\\back\\31.bmp", "Pics\\Level\\back\\32.bmp" };
//blast pictures
char blast[10][50] = { "Pics\\blast\\1.bmp", "Pics\\blast\\2.bmp", "Pics\\blast\\3.bmp", "Pics\\blast\\4.bmp", "Pics\\blast\\5.bmp", "Pics\\blast\\6.bmp", "Pics\\blast\\7.bmp", "Pics\\blast\\8.bmp", "Pics\\blast\\9.bmp", "Pics\\blast\\10.bmp" };
//before nargis change faces pictures
char beforeblast[2][15] = { "Pics\\11.bmp", "Pics\\12.bmp" };
char enemyBullet[2][30] = { "Pics\\Level\\redBullet.bmp", "Pics\\Level\\guli2.bmp" };
//bilkis picture
char enemyship[6][30] = { "Pics\\Level\\bilkis.bmp", "Pics\\Level\\bilkis.bmp", "Pics\\Level\\bilkis.bmp", "Pics\\Level\\bilkis.bmp","Pics\\Level\\bilkis.bmp","Pics\\Level\\bilkis.bmp" };
//kuddus picture
char enemyship2[10][30] = { "Pics\\Level\\kuddus.bmp", "Pics\\Level\\kuddus.bmp", "Pics\\Level\\kuddus.bmp", "Pics\\Level\\kuddus.bmp", "Pics\\Level\\kuddus.bmp", "Pics\\Level\\kuddus.bmp", "Pics\\Level\\kuddus.bmp", "Pics\\Level\\kuddus.bmp", "Pics\\Level\\kuddus.bmp", "Pics\\Level\\kuddus.bmp" };
//joshim laser
char shootFire[1][30] = { "Pics\\Level\\laser2.bmp" };
char healthBox[30] = "Pics\\Level\\health.bmp";


int score = 0, bulletcount = 0, health = 300; // health bullet and score
char health_s[1000], point_s[1000];; //health point convert to char and show variable

/*_______________________________________________For health kit____________________________________________*/
struct health
{
	int health_x;
	int health_y;
	int health_index;
	bool healthShow;
};
struct health health3[NUMBEROFHEALTH];


/*_______________________________________________For joshim fire____________________________________________*/
int joshim_x = 595, joshim_y = 30; //joshim first position
struct fire
{
	int fire_x = joshim_x + 40;
	int fire_y = joshim_y + 50;
	bool fire_OnOff = false;
};
struct fire fireBall[30];
int fireIndex = 0;
/*_______________________________________________For Kuddus and bilkis____________________________________________*/
struct enemy1
{
	int enemy_x;
	int enemy_y;
	int enemy_index;
	bool enemyShow;
	int life = 2;

	int bullet_x = enemy_x + 48;
	int bullet_y = enemy_y - 20;
	bool bullet_show = true;
};
struct enemy1 redEnemy[NUMBEROFENEMY1];
struct enemy1 redEnemy2[NUMBEROFENEMY2];

/*_______________________________________________For nargis____________________________________________*/
struct Boss
{
	int bossx = 540, bossy = 550, life = 1000;
	bool alive = true;
	bool left = true, right = false;
	int bullet_x = bossx + 48;
	int bullet_y = bossy - 20;
	bool bullet_show = true;

};
struct Boss nargis[1];
char name[20];
int indexNumber = 0;
/*_______________________________________________For highscore____________________________________________*/
bool nh = true;
struct players
{
	char name[20];
	int score;
	int bullet;
}hs[5];

