#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int tc = 1; 
	cin >> tc;
	while (tc--) {
        int n, m, q; cin >> n >> m >> q;
		int l, r; cin >> l >> r;
		for (int i = 0; i < q; i++) {
			int p; cin >> p;
			if (l < p and r < p) {
				cout << n - max(r, l) << endl;
			} else if (l > p and r > p) {
				cout << min(r, l) - 1 << endl;
			} else {
				cout << abs(r - l) / 2 << endl;
			}
		}
    }
}
