#include <bits/stdc++.h>
using namespace std;


vector<int> dsu;
int find(int v) {
	if (dsu[v] == v) return v;
	return dsu[v] = find(dsu[v]);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int tc = 1; 
	// cin >> tc;
	for (int tt = 0; tt < tc; tt++) {
		int n, m; 
		cin >> n >> m;
		dsu.resize(n + 4);
		vector<int> ans(n + 4);
		for (int i = 1; i <= n + 3; i++) dsu[i] = i;
		for (int i = 0; i < m; i++) {
			int l, r, x; cin >> l >> r >> x;
			int cur = find(l);
			while (cur <= r) {
				if (cur == x) cur++;
				else {
					ans[cur] = x;
					dsu[cur] = cur + 1;
				}
				cur = find(cur);
			}
		}
		for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
		cout << endl;
	}
}
