#include <iostream>

using namespace std;

void swap(char* a, char* b)
{
    if (*a == *b)
        return;
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}
void rev(string& str, int l, int r)
{
    while (l < r)
        swap(&str[l++], &str[r--]);
}

int bsearch(string& str, int l, int r, int key)
{
    int index = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (str[mid] <= key)
            r = mid - 1;
        else {
            l = mid + 1;
            if (index == -1 || str[index] >= str[mid])
                index = mid;
        }
    }
    return index;
}

bool nextpermutation(string& str)
{
    int len = 0;
    for(int i=0;str[i]!='\0';i++)
    {
        len++;
    }
    int i = len - 2;
    while (i >= 0 && str[i] >= str[i + 1])
        --i;
    if (i < 0)
        return false;
    else {
        int index = bsearch(str, i + 1, len - 1, str[i]);
        swap(&str[i], &str[index]);
        rev(str, i + 1, len - 1);
        return true;
    }
}

int main()
{
    cout<<"SUMIT KUMAR JHA\n2019UCO1735";
    string str;
    cout<<"\nEnter the string: ";
    getline(cin,str);
    bool value = nextpermutation(str);
    if (value == false)
        cout << "No Word Possible" << endl;
    else
        cout <<"Next permutation is:"<<str << endl;
    return 0;
}
