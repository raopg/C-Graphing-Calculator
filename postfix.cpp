#include<iostream>
using namespace std;
#include<fstream>
#include<ctype.h>
class statstack 
{
    int top;
    char stack[150];
    public:
    statstack()//default constructor
    {
        top=-1;
    }
    char pop()
    {
        char ret;
        if(top!=-1)
        {
              ret=stack[top];
              top--;
              return ret;
        }
        else
              return '#';
    }
    char topelement() //function to return the top most element of the stack.
    {
        char ch;
        if(top!=-1)
            ch=stack[top];
        else
            ch='#';
        return ch;
    }
    void push(char ch) //function to push elements into stack
    {
        if(top!=149)
        {
              top++;
              stack[top]=ch;
        }
    }
}s1;      
char postfix[150];
int precedence(char ch) //Function to assign the precedence of given operator
{
    switch(ch)
    {
        case'(':
                return 2;
        case'^':
                return 5;
        case'/':
                return 4;
        case'*':
                return 4;
        case'+':
                return 3;
        case'-':
                return 3;
        default:
                return 1;
    }
}
/*
int braces(char*s) //function to check for brace imbalance  NOTE:Does not work right. Must check.
{
      int leftbr,rightbr;
      leftbr=rightbr=0;
      for(int i=0;s[i]!='\0';i++)
      {
              if(s[i]=='(')
                  leftbr++;
              else if(s[i]==')')
                  rightbr++;
      }
      if(leftbr==rightbr)
          return 0;
      if(leftbr<rightbr)
          return 1;
      else
          return -1;
}                    
   */                  

void in_post(char infix[150])// function which does the conversion
{
 
     char ele,elem;
     int prep,pre,j=0,chk=0,popped;
     strcpy(postfix," ");
     //chk=braces(infix);
     if(chk)
     {
         cout<<"Unbalanced number of braces"<<endl<<"Extra";
         cout<<(chk==1?"Right brace ":"Left brace ")<<endl;
         
         exit(0);
     }
     int p=0,q=0;
     p=0;
     q=0;
     for(int i=0;infix[i]!='\0';i++)// the loop to read each character of the infix expression
     {
         if(isalpha(infix[i])||(isdigit(infix[i])))
         {
             postfix[j++]=infix[i];
         }
         else if(infix[i]=='(')
         {
             elem=infix[i];
             s1.push(elem);
         }
         else if(infix[i]==')')
         {
             while((popped=s1.pop())!='(')
             {
                 postfix[j++]=popped;
             }
             //popped=s1.pop();
         }
         /*else if(infix[i]==';')
         {
             postfix[j++]=';';
             break;
         }*/
         else
         {
             elem=infix[i];
             pre=precedence(elem);
             ele=s1.topelement();
             prep=precedence(ele);
             if(pre>prep)
                 s1.push(elem);
             else
             {
                 while(prep>=pre)
                 {
                     if(ele=='#')
                         break;
                     popped=s1.pop();
                     ele=s1.topelement();
                     postfix[j++]=popped;
                     prep=precedence(ele);
                 }
                 s1.push(elem);
             }
         }
     }
     while((popped=s1.pop())!='#')
         postfix[j++]=popped;
     postfix[j]='\0';
     ofstream ofile("graph_test.txt");//the postfix evaluator will read this file
     for(int i=0;postfix[i]!='\0';i++)
     {
         if(isdigit(postfix[i]))
         {
             while(isdigit(postfix[i]))
             {
                 ofile<<postfix[i];
                 i++;
             }
             ofile<<"\n";

         }
         ofile<<postfix[i]<<"\n";
     }
     //ofile<<";";
     strcat(postfix,"\0");
     cout<<postfix;
}
