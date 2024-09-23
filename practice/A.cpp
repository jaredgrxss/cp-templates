#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
int n;
int t[2 * N];

void build() {
	for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
}

int query(int p) {
	for (p += n; p > 0; p >>= 1) {
		if (t[p] != 0) return t[p];
	}
}

void modify(int l, int r, int v) {
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l&1) t[l++] = v;
		if (r&1) t[--r] = v;
	}
}

struct Battle {
	int l;
	int r;
	int w;
	Battle(int l, int r, int w) {
		this->l = l;
		this->r = r;
		this->w = w;
	};
};

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int tc = 1; 
	cin >> tc;
	for (int tt = 0; tt < tc; tt++) {
		cin >> n;
		int m; cin >> m;
		vector<Battle> A(m);
		for (int i = 0; i < m; i++) {
			int l, r, w; 
			cin >> l >> r >> w;
			Battle curr(l, r, w);
			A.push_back(curr);
		}
		reverse(A.begin(), A.end());
		for (int i = 0; i < m; i++) {
			auto b = A[i];
			modify(b.l, b.r, b.w);
		}		
		for (int i = 0; i < n; i++) {
			int ans = query(i + 1);
			if (ans = i) cout << 0 << endl;
			else cout << ans << endl;
		}
	}
}
