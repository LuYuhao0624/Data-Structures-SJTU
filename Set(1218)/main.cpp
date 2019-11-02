#include<iostream>

using namespace std;

struct node
{
    int value;
    node* up;
    node* left;
    node* right;
    node(int entry, node* parent = nullptr, node* lChild= nullptr, node* rChild = nullptr)
    {
        value = entry;
        up = parent;
        left = lChild;
        right = rChild;
    }
};

class search_tree
{
private:
    node* root;
    int num_nodes;
public:
    search_tree()
};