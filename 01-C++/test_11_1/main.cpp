#include<iostream>
using namespace std;

int a1, a2, n;
int main()
{
	cin >> a1 >> a2 >> n;
	int d = a2 - a1;
	cout << a1 + (n - 1) * d;
	return 0;
}

//int a, b, c;
//int main()
//{
//	cin >> a >> b >> c;
////	if((a < 60 && b >= 60 && c >= 60)
////	 ||(a >= 60 && b < 60 && c >= 60)
////	 ||(a >= 60 && b >= 60 && c < 60))
////	{
////		cout << 1;
////	}
//	if((a < 60) + (b < 60) + (c < 60) == 1)
//	{
//		cout << 1;
//	}
//	else cout << 0;
//	return 0;
//}

//int n;
//int main()
//{
//	cin >> n;
//	if(n % 2 == 0) cout << "even";
//	else cout << "odd";
//	return 0;
//}

//double d;
//int main()
//{
//	scanf("%lf", &d);
//	printf("%.2lf", fabs(d));
//	return 0;
//}

//const double e = 1e-16;
//double d;
//int main()
//{
//	scanf("%lf", &d);
//	if(d - e > 0) printf("%.2lf", d);
//	else printf("%.2lf", -d);
//	return 0;
//}

//long long x, y;
//int main()
//{
//	cin >> x >> y;
//	if(x > y) cout << ">";
//	else if(x == y) cout << "=";
//	else cout << "<";
//	return 0;
//}

//int m, n;
//int main()
//{
//	cin >> m >> n;
//	if(m % n == 0) cout << "YES";
//	else cout << "NO";
//	return 0;
//}

//int main()
//{
//	int n;
//	cin >> n;
//	if(n > 0) cout << "positive";
//	else if(n == 0) cout << "zero";
//	else cout << "negative";
//	return 0;
//}

//double a, b, c;
//int main()
//{
//	scanf("%lf%lf%lf", &a, &b, &c);
//	double p = (a + b + c) * 0.5;
//	double s = sqrt(p*(p-a)*(p-b)*(p-c));
//	printf("%.1lf", s);
//	return 0;
//}

//char a, b, c, d;
//int main()
//{
//	scanf("%c%c%c.%c", &a, &b, &c, &d);
//	printf("%c.%c%c%c", d, c, b, a);
//	return 0;
//}

//double d;
//int main()
//{
//	cin >> d;
//	int n = d * 10;
//	cout << n % 10 << '.';
//	n /= 10;
//	cout << n % 10;
//	n /= 10;
//	cout << n % 10;
//	n /= 10;
//	cout << n % 10;
//	return 0;
//}

//int a[5];
//int main()
//{
//	for(int i=0; i<5; ++i) scanf("%d", &a[i]);
//	for(int i=0; i<5; ++i)
//	{
//		a[i] /= 3;
//		a[(i+1)%5] += a[i];
//		a[(i+4)%5] += a[i];
//	}
//	for(int i=0; i<5; ++i) printf("%5d", a[i]);
//	return 0;
//}

//int a, b, c;
//int main()
//{
//	scanf("%d%d%d", &a, &b, &c);
//	printf("%8d %8d %8d", a, b, c);
//	return 0;
//}

//const double PI = 3.14159;
//double r;
//int main()
//{
//	scanf("%lf", &r);
//	printf("%.4lf %.4lf %.4lf", 2*r, 2*PI*r, PI*r*r);
//	return 0;
//}

//double r1, r2;
//int main()
//{
//	scanf("%lf%lf", &r1, &r2);
//	double r = 1/(1/r1+1/r2);
//	printf("%.2lf", r);
//	return 0;
//}

//double f;
//int main()
//{
//	scanf("%lf", &f);
//	printf("%.5lf", 5*(f-32)/9);
//	return 0;
//}

//int a, b;
//int main()
//{
//	scanf("%d%d", &a, &b);
//	printf("%.3lf%%", (double)b / a * 100);
//	return 0;
//}

//int a, b;
//int main()
//{
//	scanf("%d%d", &a, &b);
//	printf("%.3f", (float)a/b);
//	return 0;
//}

//char ch;
//int main()
//{
//	cin >> ch;
//	cout << (int)ch;
//	return 0;
//}

//double x;
//int main()
//{
//	cin >> x;
//	cout << (long long)x;
//	return 0;
//}

//int a, b, c;
//int main()
//{
//	cin >> a >> b >> c;
//	int s = a * 0.2 + b * 0.3 + c * 0.5;
//	cout << s;
//	return 0;
//}
