#include<iostream>
#include<cstring>
using namespace std;

const int N = 1110;
char s[N];
int cnt[26];

int main()
{
	cin >> s;
	int len = strlen(s);
	for(int i=0; i<len; ++i) ++cnt[s[i] - 'a'];
	for(int i=0; i<len; ++i)
	{
		if(cnt[s[i] - 'a'] == 1)
		{
			cout << s[i];
			return 0;
		}
	}
 	cout << "no";
	return 0;
}

//#include<iostream>
//#include<cstring>
//using namespace std;
//
//const int N = 50;
//char s[N], s1[N], s2[N];
//int pi[N];
//
//bool Search(char* p, char* t)
//{
//	memset(s, 0, sizeof s);
//	memset(pi, 0, sizeof pi);
//	
//	int m = strlen(p), n = strlen(t);
//	strcpy(s, p);
//	s[m] = '#';
//	strcat(s, t);
//	
//	int k = m + n + 1;
//	for(int i=1; i<k; ++i)
//	{
//		int len = pi[i-1];
//		while(len && s[i] != s[len]) len = pi[len-1];
//		if(s[i] == s[len])
//		{
//			pi[i] = len + 1;
//			if(pi[i] == m) return true;
//		}
//	}
//	return false;
//}
//
//int main()
//{
//	scanf("%s%s", s1, s2);
//	if(Search(s1, s2)) printf("%s is substring of %s", s1, s2);
//	else if(Search(s2, s1)) printf("%s is substring of %s", s2, s1);
//	else printf("No substring");
//	return 0;
//}

//#include<iostream>
//#include<cstring>
//using namespace std;
//
//const int N = 110;
//char a[N], b[N];
//
//int main()
//{
//	scanf("%s", a);
//	int len = strlen(a);
//	for(int i=0; i<len; ++i)
//	{
//		b[i] = a[i] + a[(i+1)%len];
//	}
//	printf("%s", b);
//	return 0;
//}

//#include<iostream>
//#include<cstring>
//using namespace std;
//
//const int N = 510;
//char a[N];
//double k;
//char ch;
//
//int main()
//{
//	scanf("%lf%s", &k, a);
//	getchar();//读取换行符，清空缓存
//	int i = 0, cnt = 0;
//	while((ch = getchar()) != '\n')
//	{
//		if(ch == a[i]) ++cnt;
//		++i;
//	}
//	
//	if(cnt >= k * strlen(a)) printf("yes");
//	else printf("no");
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//int n;
//char ch;
//
//int main()
//{
//	cin >> n;
//	getchar();//读取换行符，清空缓存
//	while(n--)
//	{
//		ch = getchar();
//		putchar(toupper(ch));
//		while((ch = getchar()) != '\n')
//		{
//			putchar(tolower(ch));
//		}
//		cout << endl;
//	}
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//char ch;
//
//int main()
//{
//	int cnt = 0;
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
//char ch;
//
//int main()
//{
//	while((ch = getchar()) != '\n')
//	{
//		putchar(toupper(ch));
//	}
//	return 0;
//}

