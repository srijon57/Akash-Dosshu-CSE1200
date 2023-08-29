
/*_______________________________________________To show score in right top and life in left top____________________________________________*/
void score_life();

/*_______________________________________________Nargis show life wise ____________________________________________*/
void Nargis(){
	if (nargis[0].alive){
		if (nargis[0].life > 720)
			iShowBMP2(nargis[0].bossx, nargis[0].bossy, "Pics\\Boss.bmp", 0);
		else if (nargis[0].life > 680 && nargis[0].life <= 720)
			iShowBMP2(nargis[0].bossx, nargis[0].bossy, beforeblast[0], 0);//For before blast nargis1
		else if (nargis[0].life > 330 && nargis[0].life <= 680)
			iShowBMP2(nargis[0].bossx, nargis[0].bossy, "Pics\\Boss2.bmp", 0);//For face change of nargis1
		else if (nargis[0].life >= 300 && nargis[0].life <=330)
			iShowBMP2(nargis[0].bossx, nargis[0].bossy, beforeblast[1], 0);//For before blast nargis2
		else if (nargis[0].life > 0 && nargis[0].life < 300)
			iShowBMP2(nargis[0].bossx, nargis[0].bossy, "Pics\\Boss3.bmp", 0);//For face change of nargis2

		iShowBMP2(nargis[0].bullet_x, nargis[0].bullet_y, "Pics\\laser3.bmp", 0);//nargis laser
	}
}
/*_______________________________________________Nargis left right movement____________________________________________*/
void NargisMovement(){


		if (nargis[0].left)
		{
			if (nargis[0].bossx > 10)
			{
				nargis[0].bossx -= 50;
			}
			if (nargis[0].bossx <=10)
			{
				nargis[0].left = false;
				nargis[0].right = true;
			}
		}

		if (nargis[0].right)
		{
			if (nargis[0].bossx < 1100)
			{
				nargis[0].bossx += 50;
			}

			if (nargis[0].bossx >= 1100)
			{
				nargis[0].left = true;
				nargis[0].right = false;
			}
		}
		
}

/*_______________________________________________Nargis fire____________________________________________*/
void Nargisfire()
{
	//shoot on off checking and show
	if (chapter == 3){
		if (nargis[0].bullet_y >= 0)
		{
			nargis[0].bullet_y -= 70;
			nargis[0].bullet_show = false;
		}

		else
		{
			nargis[0].bullet_y = nargis[0].bossy - 20;;
			nargis[0].bullet_show = true;
			if (nargis[0].bullet_show)
				nargis[0].bullet_x = nargis[0].bossx + 48;
		}
	}
	
}
/*_______________________________________________collision joshim body to Nargis Body________________________________________*/
void joshimCollision3()
{

	if ((joshim_x + 109 >= nargis[0].bossx && joshim_x <= nargis[0].bossx + 200) &&
		(joshim_y + 150 >= nargis[0].bossy && joshim_y <= nargis[0].bossy + 230))
	{
		health = 0;
	}

}
/*_______________________________________________Collision joshim fire to nargis____________________________________________*/
void fireNargisCollision()
{
	for (int i = 0; i < 30; i++) // Assuming fireBall has 30 elements
	{
		if (fireBall[i].fire_OnOff)
		{
			if ((fireBall[i].fire_x + 30 >= nargis[0].bossx && fireBall[i].fire_x <= nargis[0].bossx + 200) &&
				(fireBall[i].fire_y + 50 >= nargis[0].bossy && fireBall[i].fire_y <= nargis[0].bossy + 230))
			{
				nargis[0].life -= 10;
				fireBall[i].fire_OnOff = false;
				fireBall[i].fire_x = joshim_x + 40;
				fireBall[i].fire_y = joshim_y + 50;
				score++;
				if (nargis[0].life <= 0)
				{					
					nargis[0].alive = false;
					menu = 5; //nach hobe
				}
			}
		}
	}
}
/*_______________________________________________Collision nargis fire to joshim____________________________________________*/
void joshimNargisBulletCollision()
{

		
			if (nargis[0].bullet_x + 50 >= joshim_x && nargis[0].bullet_x <= joshim_x + 109 &&
				nargis[0].bullet_y <= joshim_y + 150 && nargis[0].bullet_y + 80 >= joshim_y)
			{
				health -= 50;
				nargis[0].bullet_show = false;
				nargis[0].bullet_x = nargis[0].bossx + 50;
				nargis[0].bullet_y = nargis[0].bossy - 10;

				if (health <= 0)
				{
					menu = 6; // oops more gelam
				}
			}
}


/*_______________________________________________Joshim fire____________________________________________*/
void setFire();
void fireMove();
/*_______________________________________________For rendering background____________________________________________*/
void imagePositionf();

//before starting chapter 3 story 
void chap3img()
{
	if (chapter3Load == 0)
		iShowBMP(0, 0, "Pics\\Menu\\Pre\\chap3\\1.bmp");
	else if (chapter3Load == 1)
		iShowBMP(0, 0, "Pics\\Menu\\Pre\\chap3\\2.bmp");
	else if (chapter3Load == 2)
		iShowBMP(0, 0, "Pics\\Menu\\Pre\\chap3\\3.bmp");
	else
		story3Finish = true;
}

//_______________________________________________health booster___________________________________________

void setHealth()
{
	for (int i = 0; i < NUMBEROFHEALTH; i++)
	{
		health3[i].health_x = 50 + rand() % 1200;
		health3[i].health_y = 600 + rand() % 700;
		health3[i].health_index = rand() % 1;
		health3[i].healthShow = true;
	}
}

void healthShow()
{
	for (int i = 0; i < NUMBEROFHEALTH; i++)
	{
		if (health3[i].healthShow)
		{
			iShowBMP2(health3[i].health_x, health3[i].health_y, healthBox, 0);//change enemyship as needed
		}
	}
}

void healthCollision()
{
	for (int i = 0; i < NUMBEROFHEALTH; i++)
	{
		if ((joshim_x + 109 >= health3[i].health_x && joshim_x <= health3[i].health_x + 50) &&
			(joshim_y + 150 >= health3[i].health_y && joshim_y <= health3[i].health_y + 50))//change constants as resolution of health img
		{
			if (health <= 980 && health3[i].healthShow == true){
				health += 50;
				health3[i].healthShow = false;
			}
		}
	}
}

/*_______________________________________________Chapter 3____________________________________________*/
void chap3(){
	chap3img();
	if (story3Finish == true)
	{
		render();//render function call
		Nargis();
		score_life();
		healthbar();
		iShowBMP2(joshim_x, joshim_y, "Pics\\Level\\joshim.bmp", 0);
		setFire();
		healthShow();
		healthCollision();
		joshimCollision3();
		fireNargisCollision();
		joshimNargisBulletCollision();
		if (health == 0)
		{
			menu = 6;//oops more gealm
		}
	}
}


