#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> a(n + 1);
	for(int i=1; i<=n; ++i)
	{
		cin >> a[i];
	}

	while(m--)
	{
		int p;
		cin >> p;
		cout << a[p] << endl;
	}
	return 0;
}
