#include <iostream>

using namespace std;

int array[1000010], c[1000010];

void successor(int x,int start,int end)
{
    int median = (start + end)/2;
    if (end - start == 0)
        c[start] = x;
    else if (end - start == 1)
        c[(c[start]>x? start:end)] =x;
    else if (c[median] < x)
        successor(x,median,end);
    else if(c[median]>x)
        successor(x,start,median);
}

int LIS(int len)
{
    c[0] = 0;
    int c_last = 0;
    for(int i = 1; i <= len; i++)
    {
        if(array[i] > c[c_last])
            c[++c_last] = array[i];
        else
            successor(array[i],1,c_last);
    }
    return c_last;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int len;
    cin>>len;
    array[0] = -1;
    for(int i = 1; i <= len; i++)
        cin>>array[i];
    cout<<LIS(len)<<'\n';
    return 0;
}