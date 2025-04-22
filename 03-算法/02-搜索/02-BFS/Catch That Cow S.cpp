#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 1e5 + 10;
int dist[N];
bool st[N];
int x, y;
int ret;

void bfs() {
	queue<int> q;
	st[x] = true;
	q.push(x);
	
	while(q.size()) {
		auto t = q.front(); q.pop();
		
		for(int k=0; k<3; ++k) {
			int tmp = t;
			if(k == 0) tmp--;
			else if(k == 1) tmp++;
			else tmp *= 2;
			
			//¿ÉÐÐÐÔ¼ôÖ¦
			if(tmp < 1 || tmp > 1e5) continue;
			if(st[tmp]) continue;
			st[tmp] = true;
			
			dist[tmp] = dist[t] + 1;
			if(tmp != y) q.push(tmp);
			else ret = min(ret, dist[tmp]);
		}
	}
}

int main() {
	int T; cin >> T;
	while(T--) {
		memset(dist, 0, sizeof dist);
		memset(st, 0, sizeof st);
		
		cin >> x >> y;
		ret = INF;
		bfs();
		cout << ret << endl;
	}
	return 0;
}
