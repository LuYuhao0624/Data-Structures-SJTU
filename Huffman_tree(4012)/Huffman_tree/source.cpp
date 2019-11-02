#include<iostream>

using namespace std;

class huffman_tree
{
private:
	int data[10000];
	int current_len;
	void bubble_up()
	{
		int index = current_len - 1;
		while (index != 0 && data[(index - 1) / 2] > data[index])
		{
			int temp = data[index];
			data[index] = data[(index - 1) / 2];
			data[(index - 1) / 2] = temp;
			index = (index - 1) / 2;
		}
	}
	void sink()
	{
		int index = 0;
		while (true)
		{
			if (index * 2 + 2 < current_len)
				if (data[index * 2 + 1] < data[index] || data[index * 2 + 2] < data[index])
				{
					int minIndex = (data[index * 2 + 1] < data[index * 2 + 2] ? (index * 2 + 1) : (index * 2 + 2));
					int temp = data[index];
					data[index] = data[minIndex];
					data[minIndex] = temp;
					index = minIndex;
				}
				else
					break;
			else
			{
				if (index * 2 + 1 < current_len)
					if (data[index] > data[index * 2 + 1])
					{
						int temp = data[index];
						data[index] = data[index * 2 + 1];
						data[index * 2 + 1] = temp;
					}
				break;
			}
		}
	}
public:
	huffman_tree()
	{
		current_len = 0;
	}
	void insert(int x)
	{
		data[current_len] = x;
		current_len++;
		bubble_up();
	}
	int extract()
	{
		int result = data[0];
		int temp = data[0];
		data[0] = data[current_len - 1];
		data[current_len - 1] = temp;
		current_len--;
		sink();
		return result;
	}
};

int main()
{
	int n;
	cin >> n;
	huffman_tree a;
	int x;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		a.insert(x);
	}
	int result = 0;
	int min1, min2,sum;
	for (int i = 0; i < n - 1; i++)
	{
		min1 = a.extract();
		min2 = a.extract();
		sum = min1 + min2;
		a.insert(sum);
		result += sum;
	}
	cout << result;
	return 0;
}