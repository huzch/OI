#include <cstdlib>
#include <ctime>
#include <iostream>
#include <utility>
using namespace std;

const int N = 1e5 + 10;
int a[N], n;
int tmp[N];

void InsertSort() {
	for(int i=2; i<=n; ++i) {
		int t = a[i];
		int j = i - 1;
		while(j >= 1) {
			if(a[j] > t) {
				a[j + 1] = a[j];
				--j;
			}
			else break;
		}
		a[j + 1] = t;
	}
}

void SelectSort() {
	for(int i=1; i<n; ++i) {
		int p = i;
		for(int j=i+1; j<=n; ++j) {
			if(a[j] < a[p]) {
				p = j;
			}
		}
		swap(a[i], a[p]);
	}
}

void BubbleSort() {
	for(int i=n; i>1; --i) {
		bool flag = false;
		for(int j=1; j<i; ++j) {
			if(a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]);
				flag = true;
			}
		}
		if(!flag) break;
	}
}

void down(int parent, int n) {
	int child = parent * 2;
	while(child <= n) {
		if(child + 1 <= n && a[child] < a[child + 1]) {
			++child;
		}

		if(a[parent] < a[child]) {
			swap(a[parent], a[child]);
			parent = child;
			child = parent * 2;
		}
		else break;
	}
}

void HeapSort() {
	for(int i=n/2; i>=1; --i) {
		down(i, n);
	}

	for(int i=n; i>1; --i) {
		swap(a[1], a[i]);
		down(1, i - 1);
	}
}

int GetKey(int l, int r) {
	return a[rand() % (r - l + 1) + l];
}

void QuickSort(int begin, int end) {
	if(begin >= end) return;

	int key = GetKey(begin, end);

	int l = begin - 1, i = begin, r = end + 1;
	while(i < r) {
		if(a[i] < key) swap(a[++l], a[i++]);
		else if(a[i] > key) swap(a[--r], a[i]);
		else ++i;
	}

	QuickSort(begin, l);
	QuickSort(r, end);
}

void MergeSort(int begin, int end) {
	if(begin == end) return;

	int mid = (begin + end) >> 1;
	MergeSort(begin, mid);
	MergeSort(mid + 1, end);

	int l = begin, r = mid + 1, i = begin;
	while(l <= mid && r <= end) {
		if(a[l] < a[r]) {
			tmp[i++] = a[l++];
		}
		else {
			tmp[i++] = a[r++];
		}
	}

	while(l <= mid) tmp[i++] = a[l++];
	while(r <= end) tmp[i++] = a[r++];
	for(int j=begin; j<=end; ++j) a[j] = tmp[j];
}

int main() {
	cin >> n;
	for(int i=1; i<=n; ++i) cin >> a[i];

	// InsertSort();

	// SelectSort();
	
	// BubbleSort();
	
	// HeapSort();
	
	// srand(time(0));
	// QuickSort(1, n);

	MergeSort(1, n);

	for(int i=1; i<=n; ++i) cout << a[i] << " ";
	cout << endl;

	return 0;
}
