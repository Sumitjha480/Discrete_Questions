#include<iostream>
using namespace std;
bool isSymmetric(int l,char relation[][2])
{
    for(int i=0;i<l;i++)
    {
        if(relation[i][0]!=relation[i][1])
        {
            int c=0;
            for(int j=0;j<l;j++)
            {
                if(relation[j][0]==relation[i][1] && relation[j][1]==relation[i][0])
                {
                    c++;
                    break;
                }
            }
            if(c==0)
                return false;
        }
    }
    return true;
}
bool isTransitive(int l,char relation[][2])
{
    for(int i=0;i<l;i++)
    {
        if(relation[i][0]!=relation[i][1])
        {
            for(int j=0;j<l;j++)
            {
                if(relation[i][1]==relation[j][0])
                {
                    int c=0;
                    for(int k=0;k<l;k++)
                    {
                        if(relation[k][0]==relation[i][0] && relation[k][1]==relation[j][1])
                        {
                            c++;
                            break;
                        }
                    }
                    if(c==0)
                        return false;
                }
            }
        }
    }
    return true;
}
bool isReflexive(int n,int l,char values[],char relation[][2])
{
    for(int i=0;i<n;i++)
    {
        int c=0;
        for(int j=0;j<l;j++)
        {
            if(values[i]==relation[j][0] && relation[j][0]==relation[j][1])
            {
                c++;
                break;
            }
        }
        if(c==0)
            return false;
    }
    return true;
}
int main()
{
    int n,l;
    cout<<("SUMIT KUMAR JHA\n2019UCO1735");
    cout<<"\nNumber of elements:";
    cin>>n;
    char values[n];
    cout<<"Enter the values:";
    for(int i=0;i<n;i++)
        cin>>values[i];
    cout<<"Enter number of relation:";
    cin>>l;
    char relation[l][2];
    cout<<"Enter the relations:";
    for(int i=0;i<l;i++)
    {
        for(int j=0;j<2;j++)
        {
            cin>>relation[i][j];
        }
    }
    if(isReflexive(n,l,values,relation) && isSymmetric(l,relation) && isTransitive(l,relation))
        cout<<"The given relation is an Equivalence Relation.";
    else
        cout<<"The given relation is not an Equivalence Relation.";
    return 0;
}
