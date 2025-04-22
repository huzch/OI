#include<iostream>
#include<cstring>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 210;
int f[N][N];
int t[N];
int n, m, q;

void floyd(int k) {
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=n; ++j) {
            f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i=1; i<=n; ++i) cin >> t[i];

    memset(f, 0x3f, sizeof f);
    for(int i=1; i<=n; ++i) f[i][i] = 0;
    for(int i=1; i<=m; ++i) {
        int u, v, w; cin >> u >> v >> w;
        ++u, ++v; //映射下标从1开始
        f[u][v] = f[v][u] = min(f[u][v], w);
    }

    cin >> q;
    int pos = 1;
    while(q--) {
        int u, v, time; cin >> u >> v >> time; //最重要的题眼：time不下降，这才可以利用floyd分步求解的特性
        ++u, ++v; //映射下标从1开始
        while(pos <= n && t[pos] <= time) floyd(pos++);

        if(t[u] > time || t[v] > time || f[u][v] == INF) cout << -1 << endl;
        else cout << f[u][v] << endl;
    }

    return 0;
}