#include <iostream>
#include <cstring>

using namespace std;

long long int power(char digit, int super)
{
    int result = digit-'0';
    long long int base = 1;
    for (int i = 0; i < super; i++)
        base *= 10;
    return result*base;
}

class super_long
{
private:
    long long int digits[40];
    int bits;
    int length;
    char* raw_input;
    const long long int BASE = 1000000000000000000; // 1e18
public:
    super_long(char* input)
    {
        for (int i = 0; i < 40; i++)
            digits[i] = 0;
        int len = strlen(input);
        length = len;
        raw_input = input;
        bits = len/18;
        int remain_bits = bits;
        if (len%18 != 0)
        {
            for (int i = 0; i < len-18*bits; i++)
                digits[bits] += power(input[i], len%18-i-1);
            bits += 1;
            remain_bits = bits-1;
        }
        for (int i = 0; i < remain_bits; i++)
        {
            digits[i] = 0;
            for (int j = 0; j < 18; j++)
                digits[i] += power(input[len-i*18-(18-j)],18-j-1);
        }
    }
    super_long()
    {
        for (int i = 0; i < 40; i++)
            digits[i] = 0;
        bits = 0;
    }
    super_long operator+(const super_long& b)
    {
        long long int carry = 0;
        int new_bits = this->bits > b.bits? this->bits:b.bits;
        super_long result;
        for (int i = 0; i < new_bits; i++)
        {
            result.digits[i] = (this->digits[i]+b.digits[i]+carry)%BASE;
            carry = (this->digits[i]+b.digits[i]+carry)/BASE;
        }
        result.bits = new_bits;
        if (carry > 0)
        {
            result.bits += 1;
            result.digits[new_bits] = carry;
        }
        return result;
    }
    super_long operator=(const super_long& b)
    {
        this->bits = b.bits;
        for (int i = 0; i < this->bits; i++)
            this->digits[i] = b.digits[i];
    }
    void print()
    {
        cout<<digits[this->bits-1];
        for (int i = this->bits-2; i >= 0; i--)
        {
            cout.width(18);
            cout.fill('0');
            cout<<this->digits[i];
        }
        cout<<'\n';
    }
    super_long mul(const int& b) {
        super_long result;
        int new_bits = this->bits;
        result.bits = new_bits;
        long long int carry = 0;
        if (b == 10)
        {
            for (int i = 0; i < this->bits; i++)
            {
                result.digits[i] = this->digits[i] % (BASE / 10) * 10 + carry;
                carry = this->digits[i] / (BASE / 10);
            }
        }
        else
        {
            for (int i = 0; i < new_bits; i++)
            {
                result.digits[i] = (this->digits[i]*b+carry)%BASE;
                carry = (this->digits[i]*b+carry)/BASE;
            }
        }
        if(carry > 0)
        {
            result.bits += 1;
            result.digits[new_bits] = carry;
        }
        return result;
    }
    super_long super_power(int a, int super)
    {
        super_long result = *this;
        for (int i = 0; i < super; i++)
            result = result.mul(a);
        return result;
    }
    super_long operator*(const super_long& b)
    {
        super_long result;
        super_long mul1 = *this;
        for (int i = 1; i <= b.length; i++)
        {
            result = result + mul1.mul(b.raw_input[i-1]-'0').super_power(10,b.length-i);
            //mul1.mul(b.raw_input[i-1]-'0').super_power(10,b.length-i).print();
        }
        return result;
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    char input1[400], input2[400];
    cin>>input1>>input2;
    super_long a(input1),b(input2),c;
    c = a*b;
    c.print();
    return 0;
}