#include<iostream>
#include<cmath>
using namespace std;

const int N = 30;
int a[N];
int n;

int main()
{
	cin >> n;
	for(int i=0; i<n; ++i) cin >> a[i];
	for(int i=0; i<n-1; ++i)
	{
		bool flag = false;
		for(int j=0; j<n-1-i; ++j)
		{
			if(a[j] < a[j+1])
			{
				swap(a[j], a[j+1]);
				flag = true;
			}
		}
		
		if(!flag) break;
	}
	for(int i=0; i<n; ++i) cout << a[i] << endl;
	return 0;
}

//const int N = 1e2 + 10;
//int a[N];
//int n;
//
//int main()
//{
//	cin >> n;
//	for(int i=0; i<n; ++i) cin >> a[i];
//	for(int i=0; i<n; ++i)
//	{
//		int cnt = 0;
//		for(int j=0; j<i; ++j)
//		{
//			if(a[j] < a[i]) ++cnt;
//		}
//		cout << cnt << " ";
//	}
//	return 0;
//}

//const int N = 5e3 + 10;
//bool a[N];
//int n;
//
//int main()
//{
//	cin >> n;
//	for(int i=2; i<=n; ++i)
//	{
//		for(int j=1; j<=n; ++j)
//		{
//			if(j % i == 0) a[j] = !a[j];
//		}
//	}
//	
//	for(int i=1; i<=n; ++i)
//	{
//		if(!a[i]) cout << i << " ";
//	}
//	return 0;
//}

//int n, x;
//int a, b, c, d;
//
//int main()
//{
//	scanf("%d", &n);
//	for(int i=0; i<n; ++i)
//	{
//		scanf("%d", &x);
//		if(x <= 18) ++a;
//		else if(x >= 19 && x <= 35) ++b;
//		else if(x >= 36 && x <= 60) ++c;
//		else ++d;
//	}
//	
//	printf("%.2lf%%\n", a * 100.0 / n);
//	printf("%.2lf%%\n", b * 100.0 / n);
//	printf("%.2lf%%\n", c * 100.0 / n);
//	printf("%.2lf%%\n", d * 100.0 / n);
//	return 0;
//}

//const int N = 1e3 + 10;
//int a[N], b[N];
//int n, ret;
//
//int main()
//{
//	cin >> n;
//	for(int i=0; i<n; ++i) cin >> a[i];
//	for(int i=0; i<n; ++i) cin >> b[i];
//	for(int i=0; i<n; ++i) ret += a[i] * b[i];
//	cout << ret;
//	return 0;
//}


//const int N = 1e2 + 10;
//int a[N];
//int n;
//
//int main()
//{
//	cin >> n;
//	for(int i=0; i<n; ++i)
//	{
//		cin >> a[i];
//	}
//	
//	for(int i=n-1; i>=0; --i)
//	{
//		cout << a[i] << " ";
//	}
//	return 0;
//}

//const int N = 1e5 + 10;
//int a[N];
//int n, x;
//
//int main()
//{
//	cin >> n;
//	for(int i=0; i<n; ++i)
//	{
//		cin >> a[i];
//	}
//	
//	cin >> x;
//	for(int i=0; i<n; ++i)
//	{
//		if(a[i] == x)
//		{
//			cout << i;
//			return 0;
//		}
//	}
//	cout << -1;
//	return 0;
//}

//int n;
//int main()
//{
//	cin >> n;
//	int cnt = 0, tmp = n;
//	while(tmp)
//	{
//		tmp /= 10;
//		++cnt;
//	}
//	
//	int ret = 0, tmp = n;
//	while(tmp)
//	{
//		ret += pow(tmp % 10, cnt);
//		tmp /= 10;
//	}
//	
//	if(ret == n) cout << "YES";
//	else cout << "NO";
//	return 0;
//}

//int main()
//{
//	for(int i=1; i<=9; ++i)
//	{
//		for(int j=0; j<=9; ++j)
//		{
//			for(int k=0; k<=9; ++k)
//			{
//				double a = pow(i,3) + pow(j,3) + pow(k,3);
//				double b = i * 100 + j * 10 + k;
//				if(a == b) cout << a << endl;
//			}
//		}
//	}
//	return 0;
//}

//int n;
//int main()
//{
//	cin >> n;
//	int count = 1;
//	if(count == n)
//	{
//		cout << 2;//唯一的偶质数 
//		return 0;
//	}
//	
//	for(int i=3;;i+=2)
//	{
//		bool flag = true;
//		for(int j=2; j<=sqrt(i); ++j)
//		{
//			if(i % j == 0)
//			{
//				flag = false;
//				break;
//			}
//		}
//		
//		if(flag)
//		{
//			++count;
//			if(count == n)
//			{
//				cout << i;
//				break;
//			}
//		}
//	}
//	return 0;
//}

