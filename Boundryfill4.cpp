#include<iostream>
using namespace std;
#include<graphics.h>

void boundryfill(int x,int y,int color,int b_color){
	if(getpixel(x,y)!=b_color && getpixel(x,y)!=color)
	{
		putpixel(x,y,color);
		boundryfill(x+1,y,color,b_color);
		boundryfill(x,y+1,color,b_color);
		boundryfill(x-1,y,color,b_color);
		boundryfill(x,y-1,color,b_color);
	}
}

int main(){
	int x,r,y;
	cout<<"Enter x : ";
	cin>>x;
	cout<<"Enter y : ";
	cin>>y;
	cout<<"radius : ";
	cin>>r;
	initwindow(500,500,"Aditya");
	circle(x,y,r);
	boundryfill(x,y,6,15);
	delay(10000);
}
