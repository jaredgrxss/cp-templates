#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int tc = 1; 
	cin >> tc;
	for (int tt = 0; tt < tc; tt++) {
		int n; cin >> n;
		vector<int> a(n), b(n);
		vector<vector<int>> ones(2, vector<int>(n + 1));
		for (int& i : a) cin >> i;
		for (int& i : b) cin >> i;
		ones[0][0] = (a[0] == 1) ? 1 : 0, ones[1][0] = (b[0] == 1) ? 1 : 0;
		for (int i = 1; i < n; i++) {
			ones[0][i] = (a[i] == 1) ? 1 + ones[0][i - 1] : ones[0][i - 1];
			ones[1][i] = (b[i] == 1) ? 1 + ones[1][i - 1] : ones[1][i - 1];
		}
		int mv1 = 0, mv2 = 0;
		for (int i = 0; i < n; i++) {
			int f = a[i], s = b[i];
			if ((f == 0 and s <= 0) or (s == 0 and f <= 0)) { continue; }
			else if (f == 1 and s != 1) mv1++;
			else if (f != 1 and s == 1) mv2++;
			else if (f == -1 and s == -1 and mv1 > mv2) mv1--;
			else if (f == -1 and s == -1 and mv2 > mv1) mv2--;
			else if (f == 1 and s == 1 and mv1 > mv2) mv2++; 
			else if (f == 1 and s == 1 and mv2 > mv1) mv1++;
			else {
				int fones = ones[0][n - 1] - ones[0][i];
				int sones = ones[1][n - 1] - ones[1][i];
				if (f == 1 and s == 1 and fones < sones) mv1++;
				else if (f == 1 and s == 1 and sones <= fones) mv2++;
				else if (f == -1 and s == -1 and fones < sones) mv2--;
				else if (f == -1 and s == -1 and sones <= fones) mv1--;
			}
		}
		cout << min(mv1, mv2) << endl;
	}
}
