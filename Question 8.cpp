/* Program to Calculate Number of Integers Divisible by 2 Numbers Within A Given Range Of Numbers */
#include <iostream>
using namespace std;
int main()
{   cout<<"SUMIT KUMAR JHA\n2019UCO1735";
    int up_lim,low_lim,range,num1,num2,Dnum1,Dnum2,Dnum1_num2,ch;
    cout<<"\nEnter Upper Limit:";
    cin>>up_lim;
    cout<<"Enter Lower Limit:";
    cin>>low_lim;
    if(up_lim<low_lim)
    {
        cout<<"Error Upper limit is less than lower limit!!!!";
        return 0;
    }
    range = up_lim - low_lim +1;
    cout<<"Enter first number:";
    cin>>num1;
    cout<<"Enter second number:";
    cin>>num2;
    Dnum1 = range/num1;
    Dnum2  = range/num2;
    Dnum1_num2 = range/(num1*num2);
    cout<<"Numbers Divisible By "<<num1<<" or "<<num2<<" = "<<Dnum1 + Dnum2 -Dnum1_num2;
    cout<<"\nDo You Want to print These numbers?(1 or 0):";
    cin>>ch;
    if(ch==1)
    {
        for(int i = low_lim;i<=up_lim;i++)
        {
            if(i%num1==0||i%num2==0)
                cout<<i<<" ";
        }
    }
    return 0;
}
