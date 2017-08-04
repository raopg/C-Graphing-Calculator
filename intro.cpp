#include<iostream>
using namespace std;
#include<graphics.h>

void intro()
{
    initwindow(800,800,"sample");
    setcolor(YELLOW);
    settextstyle(10,HORIZ_DIR,5);
    outtextxy(100,300,"C++ GRAPHING CALCULATOR");
    settextstyle(3,HORIZ_DIR,2);
    outtextxy(250,400,"Loading ");
    int space;
    for(int i =0;i<3;i++)
    {
        space=0;
        for(int j=0;j<6;j++)
        {
            settextstyle(10,HORIZ_DIR,5);
            delay(200);
            outtextxy(320+space,385,".");
            space=space+20;
        }
        outtextxy(320,385,"        ");
    }
    int x,y;
    outtextxy(200,400,"             ");
    //outtextxy(200,650,"Click to continue ");
    delay(2500);
    cleardevice();
    settextstyle(10,HORIZ_DIR,5);
    outtextxy(100,100,"INSTRUCTIONS");
    settextstyle(3,HORIZ_DIR,2);
    outtextxy(150,200,"1. Use calculator interface to enter input");
    outtextxy(150,250,"2. All inputs in \'y=f(x) \' form ");
    outtextxy(150,300,"3. This version does not support mathematical functions ");
    outtextxy(150,350,"4. User can plot as many graphs as he wishes ");
    delay(6000);
    closegraph();
}