//#include<iostream>
//#include<unordered_set>
//using namespace std;
//
//const int N = 10;
//int a[N];
//int n, x;
//
//int main()
//{
//	cin >> n;
//	unordered_set<int> hash;
//	for(int i=0; i<7; ++i)
//	{
//		cin >> x;
//		hash.insert(x);
//	}
//	
//	while(n--)
//	{
//		int cnt = 0;
//		for(int i=0; i<7; ++i)
//		{
//			cin >> x;
//			if(hash.count(x)) ++cnt;
//		}
//		++a[cnt];
//	}
//	
//	for(int i=7; i>=1; --i)
//	{
//		cout << a[i] << " ";
//	}
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//const int N = 110;
//int a[N][N], b[N][N];
//int n, m;
//int dx[] = {1, -1, 0, 0, 0};
//int dy[] = {0, 0, 1, -1, 0};
//
//int main()
//{
//	cin >> n >> m;
//	for(int i=0; i<n; ++i)
//	{
//		for(int j=0; j<m; ++j)
//		{
//			cin >> a[i][j];
//			b[i][j] = a[i][j];
//		}
//	}
//	
//	for(int i=1; i<n-1; ++i)
//	{
//		for(int j=1; j<m-1; ++j)
//		{
//			int sum = 0;
//			for(int k=0; k<5; ++k)
//			{
//				int x = i + dx[k], y = j + dy[k];
//				sum += a[x][y];
//			}
//			b[i][j] = sum / 5.0 + 0.5;//四舍五入
//		}
//	}
//	
//	for(int i=0; i<n; ++i)
//	{
//		for(int j=0; j<m; ++j)
//		{
//			cout << b[i][j] << " ";
//		}
//		cout << endl;
//	}
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//int m, n, x, sum;
//
//int main()
//{
//	cin >> m >> n;
//	for(int i=1; i<=m; ++i)
//	{
//		for(int j=1; j<=n; ++j)
//		{
//			cin >> x;
//			if(i == 1 || j == 1 || i == m || j == n)
//			{
//				sum += x;
//			}
//		}
//	}
//	cout << sum;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//const int N = 110;
//int a[N][N];
//int n, m;
//
//int main()
//{
//	cin >> n >> m;
//	for(int j=0; j<n; ++j)
//	{
//		for(int i=0; i<m; ++i)
//		{
//			cin >> a[i][j];
//		}
//	}
//	
//	for(int i=0; i<m; ++i)
//	{
//		for(int j=0; j<n; ++j)
//		{
//			cout << a[i][j] << " ";
//		}
//		cout << endl;
//	}
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//const int N = 110;
//int a[N][N];
//int n, m, tmp;
//
//int main()
//{
//	cin >> n >> m;
//	for(int i=0; i<n; ++i)
//	{
//		for(int j=0; j<m; ++j)
//		{
//			cin >> a[i][j];
//		}
//	}
//	
//	for(int i=0; i<n; ++i)
//	{
//		for(int j=0; j<m; ++j)
//		{
//			cin >> tmp;
//			cout << a[i][j] + tmp << " ";
//		}
//		cout << endl;
//	}
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//const int N = 110;
//bool a[N][N];
//int m, n;
//bool tmp;
//
//int main()
//{
//	cin >> m >> n;
//	for(int i=0; i<m; ++i)
//	{
//		for(int j=0; j<n; ++j)
//		{
//			cin >> a[i][j];
//		}
//	}
//	
//	int cnt = 0;
//	for(int i=0; i<m; ++i)
//	{
//		for(int j=0; j<n; ++j)
//		{
//			cin >> tmp;
//			if(a[i][j] == tmp) ++cnt;
//		}
//	}
//	
//	printf("%.2lf", cnt * 100.0 / (m * n));
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//const int N = 10;
//int a[N][N];
//int m, n;
//
//int main()
//{
//	for(int i=1; i<=5; ++i)
//	{
//		for(int j=1; j<=5; ++j)
//		{
//			cin >> a[i][j];
//		}
//	}
//	
//	cin >> m >> n;
//	for(int j=1; j<=5; ++j)
//	{
//		swap(a[m][j], a[n][j]);
//	}
//	
//	for(int i=1; i<=5; ++i)
//	{
//		for(int j=1; j<=5; ++j)
//		{
//			cout << a[i][j] << " ";
//		}
//		cout << endl;
//	}
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//const int N = 30;
//int a[N][N];
//int n;
//
//int main()
//{
//	cin >> n;
//	for(int i=0; i<n; ++i) a[i][0] = 1;
//	for(int i=1; i<n; ++i)
//	{
//		for(int j=1; j<=i; ++j)
//		{
//			a[i][j] = a[i-1][j-1] + a[i-1][j];
//		}
//	}
//	for(int i=0; i<n; ++i)
//	{
//		for(int j=0; j<=i; ++j)
//		{
//			cout << a[i][j] << " ";
//		}
//		cout << endl;
//	}
//	return 0;
//}
