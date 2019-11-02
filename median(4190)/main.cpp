#include <iostream>

using namespace std;

void swap_num(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

class heap
{
protected:
    int length;
    int num[50000];
public:
    heap()
    {
        length = 0;
    }
    void insert_incomplete(int x)
    {
        num[length] = x;
        length++;
    }
    void extract_incomplete()
    {
        swap_num(num[0],num[length-1]);
        length--;
    }
    int get_length()
    {
        return length;
    }
    int get_top()
    {
        return num[0];
    }
    void print()
    {
        if (length == 0)
            cout<<"empty.";
        for (int i = 0; i < length; i++)
            cout<<num[i]<<' ';
        cout<<'\n';
    }
};

class max_heap: public heap{
    void bubble_up()
    {
        int son = length-1;
        int dad = (son-1)/2;
        while (son != 0)
        {
            if (num[son] > num[dad])
            {
                swap_num(num[son],num[dad]);
                son = dad;
                dad = (son-1)/2;
            }
            else
                break;
        }
    }
    void heapify()
    {
        int dad = 0;
        int son = dad*2+1;
        while (dad <= (length-1)/2 && son < length)
        {
            if (son+1 < length && num[son] < num[son+1])
                son++;
            if (num[dad] < num[son])
            {
                swap_num(num[dad],num[son]);
                dad = son;
                son = 2*dad+1;
            }
            else
                break;
        }
    }
public:
    void insert(int x)
    {
        insert_incomplete(x);
        bubble_up();
    }
    int extract()
    {
        extract_incomplete();
        heapify();
        return num[length];
    }
};

class min_heap: public heap{
    void bubble_up()
    {
        int son = length-1;
        int dad = (son-1)/2;
        while (son != 0)
        {
            if (num[son] < num[dad])
            {
                swap_num(num[son],num[dad]);
                son = dad;
                dad = (son-1)/2;
            }
            else
                break;
        }
    }
    void heapify()
    {
        int dad = 0;
        int son = dad*2+1;
        while (dad <= (length-1)/2 && son < length)
        {
            if (son+1 < length && num[son] > num[son+1])
                son++;
            if (num[dad] > num[son])
            {
                swap_num(num[dad],num[son]);
                dad = son;
                son = 2*dad+1;
            }
            else
                break;
        }
    }
public:
    void insert(int x)
    {
        insert_incomplete(x);
        bubble_up();
    }
    int extract()
    {
        extract_incomplete();
        heapify();
        return num[length];
    }
};

void balance(max_heap& heap1, min_heap& heap2)
{
    int length1 = heap1.get_length();
    int length2 = heap2.get_length();
    if (length1-length2 == 3)
    {
        int item = heap1.extract();
        heap2.insert(item);
    }
    else if(length2-length1 == 1)
    {
        int item = heap2.extract();
        heap1.insert(item);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N;
    cin >> N;
    if (N%2==0)
        N--;
    max_heap heap1; //length of heap1 - length of heap2 = 1
    min_heap heap2;
    int data;
    cin>>data;
    heap1.insert(data);
    cout<<data<<'\n';
/*    cout<<"heap1:";
    heap1.print();
    cout<<"heap2:";
    heap2.print();
    cout<<"\n\n";*/
    for (int i = 1; i < N; i += 2)
    {
        cin>>data;
        if (data > heap1.get_top())
            heap2.insert(data);
        else
            heap1.insert(data);
/*        cout<<"After insertion 1.\nheap1:";
        heap1.print();
        cout<<"heap2:";
        heap2.print();*/
        cin>>data;
        if (data > heap1.get_top())
            heap2.insert(data);
        else
            heap1.insert(data);
/*        cout<<"After insertion 2.\nheap1:";
        heap1.print();
        cout<<"heap2:";
        heap2.print();*/
        if (heap1.get_length()-heap2.get_length() == 1) {}
        else
            balance(heap1,heap2);
/*        cout<<"After balance.\nheap1:";
        heap1.print();
        cout<<"heap2:";
        heap2.print();*/
        cout<<heap1.get_top()<<'\n';
    }
/*    heap1.insert(data);
    heap1.print();
    for(int i = 1; i< N;i++)
    {
        cin>>data;
        heap1.full_insert(data);
        cout<<"After insertion:";
        heap1.print();
        cout<<'\n';
    }*/
    return 0;
}