#include<iostream>
#include<string>
using namespace std;

int x, m;

//string f(int x)
//{
//	string s;
//	if(x % m >= 10) s = (char)('A' + (x % m) - 10);
//	else s = to_string(x % m);
//	
//	if(x < m) return s;
//	return f(x / m) + s;
//}
string s = "0123456789ABCDEF";

void f(int x)
{
	if(x >= m) f(x / m);
	cout << s[x % m];
}

int main()
{
	cin >> x >> m;
	f(x);
	return 0;
}

//#include<iostream>
//using namespace std;
//
//double f(double x, double n)
//{
//	if(n == 1) return x / (1 + x);
//	return x / (n + f(x, n - 1));
//}
//
//int main()
//{
//	double x, n;
//	cin >> x >> n;
//	printf("%.2lf", f(x, n));
//	return 0;
//}

//#include<iostream>
//#include<cmath>
//using namespace std;
//
//double f(double x, double n)
//{
//	if(n == 1) return sqrt(1 + x);
//	return sqrt(n + f(x, n - 1));
//}
//
//int main()
//{
//	double x, n;
//	cin >> x >> n;
//	printf("%.2lf", f(x, n));
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//int digit(int n, int k)
//{
//	if(k == 1) return n % 10;
//	return digit(n / 10, k - 1);
//}
//
//int main()
//{
//	int n, k;
//	cin >> n >> k;
//	cout << digit(n, k);
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//int A(int m, int n)
//{
//	if(m == 0) return n + 1;
//	if(n == 0) return A(m - 1, 1);
//	return A(m - 1, A(m, n - 1));
//}
//
//int main()
//{
//	int m, n;
//	cin >> m >> n;
//	cout << A(m, n);
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//int Sum(int n)
//{
//	if(n == 1) return 1;
//	return n + Sum(n - 1);
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//	cout << Sum(n);
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//int fact(int n)
//{
//	if(n == 0) return 1;
//	return n * fact(n - 1);
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//	cout << fact(n);
//}

//#include<iostream>
//#include<string>
//#include<algorithm>
//#include<cmath>
//using namespace std;
//
//bool check(int n)
//{
//	if(n == 1) return false;
//	for(int i=2; i<=sqrt(n); ++i)
//	{
//		if(n % i == 0) return false;
//	}
//	return true;
//}
//
//int main()
//{
//	int m, n;
//	scanf("%d%d", &m, &n);
//	bool first = true;
//	for(int i=m; i<=n; ++i)
//	{
//		int j = 0, tmp = i;
//		while(tmp)
//		{
//			j = j * 10 + tmp % 10;
//			tmp /= 10;
//		}
//		if(check(i) && check(j))
//		{
//			if(first)
//			{
//				printf("%d", i);
//				first = false;
//			}
//			else printf(",%d", i);
//		}
//	}
//	if(first) printf("No");
//	return 0;
//}

//#include<iostream>
//#include<string>
//#include<algorithm>
//#include<cmath>
//using namespace std;
//
//bool check(int n)
//{
//	for(int i=2; i<=sqrt(n); ++i)
//	{
//		if(n % i == 0) return false;
//	}
//	return true;
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//	int cnt = 0;
//	for(int i=11; i<=n; ++i)
//	{
//		string s = to_string(i), t = s;
//		reverse(s.begin(), s.end());
//		if(s == t && check(i)) ++cnt;
//	}
//	cout << cnt;
//	return 0;
//}

//#include<iostream>
//#include<cmath>
//using namespace std;
//
//int main()
//{
//	int n;
//	cin >> n;
//	int prev = 2;
//	bool empty = true;
//	for(int i=3; i<=n; i+=2)
//	{
//		bool is_prime = true;
//		for(int j=2; j<=sqrt(i); ++j)
//		{
//			if(i % j == 0)
//			{
//				is_prime = false;
//				break;
//			}
//		}
//		if(is_prime)
//		{
//			if(i - prev == 2)
//			{
//				cout << prev << " " << i << endl;
//				empty = false;
//			}
//			prev = i;
//		}
//	}
//	if(empty) cout << "empty";
//	return 0;
//}

