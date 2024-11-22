#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	long long tc = 1; 
	cin >> tc;
	for (long long tt = 0; tt < tc; tt++) {
		int n, k; cin >> n >> k;
		vector<long long> a(n + 1);
		for (int i = 0; i < n; i++) cin >> a[i];
		long long g = 0;
		for (int i = 0; i < n; i++) g = __gcd(a[i], g);
		if (n != 1) for (int i = 0; i < n; i++) a[i] = i * g;
		long long lst = -1;
		a[n] = 1e16;
		for (int i = 0; i <= n; i++) {
			if (k <= a[i] - lst - 1) break;
			k -= max(a[i] - lst - 1, (long long) 0);
			lst = a[i];
		}
		cout << lst + k << endl;
	}
}
