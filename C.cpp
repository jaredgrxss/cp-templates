#include <bits/stdc++.h>
using namespace std;

/*

	Jared's CP Template

*/

void solve() {
	int n, q; cin >> n >> q;
	vector<int> arr(n);
	for (int& i : arr) cin >> i;

	vector<long long> ones(n), psum(n); 
	ones[0] = (arr[0] == 1) ? 1 : 0; psum[0] = arr[0];
	for (int i = 1; i < n; i++) {
		ones[i] = (arr[i] == 1) ? 1 + ones[i - 1] : ones[i - 1];
		psum[i] = arr[i] + psum[i - 1];
	}
	for (int i = 0; i < q; i++) {
		int l, r; cin >> l >> r;
		long long one = (l == 1) ? ones[r - 1] : ones[r - 1] - ones[l - 2];
		one--;
		long long sm = (l == 1) ? psum[r - 1] : psum[r - 1] - psum[l - 2];
		long long mx = sm - ((r - l) + 1);
		if (mx - one < 1 || (r - l) + 1 == 1) {
			cout << "NO" << endl;
		} else {
			cout << "YES" << endl;
		}

	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int tc = 1; 
	cin >> tc;
	while (tc--) solve();
}
