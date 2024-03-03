#include <bits/stdc++.h>
using namespace std;

/*
shortest prefix some of non-identical elements

1. calc psum
2. binary search len for each element L & R
3. if sum / len == an element in the array, NO
*/
void solve() {
	int n; cin >> n;
	vector<int> a(n); 
	for (int& i : a) cin >> i;

	vector<int> psum(n); psum[0] = a[i];
	for (int i = 1; i < n; i++) {
		psum[i] = a[i] + pasum[i - 1];
	}

	vector<int> shortest(n);
	for (int i = 0; i < n; i++) {
		
	}

	for (int i : shortest) cout << i << " ";
	cout << endl;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int tc = 1; 
	cin >> tc;
	while (tc--) solve();
}
