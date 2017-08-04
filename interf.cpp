#include<iostream>
using namespace std;
#include<graphics.h>
#include<stdlib.h>
#include<ctype.h>
char y[50]={""};
int check=0;
char* interf()
{
    
    int a,b,c;
    char str[4];
    char op[4][2]={"+","-","*","/"};
    initwindow(800,800,"sample");
    outtextxy(397,400,"WELCOME!" );
    outtextxy(360,420,"This is a C++ program that emulates the working of a graphing calculator");
    outtextxy(360,440,"It plots basic and complex polynomial functions, trigonometric functions and exponential functions");
    outtextxy(375,500,"Press any key to continue...");
    if(kbhit)
    {
             system("CLS");
             }
    

    outtextxy(100,125,"y= ");
    bar(100,150,300,400);
    int p=50;
    setcolor(BLACK);
    for(int i=0;i<5;i++)//creates outline of interface
    {
        line(50+p,150,50+p,350);
        line(100,100+p,300,100+p);
        //itoa(i+1,str,10);
        p=p+50;
    }
    line(200,350,200,400);
    int q=0;
    setcolor(YELLOW);
    outtextxy(150,375,"x");
    outtextxy(250,375,";");
    for(int i=1;i<4;i++)//gives each tile a value
    {
        p=0;
        for(int j=i;j<10;j=j+3)
        {
            c=j%10;
            //cout<<c<<endl;
            itoa(c,str,10);
            //cout<<str<<endl;
            outtextxy(120+q,170+p,str);
            p=p+50;
        }
        q=q+50;
    }
    q=0;
    for(int i=0;i<4;i++)//gives each tile a value
    {
        outtextxy(270,170+q,op[i]);
        q+=50;
    }
    int temp=5,pos=0;
    outtextxy(170,320,"0");
    outtextxy(120,320,"^");
    outtextxy(220,320,"clr");
    for(int i=0;i<16;i++)
    {
        delay(1500);// if the user hovers over a tile for 1.5 seconds, it is considered as an input
        if((mousex()>=100)&&(mousex()<=300)&&(mousey()>=150)&&(mousey()<=450))
        {
            a=mousex();
            b=mousey();
            if(a<=150)
            {
                if(b<=200)
                {
                    outtextxy(110+temp,125,"1");
                    temp=temp+10;   
                    strcat(y,"1");
                    pos++;
                }
                if((b>200)&&(b<=250))
                {
                    outtextxy(110+temp,125,"4");
                    temp=temp+10;   
                    strcat(y,"4");
                    pos++;
                }
                if((b>250)&&(b<=300))
                {
                    outtextxy(110+temp,125,"7");
                    temp=temp+10;   
                    strcat(y,"7");
                    pos++;
                }
                if((b>300)&&(b<=350))
                {
                    outtextxy(110+temp,125,"^");
                    temp=temp+10;
                    strcat(y,"^");
                    pos++;
                }
            }
            if((a>150)&&(a<=200))
            {
                if(b<=200)
                {
                    outtextxy(110+temp,125,"2");
                    temp=temp+10;   
                    strcat(y,"2");
                    pos++;
                }
                if((b>200)&&(b<=250))
                {
                    outtextxy(110+temp,125,"5");
                    temp=temp+10;   
                    strcat(y,"5");
                    pos++;
                }
                if((b>250)&&(b<=300))
                {
                    outtextxy(110+temp,125,"8");
                    temp=temp+10;   
                    strcat(y,"8");
                    pos++;
                }
                if((b>300)&&(b<=350))
                {
                    outtextxy(110+temp,125,"0");
                    temp=temp+10;
                    strcat(y,"0");
                    pos++;
                }
            }
            if((a>200)&&(a<=250))
            {
                if(b<=200)
                {
                    outtextxy(110+temp,125,"3");
                    temp=temp+10;   
                    strcat(y,"3");
                    pos++;
                }
                if((b>200)&&(b<=250))
                {
                    outtextxy(110+temp,125,"6");
                    temp=temp+10;   
                    strcat(y,"6");
                    pos++;
                }
                if((b>250)&&(b<=300))
                {
                    outtextxy(110+temp,125,"9");
                    temp=temp+10;   
                    strcat(y,"9");
                    pos++;
                }
                if((b>300)&&(b<=350))
                {
                     i=0;
                     y[0]='\0';
                     cleardevice();//easiest way to clear given input will be to clear the whole screen and redraw interface
                     setcolor(WHITE);
                     outtextxy(100,125,"y= ");
                     bar(100,150,300,400);
                     int p=50;
                     setcolor(BLACK);
                     for(int i=0;i<5;i++)
                     {
                             line(50+p,150,50+p,350);
                             line(100,100+p,300,100+p);
                             p=p+50;
                     }
                     line(200,350,200,400);
                     int q=0;
                     setcolor(YELLOW);
                     outtextxy(150,375,"x");
                     outtextxy(250,375,";");
                     for(int i=1;i<4;i++)
                     {
                             p=0;
                             for(int j=i;j<10;j=j+3)
                             {
                                     c=j%10;
                                     //cout<<c<<endl;
                                     itoa(c,str,10);
                                     //cout<<str<<endl;
                                     outtextxy(120+q,170+p,str);
                                     p=p+50;
                             }
                             q=q+50;
                     }
                     q=0;
    
                     for(int i=0;i<4;i++)
                     {
                             outtextxy(270,170+q,op[i]);
                             q+=50;
                     }
                     outtextxy(170,320,"0");
                     outtextxy(120,320,"^");
                     outtextxy(220,320,"clr");
                }   
                   
            }
            if(a>250)
            {
                if(b<=200)
                {
                    outtextxy(110+temp,125,"+");
                    temp=temp+10;   
                    strcat(y,"+");
                    pos++;
                }
                if((b>200)&&(b<=250))
                {
                    outtextxy(110+temp,125,"-");
                    temp=temp+10;   
                    strcat(y,"-");
                    pos++;
                }
                if((b>250)&&(b<=300))
                {
                    outtextxy(110+temp,125,"*");
                    temp=temp+10;   
                    strcat(y,"*");
                    pos++;
                }
                if((b>300)&&(b<=350))
                {
                    outtextxy(110+temp,125,"/");
                    temp=temp+10;
                    strcat(y,"/");
                    pos++;
                }
            }
            if((b<400)&&(b>350)&&(a<200))
            {
                outtextxy(110+temp,125,"x");
                temp=temp+10;
                strcat(y,"x");
                pos++;    
            }
            if((b<400)&&(b>350)&&(a>200))
            {
                strcat(y,";");//semicolon marks the end of the function.
                pos++;
                cleardevice();//screen is cleared
                break;
            }
            
        else
            i--;
        }
        }
        
        strcat(y,"\0");
        return y;
}
        
    
