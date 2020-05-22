#include <iostream>
using namespace std;
void set_intersection(int set_1[],int set_2[],int l1,int l2)
{
    for(int i=0;i<l1;i++)
    {
        for(int j=0;j<l2;j++)
        {
            if(set_1[i]==set_2[j])
            {
                cout<<set_1[i]<<",";
                break;
            }
        }
    }
}
void set_union(int set_1[],int set_2[],int l1,int l2)
{
    int set[l1+l2];
    int l=0;
    for(int i=0;i<l1;i++)
    {
        set[l]=set_1[i];
        l++;
    }
    for(int i=0;i<l2;i++)
    {
        for(int j=0;j<l1;j++)
        {
            if(set_2[i]==set[j])
                break;
            else if(j==(l1-1))
            {
                set[l]=set_2[i];
                l++;
            }
        }
    }
    for(int i=0;i<l;i++)
    {
        cout<<set[i]<<",";
    }

}
void set_difference(int set_1[],int set_2[],int l1,int l2)
{
    int set[l1];
    int l=0;
    for(int i=0;i<l1;i++)
    {
        for(int j=0;j<l2;j++)
        {
            if(set_1[i]==set_2[j])
            {
                break;
            }
            else if(l==0 && j==(l2-1))
            {
                set[l]=set_1[i];
                l++;
            }
            else if(set[l-1]!=set_1[i] && j==(l2-1))
            {
                set[l]=set_1[i];
                l++;
            }
        }
    }
    for(int i=0;i<l;i++)
    {
        cout<<set[i]<<",";
    }
}
void sym_diff(int set_1[],int set_2[],int l1,int l2)
{
    int set[l1+l2];
    int l=0;
    for(int i=0;i<l1;i++)
    {
        set[l]=set_1[i];
        l++;
    }
    for(int i=0;i<l2;i++)
    {
        for(int j=0;j<l;j++)
        {
            if(set_2[i]==set[j])
            {
                for(int k=j;k<l-1;k++)
                {
                    set[k]=set[k+1];
                }
                l--;
                break;
            }
            else if(j==(l-1))
            {
                set[l]=set_2[i];
                l++;
                break;
            }
        }
    }
    for(int i=0;i<l;i++)
    {
        cout<<set[i]<<",";
    }
}

void enter_values(int set[],int l)
{
    for(int i=0;i<l;i++)
    {
        cin>>set[i];
    }
}
void set_addition(int set_1[],int set_2[],int l1,int l2)
{
    for(int i=0;i<l1;i++)
    {
        for(int j=0;j<l2;j++)
        {
            cout<<set_1[i]+set_2[j]<<",";
        }
    }
}
void set_subtraction(int set_1[],int set_2[],int l1,int l2)
{
    for(int i=0;i<l1;i++)
    {
        for(int j=0;j<l2;j++)
        {
            cout<<set_1[i]-set_2[j]<<",";
        }
    }
}
int main()
{
    cout<<"SUMIT KUMAR JHA\n2019UCO1735\n";
    int l1,l2;
    cout<<"Length of 1st set: ";
    cin>>l1;
    int set_1[l1];
    cout<<"Enter the values for 1st set: ";
    enter_values(set_1,l1);
    cout<<"Length of 2nd set:";
    cin>>l2;
    int set_2[l2];
    cout<<"Enter the values for 2nd set:";
    enter_values(set_2,l2);
    cout<<"\nset_intersection:     ";
    set_intersection(set_1,set_2,l1,l2);
    cout<<"\nunion:    ";
    set_union(set_1,set_2,l1,l2);
    cout<<"\nDifference:      ";
    set_difference(set_1,set_2,l1,l2);
    cout<<"\nSymmetric Difference:     ";
    sym_diff(set_1,set_2,l1,l2);
    cout<<"\nAddtion:    ";
    set_addition(set_1,set_2,l1,l2);
    cout<<"\nSubtraction:     ";
    set_subtraction(set_1,set_2,l1,l2);
    return 0;
}
