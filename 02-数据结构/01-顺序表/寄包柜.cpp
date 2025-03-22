#include <iostream>
#include <vector>
using namespace std;

int n, q;
int i, j, k;

int main()
{
	cin >> n >> q;
	vector<vector<int>> aa(n + 1);

	while(q--)
	{
		int op; cin >> op;
		if(op == 1)
		{
			cin >> i >> j >> k;
			if(aa[i].size() <= j)
			{
				aa[i].resize(j + 1);
			}
			aa[i][j] = k;
		}
		else if(op == 2)
		{
			cin >> i >> j;
			cout << aa[i][j] << endl;
		}
	}
	return 0;
}
