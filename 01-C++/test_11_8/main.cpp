#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

const int N = 110;
struct p
{
	string s;
	int y, m, d;
	int id;
}a[N];

int n;

int main()
{
	cin >> n;
	for(int i=0; i<n; ++i)
	{
		cin >> a[i].s >> a[i].y >> a[i].m >> a[i].d;
		a[i].id = i;
	}
	sort(a, a + n, [](const p& p1, const p& p2){
		if(p1.y != p2.y) return p1.y < p2.y;
		else if(p1.m != p2.m) return p1.m < p2.m;
		else if(p1.d != p2.d) return p1.d < p2.d;
		else return p1.id > p2.id;
	});
	for(int i=0; i<n; ++i) cout << a[i].s << endl;
	return 0;
}

//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//const int N = 310;
//struct stu
//{
//	int id;
//	int c;
//	int s;
//}a[N];
//
//int n, c, m, e;
//
//int main()
//{
//	cin >> n;
//	for(int i=0; i<n; ++i)
//	{
//		cin >> c >> m >> e;
//		a[i].id = i + 1;
//		a[i].c = c;
//		a[i].s = c + m + e;
//	}
//	sort(a, a + n, [](stu& s1, stu& s2){
//		return s1.s > s2.s
//			|| (s1.s == s2.s && s1.c > s2.c)
//			|| (s1.s == s2.s && s1.c == s2.c && s1.id < s2.id);
//	});
//	for(int i=0; i<5; ++i) cout << a[i].id << " " << a[i].s << endl;
//	return 0;
//}

//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//const int N = 60;
//int a[N];
//int n, s;
//
//int main()
//{
//	cin >> n;
//	for(int i=0; i<n; ++i) cin >> a[i];
//	sort(a, a + n, [](int x, int y){
//		return x > y;
//	});
//	for(int i=0; i<5; ++i) cout << a[i] << " ";
//	return 0;
//}

//#include<iostream>
//#include<string>
//#include<algorithm>
//using namespace std;
//
//struct stu
//{
//	int score;
//	string name;
//}a[110];
//
//int n, score;
//string name;
//
//int main()
//{
//	cin >> n;
//	for(int i=0; i<n; ++i)
//	{
//		cin >> a[i].score >> a[i].name;
//	}
//	sort(a, a + n, [](const stu& s1, const stu& s2){
//		return s1.score > s2.score;
//	});
//	cout << a[0].name;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//struct stu
//{
//	int n;
//	int s1;
//	int s2;
//	
//	stu(int n, int s1, int s2)
//		: n(n)
//		, s1(s1)
//		, s2(s2)
//	{}
//	
//	bool isExcellent()
//	{
//		return s1 + s2 > 140
//		&& 7 * s1 + 3 * s2 >= 800;
//	}
//};
//
//int main()
//{
//	int t;
//	cin >> t;
//	int n, s1, s2;
//	while(t--)
//	{
//		cin >> n >> s1 >> s2;
//		if(stu(n, s1, s2).isExcellent())
//			cout << "Excellent";
//		else cout << "Not excellent";
//		cout << endl;
//	}
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class Time
//{
//public:
//	Time(int h = 0, int m = 0)
//		: _h(h)
//		, _m(m)
//	{}
//	
//	bool operator<(const Time& t)
//	{
//		return _h < t._h || (_h == t._h && _m < t._m);
//	}
//
//	void show()
//	{
//		cout << _h << " " << _m << endl;
//	}
//private:
//	int _h;
//	int _m;
//};
//
//int main()
//{
//	int h, m;
//	cin >> h >> m;
//	Time t1(h, m);
//    Time t2(6, 6);
//    if(t1 < t2) cout << "yes";
//	else cout << "no";
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class Time
//{
//public:
//	Time(int h = 0, int m = 0)
//		: _h(h)
//		, _m(m)
//	{}
//	
//	Time operator+(const Time& t)
//	{
//		int h = _h + t._h;
//		int m = _m + t._m;
//		h += m / 60;
//		m %= 60;
//		return Time(h, m);
//	}
//	
//	void show()
//	{
//		cout << _h << " " << _m << endl;
//	}
//private:
//	int _h;
//	int _m;
//};
//
//int main()
//{
//	int h, m;
//	cin >> h >> m;
//	Time t1(h, m);
//    Time t2(2, 20);
//    Time t3 = t1 + t2;
//    t3.show();
//	return 0;
//}

//#include<iostream>
//#include<string>
//using namespace std;
//
//int n, m;
//string s;
//string t = "0123456789ABCDEF";
//
//void f(int x)
//{
//	if(x >= m) f(x / m);
//	cout << t[x % m];
//}
//
//int main()
//{
//	cin >> n >> s >> m;
//	int x = stoi(s, nullptr, n);
//	f(x);
//	return 0;
//}

//#include<iostream>
//#include<string>
//using namespace std;
//
//int x;
//string s;
//
//int main()
//{
//	cin >> x >> s;
//	cout << stoi(s, nullptr, x);
//	return 0;
//}

//int main()
//{
//	cin >> x >> s;
//	int ret = 0;
//	for(char ch : s)
//	{
//		ret *= x;
//		if(isdigit(ch)) ret += ch - '0';
//		else ret += ch - 'A' + 10;
//	}
//	cout << ret;
//	return 0;
//}

//#include<iostream>
//#include<string>
//#include<algorithm>
//using namespace std;
//
//string s = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//string t;
//
//int main()
//{
//	int n, x;
//	cin >> n >> x;
//	while(n)
//	{
//		t += s[n % x];
//		n /= x;
//	}
//	reverse(t.begin(), t.end());
//	cout << t;
//}
