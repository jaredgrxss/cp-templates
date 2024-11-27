#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int tc = 1; 
	cin >> tc;
	for (int tt = 0; tt < tc; tt++) {
		int n; cin >> n;
		vector<long long> a(n);
		for (long long& i : a) cin >> i;
		int can = 1;
		for (int i = 1; i < n; i++) {
			if (a[i] == 1 and a[i - 1] > 1) can = 0;
		}
		if (!can) {
			cout << -1 << endl;
		} else {
			vector<long long> ops(n);
			for (int i = 1; i < n; i++) {
				long long v = a[i - 1], v2 = a[i];
				while (sqrt(v2) >= v and v2 != 1) { v2 = sqrt(v2); ops[i]++; }
				ops[i] = -ops[i];
			}
			// for (int i = 0; i < n; i++) cout << ops[i] << ' ';
			// cout << endl;
			for (int i = 1; i < n; i++) {
				long long v = a[i - 1], v2 = a[i];
				if (ops[i - 1] >= 0 and v2 < v) ops[i] += ops[i - 1];
				else if (v2 >= v) ops[i] += ops[i - 1];
				while (v2 < v) { v2 *= v2; ops[i]++; }
			}
			// for (int i = 0; i < n; i++) cout << ops[i] << ' ';
			// cout << endl;
			long long answer = 0;
			for (int i : ops) answer += (i > 0) ? i : 0;
			cout << answer << endl;
		}
	}
}
