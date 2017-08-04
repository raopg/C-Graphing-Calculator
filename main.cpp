#include<iostream>
#include<graphics.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
extern void in_post(char []);//postfix converter
extern double evaluate(int ,int );//postfix evaluator
extern char* interf();//interface
extern void intro();
extern int check;
using namespace std;
 int main()
 {
     intro();
     int k;
     char *str;
     do
     {
     str=NULL;
     str=interf();
     in_post(str);//calls postfix converter
     double y[400];
     double y2[400];
     int a=0;
     for(int i=0;i<=400;i++)
     {
             y[i]=(evaluate(i,1));
     }
     for(int i=0;i>=-400;i--)
     {
         y2[a]=evaluate(i,0);
         //cout<<"X= "<<i<<" Y= "<<y2[a];
         a++;
     }
    initwindow(800,800,"sample");
    moveto(0,400);
    setcolor(YELLOW);//The next 3 lines create the co-ordinate axes
    lineto(getmaxx(),400);
    moveto(400,0);
    lineto(400,getmaxy());
    
    int p=0;
    char abc[3];
    for(int i=400;i<=800;i=i+30)//Loop to caliberate X-axis 
    {
        moveto(i,398);
        lineto(i,402);
        if(i==400)
            continue;
        if(i>400)
        {
                 p++;
                 itoa(p,abc,10);
                 outtextxy(i,420,abc);
        }
    }
    p=0;
    for(int i=400;i>=0;i=i-30)
    {
        line(i,398,i,402);
        if(i==400)
            continue;
        if(i<400)
        {
            p--;
            itoa(p,abc,10);
            outtextxy(i,420,abc);
        }
    }
    p=0;
   for(int i=400;i>0;i=i-10)//Loop to caliberate +Y-axis
    {
        moveto(398,i);
        lineto(402,i);
        if((i<=350)&&(((350-i)%50)==0))
        {
            p=p+10;
            itoa(p,abc,10);
            outtextxy(380,i-10,abc);
            
        }
    }
    outtextxy(100,500,"SCALE: ");
    outtextxy(100,600,"X axis: 30 pixels=1 unit");
    outtextxy(100,700,"Y axis: 50 pixels=10 units");
    char question[150]={"y= "};
    strcat(question,str);
    outtextxy(600,600,question);
    p=0;
    for(int i=400;i<=800;i=i+10)//Loop to caliberate -Y-axis
    {
        moveto(398,i);
        lineto(402,i);
        if((i>=450)&&(((450-i)%50)==0))
        {
            p=p+10;
            itoa(p,abc,10);
            outtextxy(380,i-10,abc);
        }
        
    }
    line(400,400-y2[0]*5,370,400-y2[1]*5);
    moveto(400,400);
    
    y[0]=evaluate(0,1);
     for(int i=0;i<=400;i++)
     {
             line(400+i*30,400-y[i]*5,400+((i+1))*30,400-y[i+1]*5);
   
     }
     moveto(400,400);
     for(int i=1;i<=400;i++)
     {
         
         line(400-i*30,400-y2[i]*5,400-(i+1)*30,400-y2[i+1]*5);
     }
     cout<<"Enter: \n1 to continue \n0 to exit ";
     cin>>k;
     }while(k!=0);
     return(0);
     
     
     }
