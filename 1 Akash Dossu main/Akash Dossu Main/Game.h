
/*_______________________________________________Joshim fire____________________________________________*/

void setFire()
{
	//shoot on off checking
	for (int i = 0; i < 30; i++)
	{
		if (fireBall[i].fire_OnOff)
		{
			iShowBMP2(fireBall[i].fire_x, fireBall[i].fire_y, shootFire[0], 0);
		}
	}
	//shoot turn off and place the shoot
	for (int i = 0; i < 30; i++)
	{
		if (fireBall[i].fire_y> 800)
		{
			fireBall[i].fire_OnOff = false;
			fireBall[i].fire_x = joshim_x + 40;
			fireBall[i].fire_y = joshim_y + 50;
		}
	}
}
void fireMove(){
	//joshim fire up
	for (int i = 0; i < 30; i++)
	{
		if (fireBall[i].fire_OnOff == true)
			fireBall[i].fire_y += 40;
	}
	//enemy fire down
	for (int i = 0; i < 3; i++)
	{
		if (redEnemy[i].bullet_show == true)
			redEnemy[i].bullet_y -= 5;
	}
}
/*_______________________________________________For rendering background____________________________________________*/
void imagePositionf()
{
	for (int i = 0, j = 0; i<slice; i++){
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
void renderslow(){
	for (int i = 0; i < slice; i++){
		imagePosition[i] -= width;
		if (imagePosition[i] < 0){
			imagePosition[i] = (slice*width) - width;
		}
	}
}

//before starting chapter 1
void chap1img()
{
	for (int i = 0; i < 20; i++)
	{
		iShowBMP(0, 0, "Pics\\Menu\\Pre\\bilkissaga.bmp");
	}
}
/*_______________________________________________Bilkis show____________________________________________*/
void regenerateenemy(){
	//regenerate enemy
	for (int i = 0; i < NUMBEROFENEMY1; i++)
	{
		if (!redEnemy[i].enemyShow)
		{
			redEnemy[i].enemy_x = 50 + rand() % 1200;
			redEnemy[i].enemy_y = 600 + rand() % 700;
			redEnemy[i].enemy_index = rand() % 4;
			redEnemy[i].enemyShow = true;
			redEnemy[i].enemy_life = 3;
		}
		//regenerate enemy fire
		if (!redEnemy[i].bullet_show)
		{
			redEnemy[i].bullet_x = redEnemy[i].enemy_x + 48;
			redEnemy[i].bullet_y = redEnemy[i].enemy_y - 20;
			redEnemy[i].bullet_show = true;
		}
	}
}
void setRedEnemy()
{
	for (int i = 0; i < NUMBEROFENEMY1; i++)
	{
		redEnemy[i].enemy_x = 50 + rand() % 1200;
		redEnemy[i].enemy_y = 600 + rand() % 700;
		redEnemy[i].enemy_index = rand() % 4;
		redEnemy[i].enemyShow = true;
	}
}

//enemy
void changeEnemy()
{
	//enemy redEnemy
	for (int i = 0; i < NUMBEROFENEMY1; i++)
	{
		redEnemy[i].enemy_y -= 10;
		if (redEnemy[i].enemy_y <= -100)
		{
			redEnemy[i].enemy_x = 50 + rand() % 1200;
			redEnemy[i].enemy_y = 700 + rand() % 700;
		}
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
	for (int i = 0; i < 4; i++)
	{
		redEnemy[i].bullet_show = false;
	}
	for (int i = 0; i < 3; i++)
	{
		if (redEnemy[i].enemy_x <= 900)
		{
			redEnemy[i].bullet_show = true;
			iShowBMP2(redEnemy[i].bullet_x, redEnemy[i].bullet_y, enemyBullet[0], 0);

		}
	}
	//shoot turn off and place the shoot
	for (int i = 0; i < 4; i++)
	{
		if (redEnemy[i].bullet_y < 0)
		{
			redEnemy[i].bullet_show = false;
			redEnemy[i].bullet_x = redEnemy[i].enemy_x + 48;
			redEnemy[i].bullet_y = redEnemy[i].enemy_y - 20;
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
						fireBall[i].fire_OnOff = false;
						fireBall[i].fire_x = joshim_x + 40;
						fireBall[i].fire_y = joshim_y + 50;
						
						redEnemy[j].enemy_x = 100 + rand() % 1200;
						redEnemy[j].enemy_y = 800 + rand() % 50;
						redEnemy[j].enemy_index = rand() % 3;
						redEnemy[j].enemyShow = true;
						score ++;
						if (score == 1){
							chapter = 3;
						}
					}
				}
			}
		}
	}
}
/*_______________________________________________collision joshim body to enemy____________________________________________*/
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

/*_______________________________________________To show score in right top and life in left top____________________________________________*/
void score_life()
{
	iSetColor(50, 200, 200);
	iText(15, 765, "Life: ", GLUT_BITMAP_TIMES_ROMAN_24);
	_itoa_s(health, health_s, 10); // convert int to string _itoa(int, string, base)
	iText(65, 765, health_s, GLUT_BITMAP_TIMES_ROMAN_24);//for health
	iText(1170, 765, "Score: ", GLUT_BITMAP_TIMES_ROMAN_24);
	_itoa_s(score, point_s, 10);// convert int to string _itoa(int, string, base)
	iText(1235, 765, point_s, GLUT_BITMAP_TIMES_ROMAN_24);//for score
}
/*_______________________________________________Collision bilkis fire to joshim____________________________________________*/
void BilkisFireCollision()
{
	for (int i = 0; i < NUMBEROFENEMY1; i++)
	{
		if (redEnemy[i].bullet_x + 12 >= joshim_x && redEnemy[i].bullet_x <= joshim_x + 109 && redEnemy[i].bullet_y <= joshim_y + 150 && redEnemy[i].bullet_y + 20 >= joshim_y)
		{
			redEnemy[i].bullet_show = false;
			redEnemy[i].bullet_x = redEnemy[i].enemy_x + 50;
			redEnemy[i].bullet_y = redEnemy[i].enemy_y - 10;
			if (!redEnemy[i].bullet_show)
				health -= 10;
			if (health <= 0)
			{
				menu = 6;
				//newhighscore();
			}
		}
	}
}

/*_______________________________________________Chapter 1____________________________________________*/
void chap1(){
	if (chapterLoad == 0)
		chap1img();
	else
	{
		render();//render function call
		score_life();
		setEnemyFire();
		BilkisFireCollision();
		joshimCollision();
		redEnemyShow();

		iShowBMP2(joshim_x, joshim_y, "Pics\\Level\\joshim.bmp", 0);
		setFire();
		firecollision();

		if (health == 0)
		{
			menu = 6;//oops more gealm
		}
	}
}


