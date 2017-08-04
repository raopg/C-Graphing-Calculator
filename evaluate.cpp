#include<iostream>
using namespace std;
#include<fstream>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
#include<float.h>
class restack
{
    int top;
    double stack[50];
    public:
        restack()// default constructor
        {
            top=-1;
        }
        void push2(double ele)
        {
             top++;
             stack[top]=ele;
        }
        double pop2()
        {
               double ret;
               ret=stack[top];
               top--;
               return ret;
        }
}s2;
int valid=0;
double tonum(char str[5])//function to convert given char input to its integral form
{
    int num;
    num=atoi(str);
    return (double)num;
}

double ChkOp(char ch[5], int pos)//function to check the given operator anf perform further actions based on it
{
    double op1,op2,result,n;
    switch(ch[0])
    {
        case'+':
                valid=1;
                op1=s2.pop2();
                op2=s2.pop2();
                result=op2+op1;
                s2.push2(result);
                break;
        case'-':
                if(isdigit(ch[1]))
                {
                    valid=0;
                    n=tonum(ch);
                    s2.push2(n);
                    break;
                }
                valid=1;
                op1=s2.pop2();
                op2=s2.pop2();
                result=op2-op1;
                s2.push2(result);
                break;
        case'*':
                valid=1;
                op1=s2.pop2();
                op2=s2.pop2();
                result=op1*op2;
                s2.push2(result);
                break;
        case'/':
                valid=1;
                op1=s2.pop2();
                op2=s2.pop2();
                if(op1)
                {
                    result=op2/op1;
                    s2.push2(result);
                }
                else
                {
                    if(pos)
                        result=400;
                    else
                        result=-400;
                    s2.push2(result);
                    
                }
                break;
        case'^':
                valid=1;
                op1=s2.pop2();
                op2=s2.pop2();
                result=pow(op2,op1);
                s2.push2(result);
                break;
        case';':
                valid = 1;
                result=s2.pop2();
                return result;
                break;
        default:
                valid=0;
                n=tonum(ch);
                s2.push2(n);
                break;
    }
    return DBL_MAX;
}
double evaluate(int n,int pos)//Evaluates the given postfix expression
{
    char str[10];
    double chk=DBL_MAX;
    int dbchk=0;
    char temp[2];
    
        
    //char temp2[5]={"0-"};
    ifstream ifile("graph_test.txt");
    itoa(n,temp,10);
    while(ifile)
    {
        ifile>>str;
        if(strcmp(str,"x")==0)
        {
            /*if(sign==0)
            {
                strcat(temp2,temp);
                strcpy(str,temp2);
            }
            else*/
            strcpy(str,temp);
            
        }    
           
        chk=ChkOp(str,pos);
        if(chk!=DBL_MAX)
        {
            if(valid==0)
            {
                dbchk=1;
                cout<<"Invalid input--does not end with operator "<<endl;
                break;
            }
            return chk;
            break;
        }
        /*if(valid==0)
            cout<<"Invalid input--not ending with operator"<<endl;*/
    }
}
                
