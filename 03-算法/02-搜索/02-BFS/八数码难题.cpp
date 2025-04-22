#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 5;
struct node {
	string st;
	int pos;
};
int n = 3, m = 3;
string sst;
int spos;
int ret;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
unordered_map<string, int> dist;
string target = "123804765";

void bfs() {
	queue<node> q;
	dist[sst] = 0;
	q.push({sst, spos});
	
	if(sst == target) {
		ret = 0;
		return;
	}
	
	while(q.size()) {
		auto t = q.front(); q.pop();
		int i = t.pos / m, j = t.pos % m;
		
		for(int k=0; k<4; ++k) {
			string st = t.st;
			int x = i + dx[k], y = j + dy[k];
			if(x < 0 || x >= n || y < 0 || y >= m) continue;
			
			int pos = x * m + y;
			swap(st[t.pos], st[pos]);
			if(dist.count(st)) continue;
			dist[st] = dist[t.st] + 1;
			
			if(st != target) q.push({st, pos});
			else ret = min(ret, dist[st]);
		}
	}
}

int main() {
	cin >> sst;
	for(int i=0; i<n*m; ++i) {
		if(sst[i] == '0') spos = i;
	}
	
	ret = INF;
	bfs();
	cout << ret << endl;
	
	return 0;
}
