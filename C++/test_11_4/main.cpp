#include<iostream>
using namespace std;

const int N = 30;
typedef long long ll;
ll a[N];
ll n, x, m;

int main()
{
	while(cin >> n)
	{
		for(int i=0; i<n; ++i) cin >> a[i];
		cin >> m;
		bool flag = false;
		for(int i=0; i<n; ++i)
		{
			if(a[i] == m)
			{
				cout << i << endl;
				flag = true;
				break;
			}
		}
		if(!flag) cout << "No" << endl;
	}
	return 0;
}

//#include<iostream>
//#include<string>
//using namespace std;
//
//string s, t;
//int q, l1, r1, l2, r2;
//
//int main()
//{
//	cin >> s >> t >> q;
//	while(q--)
//	{
//		cin >> l1 >> r1 >> l2 >> r2;
//		string subS = s.substr(l1-1, r1-l1+1);
//		string subT = t.substr(l2-1, r2-l2+1);
//		if(subS < subT) cout << "yifusuyi";
//		else if(subS > subT) cout << "erfusuer";
//		else cout << "ovo";
//		cout << endl;
//	}
//	
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int n;
//	while(cin >> n)
//	{
//		for(int i=1; i<=n; ++i)
//		{
//			for(int j=1; j<=i; ++j)
//			{
//				cout << j << " ";
//			}
//			cout << endl;
//		}
//	}
//}

//#include<iostream>
//using namespace std;
//
//int a, b;
//int main()
//{
//	while(cin >> a >> b)
//	{
//		cout << a + b << endl;
//	}
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//int n, a, b;
//int main()
//{
//	cin >> n;
//	while(n--)
//	{
//		cin >> a >> b;
//		cout << a + b << endl;
//	}
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//int n;
//int main()
//{
//	cin >> n;
//	int sum = 0;
//	for(int i=1; i<=n; ++i)
//	{
//		if(i % 7 == 0) continue;
//		
//		int tmp = i;
//		bool flag = true;
//		while(tmp)
//		{
//   			if(tmp % 10 == 7)
//   			{
//   				flag = false;
//   				break;
//			}
//			tmp /= 10;
//		}
//		if(flag) sum += i * i;
//	}
//	cout << sum;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//int a, b, c;
//int main()
//{
//	cin >> a >> b >> c;
//	cout << (a + b) / c;
//	return 0;
//}

//#include<iostream>
//#include<string>
//using namespace std;
//
//int t;
//char op;
//string n1, n2;
//
//string calc()
//{
//	int a = stoi(n1), b = stoi(n2), ret = 0;
//	if(op == '+') ret = a + b;
//	else if(op == '-') ret = a - b;
//	else if(op == '*') ret = a * b;
//	return to_string(ret);
//}
//
//int main()
//{
//	cin >> t;
//	while(t--)
//	{
//		string s;
//		cin >> s;
//		if(s[0] >= 'a' && s[0] <= 'c')
//		{
//			if(s[0] == 'a') op = '+';
//			else if(s[0] == 'b') op = '-';
//			else if(s[0] == 'c') op = '*';
//			cin >> n1 >> n2;
//		}
//		else
//		{
//			n1 = s;
//			cin >> n2;
//		}
//		
//		string ret = calc();
//		string t = n1 + op + n2 + '=' + ret;
//		cout << t << endl << t.size() << endl;
//	}
//	return 0;
//}

//#include<iostream>
//#include<string>
//using namespace std;
//
//string s;
//int a[26] = {1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4};
//
//int main()
//{
//	getline(cin, s);
//	int cnt = 0;
//	for(char ch : s)
//	{
//		if(ch == ' ') ++cnt;
//		else cnt += a[ch-'a'];
//	}
//	cout << cnt;
//	return 0;
//}

//#include<iostream>
//#include<string>
//using namespace std;
//
//string s;
//int a[126];
//
//int main()
//{
//	getline(cin, s);
//	
//	int k = 1;
//	for(char ch='a'; ch<='o'; ++ch)
//	{
//		a[ch] = k++;
//		if(k == 4) k = 1;
//	}
//	a['p'] = 1, a['q'] = 2, a['r'] = 3, a['s'] = 4;
//	a['t'] = 1, a['u'] = 2, a['v'] = 3, a[' '] = 1;
//	a['w'] = 1, a['x'] = 2, a['y'] = 3, a['z'] = 4;
//	
//	int cnt = 0;
//	for(char ch : s) cnt += a[ch];
//	cout << cnt;
//	
//	return 0;
//}

//#include<iostream>
//#include<string>
//#include<algorithm>
//using namespace std;
//
//string s, t;
//
//int main()
//{
//	getline(cin, s);
//	t = s;
//	reverse(t.begin(), t.end());
//	if(s == t) cout << "yes";
//	else cout << "no";
//	return 0;
//}

//#include<iostream>
//#include<string>
//#include<algorithm>
//using namespace std;
//
//string s;
//
//int main()
//{
//	while(cin >> s)
//	{
//		reverse(s.begin(), s.end());
//		cout << s << endl;
//	}
//	return 0;
//}

