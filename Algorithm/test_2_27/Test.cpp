#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int a[N], b[N], c[N];
int la, lb, lc;

void add() {
	for(int i=0; i<lc; ++i) {
		c[i] += a[i] + b[i];
		c[i + 1] = c[i] / 10;
		c[i] %= 10;
	}
	
	if(c[lc]) ++lc;
}

int main() {
	string x, y; cin >> x >> y;

	la = x.size(), lb = y.size(), lc = max(la, lb);
	for(int i=0; i<la; ++i) a[la - i - 1] = x[i] - '0';
	for(int i=0; i<lb; ++i) b[lb - i - 1] = y[i] - '0';

	add();

	for(int i=lc-1; i>=0; --i) cout << c[i];
	return 0;
}

/*#include <algorithm>*/
/*#include <iostream>*/
/*using namespace std;*/
/**/
/*int main() {*/
/*	string A, B, C;*/
/*	cin >> A >> B;*/
/**/
/*	int end1 = A.size() - 1, end2 = B.size() - 1;*/
/*	int a = 0, b = 0, carry = 0;*/
/*	while(end1 >= 0 || end2 >= 0) {*/
/*		a = end1 >= 0 ? A[end1--] - '0' : 0;*/
/*		b = end2 >= 0 ? B[end2--] - '0' : 0;*/
/*		carry += a + b;*/
/*		C += (carry % 10) + '0';*/
/*		carry /= 10;*/
/*	}*/
/*	if(carry) C += '1';*/
/**/
/*	reverse(C.begin(), C.end());*/
/*	cout << C;*/
/**/
/*	return 0;*/
/*}*/









/*#include <cctype>*/
/*#include <iostream>*/
/*#include <algorithm>*/
/*using namespace std;*/
/**/
/*int p1, p2, p3;*/
/*string s, t;*/
/**/
/*bool check(char right) {*/
/*	if(s.empty()) return false;*/
/*	char left = t.back();*/
/*	if(isalpha(left) && isalpha(right) && left < right) {*/
/*		return true;*/
/*	}*/
/*	else if(isdigit(left) && isdigit(right) && left < right) {*/
/*		return true;*/
/*	}*/
/*	return false;*/
/*}*/
/**/
/*int main() {*/
/*	cin >> p1 >> p2 >> p3;*/
/*	cin >> s;*/
/*	for(int i=0; i<s.size(); ++i) {*/
/*		if(s[i] != '-') t += s[i];*/
/*		else {*/
/*			if(i + 1 < s.size() && check(s[i + 1])) {*/
/*				string tmp;*/
/*				for(char ch=t.back()+1; ch<s[i + 1]; ++ch) {*/
/*					for(int j=0; j<p2; ++j) {*/
/*						if(isalpha(ch)) {*/
/*							if(p1 == 1) {*/
/*								tmp += tolower(ch);*/
/*							}*/
/*							else if(p1 == 2) {*/
/*								tmp += toupper(ch);*/
/*							}*/
/*							else {*/
/*								tmp += '*';*/
/*							}*/
/*						}*/
/*						else {*/
/*							if(p1 == 1 || p1 == 2) {*/
/*								tmp += ch;*/
/*							}*/
/*							else {*/
/*								tmp += '*';*/
/*							}*/
/*						}*/
/*					}*/
/*				}*/
/**/
/*				if(p3 == 2) {*/
/*					reverse(tmp.begin(), tmp.end());*/
/*				}*/
/*				t += tmp;*/
/*			}*/
/*			else t += s[i];*/
/*		}*/
/*	}*/
/*	cout << t;*/
/*	return 0;*/
/*}*/
