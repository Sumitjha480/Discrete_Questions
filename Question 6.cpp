#include<iostream>
using namespace std;

int binarysearch(char str[], int start, int last, int key)
{
    int i = -1;
    while (start <= last) {
        int mid = (start+last) / 2;
        if (str[mid] <= key)
            last = mid - 1;
        else {
            start = mid + 1;
            if (i== -1 || str[i] >= str[mid])
                i= mid;
        }
    }
    return i;
}
void swap(char* a, char* b)
{
    char t;
    t = *b;
    *b = *a;
    *a = t;
}
void str_reverse(char str[], int start, int last)
{
    while (start < last)
    {
        swap(&str[start], &str[last]);
        start++;
        last--;
    }
}

int str_len(char str[])
{
    int i;
    for(i=0;str[i]!='\0';i++);
    return i;
}

int next_comb(char str[])
{
    int length = str_len(str), i = length - 2;
    while (i >= 0 && str[i] >= str[i + 1])
        --i;
    if (i < 0)
        return i;
    else {
        int c = binarysearch(str, i + 1, length - 1, str[i]);
        swap(&str[i], &str[c]);
        str_reverse(str, i + 1, length - 1);
        return i;
    }
}


int main()
{
    cout<<"SUMIT KUMAR JHA\n2019UCO1735";
    char str[1000000],c;
    cout<<"\nEnter the string: ";
    cin>>str;
    c = next_comb(str);
    if (c<0)
    {
        cout << "No possible combination after this" << endl;
    }
    else
    {
        cout<<"Next combination is: ";
        for(int i=0;i<=c;i++)
        {
            cout<<str[i];
        }
    }
    return 0;
}

