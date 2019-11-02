#include <iostream>

using namespace std;

class super_long
{
private:
    const long long int base = 1000000000000000000;
public:
    long long int bits[10]{0,0,0,0,0,0,0,0,0,0};
    int digit;
    super_long()
    {
        digit = 0;
    }
    explicit super_long(long long int n)
    {
        digit = 1;
        bits[0] = n % base;
        long long int carry = n/base;
        if(carry != 0)
        {
            digit++;
            bits[1] = carry;
        }
    }
    super_long operator+= (super_long x)
    {
        long long int carry = 0;
        int newDigit;
        newDigit = x.digit > digit?x.digit:digit;
        for (int i = 0; i < newDigit;i++)
        {
            long long int sum = bits[i]+x.bits[i]+carry;
            bits[i] = sum%base;
            carry = sum/base;
        }
        digit = newDigit;
        if(carry > 0)
            bits[digit++] = carry;
        return *this;
    }
    super_long& operator= (const int& x)
    {
        bits[0] = x;
        digit = 1;
        return *this;
    }
    super_long& operator= (const long long int& x)
    {
        bits[0] = x;
        digit = 1;
        return *this;
    }
    void print()
    {
        cout<<bits[digit-1];
        for (int i = digit-2; i >= 0; i--)
        {
            cout.width(18);
            cout.fill('0');
            cout<<bits[i];
        }
        cout<<'\n';
    }
};

super_long c[51][51];

int main()
{
/*    long long int b[10] = {1900337283025742165,1298865301494476944
            ,3756664567012262288
            ,3169510845331312025
            ,3244990205197513269
            ,3504347092396822942
            ,4610767666586376128
            ,3916743017539956295
            ,5496882478710055771
            ,6376876088821679905};
    super_long a[10],res(0);
    for (int i = 0 ; i<10;i++)
    {
        a[i] = b[i];
        cout<<"a["<<i<<"]=";
        a[i].print();
        cout<<endl;
    }
    res.print();
    for (int i = 0; i < 10; i++)
    {res += a[i];
    res.print();}*/
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int k, h;
    cin >> k >> h;
    super_long result(0);
    for (int i = 1; i <= k; i++)
        for (int j = 1; j <= h; j++)
            c[j][i] = 0;
    c[1][k] = 1;
    for (int i = 2; i <= h; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            for (int m = 0; m < j; m++)
                c[i][j] += c[i - 1][k - m];
        }
    }
    for (int i = 1; i <= k; i++)
        result += c[h][i];
    result.print();
    cout<<'\n';
    return 0;
}