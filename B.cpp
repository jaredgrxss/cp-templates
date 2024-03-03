#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, k; cin >> n >> k;
	vector<int> arr(n), dist(n);
	for (int& i : arr) cin >> i; for (int& i : dist) cin >> i;
	map<int,int> m;
	for (int i = 0; i < n; i++) m[abs(dist[i])] += arr[i]; 
	long long left = 0; bool can = true;
	for (int i = 1; i <= n; i++) {
		left += k;
		if (m.find(i) != m.end()) {
			if (m[i] > left) { can = false; break; }
			left -= m[i];
		} 
	}
	if (can) cout << "YES" << endl;
	else cout << "NO" << endl; 
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int tc = 1; 
	cin >> tc;
	while (tc--) solve();
}
