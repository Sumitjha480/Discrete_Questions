#include <iostream>
#include<cmath>
using namespace std;
int e;
operation(char o,float a,float b)
{
    if(o=='+')
        return (a+b);
    else if (o=='-')
        return (a-b);
        else if (o=='*')
        return (a*b);
    else if(o=='/')
        return (a/b);
    else if(o=='^')
        return pow(a,b);
    else
      cout<<"Incorrect Operator!!";

}
condition1(float Group[30],int len,char o)
{
    int cnt=1,i;
    for(i=0;i<len;i++)
    {
        if(cnt==1)
        {
            for (int j=i+1;j<len;j++)
            {
                float num=operation (o,Group[i],Group[j]);
                {
                    if(cnt==1)
                    {
                        for(int k=0;k<len;k++)
                        {
                            if(num==Group[k])
                            {
                                cnt=1;
                                break;
                            }
                            else
                                cnt=0;
                        }
                    }
                    else
                        break;
                }
            }
        }
        else
            break;
    }
    if (cnt==1)
        {
            cout<<"It is a closure\n";
            return true;
        }
    else
    {
        cout<<"It is not a closure\n";
        return false;
    }
}
condition2(float Group[30],int len ,char o)
{
    int cnt=1;
    for (int i=0;i<len;i++)
    {
        for (int j=i+1;j<len;j++)
        {
            for (int k=j+1;k<len;k++)
            {
                float num1=operation(o,Group[i],Group[j]),num2=operation(o,Group[j],Group[k]);
                if (operation(o,num1,Group[k])==operation(o,Group[i],num2))
                    continue;
                else
                    cnt=0;
            }
        }
    }
    if (cnt==1)
        {
            cout<<"It is associative\n";
            return true;
        }
    else
    {
        cout<<"It is not Associative\n";
        return false;
    }

}
condition3(float Group[30],int len ,char o)
{
    int cnt=0;
    for (int i=0;i<len;i++)
    {
        for(int j=0;j<len;j++)
        {
            if (operation(o,Group[i],Group[j])==Group[i])
            {
                e=Group[j];
                cnt=1;
                break;
            }
            else
                cnt=0;
        }
    }
    if(cnt==1)
        {
            cout<<"It is an identity\n";
            return true;
        }
    else
      {
          cout<<"It is not an identity\n";
          return false;
      }
}
condition4(float Group[30],int len ,char o)
{
    int cnt=1;
    for (int i=0;i<len;i++)
    {
        for(int j=0;j<len;j++)
        {
            if(operation(o,Group[i],Group[j])==operation(o,Group[j],Group[i]))
            {
                cnt=1;
                break;
            }
            else
                cnt=0;
        }
    }
    if(cnt==1)
    {
        cout<<"It is an inverse\n";
        return true;
    }
    else
       {
           cout<<"It is not an inverse\n";
           return false;
       }
}

condition5(float Group[30],int len,char o)
{
    int cnt=1;
    for(int i=0;i<len;i++)
    {
        if(cnt==1)
        {
            for(int j=i+1;j<len;j++)
            {
                if(operation(o,Group[i],Group[j])==operation(o,Group[j],Group[i]))
                {
                    cnt=1;
                    break;
                }
                else
                    cnt=0;
            }
        }
        else
            break;
    }
    if(cnt==1)
    {
        cout<<"It is commutative\n";
        return true;
    }
    else
    {
        cout<<"It is not Commutative\n";
        return false;
    }
}
int main()
{   cout<<"SUMIT KUMAR JHA\n2019UCO1735";
    float G[30];
    int len,ch=1;
    char oper;
    while(ch==1)
    {
    cout<<"\nEnter the number of elements in a group: ";
    cin>>len;
    cout<<"Enter the values :\n";
    for (int i=0;i<len;i++)
        {
            cin>>G[i];
        }
    cout<<"Enter the operator form +,-,*,/,^   \n";
    cin>>oper;
    bool prop1,prop2,prop3,prop4,prop5;
    prop1=condition1(G,len,oper);
    prop2=condition2(G,len,oper);
    prop3=condition3(G,len,oper);
    prop4=condition4(G,len,oper);
    prop5=condition5(G,len,oper);
    if(prop1&& prop2&&prop3&& prop4&&prop5)
        cout<<"Hence,It is a group";
    else
        cout<<"Hence,It is not a group";
    cout<<"\nDo you want to try again?(1/0):";
    cin>>ch;
    }

}
