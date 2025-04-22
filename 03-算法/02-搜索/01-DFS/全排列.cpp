#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

const int N = 15;

int n;
vector<int> path;
bool st[N];

void dfs() {
	if(path.size() == n) {
		for(auto& x: path) {
			printf("%5d", x);
		}
		printf("\n");
	}

	for(int i=1; i<=n; ++i) {
		if(st[i]) continue;
		path.push_back(i);
		st[i] = true;
		dfs();
		st[i] = false;
		path.pop_back();
	}
}

int main() {
	cin >> n;

	dfs();

	return 0;
}
