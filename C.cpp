#include <bits/stdc++.h>
using namespace std;
#define ll long long

// if any # if a range in m(i) is missing (l,r), yes
// then for each two digits, go through each combination of digits and see if
// the leftmost occurence of digit i occurs to the right of the leftmost digit j

/*
0111110010000111100101
10
0010100000
1110111100
*/
void testcase() {
	map<int,int> leftmost;
	map<int,int> rightmost;
	string s; cin >> s;
	int m; cin >> m;
	string l, r; cin >> l >> r;
	int n = s.length();
	for (int i = n - 1; i >= 0; i--) leftmost[s[i]-'0'] = i;
	for (int i = 0; i < n; i++) rightmost[s[i]-'0'] = i;
	for (int i = 0; i < m - 1; i++) {
		int left1 = l[i] - '0', right1 = r[i] - '0';
		int left2 = l[i+1] - '0', right2 = r[i+1] - '0';
		for (int i = left1; i <= right1; i++) {
			for (int j = left2; j <= right2; j++) {
				if (leftmost.find(i) == leftmost.end() || leftmost.find(j) == leftmost.end() || leftmost[i] >= rightmost[j]) {
					cout << "YES" << endl;
					return;
				}
			}
		}
	}
	cout << "NO" << endl;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int tc = 1; 
	cin >> tc;
	while(tc--) testcase();
	return 0;
}
