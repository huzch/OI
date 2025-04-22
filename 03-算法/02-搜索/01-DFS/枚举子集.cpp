#include <iostream>
using namespace std;

string path;
int n;

void dfs(int pos) {
	if(pos > n) {
		cout << path << endl;
		return;
	}
	//字典序，先不选后选
	//不选
	path += 'N';
	dfs(pos + 1);
	path.pop_back();
	//选
	path += 'Y';
	dfs(pos + 1);
	path.pop_back();
}

int main() {
	cin >> n;

	dfs(1);

	return 0;
}
