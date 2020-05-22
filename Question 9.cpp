#include <iostream>
#include<cmath>
using namespace std;
int A,B,a,b,maxc;
int *val;
int const_eval,c,x;
int eval_Lexp(int n)
{
    if(n<maxc)
        return val[n];
    return A*eval_Lexp(n-a) + B*eval_Lexp(n-b);
}

int eval_nonExp(int n)
{
    if(n<maxc)
        return val[n];
    const_eval = c*pow(x,n)+1;
    return const_eval + A*eval_nonExp(n-a) + B*eval_nonExp(n-b);
}
void Linear_relation()
{  int n;
    cout<<"Relation of type F(n) = AF(n-a) + BF(n-b) {A and B Must be positive}";
    cout<<"\nEnter A: ";
    cin>>A;
    cout<<"Enter B: ";
    cin>>B;
    cout<<"Enter a: ";
    cin>>a;
    cout<<"Enter b: ";
    cin>>b;
    cout<<"Enter n: ";
    cin>>n;
    maxc = a>b?a:b;
    val = new int[maxc];
    for(int i=0;i<maxc;i++)
    {
        cout<<"Enter F("<<i<<"): ";
        cin>>val[i];
    }
    cout<<"Final Result after evaluation : "<<eval_Lexp(n);
}
void Non_Homogeneous_relation()
{  int n;
   cout<<"Relation of type F(n) = AF(n-a) + BF(n-b) +c.x^n{A and B must be positive}";
    cout<<"\nEnter A: ";
    cin>>A;
    cout<<"Enter B: ";
    cin>>B;
    cout<<"Enter a: ";
    cin>>a;
    cout<<"Enter b: ";
    cin>>b;
    cout<<"Enter c: ";
    cin>>c;
    cout<<"Enter x: ";
    cin>>x;
    cout<<"Enter n: ";
    cin>>n;
    maxc = a>b?a:b;
    val = new int[maxc];
    for(int i=0;i<maxc;i++)
    {
        cout<<"Enter F("<<i<<"): ";
        cin>>val[i];
    }
    cout<<"Final Result After evaluation: "<<eval_nonExp(n);
}
int main()
{ cout<<"SUMIT KUMAR JHA\n2019UCO1735";
    int ch,opt;
  do
  {
    cout<<"\nWhat kind of relation do you want to solve: ";
    cout<<"\n1.Linear Recurrence Relation";
    cout<<"\n2.Non Homogeneous Relation";
    cout<<"\n3.Exit";
    cout<<"\nEnter Your Choice(1-3):";
    cin>>ch;
    switch(ch)
    {
        case 1:Linear_relation();
        break;
        case 2:Non_Homogeneous_relation();
        break;
        case 3:return 0;
        break;
        default:cout<<"Wrong choice";
        break;
    }
    cout<<"\nDo you want to try again?(1/0):";
    cin>>opt;
  }while(opt==1);
  return 0;
}

