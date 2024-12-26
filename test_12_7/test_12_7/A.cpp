//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int main() {
//	int n, k;
//	cin >> n >> k;
//	string s = "";
//	while (k > 0) {
//		char ch = k % 2 + '0';
//		s = ch + s;
//		k /= 2;
//	}
//	int max = 0;
//	for (int i = 0; i < n; ++i) {
//		if (s[i] == '1') {
//			max++;
//		}
//	}
//
//	cout << max << endl;
//	return 0;
//}

//#include<iostream>
//#include<string>
//using namespace std;
//
//int main()
//{
//	int n;
//	string s;
//	cin >> n >> s;
//
//	int cnt = 0;
//	string t = "SYSU";
//	for (int i = 0; i < n; ++i)
//	{
//		int j = i % 4;
//		if (s[i] != t[j]) ++cnt;
//	}
//	cout << cnt << endl;
//	return 0;
//}