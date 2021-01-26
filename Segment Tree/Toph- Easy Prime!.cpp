#include<bits/stdc++.h>
#define Max 10000005
using namespace std;
bool ar[Max];
void sieve()
{
	ar[0] = true;
	ar[1] = true;
	for (int i = 4; i < Max; i += 2)
	{
		ar[i] = true;
	}
	for (int i = 3; i * i < Max; i += 2)
	{
		if (ar[i] == false)
		{
			for (int j = i * i; j < Max; j += i + i)
			{
				ar[j] = true;
			}
		}
	}
}

void init(vector<int>& arr, vector<int>& tree, int node, int b, int e)
{
     if(b==e)
	 {
		 if (ar[arr[b]] == false)
		 {
			 tree[node] = 1;
			 return;
		 }
		 else
		 {
			 tree[node] = 0;
			 return;
		 }
	 }

	 int mid = (b + e) / 2;
	 init(arr, tree, node * 2, b, mid);
	 init(arr, tree, node * 2 + 1, mid + 1, e);
	 tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void update(vector<int>& tree, int node, int b, int e, int i, int value)
{
	if (b > i || i > e)
	{
		return;
	}
	if (b >= i && e <= i)
	{
		if (ar[value] == false)
		{
			tree[node] = 1;
			return;
		}
		else
		{
			tree[node] = 0;
			return;
		}
	}

	int mid = (b + e) / 2;
	if (i <= mid)
	{
		update(tree, node * 2, b, mid, i, value);
	}
	else
	{
		update(tree, node * 2 + 1, mid + 1, e, i, value);
	}
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(vector<int>& tree, int node, int b, int e, int i, int j)
{
	if (b > j || i > e)
	{
		return 0;
	}
	else if (b >= i && e <= j)
	{
		return tree[node];
	}

	int mid = (b + e) / 2;
	int val1 = query(tree, node * 2, b, mid, i, j);
	int val2 = query(tree, node * 2 + 1, mid + 1, e, i, j);
	return (val1 + val2);
}

int main()
{
	sieve();
	int num;
	while (cin >> num)
	{
		vector<int>arr(num + 2), tree(num * 4 + 2);
		for (int i = 1; i <= num; i++)
		{
			cin >> arr[i];
		}

		init(arr, tree, 1, 1, num);
		int q;
		cin >> q;
		while (q--)
		{
			int type;
			cin >> type;
			if (type == 1)
			{
				int i, j;
				cin >> i >> j;
				cout << query(tree, 1, 1, num, i, j) << '\n';
			}
			else
			{
				int i, value;
				cin >> i >> value;
				update(tree, 1, 1, num, i, value);
			}
		}
		arr.clear(), tree.clear();
	}
}
