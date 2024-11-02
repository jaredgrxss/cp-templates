#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int tc = 1; 
	cin >> tc;
	for (int tt = 0; tt < tc; tt++) {
		int n; cin >> n;
		vector<int> a(n);
		int mx = -INT_MAX;
		for (int& i : a) cin >> i, mx = max(mx, i);
		long long lo = 0, hi = 1e9;
		int x = INT_MAX;
		while (lo <= hi) {
			long long m = (lo + hi) / 2;
			long long sm = m, avg = 0;
			for (int i = 0; i < n; i++) sm += a[i];
			avg = sm / n;
			int unhappy = 0;
			for (int i : A) {
				if (i < avg) unhappy++;
			}
			if (unhappy > n / 2) { x = m, hi = m - 1; }
			else lo = m + 1;
		}
		cout << (x == INT_MAX ? -1 : x) << endl; 
	}
}
