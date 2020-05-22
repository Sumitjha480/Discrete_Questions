#include<iostream>
using namespace std;
class stack
{
	int *arr;
	int front;
	int size_stack;
public:
	stack()
	{
	    size_stack=50;
		arr = new int[size_stack];
		front = -1;
	}
	~stack()
	{
		delete arr;
	}
	void push(int x)
	{
		arr[++front] = x;
	}
	void pop()
	{
		front--;
	}
	int top()
	{
		return arr[front];
	}
	int size()
	{
	    return front + 1;
	}
};
int c=0;
int c1=0;
int C(int n1, int n2){
    return n1 & n2;
}
int D(int n1,int n2) {
    return n1 | n2;
}
int  I(int n1,int n2){
    return !n1 | n2;
}
int E(int n1, int n2) {
    return !(n1 ^ n2);
}
int N(int n1)  {
    return !n1;
}
void check()
{
    string s;
    cin>>s;
    int vaaible[26];
    for(int i=0;i<26;i++)
        vaaible[i]=-1;
    int n=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='a' && vaaible[s[i]-'a']==-1)
        {
            vaaible[s[i]-'a']=n++;
        }
    }
    int val[n];
    for(int i=0;i<(1<<n);i++)
    {
        for(int j=0;j<n;j++)
            val[j]=(i>>j) & 1;
        stack st;
        for(int k=s.size()-1;k>=0;k--)
        {
            if(s[k]>='a')
            {
                st.push(val[vaaible[s[k]-'a']]);
                    continue;
            }
            int val1=st.top();
            st.pop();
            int val2;
            switch(s[k])
            {
                case 'C':
                    val2=st.top();
                    st.pop();
                    st.push(C(val1,val2));
                    break;
                case 'D':
                    val2=st.top();
                    st.pop();
                    st.push(D(val1,val2));
                    break;
                case 'I':
                    val2=st.top();
                    st.pop();
                    st.push(I(val1,val2));
                    break;
                case 'E':
                    val2=st.top();
                    st.pop();
                    st.push(E(val1,val2));
                    break;
                case 'N':
                    st.push(N(val1));
                    break;
                default:
                    break;

            }
        }

        if(st.top()==0)
            c++;
        else
            c1++;
    }
}
int main()
{
    cout<<"SUMIT KUMAR JHA\n2019UCO1735";
    cout<<"\nEnter following letters in uppercase for operations:\n";;
	cout<<"AND operation -> C\n";
	cout<<"OR operation -> D\n";
	cout<<"IMPLIES operation ->I\n";
	cout<<"IF and ONLY IF operation ->E\n";
	cout<<"For NOT operation->N\n";
	cout<<"Enter expression and variables(should in lowercase only):\n";
    check();
    if(c==0){
        cout<<"\nExpression is tautology";
    }
    else if (c1==0){
        cout<<"\nExpression is contradiction";
    }
    else{
        cout<<"\nExpression is contingency";
    }
}
