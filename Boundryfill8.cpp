#include<iostream>
#include<graphics.h>
using namespace std;

void boundryfill8(int x,int y,int b,int color,int b_color)
{
	if(getpixel(x,y)!=b_color & getpixel(x,y)!=color)
	{
		putpixel(x,y,color);
		boundryfill8(x+1,y,color,b_color);
		boundryfill8(x,y+1,color,b_color);
		boundryfill8(x-1,y,color,b_color);
		boundryfill8(x,y+1,color,b_color);
		boundryfill8(x-1,y-1,color,b_color);
		boundryfill8(x-1,y+1,color,b_color);
		boundryfill8(x+1,y-1,color,b_color);
		boundryfill8(x+1,y+1,color,b_color);
	}
}
int main(){
	cout<<"Enter x : ";
	int x,y,r;
	cin>>x;
	cout<<"Enter y : ";
	cin>>y;
	cout<<"Enter r : ";
	cin>>r;
	
	cout<<"\n\nEnter the center the points x,y : ";
	int x1,y1;
	cin>>x1>>y1;
	circle(x,y,r);
	
	rectangle(x,y,x1,y1);
	initwindow(500,500);
	
		boundryfill8(x+10,y+10,6,15);
	
	cirle(x,y,radius);
	
	boundryfill8(x,y,)
}
