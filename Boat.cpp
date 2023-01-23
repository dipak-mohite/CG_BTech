#include<conio.h>
#include<graphics.h>
#include<stdio.h>
#include<dos.h>
using namespace std;
class Boat
{
private:
int x,y,xc,yc,r,p;
public:
//member function
void drawCircle(int xc,int yc,int r,int colour)
{
putpixel(xc+x,yc+y,colour);
putpixel(xc-x,yc+y,colour);
putpixel(xc+x,yc-y,colour);
putpixel(xc-x,yc-y,colour);
putpixel(xc+y,yc+x,colour);
putpixel(xc-y,yc+x,colour);
putpixel(xc+y,yc-x,colour);
putpixel(xc-y,yc-x,colour);
}
void plot(int xc,int yc,int r,int colour)
{
x = 0;
y = r;
p = 1-r;
if(p>=0)
{
y = y-1;
}
x = x+1;
do
{
drawCircle(xc,yc,r,colour);
if(p<0)
{
p = p+(2*x)+1;
}
else
{
p = p+(2*x)+1-(2*y);
y = y-1;
}
x = x+1;
}while(x<=y);
}
};
int main()
{
Boat b;
initwindow(1500,750,"Boat Locomotion");
 for (int i = 0; i <= 420; i = i + 10) {
 line(500+i,300,800+i,300);
 line(555+i,390,745+i,390);
 line(500+i,300,555+i,390);
 line(745+i,390,800+i,300);
 line(720+i,300,720+i,200);
 line(720+i,200,800+i,300);
 for(int j=0;j<10;j++)
 {
 b.plot(760+i,275,j,YELLOW);
}
cleardevice();
delay(100);
line(500+i,300,800+i,300);
 line(555+i,390,745+i,390);
 line(500+i,300,555+i,390);
 line(745+i,390,800+i,300);
 line(720+i,300,720+i,200);
 line(720+i,200,800+i,300);
 for(int j=0;j<10;j++)
 {
 b.plot(760+i,275,j,YELLOW);
}
delay(50);
 }
 getch();
return 0;
}
