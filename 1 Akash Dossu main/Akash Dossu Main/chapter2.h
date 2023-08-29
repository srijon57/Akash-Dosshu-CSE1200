
/*_______________________________________________Joshim fire____________________________________________*/

void setFire();

void fireMove();
/*_______________________________________________For rendering background____________________________________________*/
void imagePositionf();
void render();
void renderslow();

//before starting chapter 1
void chap2img()
{
	if (chapter2Load==0)
		iShowBMP(0, 0, "Pics\\Menu\\Pre\\chap2\\1.bmp");
	else if (chapter2Load == 1)
		iShowBMP(0, 0, "Pics\\Menu\\Pre\\chap2\\2.bmp");
	else if (chapter2Load == 2)
		iShowBMP(0, 0, "Pics\\Menu\\Pre\\chap2\\3.bmp");
	else
		story2Finish = true;
}
/*_______________________________________________To show score in right top and life in left top____________________________________________*/
void score_life();
/*_______________________________________________Bilkis show____________________________________________*/
void regenerateenemy2(){
	//regenerate enemy

	for (int i = 0; i < NUMBEROFENEMY2; i++)
	{
		if (!redEnemy2[i].enemyShow)
		{
			redEnemy2[i].enemy_x = 50 + rand() % 1200;
			redEnemy2[i].enemy_y = 600 + rand() % 700;
			redEnemy2[i].enemy_index = rand() % NUMBEROFENEMY2;
			redEnemy2[i].life = 2;
			redEnemy2[i].enemyShow = true;
			
		}
		//regenerate enemy fire
		if (!redEnemy2[i].bullet_show)
		{
			redEnemy2[i].bullet_x = redEnemy2[i].enemy_x + 48;
			redEnemy2[i].bullet_y = redEnemy2[i].enemy_y - 20;
			redEnemy2[i].bullet_show = true;
		}
	}
}
void setRedEnemy2()
{
	for (int i = 0; i < NUMBEROFENEMY2; i++)
	{
		redEnemy2[i].enemy_x = 50 + rand() % 1200;
		redEnemy2[i].enemy_y = 600 + rand() % 700;
		redEnemy2[i].enemy_index = rand() % NUMBEROFENEMY2;
		redEnemy2[i].life = 2;
		redEnemy2[i].enemyShow = true;
		
	}
}

//enemy
void changeEnemy2()
{
	//enemy redEnemy
	if (story2Finish==true && chapter==2){
		for (int i = 0; i < NUMBEROFENEMY2; i++)
		{
			redEnemy2[i].enemy_y -= 10;
			if (redEnemy2[i].enemy_y <= -100)
			{
				redEnemy2[i].enemy_x = 50 + rand() % 1200;
				redEnemy2[i].enemy_y = 700 + rand() % 700;
			}
		}
	}
}
void redEnemyShow2()
{
	for (int i = 0; i < NUMBEROFENEMY2; i++)
	{
		if (redEnemy2[i].enemyShow)
		{
			iShowBMP2(redEnemy2[i].enemy_x, redEnemy2[i].enemy_y, enemyship2[0], 0);
		}
	}
}

/*_______________________________________________set enemy fire____________________________________________*/
void setEnemyFire2()
{
	//shoot on off checking and show
	for (int i = 0; i < NUMBEROFENEMY2; i++)
	{
		redEnemy2[i].bullet_show = false;
	}
	for (int i = 0; i < NUMBEROFENEMY2; i++)
	{
		if (redEnemy2[i].enemy_x <= 1200)
		{
			redEnemy2[i].bullet_show = true;
			iShowBMP2(redEnemy2[i].bullet_x, redEnemy2[i].bullet_y, enemyBullet[0], 0);

		}
	}
	//shoot turn off and place the shoot
	for (int i = 0; i < NUMBEROFENEMY2; i++)
	{
		if (redEnemy2[i].bullet_y < 0)
		{
			redEnemy2[i].bullet_show = false;
			redEnemy2[i].bullet_x = redEnemy2[i].enemy_x + 48;
			redEnemy2[i].bullet_y = redEnemy2[i].enemy_y - 20;
		}
	}
}

