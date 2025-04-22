#include <iostream>
#include <vector>
using namespace std;

const int N = 15;
bool col[N], st1[2 * N] ,st2[2 * N];
int n;
vector<int> path;
int ret;

void dfs(int i) {
	if(i > n) {
		if(ret < 3) {
			for(auto& x: path) {
				cout << x << " ";
			}
			cout << endl;
		}
		++ret;
		return;
	}

	for(int j=1; j<=n; ++j) {
		if(col[j] || st1[j - i + n] || st2[j + i]) continue;
		col[j] = st1[j - i + n] = st2[j + i] = true;
		path.push_back(j);
		dfs(i + 1);
		path.pop_back();
		col[j] = st1[j - i + n] = st2[j + i] = false;
	}
}

int main() {
	cin >> n;

	dfs(1);
	cout << ret << endl;

	return 0;
}
