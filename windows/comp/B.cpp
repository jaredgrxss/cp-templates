#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int tc = 1; 
	cin >> tc;
	while (tc--) {
        int n, k; cin >> n >> k;
		map<int,long long> mp;
		vector<pair<int,long long>> bottles;
		for (int i = 0; i < k; i++) {
			int b; long long c; cin >> b >> c;
			if (mp.find(b) != mp.end()) mp[b] += c;
			else mp[b] = c;
		}
		for (auto x : mp) bottles.push_back(make_pair(x.first, x.second));
		auto SortBottles = [&](pair<int,long long> a, pair<int,long long> b) {
			return a.second > b.second;
		};
		sort(bottles.begin(), bottles.end(), SortBottles);
		long long answer = 0;
		for (int i = 0; i < bottles.size(); i++) {
			if (i >= n) break;
			answer += bottles[i].second;
		}
		cout << answer << endl;
    }
}
