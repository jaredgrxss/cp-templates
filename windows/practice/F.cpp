#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int tc = 1; 
	cin >> tc;
	for (int tt = 0; tt < tc; tt++) {
		double n, k; cin >> n >> k;
		vector<double> a(n), b(n);
		for (double& i : a) cin >> i;
		for (double& i : b) cin >> i;
		set<pair<double,double>> s;
		for (int i = 0; i < n; i++) s.insert({a[i], b[i]});
		auto Sum = [&](double n, double d, double a) {
			return (n / 2) * (2 * a + (n - 1) * d);
		};
		double answer = 0;
		while (k and !s.empty()) {
			auto curr = *s.rbegin();
			s.erase(prev(s.end()));
			auto prev = (s.empty()) ? make_pair(0.0, 0.0) : *s.rbegin();
			long long l = 0, r = k;
			long long ops = 0;
			while (l <= r) {
				long long m = (l + r) / 2;
				double rem = max((double) 0, curr.first - (m * curr.second));
				if (rem > prev) {
					ops = m;
					l = m + 1;
				} else {
					 r = m - 1;
				}
			}
			if (curr.first - (ops * curr.second) > 0) s.insert({curr.first - (ops * curr.second), curr.second});
			answer += Sum(ops + 1, curr.second, curr.first - (ops * curr.second));
			k -= ops + 1;
		}
		cout << (long long) answer << endl;
	}
}
