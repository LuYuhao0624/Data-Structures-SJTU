#include <iostream>

using namespace std;

struct index;

struct node
{
    index *adj_list;
    int family;
    node() {adj_list = nullptr; family = 1;}
};

struct index
{
    int idx;
    index* next;
    index(int num = -1, index* ptr = nullptr) {idx = num; next = ptr;}
};

struct idx_max
{
    int idx;
    int max;
    idx_max(int index = 0, int num = 0) {idx = index; max= num;}
};

void swap_num(idx_max &a, idx_max &b)
{
    idx_max temp = a;
    a = b;
    b = temp;
}

void quick_sort(idx_max *num, int start, int end)
{
    if (end-start > 1)
    {
        int current = start+1;
        int cursor = start+1;
        for (; current < end ; current++)
        {
            if (num[current].idx < num[start].idx)
            {
                swap_num(num[current],num[cursor]);
                cursor++;
            }
        }
        swap_num(num[cursor-1],num[start]);
        quick_sort(num, start, cursor-1);
        quick_sort(num, cursor, end);
    }
}

bool explored[100000]; //index 0 not used!
node nodes[100000];
int level[100000];
int max_son[100000];
idx_max result[100000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N, result_len = 0;
    cin>>N;
    for (int i = 1; i <= N; i++)
    {
        max_son[i] = 0;
        explored[i] = false;
    }
    int v1, v2;
    for (int i = 0; i < N-1; i++)
    {
        cin>>v1>>v2;
        index* new_node1 = new index(v1,nodes[v2].adj_list);
        index* new_node2 = new index(v2,nodes[v1].adj_list);
        nodes[v1].adj_list = new_node2;
        nodes[v2].adj_list = new_node1;
    }
    level[1] = 1;
    int max_level = 1, level_change = 1;
    while(level_change != N)
    {
        for (int i = 1; i <= N; i++)
        {
            if(level[i] != max_level)
                continue;
            //explored[i] = true;
            index* cursor = nodes[i].adj_list;
            while (cursor != nullptr)
            {
                int idx = cursor->idx;
                //if (explored[idx])
                if (level[idx] != 0)
                {
                    cursor = cursor->next;
                    continue;
                }
                level[idx] = level[i]+1;
                level_change++;
                //if (level[idx] > max_level)
                //    max_level = level[idx];
                cursor = cursor->next;
            }
        }
        max_level++;
    }
    for (int j = max_level-1; j >= 1; j--) {
        for (int i = 1; i <= N; i++) {
            if (level[i] != j)
                continue;
            else {
                index *cursor = nodes[i].adj_list;
                while (cursor != nullptr)
                {
                    if (level[i] < level[cursor->idx])
                    {
                        nodes[i].family += nodes[cursor->idx].family;
                    }
                    cursor = cursor->next;
                }
            }
        }
    }
    for (int j = 1; j <= max_level; j++)
    {
        for (int i = 1; i <= N; i++)
        {
            if (level[i] != j)
                continue;
            else{
                index *cursor = nodes[i].adj_list;
                int dad_family = nodes[1].family - nodes[i].family;
                if (dad_family > max_son[i])
                    max_son[i] = dad_family;
                while (cursor != nullptr)
                {
                    if (level[i] < level[cursor->idx] && nodes[cursor->idx].family > max_son[i])
                    {
                        max_son[i] = nodes[cursor->idx].family;
                    }
                    cursor = cursor->next;
                }
            }
            if (max_son[i] <= N/2)
            {
                result[result_len].idx = i;
                result[result_len++].max = max_son[i];
            }
        }
    }
    quick_sort(result,0,result_len);
    /*cout<<"Below is adjacent list:"<<endl;
    for (int i = 1; i <= N; i++)
    {
        index* cursor = nodes[i].adj_list;
        cout<<i<<":";
        while(cursor != nullptr)
        {
            cout<<cursor->idx<<' ';
            cursor = cursor->next;
        }
        cout<<endl;
    } //debug adjacent list
    cout<<"Below is the level:"<<endl;
    for (int i = 1; i <= N; i++)
        cout<<i<<":"<<level[i]<<", ";
    cout<<endl;
    cout<<"Below is the families:"<<endl;
    for (int i = 1; i <= N; i++)
    {
        cout<<i<<":"<<nodes[i].family<<endl;
    }*/
    for (int i = 0; i < result_len; i++)
        cout<<result[i].idx<<' ';
    cout<<endl;
    return 0; // watch out discreet node index
}