//#include<iostream>
//#include<string>
//using namespace std;
//
//string s;
//
//int main()
//{
//	cin >> s;
//	cout << s.size();
//	while(cin >> s)
//	{
//		cout << "," << s.size();
//	}
//	return 0;
//}

//#include<iostream>
//#include<string>
//using namespace std;
//
//int q, op;
//string s;
//
//int main()
//{
//	cin >> q >> s;
//	while(q--)
//	{
//		cin >> op;
//		if(op == 1)
//		{
//			string t;
//			cin >> t;
//			s += t;
//			cout << s << endl;
//		}
//		else if(op == 2)
//		{
//			int a, b;
//			cin >> a >> b;
//			s = s.substr(a, b);
//			cout << s << endl;
//		}
//		else if(op == 3)
//		{
//			int a;
//			string t;
//			cin >> a >> t;
//			s.insert(a, t);
//			cout << s << endl;
//		}
//		else if(op == 4)
//		{
//			string t;
//			cin >> t;
//			size_t pos = s.find(t);
//			if(pos == -1) cout << -1 << endl;
//			else cout << pos << endl;
//		}
//	}
//	return 0;
//}

//#include<iostream>
//#include<string>
//using namespace std;
//
//string s;
//
//int main()
//{
//	getline(cin, s);
//	int sz = s.size();
//	for(int i=0; i<sz; ++i)
//	{
//		char ch = s[i];
//		if(isalpha(ch))
//		{
//			if(ch == 'a' || ch == 'A') s[i] += 26;
//			--s[i];
//		}
//	}
//	cout << s;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//int ch;
//
//int main()
//{
//	while((ch = getchar()) != '\n')
//	{
//		if(isalpha(ch))
//		{
//			if(ch == 'a' || ch == 'A') ch += 26;
//			putchar(ch-1);
//		}
//		else putchar(ch);
//	}
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//string s1, s2;
//int n;
//
//int main()
//{
//	cin >> n;
//	while(n--)
//	{
//		cin >> s1 >> s2;
//		if(s1 == "Rock")
//		{
//			if(s2 == "Rock") cout << "Tie";
//			else if(s2 == "Scissors") cout << "Player1";
//			else cout << "Player2";
//		}
//		else if(s1 == "Scissors")
//		{
//			if(s2 == "Rock") cout << "Player2";
//			else if(s2 == "Scissors") cout << "Tie";
//			else cout << "Player1";
//		}
//		else
//		{
//			if(s2 == "Rock") cout << "Player1";
//			else if(s2 == "Scissors") cout << "Player2";
//			else cout << "Tie";
//		}
//		cout << endl;
//	}
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//char ch;
//int cnt;
//
//int main()
//{
//	while((ch = getchar()) != '\n')
//	{
//		if(isalnum(ch)) ++cnt;
//	}
//	printf("%d", cnt);
//	return 0;
//}

//#include <iostream>
//#include <string>
//#include <cstring>
//#include <chrono>
//#include <random>
//
//// 生成一个包含大量重复字符的长字符串
//std::string generate_large_string(size_t length, const std::string& pattern) {
//    std::string result;
//    result.reserve(length);
//    while (result.size() + pattern.size() <= length) {
//        result += pattern;
//    }
//    result.resize(length, 'A'); // 填充剩余部分
//    return result;
//}
//
//void test_strstr(const char* haystack, const char* needle, int iterations) {
//    auto start = std::chrono::high_resolution_clock::now();
//    for (int i = 0; i < iterations; ++i) {
//        const char* result = strstr(haystack, needle);
//    }
//    auto end = std::chrono::high_resolution_clock::now();
//    std::chrono::duration<double> duration = end - start;
//    std::cout << "strstr time: " << duration.count() << " seconds" << std::endl;
//}
//
//void test_string_find(const std::string& haystack, const std::string& needle, int iterations) {
//    auto start = std::chrono::high_resolution_clock::now();
//    for (int i = 0; i < iterations; ++i) {
//        size_t result = haystack.find(needle);
//    }
//    auto end = std::chrono::high_resolution_clock::now();
//    std::chrono::duration<double> duration = end - start;
//    std::cout << "string::find time: " << duration.count() << " seconds" << std::endl;
//}
//
//int main() {
//    const size_t large_size = 10000000000; // 生成一个1千万字符的字符串
//    const std::string pattern = "This is a test pattern."; // 待查找的子串
//    std::string haystack_str = generate_large_string(large_size, pattern);
//    std::string needle_str = "pattern";
//
//    // C 风格的字符串表示
//    const char* haystack = haystack_str.c_str();
//    const char* needle = needle_str.c_str();
//
//    const int iterations = 100000000; // 重复查找的次数，模拟高负载
//
//    // 压力测试
//    test_strstr(haystack, needle, iterations);
//    test_string_find(haystack_str, needle_str, iterations);
//
//    return 0;
//}

