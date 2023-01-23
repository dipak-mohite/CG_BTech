#include<iostream>
#include<graphics.h>
using namespace std;

class drop
{
    public:
    drop()
    {

    }
   

 
};

int main()
{
    initwindow(1560,750, "Rain Drop");
    drop drop1;
    int i=0;
    while(1)
    {
        if(i>=520)
            i=0;

        line(600, 100+i,585, 150+i);
        line(600, 100+i,615, 150+i);
        setcolor(15);
        arc(600, 150+i, 180, 360, 15);
        // floodfill(620,530+i, 1);
        i++;
        delay(3);
        cleardevice();
        if(i==520)
        {
            int j=0, k=15;
            // while(k<=200)
            // {
            while(j<=200)
            {
                circle(600,600,15+j);
                if(j>=50)
                {
                    circle(600,600,15+k);
                    k++;
                }
                j++;
                delay(20);
                cleardevice();
            }
            // }
            
            delay(200);
        }
    }
    getch();


}

