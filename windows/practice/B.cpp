#include <bits/stdc++.h>
using namespace std;
 
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int tc = 1; 
	cin >> tc;
	for (int tt = 0; tt < tc; tt++) {
		int n, k; cin >> n >> k;
		if ((k == 1 and n > 1) or (k == n and n > 1)) {
			cout << -1 << endl;
		} else {
			set<int> borders;
			if (n == 1) borders.insert(1);
			else {
				if (k & 1) {
					borders.insert(k);
					borders.insert(k - 1);
					borders.insert(k + 1);
					borders.insert(1);
					if (k + 2 <= n) borders.insert(k + 2);
				} else {
					borders.insert(k);
					borders.insert(1);
					borders.insert(k + 1);
				}
			}
			cout << borders.size() << endl;
			for (int i : borders) cout << i << ' ';
			cout << endl;
		}

	}
}