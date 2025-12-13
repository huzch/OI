// bfs --- 单源最短路
#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;

const int N = 10;
string a, b;
string x[N], y[N];
int n;
unordered_map<string, int> dist;

int bfs() {
	queue<string> q;
	q.push(a);
	dist[a] = 0;
	
	while(q.size()) {
		auto s = q.front(); q.pop();
		if(dist[s] == 10) continue;
		
		for(int i=0; i<n; ++i) {
			int pos = 0;
			while((pos = s.find(x[i], pos)) != -1) {
				string t = s.substr(0, pos) + y[i] + s.substr(pos + x[i].size());
				++pos;
				
				if(!dist.count(t)) {
					q.push(t);
					dist[t] = dist[s] + 1;
					if(t == b) return dist[t];
				}
			}
		}
	}
	return -1;
}

int main() {
	cin >> a >> b;
	while(cin >> x[n] >> y[n]) ++n;
	
	int ret = bfs();
	if(ret != -1) cout << ret << endl;
	else cout << "NO ANSWER!" << endl;
	
	return 0;
}




// dfs --- 有几个样例WA
//#include<iostream>
//#include<unordered_map>
//using namespace std;
//
//const int INF = 0x3f3f3f3f;
//string a, b, c, d;
//unordered_map<string, string> mp;
//int ret;
//
//void dfs(string& s, int step) {
//	if(s == b) {
//		ret = min(ret, step);
//		return;
//	}
//	if(step > 10) return;
//	
//	for(auto& [x, y]: mp) {
//		int pos = s.find(x);
//		if(pos != -1) {
//			int n = x.size();
//			string t = s.substr(0, pos) + y + s.substr(pos + n);
//			dfs(t, step + 1);
//		}
//	}
//	
//	//	int n = s.size();
//	//	for(int i=0; i<n; ++i) {
//	//		for(int j=i; j<n; ++j) {
//	//			string tmp = s.substr(i, j - i + 1);
//	//			if(mp.count(tmp)) {
//	//				string t = s.substr(0, i) + mp[tmp] + s.substr(j + 1, n - j - 1);
//	//				dfs(t, step + 1);
//	//			}
//	//		}
//	//	}
//}
//
//int main() {
//	cin >> a >> b;
//	while(cin >> c >> d) {
//		mp[c] = d;
//	}
//	
//	ret = INF;
//	dfs(a, 0);
//	
//	if(ret <= 10) cout << ret << endl;
//	else cout << "NO ANSWER!" << endl;
//	
//	return 0;
//}
