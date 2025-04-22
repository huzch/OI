#include<iostream>
#include<cstring>
using namespace std;

const int N = 110;
int f[N][N];
int n, m;

int main() {
    cin >> n >> m;
    //初始化
    memset(f, 0x3f, sizeof f);
    for(int i=1; i<=n; ++i) f[i][i] = 0;

    for(int i=1; i<=m; ++i) {
        int u, v, w; cin >> u >> v >> w;
        f[u][v] = f[v][u] = min(f[u][v], w); //重边
    }

    for(int k=1; k<=n; ++k) {
        for(int i=1; i<=n; ++i) {
            for(int j=1; j<=n; ++j) {
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            }
        }
    }

    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=n; ++j) {
            cout << f[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}