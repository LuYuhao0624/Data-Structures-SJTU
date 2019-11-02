#include<iostream>

using namespace std;

class min_heap
{
private:
	int data[20000];
	int current_len;
	void bubble_up(int n)
	{
		int index = n;
		while (index != 0 && data[(index - 1) / 2] > data[index])
		{
			int temp = data[index];
			data[index] = data[(index - 1) / 2];
			data[(index - 1) / 2] = temp;
			index = (index - 1) / 2;
		}
	}
public:
	min_heap()
	{
		current_len = 0;
	}
	void insert(int x)
	{
		data[current_len] = x;
		current_len++;
		bubble_up(current_len-1);
	}
	int find(int x)
	{
		int successor, i,index;
		for (i = 0; i < current_len; i++)
		{
			if (data[i] > x)
			{
				successor = data[i];
				index = i;
				break;
			}
		}
		for (;i < current_len; i++)
		{
			if (data[i] > x && data[i] < successor)
			{
				successor = data[i];
				index = i;
			}
				
		}
		return index;
	}
	void decrease(int i, int v)
	{
		data[i] -= v;
		bubble_up(i);
	}
};

int main()
{
	min_heap a;
	int num;
	cin >> num;
	char order[10];
	for (int i = 0; i < num; i++)
	{
		cin >> order;
		int x;
		if (order[0] == 'i')
		{
			cin >> x;
			a.insert(x);
		}
		else
		{
			if (order[0] == 'f')
			{
				cin >> x;
				cout << a.find(x) + 1 << endl;
			}
			else
			{
				int j, v;
				cin >> j >> v;
				if (order[0] == 'd')
					a.decrease(j, v);
			}
		}
	}
	return 0;
}