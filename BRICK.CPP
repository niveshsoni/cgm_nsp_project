#include <conio.h>
#include <dos.h>
#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void outline()
{
    int u = 198;
    rectangle(300,130,550,470);
    line(385,130,385,470);
    line(470,130,470,470);
    while (u <= 470) {
	line(300,u,550,u);
	u = u + 68;
    }
    settextstyle(3,0,1);
    outtextxy(2,20, "FOR MOVE LEFT PRESS 'l'");
    outtextxy(2,40, "FOR MOVE RIGHT PRESS 'r'");
    outtextxy(2,60, "FOR MOVE MIDDLE PRESS 'm'");
}
void main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\turboc3\\bgi");

    // Declaring & Initialising Variables
    int a = 420, b = 40, c = 450, d = 70,
	x, left[10], right[10], mid[10],
	up = 5, low = 2, lb =470 , mb = 470,
	rb = 470, i = 0, j = 0, k = 0,
	score = 0, p;
    char z, str[3];
    outline();
    while (1){
	settextstyle(3,0,1);
	outtextxy(400, 10, "Brick Box");
	rectangle(a, b, c, d);
	x = (rand() % (up - low + 1)) + low;
	setfillstyle(SOLID_FILL, x);
	floodfill(a+5,d-5,15);
	z = getch();
	if (z == 'l') {
	    settextstyle(3,0,1);
	    outtextxy(260,10, "Left Sub-Box");
	    rectangle(a-140,b,c-140,d);
	    floodfill(a-135,d-5, 15);
	    delay(200);
	    setfillstyle(SOLID_FILL, BLACK);
	    floodfill(a-135,d-5,15);
	    rectangle(a-120,lb-68,c-65, lb);
	    setfillstyle(SOLID_FILL, x);
	    floodfill(a-115,lb-5, 15);
	    delay(200);
	    lb = lb -68;
	    left[i] = x;
	    i++;

	    // Process To Check Is There Any
	    // Matching In The Left Side By
	    // Upside Down
	    if (left[0] == left[1]) {
		lb = 470;
		setfillstyle(SOLID_FILL, BLACK);
		floodfill(a-115,lb-5,15);
		floodfill(a-115,lb-73,15);
		score = score + 10;
		i = 0;
		left[1] = 0;
	    }
	    else if (left[1] == left[2]) {
		lb = 402;
		setfillstyle(SOLID_FILL, BLACK);
		floodfill(a - 115, lb - 5, 15);
		floodfill(a - 115, lb - 73, 15);
		score = score + 10;
		i = 1;
		left[2] = 0;
	    }
	    else if (left[2] == left[3]) {
		lb = 334;
		setfillstyle(SOLID_FILL, BLACK);
		floodfill(a - 115, lb - 5, 15);
		floodfill(a - 115, lb - 73, 15);
		score = score + 10;
		i = 2;
		left[3] = 0;
	    }
	    else if (left[3] == left[4]) {
		lb =266;
		setfillstyle(SOLID_FILL, BLACK);
		floodfill(a - 115, lb - 5, 15);
		floodfill(a - 115, lb - 73, 15);
		score = score + 10;
		i = 3;
		left[4] = 0;
	    }
	    else if (left[4] == left[5]) {
		lb = 198;
		setfillstyle(SOLID_FILL, BLACK);
		floodfill(a-115,lb-5,15);
		floodfill(a-115,lb-73,15);
		score = score + 10;
		i = 4;
		left[5] = 0;
	    }
	    else
		p = 0;

	    // Loop Breaking Condition For
	    // Left Side
	    if (lb < 130)
		break;
	}

	// Operations For Place The Bricks
	// In Right Side
	else if (z == 'r') {
	    // Creating & Naming The Left
	    // Sub-Box
	    settextstyle(3,0,1);
	    outtextxy(510,10, "Right Sub-Box");

	    rectangle(a + 150, b, c + 150, d);
	    floodfill(a + 155, d-5, 15);
	    delay(200);
	    setfillstyle(SOLID_FILL, BLACK);
	    floodfill(a + 155, d - 5, 15);
	    rectangle(a+50,rb-68,c+100,rb);
	    setfillstyle(SOLID_FILL, x);
	    floodfill(a + 105, rb - 5, 15);
	    delay(100);

	    // Decreasing The Base Of
	    // Right Side
	    rb = rb - 68;

	    // Storing Corresponding Color
	    // In Right[] Array
	    right[j] = x;
	    j++;

	    // Process to Check Is There Any Matching
	    // In The Right Side By Upside Down
	    if (right[0] == right[1]) {
		rb = 470;
		setfillstyle(SOLID_FILL, BLACK);
		floodfill(a + 105, rb - 5, 15);
		floodfill(a + 105, rb - 105, 15);
		score = score + 10;
		j = 0;
		right[1] = 0;
	    }
	    else if (right[1] == right[2]) {
		rb = 402;
		setfillstyle(SOLID_FILL, BLACK);
		floodfill(a + 105, rb - 5, 15);
		floodfill(a + 105, rb - 105, 15);
		score = score + 10;
		j = 1;
		right[2] = 0;
	    }
	    else if (right[2] == right[3]) {
		rb = 334;
		setfillstyle(SOLID_FILL, BLACK);
		floodfill(a + 105, rb - 5, 15);
		floodfill(a + 105, rb - 105, 15);
		score = score + 10;
		j = 2;
		right[3] = 0;
	    }
	    else if (right[3] == right[4]) {
		rb = 266;
		setfillstyle(SOLID_FILL, BLACK);
		floodfill(a + 105, rb - 5, 15);
		floodfill(a + 105, rb - 105, 15);
		score = score + 10;
		j = 3;
		right[4] = 0;
	    }
	    else if (right[4] == right[5]) {
		rb = 198;
		setfillstyle(SOLID_FILL, BLACK);
		floodfill(a + 105, rb - 5, 15);
		floodfill(a + 105, rb - 105, 15);
		score = score + 10;
		j = 4;
		right[5] = 0;
	    }
	    else
		p = 0;

	    // Loop Breaking Condition For
	    // Right Side
	    if (rb-68< 130)
		break;
	}

	// Operations For Place The Bricks
	// In Middle Side
	else {
	    rectangle(a-35, mb-68,c+20, mb);
	    floodfill(a + 5, mb - 5, 15);
	    delay(100);

	    // Decreasing The Base Of
	    // Middle Side
	    mb = mb - 68;

	    // Storing Corresponding Color In
	    // Mid[] Array
	    mid[k] = x;
	    k++;

	    // Process To Check Is There Any
	    // Matching In The Middle Side
	    // By Upside Down
	    if (mid[0] == mid[1]) {
		mb = 470;
		setfillstyle(SOLID_FILL, BLACK);
		floodfill(a + 5, mb - 5, 15);
		floodfill(a + 5, mb - 105, 15);
		score = score + 10;
		k = 0;
		mid[1] = 0;
	    }
	    else if (mid[1] == mid[2]) {
		mb = 402;
		setfillstyle(SOLID_FILL, BLACK);
		floodfill(a + 5, mb - 5, 15);
		floodfill(a + 5, mb - 105, 15);
		score = score + 10;
		k = 1;
		mid[2] = 0;
	    }
	    else if (mid[2] == mid[3]) {
		mb = 334;
		setfillstyle(SOLID_FILL, BLACK);
		floodfill(a + 5, mb - 5, 15);
		floodfill(a + 5, mb - 105, 15);
		score = score + 10;
		k = 2;
		mid[3] = 0;
	    }
	    else if (mid[3] == mid[4]) {
		mb = 266;
		setfillstyle(SOLID_FILL, BLACK);
		floodfill(a + 5, mb - 5, 15);
		floodfill(a + 5, mb - 105, 15);
		score = score + 10;
		k = 3;
		mid[4] = 0;
	    }
	    else if (mid[4] == mid[5]) {
		mb = 198;
		setfillstyle(SOLID_FILL, BLACK);
		floodfill(a + 5, mb - 5, 15);
		floodfill(a + 5, mb - 105, 15);
		score = score + 10;
		k = 4;
		mid[5] = 0;
	    }
	    else
		p = 0;

	    // Loop Breaking Condition For
	    // Middle Side
	    if (mb-68 < 130)
		break;
	}
	delay(100);
	sprintf(str,"%d",score);
	outtextxy(50,300,"SCORE: ");
	outtextxy(50,350, str);
    }
    delay(300);
    cleardevice();
    getch();
    closegraph();
}