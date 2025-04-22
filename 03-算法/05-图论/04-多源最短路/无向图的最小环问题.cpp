#include<iostream>
#include<cstring>
using namespace std;

const int INF = 1e8;
const int N = 110;
int f[N][N];
int e[N][N];
int n, m;

int main() {
    cin >> n >> m;

    // memset(f, 0x3f, sizeof f);
    // memset(e, 0x3f, sizeof e);
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=n; ++j) {
            f[i][j] = e[i][j] = INF;
        }
    }
    for(int i=1; i<=n; ++i) f[i][i] = e[i][i] = 0;
    for(int i=1; i<=m; ++i) {
        int u, v, d; cin >> u >> v >> d;
        f[u][v] = f[v][u] = e[u][v] = e[v][u] = min(f[u][v], d);
    }

    int ret = INF;
    for(int k=1; k<=n; ++k) {
        //统计编号为k最大时的最小环
        for(int i=1; i<k; ++i) {
            for(int j=i+1; j<k; ++j) {
                ret = min(ret, f[i][j] + e[i][k] + e[k][j]); //这里使用0x3f3f3f3f会溢出，所以换成1e8
            }
        }

        for(int i=1; i<=n; ++i) {
            for(int j=1; j<=n; ++j) {
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            }
        }
    }
    
    if(ret == INF) cout << "No solution." << endl;
    else cout << ret << endl;

    return 0;
}