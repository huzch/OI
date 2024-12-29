// #include <iostream>
// using namespace std;
//
// const int N = 1e6 + 10;
// int ne[N], h;
// int n;
//
// void print() {
// 	for(int i=h; i; i=ne[i]) {
// 		cout << i << " ";
// 	}
// 	cout << endl;
// }
//
// int main() {
// 	cin >> n;
// 	for(int i=1; i<=n; ++i) {
// 		cin >> ne[i];
// 	}
// 	cin >> h;
//
// 	print();
// 	return 0;
// }



//
// #include <iostream>
// using namespace std;
//
// const int N = 1e5 + 10, M = 1e6 + 10;
// int e[N], ne[N], h, id;
// int mp[M];
// int q, op, x, y;
//
// void insert(int p, int y) {
// 	e[++id] = y;
// 	mp[y] = id;
// 	ne[id] = ne[p];
// 	ne[p] = id;
// }
//
// void erase(int p) {
// 	if(ne[p]) {
// 		ne[p] = ne[ne[p]];
// 	}
// }
//
// int main() {
// 	cin >> q;
// 	insert(0, 1);
// 	while(q--) {
// 		cin >> op >> x;
// 		int p = mp[x];
// 		if(op == 1) {
// 			cin >> y;
// 			insert(p, y);
// 		}
// 		else if(op == 2) {
// 			cout << e[ne[p]] << endl;
// 		}
// 		else if(op == 3) {
// 			erase(p);
// 		}
// 	}
// 	return 0;
// }



// #include <iostream>
// using namespace std;
//
// const int N = 1e5 + 10;
// int e[N], ne[N], pre[N], h, id;
// int mp[N];
//
// void insert_front(int p, int x) {
// 	e[++id] = x;
// 	mp[x] = id;
//
// 	ne[id] = p;
// 	pre[id] = pre[p];
// 	ne[pre[p]] = id;
// 	pre[p] = id;
// }
//
// void insert_back(int p, int x) {
// 	e[++id] = x;
// 	mp[x] = id;
//
// 	ne[id] = ne[p];
// 	pre[id] = p;
// 	pre[ne[p]] = id;
// 	ne[p] = id;
// }
//
// void erase(int p) {
// 	mp[e[p]] = 0;
// 	ne[pre[p]] = ne[p];
// 	if(ne[p]) pre[ne[p]] = pre[p];
// }
//
// int main() {
// 	int n; cin >> n;
// 	insert_back(0, 1);
// 	for(int i=2; i<=n; ++i) {
// 		int k, op;
// 		cin >> k >> op;
// 		int p = mp[k];
// 		if(op == 0) {
// 			insert_front(p, i);
// 		}
// 		else if(op == 1) {
// 			insert_back(p, i);
// 		}
// 	}
//
// 	int m; cin >> m;
// 	for(int i=1; i<=m; ++i) {
// 		int x; cin >> x;
// 		int p = mp[x];
// 		if(p) erase(p);
// 	}
//
// 	for(int i=ne[h]; i; i=ne[i]) {
// 		cout << e[i] << " ";
// 	}
// 	cout << endl;
// 	return 0;
// }








// #include <iostream>
// using namespace std;
//
// const int N = 110;
// int ne[N], h, id;
//
// void insert(int p) {
// 	ne[++id] = ne[p];
// 	ne[p] = id;
// }
//
// void erase(int p) {
// 	if(ne[p]) {
// 		ne[p] = ne[ne[p]];
// 	}
// 	else {
// 		ne[h] = ne[ne[h]];
// 	}
// }
//
// int main() {
// 	int n, m;
// 	cin >> n >> m;
// 	for(int i=1; i<=n; ++i) {
// 		insert(i - 1);
// 	}
//
// 	int cur = h;
// 	while(n) {
// 		//找到待删除元素的前驱结点
// 		for(int i=2; i<=m; ++i) {
// 			cur = ne[cur];
// 			if(cur == h) cur = ne[cur];
// 		}
//
// 		if(ne[cur] == h) {
// 			cout << ne[ne[cur]] << " ";
// 		}
// 		else {
// 			cout << ne[cur] << " ";
// 		}
// 		erase(cur);
// 		--n;
// 	}
// 	return 0;
// }
//



//
//
//
//
//
//
// #include <iostream>
// using namespace std;
//
// const int N = 110;
// int ne[N];
// int n, m;
//
// int main() {
// 	cin >> n >> m;
// 	for(int i=1; i<n; ++i) {
// 		ne[i] = i + 1;
// 	}
// 	ne[n] = 1;
//
// 	int t = n;
// 	for(int i=1; i<=n; ++i) {
// 		for(int j=1; j<m; ++j) {
// 			t = ne[t];
// 		}
// 		cout << ne[t] << " ";
//
// 		ne[t] = ne[ne[t]];
// 	}
// 	return 0;
// }







// #include <cstdio>
// #include <cstring>
// #include <iostream>
// using namespace std;
//
// typedef unsigned long long ll;
// const int N = 1e6 + 10;
// ll st[N], n;
//
// int main() {
// 	int t; cin >> t;
// 	while(t--) {
// 		n = 0;
//
// 		int p; cin >> p;
// 		while(p--) {
// 			string op; cin >> op;
// 			if(op == "push") {
// 				ll x; cin >> x;
// 				st[++n] = x;
// 			}
// 			else if(op == "pop") {
// 				if(n == 0) {
// 					cout << "Empty" << endl;
// 				}
// 				else {
// 					--n;
// 				}
// 			}
// 			else if(op == "query") {
// 				if(n == 0) {
// 					cout << "Anguei!" << endl;
// 				}
// 				else {
// 					cout << st[n] << endl;
// 				}
// 			}
// 			else if(op == "size") {
// 				cout << n << endl;
// 			}
// 		}
// 	}
// 	return 0;
// }
//



