void blasting();
/*_______________________________________________Collision joshim fire to enemy____________________________________________*/
void firecollision2()
{
	for (int i = 0; i < 30; i++) // Assuming fireBall has 30 elements
	{
		if (fireBall[i].fire_OnOff)
		{
			for (int j = 0; j < NUMBEROFENEMY2; j++)
			{
				if (redEnemy2[j].enemyShow)
				{
					if ((fireBall[i].fire_x + 30 >= redEnemy2[j].enemy_x && fireBall[i].fire_x <= redEnemy2[j].enemy_x + 100) &&
						(fireBall[i].fire_y + 50 >= redEnemy2[j].enemy_y && fireBall[i].fire_y <= redEnemy2[j].enemy_y + 100))
					{
						redEnemy2[j].life--;

							//redEnemy2[j].enemyShow = false;
							fireBall[i].fire_OnOff = false;
							fireBall[i].fire_x = joshim_x + 40;
							fireBall[i].fire_y = joshim_y + 50;
							redEnemy2[j].life--;
							if (redEnemy2[j].life < 0){
								redEnemy2[j].enemyShow = false;
								blasts2 = true;
								blasting();
								redEnemy2[j].enemy_x = 100 + rand() % 1200;
								redEnemy2[j].enemy_y = 800 + rand() % 50;
								redEnemy2[j].enemy_index = rand() % NUMBEROFENEMY2;
								redEnemy2[j].life = 2;
								redEnemy2[j].enemyShow = true;
							}						
							score++;
						if (score == 60){
							chapter = 3;
						}
					}
				}
			}
		}
	}
}
/*_______________________________________________collision joshim body to enemy____________________________________________*/
void joshimCollision2()
{
	for (int i = 0; i < NUMBEROFENEMY2; i++)
	{
		if ((joshim_x + 109 >= redEnemy2[i].enemy_x && joshim_x <= redEnemy2[i].enemy_x + 100) && 
			(joshim_y + 150 >= redEnemy2[i].enemy_y && joshim_y <= redEnemy2[i].enemy_y + 100))
		{
			health = 0;
		}
	}
}


/*_______________________________________________Collision bilkis fire to joshim____________________________________________*/
void BilkisFireCollision2()
{
	for (int i = 0; i < NUMBEROFENEMY2; i++)
	{
		if (redEnemy2[i].bullet_x + 12 >= joshim_x && redEnemy2[i].bullet_x <= joshim_x + 109 && redEnemy2[i].bullet_y <= joshim_y + 150 && redEnemy2[i].bullet_y + 20 >= joshim_y)
		{
			redEnemy2[i].bullet_show = false;
			redEnemy2[i].bullet_x = redEnemy2[i].enemy_x + 50;
			redEnemy2[i].bullet_y = redEnemy2[i].enemy_y - 10;
			if (!redEnemy2[i].bullet_show)
				health -= 20;
			if (health <= 0)
			{
				menu = 6;
				//newhighscore();
			}
		}
	}
}
void healthShow();
void healthCollision();
void setHealth();
/*_______________________________________________Chapter 2____________________________________________*/
void chap2(){
	chap2img();
	if (story2Finish == true)
	{
		render();//render function call	
		setEnemyFire2();
		BilkisFireCollision2();
		joshimCollision2();
		redEnemyShow2();
		healthShow();
		healthCollision();
		score_life();
		healthbar();
		iShowBMP2(joshim_x, joshim_y, "Pics\\Level\\joshim.bmp", 0);
		setFire();
		firecollision2();

		if (health == 0)
		{
			menu = 6;//oops more gealm
		}
	}
}


