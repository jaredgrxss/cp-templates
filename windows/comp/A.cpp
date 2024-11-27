#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int tc = 1; 
	cin >> tc;
	while (tc--) {
        int n; cin >> n;
		vector<int> A(n);
		for (int& i : A) cin >> i;
		int perfect = 1;
		for (int i = 1; i < n; i++) {
			int back = A[i - 1], curr = A[i];
			if (i < n - 1) {
				int front = A[i + 1];
				if ((abs(curr - back)== 7 or abs(curr - back) == 5) and (abs(curr - front) == 7 or abs(curr - front) == 5)) {
					continue;
				} else { perfect = 0; break; }
			} else {
				if (abs(curr - back) == 7 or abs(curr - back) == 5) {
					continue;
				} else { perfect = 0; break; }
			}
		}
		if (perfect) cout << "YES" << endl;
		else cout << "NO" << endl;
    }
}
