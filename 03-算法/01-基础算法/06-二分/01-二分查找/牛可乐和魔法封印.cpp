#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e5 + 10;
int a[N];

int main() {
    int n; cin >> n;
    for (int i=1; i<=n; i++) {
       cin >> a[i]; 
    }
    
    int q; cin >> q;
    while(q--) {
        int x, y; cin >> x >> y;
        int s = 0;
        
        //左边界二分
        int l = 1, r = n;
        while(l < r) {
            int mid = l + (r - l) / 2;
            if(a[mid] >= x) r = mid;
            else l = mid + 1;
        }
        //检查结果
        if(a[l] < x) {
            cout << 0 << endl;
            continue;
        }
        s = l;
        
        //右边界二分
        l = 1, r = n;
        while(l < r) {
            int mid = l + (r - l + 1) / 2;
            if(a[mid] <= y) l = mid;
            else r = mid - 1;
        }
        //检查结果
        if(a[l] > y) {
            cout << 0 << endl;
            continue;
        }
        
        cout << l - s + 1 << endl;
    }
    return 0;
}