//int a, b, f;
//char c;
//
//int main()
//{
//	cin >> a >> b >> c >> f;
//	for(int i=0; i<a; ++i)
//	{
//		for(int j=0; j<b; ++j)
//		{
//			if(i == 0 || i == a-1 || j == 0 || j == b-1)
//			{
//				cout << c;
//			}
//			else
//			{
//				if(f == 1) cout << c;
//				else cout << ' ';
//			}
//		}
//		cout << endl;
//	}
//	return 0;
//}

//int n;
//
//int main()
//{
//	cin >> n;
//	for(int i=0; i<n; ++i)
//	{
//		for(int j=0; j<=i; ++j)
//		{
//			cout << '*';
//		}
//		cout << endl;
//	}
//	return 0;
//}

//int n;
//
//int main()
//{
//	scanf("%d", &n);
//	double e = 1.0;
//	long long x = 1;
//	for(int i=1; i<=n; ++i)
//	{
//		x *= i;
//		e += 1.0 / x;
//	}
//	printf("%.10lf", e);
//	return 0;
//}

//int n, a;
//int main()
//{
//	cin >> n;
//	while(n--)
//	{
//		cin >> a;
//		int x = 1, y = 1, z = 1;
//		for(int i=2; i<a; ++i)
//		{
//			z = x + y;
//			x = y;
//			y = z;
//		}
//		cout << z << endl;
//	}
//	return 0;
//}

//int main()
//{
//	int count = 0;
//	for(int i=1; i<=2019; ++i)
//	{
//		int n = i;
//		while(n)
//		{
//			if(n % 10 == 9)
//			{
//				++count;
//				break;
//			}
//			n /= 10;
//		}
//	}
//	cout << count;
//	return 0;
//}

//int main()
//{
//	for(int i=1; i<=9; ++i)
//	{
//		for(int j=1; j<=i; ++j)
//		{
//			printf("%d*%d=%2d ", j, i, i * j);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//int main()
//{
//	int n;
//	cin >> n;
//	for(int i=n-1; i>=2; --i)
//	{
//		if(n % i == 0)
//		{
//			cout << i;
//			break;
//		}
//	}
//	return 0;
//}

//double h, sum;
//
//int main()
//{
//	cin >> h;
//	for(int i=0; i<10; ++i)
//	{
//		sum += 1.5 * h;
//		h /= 2;
//	}
//	cout << sum - h << endl << h;
//}

//int n;
//double ret;
//
//int main()
//{
//	scanf("%d", &n);
//	double p = 1, q = 2;
//	for(int i=0; i<n; ++i)
//	{
//		ret += q / p;
//		int tmp = p;
//		p = q;
//		q = q + tmp;
//	}
//	printf("%.4lf", ret);
//}

//int n;
//double ret;
//
//int main()
//{
//	scanf("%d", &n);
//	int flag = 1;
//	for(int i=1; i<=n; ++i)
//	{
//		ret += 1.0 * flag / i;
//		flag = -flag;
//	}
//	printf("%.4lf", ret);
//	return 0;
//}

//long long n, p;
//double ret, x, y;
//
//int main()
//{
//	cin >> n;
//	for(int i=0; i<n; ++i)
//	{
//		cin >> x >> y >> p;
//		ret += sqrt(x * x + y * y) / 25 + p * 1.5;
//	}
//	cout << (int)ceil(ret);
//	return 0;
//}

//int n, a, b;
//
//int main()
//{
//	cin >> n >> a >> b;
//	double x = b * 1.0 / a;
//	for(int i=0; i<n-1; ++i)
//	{
//		cin >> a >> b;
//		double y = b * 1.0 / a;
//		if(y - x > 0.05) cout << "better" << endl;
//		else if(x - y > 0.05) cout << "worse" << endl;
//		else cout << "same" << endl;
//	}
//	return 0;
//}

//int n, x, y, z, sum;
//int a[3];
//int main()
//{
//	cin >> n;
//	for(int i=0; i<n; ++i)
//	{
//		cin >> x >> y >> z;
//		a[0] += x, a[1] += y, a[2] += z;
//	}
//	
//	for(int i=0; i<3; ++i)
//	{
//		cout << a[i] << " ";
//		sum += a[i];
//	}
//	cout << sum;
//	return 0;
//}

