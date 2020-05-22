#include <iostream>
using namespace std;
void set_union(char set_1[],char set_2[],int l1,int l2)
{
    char set[l1+l2];
    int l=0;
    for(int i=0;i<l1;i++)
    {
        int c1=0,c2=0,k=0;
        for(k=0;k<i;k++)
        {
            if(set_1[i]==set_1[k])
                break;
        }
        if(k!=i)
            continue;
        for(int j=0;j<l1;j++)
        {
            if(set_1[i]==set_1[j])
                c1++;
        }
        for(int j=0;j<l2;j++)
        {
            if(set_1[i]==set_2[j])
                c2++;
        }
        if(c1>c2)
        {
            for(int j=0;j<c1;j++)
            {
                set[l]=set_1[i];
                l++;
            }
        }
        else
        {
            for(int j=0;j<c2;j++)
            {
                set[l]=set_1[i];
                l++;
            }
        }
    }
    for(int i=0;i<l2;i++)
    {
        int k=0;
        for(k=0;k<l;k++)
        {
            if(set_2[i]==set[k])
                break;
        }
        if(k!=l)
            continue;
        int c=0;
        for(int j=0;j<l2;j++)
        {
            if(set_2[i]==set_2[j])
                c++;
        }
        for(int j=0;j<c;j++)
        {
            set[l]=set_2[i];
            l++;
        }
    }
    for(int i=0;i<l;i++)
    {
        cout<<set[i]<<",";
    }
}
void set_intersection(char set_1[],char set_2[],int l1,int l2)
{
   int i = 0, j = 0;

    while (i < l1 && j < l2)
    {

        if (set_1[i] > set_2[j])
        {
            j++;
        }

        else
        if (set_2[j] > set_1[i])
        {
            i++;
        }
        else
        {
            cout<<set_1[i]<<",";
            i++;
            j++;
        }
    }
}
void set_sum(char set_1[],char set_2[],int l1,int l2)
{
    for(int i=0;i<l1;i++)
    {
        cout<<set_1[i]<<",";
    }
    for(int i=0;i<l2;i++)
    {
        cout<<set_2[i]<<",";
    }
}
void set_difference(char set_1[],char set_2[],int l1, int l2)
{
    for(int i=0;i<l1;i++)
    {
        for(int j=0;j<l2;j++)
        {
            if(set_1[i]==set_2[j])
                break;
            cout<<set_1[i]<<",";
            break;
        }
    }
}
int cardinality(char set[],int l)
{
    int c=0;
    for(int i=0;i<l;i++)
    {
        int k=0;
        for(k=0;k<i;k++)
        {
            if(set[i]==set[k])
                break;
        }
        if(k!=i)
            continue;
        else
            c++;
    }
    return c;
}
void enter_values(char set[],int l)
{
    for(int i=0;i<l;i++)
    {
        cin>>set[i];
    }
}
int main()
{
    cout<<"SUMIT KUMAR JHA\n2019UCO1735";
    int l1,l2;
    cout<<"\nNumber of elements in 1st multiset:";
    cin>>l1;
    char set_1[l1];
    cout<<"\nEnter the values:";
    enter_values(set_1,l1);
    cout<<"\nNumber of elements in 2nd mutliset:";
    cin>>l2;
    char set_2[l2];
    cout<<"\nEnter the values:";
    enter_values(set_2,l2);
    cout<<"\nUnion:\t";
    set_union(set_1,set_2,l1,l2);
    cout<<"\n\nset_intersection:\t";
    set_intersection(set_1,set_2,l1,l2);
    cout<<"\n\nAddtion:\t";
    set_sum(set_1,set_2,l1,l2);
    cout<<"\n\nset_difference:\t";
    set_difference(set_1,set_2,l1,l2);
    cout<<"\nCardinality of 1st multiset: "<<cardinality(set_1,l1);
    cout<<"\nCardinality of 2nd multiset: "<<cardinality(set_2,l2);
    return 0;
}
