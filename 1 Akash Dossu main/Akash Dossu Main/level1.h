
struct Boss
{
	int bossx=540, bossy=550,life=200;
	bool alive = true;
	bool left=true, right=false;
	int bullet_x =bossx + 48;
	int bullet_y = bossy - 20;
	bool bullet_show = true;

};
Boss nargis[1];

void Nargis(){
	iShowBMP2(nargis[0].bossx, nargis[0].bossy, "Pics\\Boss.bmp", 0);
	iShowBMP2(nargis[0].bullet_x, nargis[0].bullet_y, "Pics\\laser3.bmp", 0);
}
void NargisMovement(){


		//if (enemyMovementUp)
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

		//if (enemyMovemntDown)
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
////////////////////////////////////////////////////////////////
void Nargisfire()
{
	//shoot on off checking and show
	if (chapter == 3){
		if (nargis[0].bullet_y >= 0)
		{
			nargis[0].bullet_y -= 50;
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
/*_______________________________________________Joshim fire____________________________________________*/

void setFire();

void fireMove();

/*_______________________________________________For rendering background____________________________________________*/
void imagePositionf();


//before starting chapter 1
void chap1img();


/*_______________________________________________To show score in right top and life in left top____________________________________________*/
void score_life();


/*_______________________________________________Chapter 3____________________________________________*/
void chap3(){
	if (chapterLoad == 0)
		chap1img();
	else
	{
		render();//render function call
		score_life();
		Nargis();
		iShowBMP2(joshim_x, joshim_y, "Pics\\Level\\joshim.bmp", 0);
		setFire();
		if (health == 0)
		{
			menu = 6;//oops more gealm
		}
	}
}


