#include <iostream>

using namespace std;

class Stack {
private:
    int* data;
    int top;
    int capacity;
public:
    Stack(int m) {data = new int [m + 1]; data[0] = -1; top = 0; capacity = m;}
    void sequential_init() {
        top = capacity;
        for (int i = 1; i < capacity; i++)
            data[capacity - i] = i;
    }
    int in(int x) {
        if (top >= capacity)
            return -1;
        data[++top] = x;
        return 0;
    }
    int out() {return data[top--];}
    int top_ele() {return data[top];}
    bool empty() {return top == 0;}
};

bool feasible() {
    int N, M;
    cin >> N >> M;
    Stack scheduler = Stack(M);
    Stack east = Stack(N);
    east.sequential_init();
    int next;
    int res;
    int* order = new int [N];
    for (int i = 0; i < N; i++)
        cin >> order[i];
    for (int i = 0; i < N; i++) {
        next = order[i];
        if (!east.empty()) {
            while (next != east.top_ele() && next != scheduler.top_ele()) {
                res = scheduler.in(east.out());
                if (res == -1)
                    return false;
            }
            if (next == east.top_ele()) {
                east.out();
                continue;
            }
            else if (next == scheduler.top_ele()) {
                scheduler.out();
                continue;
            }
        }
        else {
            if (next == scheduler.top_ele())
                scheduler.out();
            else
                return false;
        }
    }
    return true;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        if (feasible())
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}