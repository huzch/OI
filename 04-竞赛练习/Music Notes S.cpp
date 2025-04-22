//前缀和+二分查找 --- O(qlogn)
#include<iostream>
using namespace std;

const int N = 5e4 + 10;
int b[N];
int n, q;

int f[N];

int main() {
	cin >> n >> q;
	for(int i=1; i<=n; ++i) {
		cin >> b[i];
		f[i] = f[i - 1] + b[i];
	}

	while(q--) {
		int t; cin >> t;
		int l = 1, r = n;
		while(l < r) {
			int mid = l + (r - l) / 2;
			if(f[mid] > t) r = mid;
			else l = mid + 1;
		}
		cout << l << endl;
	}
	return 0;
}


//前缀和+线性查找 --- O(qn)
//#include<iostream>
//using namespace std;
//
//const int N = 5e4 + 10;
//int b[N];
//int n, q;
//
//int f[N];
//
//int main() {
//	cin >> n >> q;
//	for(int i=1; i<=n; ++i) {
//		cin >> b[i];
//		f[i] = f[i - 1] + b[i];
//	}
//	
//	while(q--) {
//		int t; cin >> t;
//		for(int i=1; i<=n; ++i) {
//			if(t < f[i]) {
//				cout << i << endl;
//				break;
//			}
//		}
//	}
//	return 0;
//}
