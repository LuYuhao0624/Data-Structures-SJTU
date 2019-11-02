#include <iostream>

using namespace std;

char ch[1010],a[1010],b[1010];

int LCS(int lenA,int lenB)
{
    int c[lenA+1][lenB+1];
    for (int i = 0; i <= lenA; i++)
        c[i][0] = 0;
    for (int j = 0; j <= lenB; j++)
        c[0][j] = 0;
    for (int i = 1; i <= lenA; i++)
    {
        for (int j = 1; j <= lenB; j++)
        {
            if (a[i] == b[j])
                c[i][j] = c[i - 1][j - 1] + 1;
            else
                c[i][j] = (c[i - 1][j] > c[i][j - 1] ? c[i - 1][j] : c[i][j - 1]);
        }
    }
    return c[lenA][lenB];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int lenA,lenB;
    cin>>lenA>>lenB;
    for(int i = 1; i <= lenA; i++)
        cin>>a[i];
    for(int i = 1; i <= lenB; i++)
        cin>>b[i];
    cout<<LCS(lenA,lenB)<<'\n';
    return 0;
}