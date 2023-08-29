#ifndef MYHEADER_H_INCLUDED
#define MYHEADER_H_INCLUDED

int pic_x, pic_y;
int dx, dy;

void objectChange() {
	pic_x += dx;
	pic_y += dy;

	if (pic_x >= 400 || pic_x <= 0)
		dx = -dx;
	if (pic_y >= 400 || pic_y <= 0)
		dy = -dy;
}

#endif // !MYHEADER_H_INCLUDED
