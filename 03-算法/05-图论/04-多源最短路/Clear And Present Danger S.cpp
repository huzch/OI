#include<iostream>
using namespace std;

const int N = 110;
const int M = 1e4 + 10;
int f[N][N];
int a[M];
int n, m;

int main() {
    cin >> n >> m;
    for(int i=1; i<=m; ++i) cin >> a[i];
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=n; ++j) {
            cin >> f[i][j];
        }
    }

    for(int k=1; k<=n; ++k) {
        for(int i=1; i<=n; ++i) {
            for(int j=1; j<=n; ++j) {
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            }
        }
    }

    int ret = 0;
    for(int i=1; i<=m; ++i) {
        int x = a[i - 1], y = a[i];
        ret += f[x][y];
    }
    cout << ret << endl;

    return 0;
}