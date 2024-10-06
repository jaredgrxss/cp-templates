#include <bits/stdc++.h>
using namespace std;

const string narek = "narek";

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int tc = 1; 
	cin >> tc;
	while (tc--) {
        int n, m; cin >> n >> m;
		vector<string> s(n);
		for (string& i : s) cin >> i;
		vector<int> dp(5, -1e9), ndp;
		dp[0] = 0;
		for (int i = 0; i < n; i++) {
			ndp = dp;
			for (int j = 0; j < 5; j++) {
				if (dp[j] == -INT_MAX) continue; 
				int cnt = 0, next = j;
				for (int k = 0; k < m; k++) {
					int ind = narek.find(s[i][k]);
					if (ind == -1) continue; 

					if (next == ind) { next = (next + 1) % 5; cnt++; }
					else cnt--;
				}
				ndp[next] = max(ndp[next], dp[j] + cnt);
			}
			dp = ndp;
		}
		int ans = 0;
		for (int i = 0; i < 5; i++) ans = max(ans, dp[i] - 2 * i);
		cout << ans << endl;
    }
}
