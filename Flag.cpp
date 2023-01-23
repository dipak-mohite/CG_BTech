#include<iostream>
#include<math.h>
#include<dos.h>
#include<conio.h>
#include<graphics.h>
#include<stdio.h>
class Flag
{
	int d,r,k,xo,yo,xc,yc;
	int x1,x2,y1,y2,i,j;
	float x,y,dx,dy,step,xinc,yinc;
	public:
		void draw_line(int x1, int y1, int x2, int y2);
		void drawCircle(int xc,int yc,int r,int k);
};
void Flag :: draw_line(int x1, int y1, int x2, int y2)
{
	dx=(x2-x1);
	dy=(y2-y1);
	if(abs(dx)>abs(dy))
			 step=abs(dx);
	else
		 step=abs(dy);
	xinc=dx/step;
	yinc=dy/step;
	x=x1;
	y=y1;
	putpixel(round(x),round(y),15);
	for (int i=0;i<step;i++)
	{
		putpixel(round(x),round(y), 15);
		x=x+xinc;
		y=y+yinc;
	}	
}

void Flag :: drawCircle(int xc,int yc,int r,int k)
{
	d=3-2*r;
	xo=0;
	yo=r;
	while(xo<=yo){
		putpixel(xc+xo,yc+yo,k);
		putpixel(xc-xo,yc-yo,k);
		putpixel(xc+xo,yc-yo,k);
		putpixel(xc-xo,yc+yo,k);
		putpixel(xc+yo,yc+xo,k);
		putpixel(xc-yo,yc-xo,k);
		putpixel(xc+yo,yc-xo,k);
		putpixel(xc-yo,yc+xo,k);
		if(d<=0){
			d=d+4*xo+6;
		}
		else{
			d=d+4*xo-4*yo+10;
			yo=yo-1;
		}
		xo=xo+1;
	}
}
int main()
{
Flag f;
 int gd=DETECT,gm;
// initgraph(&gd, &gm, "");
initwindow(800,800,"Flag");
 for(int i=310;i>0;i--){
 f.draw_line(100,50,100,450);
 f.draw_line(98,50,98,450);
 f.draw_line(98,50,100,50);
 f.drawCircle(99,45,5,15);
 setfillstyle(SOLID_FILL, WHITE);
 floodfill(99,45,15);
 f.draw_line(100,50+i,100,140+i);
 f.draw_line(100,50+i,250,50+i);
 f.draw_line(100,80+i,250,80+i);
 f.draw_line(100,110+i,250,110+i);
 f.draw_line(100,140+i,250,140+i);
 f.draw_line(250,50+i,250,140+i);
 f.draw_line(80,450,120,450);
 f.draw_line(80,460,120,460);
 f.draw_line(80,450,80,460);
 f.draw_line(120,450,120,460);
 f.draw_line(70,460,130,460);
 f.draw_line(70,470,130,470);
 f.draw_line(70,460,70,470);
 f.draw_line(130,460,130,470);
 
 setfillstyle(SOLID_FILL, 255);
 floodfill(105, 55+i, 15);
 
setfillstyle(SOLID_FILL, GREEN);
 floodfill(105, 115+i, 15);
 
 f.drawCircle(175,95+i,15,15);
 
 setfillstyle(SOLID_FILL, BLUE);
 floodfill(175, 85+i, 15);
 
 setfillstyle(SOLID_FILL, WHITE);
 floodfill(105, 85+i, 15);
 
 setfillstyle(SOLID_FILL, WHITE);
 floodfill(245, 85+i, 15);
 
 setfillstyle(SOLID_FILL, WHITE);
 floodfill(85, 455, 15);
 setfillstyle(SOLID_FILL, WHITE);
 floodfill(75, 465, 15);
 
 delay(30);
 cleardevice();
}
//To erase the flag
f.draw_line(100,50,100,450);
f.draw_line(98,50,98,450);
 f.draw_line(98,50,100,50);
 f.drawCircle(99,45,5,15);
 setfillstyle(SOLID_FILL, WHITE);
 floodfill(99,45,15);
 f.draw_line(100,50,100,140);
 f.draw_line(100,50,250,50);
 f.draw_line(100,80,250,80);
 f.draw_line(100,110,250,110);
 f.draw_line(100,140,250,140);
 f.draw_line(250,50,250,140);
 f.draw_line(80,450,120,450);
 f.draw_line(80,460,120,460);
 f.draw_line(80,450,80,460);
 f.draw_line(120,450,120,460);
 f.draw_line(70,460,130,460);
 f.draw_line(70,470,130,470);
 f.draw_line(70,460,70,470);
 f.draw_line(130,460,130,470);
 
 setfillstyle(SOLID_FILL, 255);
 floodfill(105, 55, 15);
 
setfillstyle(SOLID_FILL, GREEN);
 floodfill(105, 115, 15);
 
 f.drawCircle(175,95,15,15);
 
 setfillstyle(SOLID_FILL, BLUE);
 floodfill(175, 85, 15);
 
 setfillstyle(SOLID_FILL, WHITE);
 floodfill(105, 85, 15);
 
 setfillstyle(SOLID_FILL, WHITE);
 floodfill(245, 85, 15);
 
 setfillstyle(SOLID_FILL, DARKGRAY);
 floodfill(85, 455, 15);
 setfillstyle(SOLID_FILL, MAGENTA);
 floodfill(75, 465, 15);
 
 delay(10000);
 
 getch();
 closegraph();
}

