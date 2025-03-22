#include <cctype>
#include <iostream>
#include <algorithm>
using namespace std;

int p1, p2, p3;
string s, t;

bool check(char right) {
	if(s.empty()) return false;
	char left = t.back();
	if(isalpha(left) && isalpha(right) && left < right) {
		return true;
	}
	else if(isdigit(left) && isdigit(right) && left < right) {
		return true;
	}
	return false;
}

int main() {
	cin >> p1 >> p2 >> p3;
	cin >> s;
	for(int i=0; i<s.size(); ++i) {
		if(s[i] != '-') t += s[i];
		else {
			if(i + 1 < s.size() && check(s[i + 1])) {
				string tmp;
				for(char ch=t.back()+1; ch<s[i + 1]; ++ch) {
					for(int j=0; j<p2; ++j) {
						if(isalpha(ch)) {
							if(p1 == 1) {
								tmp += tolower(ch);
							}
							else if(p1 == 2) {
								tmp += toupper(ch);
							}
							else {
								tmp += '*';
							}
						}
						else {
							if(p1 == 1 || p1 == 2) {
								tmp += ch;
							}
							else {
								tmp += '*';
							}
						}
					}
				}

				if(p3 == 2) {
					reverse(tmp.begin(), tmp.end());
				}
				t += tmp;
			}
			else t += s[i];
		}
	}
	cout << t;
	return 0;
}
