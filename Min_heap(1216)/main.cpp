#include <iostream>

using namespace std;

int array[20010];
int used = 1;

void pop_up(int n)
{
    int index = n, up = index/2;
    if (index == 1)
        return;
    while(array[up] > array[index])
    {
        int temp = array[index];
        array[index] = array[up];
        array[up] = temp;
    }
}

void insert(int x)
{
    array[used] = x;
    pop_up(used);
    used++;
}

int find(int x)
{
    int index = 0, successor = 2147483647;
    for (int i = 1; i < used; i++)
    {
        if (array[i] > x && array[i] < successor)
        {
            index = i;
            successor = array[i];
        }
    }
    return index;
}

void decrease(int i, int v)
{
    array[i] -= v;
    pop_up(i);
}

void print()
{
    cout<<"The array now:";
    for (int i = 1; i<used;i++)
        cout<<array[i]<<" ";
    cout<<'\n';
}

int main() {
/*    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);*/
    int num_op,x,i,v;
    cin>>num_op;
    char op[20];
    for (int j = 0; j < num_op; j++)
    {
        cin>>op;
        if (op[0] == 'i')
        {
            cin>>x;
            insert(x);
            cout<<"Insert "<<x<<endl;
            print();
        }
        else if(op[0] == 'f')
        {
            cin>>x;
            cout<<find(x)<<"\n";
            cout<<"Find"<<x<<endl;
            print();
        }
        else
        {
            cin>>i>>v;
            decrease(i,v);
            cout<<"Decrease "<< i <<' '<<v<<endl;
            print();
        }
    }
    return 0;
}