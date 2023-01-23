#include<iostream>
#include<math.h>
#include<graphics.h>
using namespace std;

class DDA{
	public:
		
		float dx,dy,xinc,yinc,steps,k=1,a,b;
		void line(int x1,int y1,int x2,int y2);
		void dotted(int x1,int y1,int x2,int y2);
		void dash(int x1,int y1,int x2,int y2);
};

void DDA::line(int x1,int y1,int x2,int y2)
{
	
	dx= x2-x1;
	dy=y2-y1;
	if(abs(dx)>abs(dy))
	{
		steps = dx;
	}
	else
	{
		steps = dy;
	}
	
	a = x1;
	b = y1;
	putpixel(a,b,GREEN);
	
	xinc = (dx/steps);
	yinc = (dy/steps);
	
	for(int i=0;i<=steps;i++)
	{
		a = a + xinc;
		b = b + yinc;
		putpixel(a,b,YELLOW);
	}
	
}


void DDA::dotted(int x1,int y1,int x2,int y2)
{
	dx = x2-x1;
	dy = y2-y1;
	if(abs(dx)>abs(dy))
	{
		steps = abs(dx);
	}
	else{
		steps = abs(dy);
	}
	
	a=x1;
	b=y1;
	putpixel(a,b,YELLOW);
	
	xinc = (dx/steps);
	yinc = (dy/steps);
	
//	while(a<x2)
//	{
//		a = a + (3*xinc);
//		b = b + (3*yinc);
//		putpixel(round(a),round(b),15);	
//	}

	for(int i=0;i<=steps;i++)
	{
		a = a + (3*xinc);
		b = b + (3*yinc);
		putpixel(a,b,YELLOW);
	}
	
}


void DDA::dash(int x1,int y1,int x2,int y2)
{
	dx = x2-x1;
	dy = y2-y1;
	
	a = x1;
	b = y2;
	putpixel(round(a),round(b),15);
	
	if(abs(dx)>abs(dy))
	{
		steps = abs(dx);
	}
	else
	{
		steps = abs(dy);
	}
	
	xinc = dx/steps;
	yinc = dy/steps;
	while(a<x2)
	{
		if(int(a)%3==0)
		{
			a+=xinc;
			b+=yinc;
			continue;
		}
		else
		{
			a+=xinc;
			b+=yinc;
			putpixel(round(a),round(b),15);
		}
	}
	
}



int main(){
	int x1,x2,y1,y2;
	int ch;
	 
	DDA d;
	
	cout<<"TYPES:"<<endl;
	
	do{
		cout<<"1. THIN LINE."<<endl;
		cout<<"2. DOTTED LINE."<<endl;
		cout<<"3. DASH LINE."<<endl;
		
		cout<<"ENTER YOUR CHOICE : ";
		cin>>ch;
		
		cout<<"\nEnter the co-ordinates "<<endl;
		cout<<"Enter x1 : ";
		cin>>x1;
		cout<<"Enter y1 : ";
		cin>>y1;
		cout<<"Enter y1 : ";
		cin>>x2;
		cout<<"Enter y1 : ";
		cin>>y2;
		initwindow(500,500);
		switch(ch)
		{
			case 1:{
				d.line(x1,y1,x2,y2);
				break;
			}
			case 2:{
				d.dotted(x1,y1,x2,y2);
				break;
			}
			case 3:{
				d.dash(x1,y1,x2,y2);
				break;
			}
		}
	}while(ch!=4);
	delay(10000);
}
