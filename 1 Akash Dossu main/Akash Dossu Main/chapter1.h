/*_______________________________________________Joshim health bar____________________________________________*/
void healthbar(){
	if (health >= 280)
		iShowBMP2(15, 760, "Pics\\health\\15.bmp", 0);
	else if (health < 280 && health>=260)
		iShowBMP2(15, 760, "Pics\\health\\14.bmp", 0);
	else if (health < 260 && health >= 240)
		iShowBMP2(15, 760, "Pics\\health\\13.bmp", 0);
	else if (health < 240 && health >= 220)
		iShowBMP2(15, 760, "Pics\\health\\12.bmp", 0);
	else if (health < 220 && health >= 200)
		iShowBMP2(15, 760, "Pics\\health\\11.bmp", 0);
	else if (health < 200 && health >= 180)
		iShowBMP2(15, 760, "Pics\\health\\10.bmp", 0);
	else if (health < 180 && health >= 160)
		iShowBMP2(15, 760, "Pics\\health\\9.bmp", 0);
	else if (health < 160 && health >= 140)
		iShowBMP2(15, 760, "Pics\\health\\8.bmp", 0);
	else if (health < 140 && health >= 120)
		iShowBMP2(15, 760, "Pics\\health\\7.bmp", 0);
	else if (health < 120 && health >= 100)
		iShowBMP2(15, 760, "Pics\\health\\6.bmp", 0);
	else if (health < 100 && health >= 80)
		iShowBMP2(15, 760, "Pics\\health\\5.bmp", 0);
	else if (health < 80 && health >= 60)
		iShowBMP2(15, 760, "Pics\\health\\4.bmp", 0);
	else if (health < 60 && health >= 40)
		iShowBMP2(15, 760, "Pics\\health\\3.bmp", 0);
	else if (health < 40 && health >= 20)
		iShowBMP2(15, 760, "Pics\\health\\2.bmp", 0);
	else if (health < 20 && health > 1)
		iShowBMP2(15, 760, "Pics\\health\\1.bmp", 0);
}

/*_______________________________________________Joshim fire____________________________________________*/

void setFire()
{
	//shoot on off checking
	for (int i = 0; i < 30; i++) //for brush fire 
	{
		if (fireBall[i].fire_OnOff)
		{
			iShowBMP2(fireBall[i].fire_x, fireBall[i].fire_y, shootFire[0], 0);
		}
	}
	//shoot turn off and place the shoot
	for (int i = 0; i < 30; i++)
	{
		if (fireBall[i].fire_y> 800) //for border
		{
			fireBall[i].fire_OnOff = false;
			fireBall[i].fire_x = joshim_x + 40;
			fireBall[i].fire_y = joshim_y + 50;
		}
	}
}

//this fucntion works to move joshim/enemy fire up and down(iSetTimer used)
void fireMove(){//isettimer used
	//joshim fire up
	for (int i = 0; i < 30; i++)
	{
		if (fireBall[i].fire_OnOff == true)
			fireBall[i].fire_y += 40; //speed of joshim gun
	}
	//bilkis fire down
	if (chapter == 1){
		for (int i = 0; i < NUMBEROFENEMY1; i++)
		{
			if (redEnemy[i].bullet_show == true)
				redEnemy[i].bullet_y -= 9; //speed of bilkis gun
		}
	}
	//kuddus fire down
	else if (chapter == 2){
		for (int i = 0; i < NUMBEROFENEMY2; i++)
		{
			if (redEnemy2[i].bullet_show == true)
				redEnemy2[i].bullet_y -= 8; //speed of kuddus gun
		}
	}
}
/*_______________________________________________For rendering background____________________________________________*/
void imagePositionf()//isettimer used
{
	for (int i = 0, j = 0; i<slice; i++){ //set the slices in exact position of y axis
		imagePosition[i] = j;
		j += width;
	}
}
void render(){
	//idraw
		for (int i = 0; i < slice; i++){
			iShowBMP(0, imagePosition[i], imgName[i]);
		}
} 
void renderslow(){//isettimer used
	for (int i = 0; i < slice; i++){ //slices one by one swap//send last to first
		imagePosition[i] -= width;
		if (imagePosition[i] < 0){
			imagePosition[i] = (slice*width) - width;
			//printf("%d\n", i);
		}
	}
}

