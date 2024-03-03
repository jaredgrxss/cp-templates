#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;
	vector<int> arr(n);
	int fdx = n, ldx = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i]) { fdx = min(fdx, i); ldx = max(ldx, i);}
	}
	int ans = 0;
	for (int i = fdx; i <= ldx; i++) {
		if (!arr[i]) ans++;
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int tc = 1; 
	cin >> tc;
	while (tc--) solve();
}
