#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int n, k;
vector<int> path;
unordered_set<int> st;

void dfs() {
	if(path.size() == k) {
		for(auto& x: path) {
			cout << x << " ";
		}
		cout << endl;
	}

	for(int i=1; i<=n; ++i) {
		if(st.count(i)) continue;

		path.push_back(i);
		st.insert(i);
		dfs();
		path.pop_back();
		st.erase(i);
	}
}

int main() {
	cin >> n >> k;

	dfs();

	return 0;
}
