#include<iostream>
using namespace std;

template <typename T>
class queue{
    T arr[100];
    int top = 0, bottom = 0;
public:
    T front()
    {
        return arr[top];
    }
    void push(T d)
    {
        arr[bottom] = d;
        bottom = (bottom+1)%100;
    }
    void pop()
    {
        top = (top+1)%100;
    }
    int size()
    {
        return bottom;
    }
    bool empty()
    {
        return top==bottom;
    }
};

int vertices[10000] = {0};
bool container[10000] = {false};
bool container2[10000] = {false};
int i = 0;

string to_string(int a)
{
    char c[10],b,t;
    int res,i=0,n;
    while(a>0)
    {
        res = a%10;
        b= res+ '0';
        c[i] = b;
        i++;
        a=a/10;
    }
    c[i]= '\0';
    n=i;
    for(i=0;i<n/2;i++)
    {
        t=c[i];
        c[i] = c[n-i-1];
        c[n-i-1] = t;
    }
    return c;
}

void print(queue<int> q)
{
    while(!q.empty())
    {
        cout<<q.front()<<"->";
        q.pop();
    }
    cout<<endl;
}

bool check(queue<int> q,int data)
{
    while(!q.empty())
    {
        if(q.front() == data)
        {
            return true;
        }
        q.pop();
    }
    return false;
}

class Graph{
public:
    int v;
    int arr[100][100];
    Graph(int V)
    {
        v = V;
    }
    void addedge(int x, int y)
    {
        arr[x][vertices[x]++] = y;
        arr[y][vertices[y]++] = x;
    }
    void printlist(int n)
    {
        for (int i=0;i<n;i++)
        {
            cout<<i<<"->";
            for(int j=0;j<vertices[i];j++)
            {
                cout<<arr[i][j];
            }
            cout<<endl;
        }
        return;
    }
    void getPath(int a, int b,queue<int> q)
    {
        if(a==b)
        {
            q.push(a);
            print(q);
            return;
        }
        else{
            container[a] = true;
            for(int j=0;j<vertices[a];j++)
            {
                if(container[arr[a][j]] == false)
                {
                    if(check(q,a)==0)
                    {
                        q.push(a);
                    }
                    getPath(arr[a][j],b,q);
                }
            }
            container[a] = false;
            q.pop();
        }
    }
    void cycles(int a)
    {
        for(int i=0;i<vertices[a];i++)
        {
            cycle(a,arr[a][i],"",a);
        }
        return;
    }
    void cycle(int a, int b,string s,int con)
    {
        if(a==b && s.length()>3)
        {
            cout<<s<<b<<"->"<<con<<endl;
            return;
        }
        container2[a] = true;
        for(int j=0;j<vertices[a];j++)
        {
            if(container2[arr[a][j]] == false)
            {
                cycle(arr[a][j],b,s + to_string(a) + "->",con);
            }
        }
        container2[a] = false;
    }
};
int main()
{
    cout<<"SUMIT KUMAR JHA\n2019UCO1735";
    int n,a,b;
    queue<int> q;
    cout<<"\nEnter Graph Size\n";
    cin>>n;
    a=n;
    Graph p(n);
    cout<<"Enter Pairs\n";
    while(n--)
    {
        int x,y;
        cin>>x>>y;
        p.addedge(x,y);
    }
    p.printlist(a);
    cout<<"Enter the start and end pt\n";
    cin>>a>>b;
    p.getPath(a,b,q);
    cout<<endl;
    while(!q.empty())
        q.pop();
    cout<<"Enter a cycle element\n";
    cin>>a;
    p.cycles(a);
    return 0;
}
