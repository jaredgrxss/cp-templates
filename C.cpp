#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<bool> is_prime(1e5+5);
void sieve() {
	is_prime[0] = is_prime[1] = false;
	is_prime[2] = true;
	for (int i = 2; i * i <= 1e5; i++) {
		if (is_prime[i]) {
			for (int j = i + i; j <= 1e5; j += i) {
				is_prime[j] = false;
			}
		}
	}
}
int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int tc = 1; 
	sieve();
	cin >> tc;
	for (int t = 0; t < tc; t++) {
		int n; cin >> n;
		map<int,int> m;
		for (int i = n; i > 0; i--) {
			if (i % n == 0 && m.find(i) == m.end()) {
				int j = i;
				while (j % 2 == 0) {
					m[j] = j / 2;
					j /= 2; 
				}
			} else if (i % n) {

			}
		}
		set<int> used;
		for (auto& i : m) {
			
		}
	}
	return 0;
}