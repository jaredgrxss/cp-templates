#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int tc = 1; 
	cin >> tc;
	for (int tt = 0; tt < tc; tt++) {
		long long n, m; cin >> n >> m;
		long long newmex = 0, mxlen = 0;
		for (int i = 0; i < n; i++) {
			int l; cin >> l;
			set<long long> b;
			for (int j = 0; j < l; j++) {
				int v; cin >> v;
				if (v <= l) b.insert(v);
			}
			mxlen = max(mxlen, (long long) b.size());
			long long mex = 0;
			for (auto j : b) if (j == mex) mex++;
			b.insert(mex);
			mex = 0;
			for (auto j : b) if (j == mex) mex++;
			if (mex > newmex) newmex = mex;
		}
		long long answer = (long long) (newmex * min(m + 1, newmex + 1));
		auto FindSum = [&](long long n) {
			return (long long) (n * (n + 1)) / 2;
		};
		long long l = min(newmex, m), r = m;
		if (FindSum(r) - FindSum(l) >= 0) answer += FindSum(r) - FindSum(l);
		cout << answer << endl;
	}
}
