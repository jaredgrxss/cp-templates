#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int tc = 1; 
	cin >> tc;
	for (int t = 0; t < tc; t++) {
		int n, k; cin >> n >> k;
		vector<int> a(n);
		vector<int> b(n);
		for (int& i : a) cin >> i;
		for (int& i : b) cin >> i;
		vector<int> mx1;
		vector<int> mx2;
		vector<int> mn1;
		vector<int> mn2;
		vector<vector<int>> dp;
		mx1.assign(n + 1, -INF); mx2.assign(n + 1, -INF);
		mn1.assign(n + 1, INF); mn2.assign(n + 1, INF);
		dp.assign(n + 1, vector<int>(k + 1, 0));
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= min(i, k); j++) {
				if (i != 0) dp[i][j] = dp[i - 1][j];
				int dv = i - j;
				if (i != 0) {
					dp[i][j] = max(dp[i][j], b[i - 1] + a[i - 1] - mn1[dv]);
					dp[i][j] = max(dp[i][j], -b[i - 1] - a[i - 1] + mx1[dv]);
					dp[i][j] = max(dp[i][j], a[i - 1] - b[i - 1] - mn2[dv]);
					dp[i][j] = max(dp[i][j], b[i - 1] - a[i - 1] + mx2[dv]);
				}
				if (i != n) {
					mn1[dv] = min(mn1[dv], b[i] + a[i] - dp[i][j]);
					mx1[dv] = max(mx1[dv], b[i] + a[i] + dp[i][j]);
					mn2[dv] = min(mn2[dv], b[i] - a[i] - dp[i][j]);
					mx2[dv] = max(mx2[dv], b[i] - a[i] + dp[i][j]);
				}
			}
		}
		cout << dp[n][k] << endl;
	}
	return 0;
}