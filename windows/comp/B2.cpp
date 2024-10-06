#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int tc = 1; 
	cin >> tc;
	while (tc--) {
        int n, m, q; cin >> n >> m >> q;
		int mx = -INT_MAX, mn = INT_MAX;
		vector<int> B(m);
		for (int& i : B) cin >> i, mx = max(mx, i), mn = min(mn, i);
		sort(B.begin(), B.end());
		for (int i = 0; i < q; i++) {
			int p; cin >> p;
			if (p < mn) {
				cout << mn - 1 << endl;
			} else if (p > mx) {
				cout << n - mx << endl;
			} else {
				auto it = upper_bound(B.begin(), B.end(), p);
				if (it != B.begin()) it--;
				int lw = *it;
				int hw = *upper_bound(B.begin(), B.end(), p);
				cout << (hw - lw) / 2 << endl;
			}
		}
    }
}
