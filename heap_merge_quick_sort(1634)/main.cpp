#include <iostream>

using namespace std;

int num_comp = 0;
int num[100000];

void swap_num(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void min_heapify(int* num, int start, int end)
{
    int dad = start;
    int son = dad*2+1;
    while(son <= end)
    {
        if (son+1 <= end)
        {
            num_comp++;
            if (num[son] > num[son+1])
                son++;
        }
        num_comp++;
        if (num[dad] <= num[son])
            return;
        else
        {
            swap_num(num[dad],num[son]);
            dad = son;
            son = dad*2+1;
        }
    }
}

void bubble_up(int* num, int end)
{
    int son = end;
    int dad = (son-1)/2;
    while (son > 0)
    {
        num_comp++;
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

void heap_sort(int* num, int end)
{
    for (int i = 1; i < end; i++)
        bubble_up(num,i);
    for (int i = end-1; i > 0; i--){
        swap_num(num[0],num[i]);
        min_heapify(num,0,i-1);
    }
}

void merge_sort(int *num, int start, int end)
{
    if (end-start > 1)
    {
        int pivot = start+(end-start)/2;
        merge_sort(num, start, pivot);
        merge_sort(num, pivot, end);
        int result[end-start];
        int i, j, k;
        i = j = k = 0;
        while (i != pivot-start && j != end-pivot)
        {
            num_comp++;
            if (num[start+i] <= num[pivot+j])
            {
                result[k++] = num[start+i];
                i++;
            }
            else
            {
                result[k++] = num[pivot+j];
                j++;
            }
        }
        int i_or_j = ((i == pivot-start)?j:i);
        int unfinished = end-start-i-j;
        int new_start = ((i == pivot-start)?pivot:start);
        for (int l = i_or_j; l < i_or_j+unfinished; l++)
            result[k++] = num[new_start+l];
        for (int l = 0; l < end-start; l++)
            num[start+l] = result[l];
    }
}

void quick_sort(int *num, int start, int end)
{
    if (end-start > 1)
    {
        int current = start+1;
        int cursor = start+1;
        for (; current < end ; current++)
        {
            //num_comp++;
            if (num[current] < num[start])
            {
                swap_num(num[current],num[cursor]);
                cursor++;
            }
        }
        //num_comp += (end-start-1);
        swap_num(num[cursor-1],num[start]);
        quick_sort(num, start, cursor-1);
        quick_sort(num, cursor, end);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N,k;
    cin>>N>>k;
    for (int i = 0; i < N; i++)
        cin>>num[i];
    if (k == 1)
        heap_sort(num,N);
    else if(k == 2)
        merge_sort(num,0,N);
    else if(k == 3)
        quick_sort(num,0,N);
/*    for (int i = 0; i < N; i++)
        cout<<num[i]<<' ';
    cout<<'\n';*/
    cout<<num_comp;
    return 0;
}