//int n, tmp;
//double ret;
//int main()
//{
//	scanf("%d", &n);
//	for(int i=0; i<n; ++i)
//	{
//		cin >> tmp;
//		ret += tmp;
//	}
//	printf("%.2lf", ret / n);
//	return 0;
//}

//int main()
//{
//	int sum = 0;
//	for(int i=3; i<=100; i+=3)
//	{
//		sum += i;
//	}
//	cout << sum;
//	return 0;
//}

//double x, ret;
//int n;
//
//int main()
//{
//	scanf("%lf%d", &x, &n);
//	ret = (1 - pow(x, n + 1)) / (1 - x);
//	printf("%.2lf", ret);
//	return 0;
//}

//long long n;
//int main()
//{
//	scanf("%lld", &n);
//	while(n > 1)
//	{
//		if(n % 2 == 1)
//		{
//			printf("%lld*3+1=%lld\n", n, n * 3 + 1);
//			n = n * 3 + 1;
//		}
//		else
//		{
//			printf("%lld/2=%lld\n", n, n / 2);
//			n = n / 2;
//		}
//	}
//	printf("End");
//	return 0;
//}

//char ch;
//int count, k;
//int main()
//{
//	while((ch = getchar()) != ' ')
//	{
//		if(ch == '3') ++count;
//	}
//	
//	cin >> k;
//	if(count == k) cout << "YES";
//	else cout << "NO";
//	return 0;
//}

//long long n, sum;
//int main()
//{
//	cin >> n;
//	for(int i=1; i<=n; ++i)
//	{
//		sum += i;
//	}
//	cout << sum;
//	return 0;
//}

//long long n, sum;
//int main()
//{
//	cin >> n;
//	while(n)
//	{
//		sum += n % 10;
//		n /= 10;
//	}
//	cout << sum;
//	return 0;
//}

//int main()
//{
//	char a, b, c, d;
//	cin >> a >> b >> c >> d;
//	cout << d << c << b << a;
//	return 0;
//}

//int a, b;
//char op;
//int main()
//{
//	cin >> a >> b >> op;
//	if(op == '+') cout << a + b;
//	else if(op == '-') cout << a - b;
//	else if(op == '*') cout << a * b;
//	else if(op == '/')
//	{
//		if(b != 0) cout << a / b;
//		else cout << "Divided by zero!";
//	}
//	else cout << "Invalid operator!";
//	return 0;
//}

//int n;
//int main()
//{
//	cin >> n;
//	int month = n % 100;
//	switch(month)
//	{
//	case 3:
//	case 4:
//	case 5:
//		cout << "spring";
//		break;
//	case 6:
//	case 7:
//	case 8:
//		cout << "summer";
//		break;
//	case 9:
//	case 10:
//	case 11:
//		cout << "autumn";
//		break;
//	case 12:
//	case 1:
//	case 2:
//		cout << "winter";
//		break;
//	}
//	return 0;
//}

//int main()
//{
//	int x;
//	cin >> x;
//	int ret = 0;
//	if(x % 2 == 0) ret += 1;
//	if(x > 4 && x <= 12) ret += 2;
//	
//	if(ret == 0) cout << "0 0 0 1";
//	else if(ret == 3) cout << "1 1 0 0";
//	else cout << "0 1 1 0";
//	return 0;
//}

//int main()
//{
//	int x;
//	cin >> x;
//	if(x % 3 == 0) cout << "3 ";
//	if(x % 5 == 0) cout << "5 ";
//	if(x % 7 == 0) cout << "7 ";
//	if(x % 3 && x % 5 && x % 7) cout << "n";
//	return 0;
//}

//int a, b, c;
//int main()
//{
//	cin >> a >> b >> c;
//	if(a + b > c && a + c > b && b + c > a) cout << 1;
//	else cout << 0;
//	return 0;
//}

//int n;
//int main()
//{
//	cin >> n;
//	if(n == 1 || n == 3 || n == 5) cout << "NO";
//	else cout << "YES";
//	return 0;
//}

//int main()
//{
//	int y;
//	cin >> y;
//	if((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) cout << 1;
//	else cout << 0;
//	return 0;
//}

//int m, t, s;
//int main()
//{
//	cin >> m >> t >> s;
//	if(t == 0) cout << 0;
//	else
//	{
//		int ret = m - ceil((double)s / t);
//		if(ret > 0) cout << ret;
//		else cout << 0;
//	}
//	return 0;
//}

//long long x, y;
//int main()
//{
//	cin >> x >> y;
//	if(y % x == 0) cout << y + x;
//	else cout << y - x;
//	return 0;
//}

//int a, b, c;
//int main()
//{
//	cin >> a >> b >> c;
//	cout << max(a, max(b, c));
//	return 0;
//}
