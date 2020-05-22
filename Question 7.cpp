#include<iostream>
using namespace std;
void create_rel(int arr[],int rel[][20],int size)
{
    for(int i=0;i<size;i++)
    {
        int k=1;
        rel[i][0]=arr[i];
        for(int j=i+1;j<size;j++)
        {
            if(arr[i]%arr[j]==0)
            {
                rel[i][k]=arr[j];
                k++;
            }
        }
    }
    cout<<"Poset Created Successfully\n";

}
bool Check_Lattice(int rel[][20],int size)
{
    for(int i=0;i<size;i++)
    {
        if(rel[0][i]!=rel[i][0])
            return false;
        for(int j=0;rel[i][j]!=-1;j++)
        {
            if(rel[i][j+1]==-1 && rel[i][j]!=rel[size-1][0])
            {
                return false;
            }
        }
    }
    return true;
}
void sort_(int arr[],int size)
{
   for (int i=0;i<size-1;i++)
   {
     bool swapped = false;
     for (int j=0;j<size-i-1;j++)
     {
        if (arr[j]<arr[j+1])
        {
           int temp=arr[j];
           arr[j]=arr[j+1];
           arr[j+1]=temp;
           swapped = true;
        }
     }
     if (swapped==false)
        break;
   }
}
int main()
{
    cout<<"SUMIT KUMAR JHA\n2019UCO1735";
    int poset_size,ch=1;
    while(ch==1)
    {
    cout<<"\nEnter number of Elements in Poset:";
    cin>>poset_size;
    int poset[poset_size];
    cout<<"Enter the values:\n";
    for(int i=0;i<poset_size;i++)
        cin>>poset[i];
    int rel[poset_size][20];
    for(int i=0;i<poset_size;i++)
    {
        for(int j=0;j<20;j++)
            rel[i][j]=-1;
    }
    sort_(poset,poset_size);
    create_rel(poset,rel,poset_size);
    if(Check_Lattice(rel,poset_size))
        cout<<"Given Poset is a lattice\n";
    else
        cout<<"Given Poset is not a lattice\n";

    cout<<"Do You Want to try again?(1/0):";
    cin>>ch;
    }
    return 0;
}
