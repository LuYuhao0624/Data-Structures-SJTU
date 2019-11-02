#include <iostream>

using namespace std;

int numComp = 0;

struct node
{
    long long int data;
    node *next;
    explicit node(long long int x, node* ptr = nullptr)
    {
        data = x;
        next = ptr;
    }
};

class linked_list
{
private:
    node *head;
    node *tail;
public:
    linked_list(node *firstNode)
    {
        head = tail = firstNode;
    }
    void insert_at_head(long long int x)
    {
        head = new node(x,head);
    }
    void insert_at_tail(long long int x)
    {
        node *newNode;
        newNode = new node(x,nullptr);
        tail->next = newNode;
        tail = newNode;
    }
    void dump(node *target)
    {
        node *cursor = head;
        while (cursor->next != target)
            cursor = cursor->next;
        node *temp = target;
        if(target == tail)
        {
            tail = cursor;
            cursor->next = nullptr;
        }
        else
        {
            cursor->next = target->next;
        }
        delete temp;
    }
    node* find(long long int x)
    {
        bool equal = false;
        node *cursor = head;
        while(true)
        {
            equal = (cursor->data == x);
            numComp++;
            if (cursor == tail && !equal)
                return nullptr;
            else if (cursor != tail && !equal)
                cursor = cursor->next;
            else if(equal)
                return cursor;
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    long long int insertion,inquiry;
    cin>>n;
    cin>>insertion;
    node* headNode;
    headNode = new node(insertion);
    linked_list a(headNode);
    for(int i = 1; i < n; i++)
    {
        cin>>insertion;
        a.insert_at_tail(insertion);
    }
    cin>>m;
    for (int i = 0; i < m; i++)
    {
        cin>>inquiry;
        node *finding = a.find(inquiry);
        if(finding != nullptr)
        {
            a.insert_at_head(finding->data);
            a.dump(finding);
        }
    }
    cout<<numComp<<'\n';
    return 0;
}