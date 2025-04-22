#include<iostream>
#include<vector>
#include<queue>
#include<functional>
using namespace std;

typedef long long LL;
priority_queue<LL, vector<LL>, greater<LL>> hp;

int main() {
    int n; cin >> n;
    for(int i=1; i<=n; ++i) {
        LL x; cin >> x;
        hp.push(x);
    }
    
    LL ret = 0;
    while(hp.size() >= 2) {
        LL x = hp.top(); hp.pop();
        LL y = hp.top(); hp.pop();
        ret += x + y;
        hp.push(x + y);
    }
    cout << ret << endl;
    
    return 0;
}
