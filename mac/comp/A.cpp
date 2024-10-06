#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int tc = 1; 
	cin >> tc;
	while (tc--) {
        int n; cin >> n;
		vector<char> vowels{
			'a', 'e', 'i', 'o', 'u'
		};
		if (n <= 5) {
			for (int i = 0; i < n; i++) cout << vowels[i];
		} else {
			int each = n / 5;
			int rem = n % 5;
			map<char,int> cnt;
			for (int i = 0; i < 5; i++) {
				cnt[vowels[i]] = each;
			}
			int inc = 0;
			while (rem--) {
				cnt[vowels[inc]]++;
				inc = (inc + 1) % 5;
			}
			for (auto x : cnt) {
				for (int i = 0; i < x.second; i++) {
					cout << x.first;
				}
			}
			
		}
		cout << endl;
    }
}
