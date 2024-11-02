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
		sort(a.begin(), a.end());
		long long lo = 0, hi = 1e18;
		long long x = INT_MAX;
		while (lo <= hi) {
			long long m = (hi + lo) / 2;
			double avg = 0;
			a[n - 1] += m;
			for (int i = 0; i < n; i++) avg += (double) a[i];
			avg /= (double) n;
			int unhappy = 0;
			for (double i : a) if (i < avg / 2.0) unhappy++;
			a[n - 1] -= m;
			if (unhappy > n / 2) { x = m, hi = m - 1; }
			else lo = m + 1;
		}
		cout << (x == INT_MAX ? -1 : x) << endl; 
	}
}