/*_______________________________________________For Storyline____________________________________________*/
void chap1img()
{
	if (chapterLoad==0)
		iShowBMP(0, 0, "Pics\\Menu\\Pre\\chap1\\1.bmp");
	else if (chapterLoad == 1)
		iShowBMP(0, 0, "Pics\\Menu\\Pre\\chap1\\2.bmp");
	else if (chapterLoad == 2)
		iShowBMP(0, 0, "Pics\\Menu\\Pre\\chap1\\3.bmp");
	else if (chapterLoad == 3)
		iShowBMP(0, 0, "Pics\\Menu\\Pre\\chap1\\4.bmp");
	else if (chapterLoad == 4)
		iShowBMP(0, 0, "Pics\\Menu\\Pre\\chap1\\5.bmp");
	else if (chapterLoad == 5)
		iShowBMP(0, 0, "Pics\\Menu\\Pre\\chap1\\6.bmp");
	else
		storyFinish = true;
}

/*_______________________________________________To show score in right top and life in left top____________________________________________*/
void score_life()
{
	iSetColor(50, 200, 200);
	iText(1170, 765, "Score: ", GLUT_BITMAP_TIMES_ROMAN_24);
	_itoa_s(score, point_s, 10);// convert int to string _itoa(int, string, base)
	iText(1235, 765, point_s, GLUT_BITMAP_TIMES_ROMAN_24);//for score
}

/*_______________________________________________Bilkis show____________________________________________*/
void regenerateenemy(){//isettimer used
	//regenerate enemy
	for (int i = 0; i < NUMBEROFENEMY1; i++)
	{
		if (!redEnemy[i].enemyShow)
		{
			redEnemy[i].enemy_x = 50 + rand() % 1200;
			redEnemy[i].enemy_y = 600 + rand() % 700;
			redEnemy[i].enemy_index = rand() % NUMBEROFENEMY1;
			redEnemy[i].enemyShow = true;
			redEnemy[i].life = 2;
		}
		//regenerate enemy fire
		if (!redEnemy[i].bullet_show)
		{
			redEnemy[i].bullet_x = redEnemy[i].enemy_x + 48;
			redEnemy[i].bullet_y = redEnemy[i].enemy_y - 20;
			redEnemy[i].bullet_show = true;
		}
	}
	//chapter 3 health booster regenarate
	if (chapter == 3 || chapter == 2){
		for (int i = 0; i < NUMBEROFHEALTH; i++)
		{
			if (!health3[i].healthShow)
			{
				health3[i].health_x = 50 + rand() % 1200;
				health3[i].health_y = 600 + rand() % 700;
				health3[i].health_index = rand() % NUMBEROFENEMY1;
				health3[i].healthShow = true;

			}
		}
	}
}
void setRedEnemy()//initial value of bilkis
{
	for (int i = 0; i < NUMBEROFENEMY1; i++)
	{
		redEnemy[i].enemy_x = 50 + rand() % 1200;
		redEnemy[i].enemy_y = 600 + rand() % 700;
		redEnemy[i].enemy_index = rand() % NUMBEROFENEMY1;
		redEnemy[i].enemyShow = true;
	}
}

/*_______________________________________________enemy speed up down___________________________________________*/
void changeEnemy()//iSetTimer used
{
	//enemy Bilkis
	if (storyFinish){
		for (int i = 0; i < NUMBEROFENEMY1; i++)
		{
			redEnemy[i].enemy_y -= 15; //bilkis speed down
			if (redEnemy[i].enemy_y <= -100)
			{
				redEnemy[i].enemy_x = 50 + rand() % 1200; //final value falls within the range of 50 to 1249
				redEnemy[i].enemy_y = 700 + rand() % 700;
			}
		}
	}

	//chapter 3 health booster health speed y axis down
	if (chapter == 3||chapter == 2){
		for (int i = 0; i < NUMBEROFHEALTH; i++)
		{
			health3[i].health_y -= 10;
			if (health3[i].health_y <= -100)
			{
				health3[i].health_x = 50 + rand() % 1200;
				health3[i].health_y = 700 + rand() % 700;
			}
		}
	}

	//loading screen image one by one time
	loadIndex++;
	if (loadIndex >= 5)
	{
		loadfinish = true;
	}

}
void redEnemyShow()
{
	for (int i = 0; i < NUMBEROFENEMY1; i++)
	{
		if (redEnemy[i].enemyShow)
		{
			iShowBMP2(redEnemy[i].enemy_x, redEnemy[i].enemy_y, enemyship[0], 0);
		}
	}
}

