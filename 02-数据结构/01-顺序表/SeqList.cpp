#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int a[N], n;

void print()
{
	for(int i=1; i<=n; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

void push_back(int x)
{
	a[++n] = x;
}

void push_front(int x)
{
	for(int i=n; i>=1; --i)
	{
		a[i+1] = a[i];
	}
	a[1] = x;
	++n;
}

void insert(int p, int x)
{
	for(int i=n; i>=p; --i)
	{
		a[i+1] = a[i];
	}
	a[p] = x;
	++n;
}

void pop_back()
{
	--n;
}

void pop_front()
{
	for(int i=2; i<=n; ++i)
	{
		a[i-1] = a[i];
	}
	--n;
}

void erase(int p)
{
	for(int i=p+1; i<=n; ++i)
	{
		a[i-1] = a[i];
	}
	--n;
}

int find(int x)
{
	for(int i=1; i<=n; ++i)
	{
		if(a[i] == x)
		{
			return i;
		}
	}
	return 0;
}

int at(int p)
{
	return a[p];
}

void change(int p, int x)
{
	a[p] = x;
}

int main()
{
	push_back(1);
	push_back(2);
	push_back(3);
	push_back(4);
	push_back(5);
	print();

	push_front(6);
	push_front(7);
	push_front(8);
	push_front(9);
	push_front(10);
	print();

	insert(1, 1);
	insert(2, 2);
	insert(3, 3);
	insert(4, 4);
	insert(5, 5);
	print();

	// pop_back();
	// pop_back();
	// pop_back();
	// pop_back();
	// pop_back();
	// print();
	//
	// pop_front();
	// pop_front();
	// pop_front();
	// pop_front();
	// pop_front();
	// print();
	//
	// erase(1);
	// print();
	// erase(2);
	// print();
	// erase(3);
	// print();

	return 0;
}
