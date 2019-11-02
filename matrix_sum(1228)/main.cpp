#include <iostream>

using namespace std;

int mat[410][410];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> mat[i][j];
        }
    }
    int odd = 0, even = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for(int height = 1; height <= n-i+1; height++)
            {
                for (int width = 1; width <= n-j+1; width++)
                {

                }
            }
        }
    }
    return 0;
}