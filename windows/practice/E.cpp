#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int tc = 1; 
	cin >> tc;
	for (int tt = 0; tt < tc; tt++) {
		int n, k; cin >> n >> k;
		vector<long long> a(n);
		map<long long,multiset<long long>> mod;
		for (long long& i : a) cin >> i;
		for (int i = 0; i < n; i++) mod[a[i] % k].insert(a[i]);
		long long odd = 0;
		for (auto x : mod) odd += (x.second.size() & 1);
		if (odd > 1) cout << -1 << endl;
		else {
			long long answer = 0;
			for (auto x : mod) {
				vector<long long> tmp, left, right, pleft, pright;
				tmp.insert(tmp.end(), x.second.begin(), x.second.end());
				if (tmp.size() & 1 and tmp.size() > 1) {
					for (int i = 0; i < tmp.size() - 1; i += 2) left.push_back(abs(tmp[i] - tmp[i + 1]) / k);
					for (int i = tmp.size() - 1; i > 1; i -= 2) right.push_back(abs(tmp[i] - tmp[i - 1]) / k);
					pleft.resize(left.size()), pright.resize(right.size());
					pleft[0] = left[0], pright[0] = right[0];
					for (int i = 1; i < left.size(); i++) {
						pleft[i] = left[i] + pleft[i - 1];
						pright[i] = right[i] + pright[i - 1];
					}
					reverse(pright.begin(), pright.end());
					int added = INT_MAX;
					for (int i = 0; i < tmp.size(); i++) {
						if (i % 2 == 0) {
							int rsum = (i == tmp.size() - 1) ? 0 : pright[max(0,i / 2)], lsum = (i == 0) ? 0 : pleft[i / 2 - 1];
							added = min(added, rsum + lsum);
						}
					}
					answer += added;
				} else {
					for (int i = 0; i < tmp.size() - 1; i += 2) answer += abs(tmp[i] - tmp[i + 1]) / k;
				}
			}
			cout << answer << endl;
		}
	}
}
