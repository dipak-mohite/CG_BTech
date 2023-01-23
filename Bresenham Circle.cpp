#include<iostream>
using namespace std;
#include<graphics.h>

class bc{
	public:
	int x,y,r,d;
	void draw(int xc,int yc,int r);
	void display(int xc,int yc,int a,int b);
};

void bc::draw(int xc,int yc,int r){
	x=0;
	y=r;
	d=3-2*r;
	
	while(x<=y)
	{
		x++;
		if(d>0)
		{
			y--;
			d+=4*(x-y)+10;
		}
		else
		{
			d+=4*x+6;
		}
		display(xc,yc,x,y);
	}
}

void bc::display(int xc,int yc,int a,int b){
	putpixel(xc+a,yc+b,YELLOW);
	putpixel(xc-a,yc+b,YELLOW);
	putpixel(xc+a,yc-b,YELLOW);
	putpixel(xc-a,yc-b,YELLOW);
	putpixel(xc+b,yc+a,YELLOW);
	putpixel(xc-b,yc+a,YELLOW);
	putpixel(xc+b,yc-a,YELLOW);
	putpixel(xc-b,yc-a,YELLOW);
}

int main(){
	initwindow(500,500,"aditya");
	bc b;
	b.draw(50,50,10);
	delay(10000);
}