/*_______________________________________________set enemy fire____________________________________________*/
void setEnemyFire()
{
	//shoot on off checking and show
	for (int i = 0; i < NUMBEROFENEMY1; i++)
	{
		redEnemy[i].bullet_show = false;
	}
	for (int i = 0; i < NUMBEROFENEMY1; i++)
	{
		if (redEnemy[i].enemy_x <= 1200)
		{
			redEnemy[i].bullet_show = true;
			iShowBMP2(redEnemy[i].bullet_x, redEnemy[i].bullet_y, enemyBullet[1], 0);

		}
	}
	//shoot turn off and place the shoot
	for (int i = 0; i < NUMBEROFENEMY1; i++)
	{
		if (redEnemy[i].bullet_y < 0)
		{
			redEnemy[i].bullet_show = false;
			redEnemy[i].bullet_x = redEnemy[i].enemy_x + 48;
			redEnemy[i].bullet_y = redEnemy[i].enemy_y - 20;
		}
	}
}
/*_______________________________________________For blasting____________________________________________*///isettimer used

void blasting() {
	for (int i = 0; i < NUMBEROFENEMY1; i++) {
		if (!redEnemy[i].enemyShow) {
			if (blasts) {
				iShowBMP2(redEnemy[i].enemy_x, redEnemy[i].enemy_y, blast[blastFrame], 0);
				blasts = false;
			}
		}
		else if (!redEnemy2[i].enemyShow){
		 if (blasts2) {
			iShowBMP2(redEnemy2[i].enemy_x, redEnemy2[i].enemy_y, blast[blastFrame], 0);
			blasts2 = false;
		}
		}
		blastFrame++; // Increment blast frame counter
		if (blastFrame >= 10) {
			blastFrame = 0; // Reset blast frame counter
		}
	}
}

/*_______________________________________________Collision joshim fire to enemy____________________________________________*/
void firecollision()
{
	for (int i = 0; i < 30; i++) // Assuming fireBall has 30 elements
	{
		if (fireBall[i].fire_OnOff)
		{
			for (int j = 0; j < NUMBEROFENEMY1; j++)
			{
				if (redEnemy[j].enemyShow)
				{
					if ((fireBall[i].fire_x + 30 >= redEnemy[j].enemy_x && fireBall[i].fire_x <= redEnemy[j].enemy_x + 100) &&
						(fireBall[i].fire_y + 50 >= redEnemy[j].enemy_y && fireBall[i].fire_y <= redEnemy[j].enemy_y + 100))
					{
						redEnemy[j].enemyShow = false;
						blasts = true;
						blasting();
						fireBall[i].fire_OnOff = false;
						fireBall[i].fire_x = joshim_x + 40;
						fireBall[i].fire_y = joshim_y + 50;
						
						redEnemy[j].enemy_x = 100 + rand() % 1200;
						redEnemy[j].enemy_y = 800 + rand() % 50;
						redEnemy[j].enemy_index = rand() % NUMBEROFENEMY1;
						redEnemy[j].enemyShow = true;
						score ++;
						if (score == 30){
							chapter = 2; //NExt Chapter 
						}
					}
				}
			}
		}
	}
}
/*_______________________________________________collision joshim body to enemy body____________________________________________*/
void joshimCollision()
{
	for (int i = 0; i < NUMBEROFENEMY1; i++)
	{
		if ((joshim_x + 109 >= redEnemy[i].enemy_x && joshim_x <= redEnemy[i].enemy_x + 100) && 
			(joshim_y + 150 >= redEnemy[i].enemy_y && joshim_y <= redEnemy[i].enemy_y + 100))
		{
			health = 0;
		}
	}
}


/*_______________________________________________Collision bilkis fire to joshim____________________________________________*/
void BilkisFireCollision()
{
	for (int i = 0; i < NUMBEROFENEMY1; i++)
	{
		if (redEnemy[i].bullet_x + 12 >= joshim_x && redEnemy[i].bullet_x <= joshim_x + 109 &&
			redEnemy[i].bullet_y <= joshim_y + 150 && redEnemy[i].bullet_y + 20 >= joshim_y)
		{
			redEnemy[i].bullet_show = false;
			redEnemy[i].bullet_x = redEnemy[i].enemy_x + 50;
			redEnemy[i].bullet_y = redEnemy[i].enemy_y - 10;
			if (!redEnemy[i].bullet_show)
				health -= 10;
			if (health <= 0)
			{
				menu = 6;//oops more gelam
			}
		}
	}
}

/*_______________________________________________Chapter 1____________________________________________*/
void chap1(){
	chap1img();
	if (storyFinish == true)
	{
		render(); // render function call
		setEnemyFire();
		BilkisFireCollision();
		joshimCollision();
		redEnemyShow();
		score_life();
		healthbar(); // Display healthbar on top
		iShowBMP2(joshim_x, joshim_y, "Pics\\Level\\joshim.bmp", 0);
		setFire();
		firecollision();

		if (health == 0)
		{
			menu = 6; // oops more gealm
		}
	}
}