//#include<iostream>
//#include<cmath>
//using namespace std;
//
//int main()
//{
//	int n;
//	cin >> n;
//	int cnt = 1;
//	for(int i=3; i<=n; i+=2)
//	{
//		bool is_prime = true;
//		for(int j=2; j<=sqrt(i); ++j)
//		{
//			if(i % j == 0)
//			{
//				is_prime = false;
//				break;
//			}
//		}
//		if(is_prime) ++cnt;
//	}
//	cout << cnt;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//int n;
//string name;
//float t;
//bool flag;
//
//int main()
//{
//	cin >> n;
//	int cnt = 0;
//	while(n--)
//	{
//		cin >> name >> t >> flag;
//		if(flag && t >= 37.5)
//		{
//			cout << name << endl;
//			++cnt;
//		}
//	}
//	cout << cnt;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int n;
//	cin >> n;
//	for(int i=2; i<=n; ++i)
//	{
//		int sum = 0;
//		for(int j=1; j<i; ++j)
//		{
//			if(i % j == 0) sum += j;
//		}
//		if(sum == i) cout << i << endl;
//	}
//	return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<algorithm>
//using namespace std;
//
//const int INF = 0x3f3f3f3f;
//int n, m, x;
//
//int main()
//{
//	scanf("%d%d", &n, &m);
//	double ret = -INF;
//	while(n--)
//	{
//		int sum = 0, high = -INF, low = INF;
//		for(int i=0; i<m; ++i)
//		{
//			scanf("%d", &x);
//			high = max(high, x);
//			low = min(low, x);
//			sum += x;
//		}
//		double tmp = (sum - high - low) * 1.0 / (m - 2);
//		ret = max(ret, tmp);
//	}
//	printf("%.2lf", ret);
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//const int INF = 0x3f3f3f3f;
//int n, x;
//int high = -INF, low = INF;
//
//int main()
//{
//	cin >> n;
//	while(n--)
//	{
//		cin >> x;
//		high = max(high, x);
//		low = min(low, x);
//	}
//	cout << high - low;
//	return 0;
//}

//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//double a, b, c, m;
//
//double Max(double x, double y, double z)
//{
//	return max(x, max(y, z));
//}
//
//int main()
//{
//	cin >> a >> b >> c;
//	double tmp = Max(a + b, b, c) * Max(b + c, a, b);
//	m = Max(a, b, c) / tmp;
//	printf("%.3lf", m);
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//int a, b;
//char op;
//
//int main()
//{
//	cin >> a >> op >> b;
//	if(op == '+') cout << a + b;
//	else if(op == '-') cout << a - b;
//	else if(op == '*') cout << a * b;
//	else if(op == '/') cout << a / b;
//	else if(op == '%') cout << a % b;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//int t, x;
//int main()
//{
//	scanf("%d", &t);
//	while(t--)
//	{
//		scanf("%d", &x);
//		int ret = 0;
//		while(x)
//		{
//			int n = x, cnt = 0;
//			while(n)
//			{
//				n &= n - 1;
//				++cnt;
//			}
//
//			if(cnt % 2 == 1)
//			{
//				if(x & 1 == 1) x &= ~1;
//				else x |= 1;
//			}
//			else
//			{
//				int i = 31;
//				for(; i>=0; --i)
//				{
//					if((x >> i) & 1 == 1) break;
//				}
//				x &= ~(1 << i);
//			}
//			++ret;
//		}
//		printf("%d\n", ret);
//	}
//}

//#include<iostream>
//using namespace std;
//
//int t, x;
//int main()
//{
//	cin >> t;
//	while(t--)
//	{
//		cin >> x;
//		int ret = 0;
//		while(x)
//		{
//			int n = x, cnt = 0;
//			while(n)
//			{
//				n &= n - 1;
//				++cnt;
//			}
//			
//			if(cnt % 2 == 1)
//			{
//				if(x & 1 == 1) x &= ~1;
//				else x |= 1;
//			}
//			else
//			{
//				int i = 31;
//				for(; i>=0; --i)
//				{
//					if((x >> i) & 1 == 1) break;
//				}
//				x &= ~(1 << i);
//			}
//			++ret;
//		}
//		cout << ret << endl;
//	}
//}

//#include<iostream>
//#include<string>
//using namespace std;
//
//string s;
//int main()
//{
//	cin >> s;
//	for(char& ch : s)
//	{
//		int num = ch - '0';
//		if(num % 2 == 0) ch = '0';
//		else ch = '1';
//	}
//	cout << stoi(s);
////	size_t pos = s.find('1');
////	if(pos != -1) cout << s.substr(pos);
////	else cout << 0;
//	return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<cctype>
//using namespace std;
//
//char ch;
//int cnt;
//
//int main()
//{
//	while((ch = getchar()) != '\n')
//	{
//		if(isdigit(ch)) ++cnt;
//	}
//	cout << cnt;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//int a, b;
//int main()
//{
//	while(cin >> a >> b && (a || b))
//	{
//		cout << a + b << endl;
//	}
//	return 0;
//}
