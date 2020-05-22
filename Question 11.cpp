#include<iostream>
using namespace std;

int identityelemnent;

bool closureaddition(int n,int arr[])
{
	int ans,k;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				ans=arr[i]+arr[j];
				for(k=0;k<n;k++)
				{
					if(arr[k]==ans)
					{
						break;
					}
				}
				if(k>=n)
				{
					return false;
				}
			}
		}
		return true;
}

bool closuremultiplacation(int n,int arr[])
{
    int k,ans;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            ans=arr[i]*arr[j];
            for(k=0;k<n;k++)
            {
                if(arr[k]==ans)
                {
                    break;
                }
            }
            if(k>=n)
            {
                return false;
            }
        }
    }
    return true;
}

bool commutative(int n,int arr[])
{
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if((arr[i]+arr[j])!=(arr[j]+arr[i]))
                {
                    return false;
                }
            }
        }
        return true;
}

bool associativeaddition(int n,int arr[])
{
	int k;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				for(k=0;k<n;k++)
				{
					if(((arr[i]+arr[j])+arr[k])!=(arr[i]+(arr[j]+arr[k])))
					{
						return false;
					}
				}
			}
		}
		return true;
}
bool associativemultiplication(int n,int arr[])
{
    int k;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				for(k=0;k<n;k++)
				{
					if(((arr[j]*arr[j])*arr[k])!=(arr[j]*(arr[j]*arr[k])))
					{
						return false;
					}
				}
			}
		}
		return true;
}

bool identityaddition(int n,int arr[])
{
	int c=0;
		for(int i=0;i<n;i++)
		{
			c=0;
			for(int j=0;j<n;j++)
			{
				if((arr[i]+arr[j])==arr[j])
				{
					c++;
				}
			}
			if(c==n)
			{
				identityelemnent=arr[i];
				return true;
			}
		}
		return false;
}
bool identitymultiplication(int n,int arr[])
{
    int c=0;
		for(int i=0;i<n;i++)
		{
			c=0;
			for(int j=0;j<n;j++)
			{
				if((arr[i]*arr[j])==arr[j])
				{
					c++;
				}
			}
			if(c==n)
			{
				identityelemnent=arr[i];
				return true;
			}
		}
		return false;
}

bool inverseaddition(int n,int arr[])
{
	int j;
		for(int i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if((arr[i]+arr[j])==identityelemnent)
				{
					break;
				}
			}
			if(j>=n)
			{
				return false;
			}
		}
		return true;
}

bool inversemultiplication(int n,int arr[])
{
    int j;
		for(int i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if((arr[i]*arr[j])==identityelemnent)
				{
					break;
				}
			}
			if(j>=n)
			{
				return false;
			}
		}
		return true;
}

bool distributive(int n,int arr[])
{
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                for(int k=0;k<n;k++)
                {
                    if((arr[i]*(arr[j]+arr[k]))!=((arr[i]*arr[j])+(arr[i]*arr[k]))&&(((arr[j]+arr[k])*arr[i])!=((arr[j]*arr[i])+(arr[k]*arr[i]))))
                    {
                        return false;
                    }
                }
            }
        }
        return true;
}
bool check(int n,int arr[])
{
	if(closureaddition(n,arr)==1 && associativeaddition(n,arr)==1 && identityaddition(n,arr)==1 && inverseaddition(n,arr)==1 && closuremultiplacation(n,arr) && associativemultiplication(n,arr) && identitymultiplication(n,arr) && inversemultiplication(n,arr) && distributive(n,arr))
	{
		return true;
	}
	return false;
}

int main()
{
    cout<<"\nSUMIT KUMAR JHA\n2019UCO1735";
	int n;
	cout<<"\nEnter the size of set: ";
	cin>>n;
	int arr[n];
	cout<<"\nEnter the set: ";
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	if(check(n,arr)==1)
	{
		cout<<"\nIt is a Ring";
	}
	else{
		cout<<"\nIt is not a Ring";
	}
	return 0;
}
